/**
* \file
* Setting request options using iterators to custom container of curlpp options.
*
*/

#include <vector>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>


using namespace curlpp::options;

int main(int, char **)
{
	try
	{
		// curlpp::cleanup is deprecated.
		curlpp::initialize();

		// Our request to be sent.
		curlpp::Easy myRequest;

		// Container of our choice with pointers to curlpp options.
		std::vector<curlpp::OptionBase *> options;

		options.push_back(new Url("http://example.com"));
		options.push_back(new Port(80));

		// Set all options in range to the Easy handle.
		myRequest.setOpt(options.begin(), options.end());

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

	curlpp::terminate();
	return 0;
}
