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


// Better exception handling: https://stackoverflow.com/questions/7272093/what-happens-when-an-exception-goes-unhandled-in-a-multithreaded-c11-program

using namespace std;

#define URL_SIZE 150
#define NO_CHILD_THREAD 200

void childtask() {

	// HARDCODED URL
	const char* googleurl = "https://www.google.co.in";

	char url[URL_SIZE]={0};
	strcat(url, googleurl);
	curlpp::Easy request;
	try {
		request.setOpt(new curlpp::options::Url(url)); 
		request.setOpt(new curlpp::options::Verbose(true)); 
		printf("Requesting to google : \n");

		std::stringstream response;
		request.setOpt(new curlpp::options::WriteStream(response));
		request.perform();
		string response_str = response.str();
		printf("********\n");
		printf("\n");
		printf("Response: %s \n", response_str.c_str());
		printf("\n");
		printf("**********\n");
	}
	catch ( curlpp::LogicError & e ) {
		printf(" Logic Error: %s \n", e.what());
	}
	catch ( curlpp::RuntimeError & e ) {
		printf(" Runtime Error: %s \n", e.what());
	}
}


int main() {
	
	thread childThread[NO_CHILD_THREAD];

    // spawn n threads:
    for (int i = 0; i < n; i++) {
        childThread[i] = thread(childtask);
    }

    for (auto& th : threads) {
        th.join();
	}
}
