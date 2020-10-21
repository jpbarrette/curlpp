/**
* \file
* The most simple example.
*
*/

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>


using namespace curlpp::options;

int main(int, char **)
{
	try
	{
		// This is marked deprecated.
		// curlpp::Cleanup myCleanup;

		// Use this instead.
		curlpp::initialize();

		// Our request to be sent.
		curlpp::Easy myRequest;

		// Set the URL.
		myRequest.setOpt<Url>("http://example.com");

		// Send request and get a result.
		// By default the result goes to standard output.
		myRequest.perform();
	}

	catch(curlpp::RuntimeError & e)
	{
		std::cout << e.what() << std::endl;
	}

	catch(curlpp::LogicError & e)
	{
		std::cout << e.what() << std::endl;
	}

	// :Cleanup is deprecated, so do this for cleanup.
	curlpp::terminate();

	return 0;
}
