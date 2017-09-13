#include <stdio.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <unistd.h>

using namespace std;

#define URL_SIZE 150
#define NO_CHILD_THREAD 20

void *childtask(void *arg) {

	int *flag = (int *)arg;
	// HARDCODED URL
	const char* googleurl = "https://www.google.co.in";

	char url[URL_SIZE]={0};
	strcat(url, googleurl);
	curlpp::Easy *request = NULL;
	try {
		request = new curlpp::Easy();
		request->setOpt(new curlpp::options::Url(url)); 
		request->setOpt(new curlpp::options::Verbose(true)); 
		printf("%d : Requesting to google : \n", pthread_self());

		std::stringstream *response = new stringstream();
		request->setOpt(new curlpp::options::WriteStream(response));
		request->perform();
		string response_str = response->str();
		printf("********\n");
		printf("\n");
		printf("%d : Response: %s \n", pthread_self(), response_str.c_str());
		printf("\n");
		printf("**********\n");
		/***
		 * ignore parsing response code 
		 ***/
		if(request != NULL) {
			delete request;
			request = NULL;
		}
	}
	catch ( curlpp::LogicError & e ) {
		printf(" Logic Error: %s \n", e.what());
		if(request != NULL) {
			delete request;
			request = NULL;
		}
		*flag = 0;
		return (void *) 0;
	}
	catch ( curlpp::RuntimeError & e ) {
		printf(" Runtime Error: %s \n", e.what());
		printf( "%d Runtime Error %s \n", pthread_self(), e.what());
		if(request != NULL) {
			delete request;
			request = NULL;
		}
		*flag = 0;
		return (void *) 0;
	}

	*flag = 0;
	return (void *) 0;
}

void *parenttask(void *)
{
	pthread_t childThread[NO_CHILD_THREAD];
	int i = 0;
	int flag[NO_CHILD_THREAD];
	for(i = 0; i < NO_CHILD_THREAD; i++) { 
		flag[i] = 1;
		int st  = pthread_create(&childThread[i], NULL, childtask, &flag[i]);
	}

	for(i = 0; i < NO_CHILD_THREAD; i++) { 
		while(flag[i]) {
			//wait for finishing the child
		}
	}

}

int main() {
	int i = 1;
	while(true) {
		pthread_t parentThread;
		pthread_create(&parentThread, NULL, parenttask, NULL);
	}
	return 0;
}
