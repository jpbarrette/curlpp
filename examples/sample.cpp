#include <stdio.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <string>
#include <string.h>
#include <thread>
#include <iostream>
#include <sstream>
#include <unistd.h>



// Better exception handling: https://stackoverflow.com/questions/7272093/what-happens-when-an-exception-goes-unhandled-in-a-multithreaded-c11-program

using namespace std;

#define URL_SIZE 150
#define NO_CHILD_THREAD 200

void childtask() {

	// HARDCODED URL
//    std::string googleurl = "https://www.google.co.in";
    const char* test_url = "https://httpbin.org/";

    curlpp::Easy *request = nullptr;
    std::stringstream *response = nullptr;

	try {
        request = new curlpp::Easy();
		request->setOpt(new curlpp::options::Url(test_url));
		request->setOpt(new curlpp::options::Verbose(true)); 
		printf("Requesting to google : %s\n", test_url);

		response = new stringstream();;
		request->setOpt(new curlpp::options::WriteStream(response));
		request->perform();
		string response_str = response->str();
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

    delete request;
    delete response;
}


int main() {

    curlpp::Cleanup myCleanup;

    std::thread childThread[NO_CHILD_THREAD];

    for (unsigned i = 0; i < 200; ++i) {
        // spawn n threads:
        for (int i = 0; i < NO_CHILD_THREAD; i++) {
            childThread[i] = std::thread(childtask);
        }

        for (auto& th : childThread) {
            th.join();
        }
    }
}
