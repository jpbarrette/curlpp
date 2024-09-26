/*
*    Copyright (c) <2002-2005> <Jean-Philippe Barrette-LaPierre>
*
*    Permission is hereby granted, free of charge, to any person obtaining
*    a copy of this software and associated documentation files
*    (curlpp), to deal in the Software without restriction,
*    including without limitation the rights to use, copy, modify, merge,
*    publish, distribute, sublicense, and/or sell copies of the Software,
*    and to permit persons to whom the Software is furnished to do so,
*    subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included
*    in all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
*    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
*    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
*    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/**
 * \file
 * Multi demo using poll/wait
 *
 */

#include <iostream>
#include <sstream>
#include <cstdlib>

#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Multi.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#pragma comment(lib, "Ws2_32.lib")
#endif // WIN32

int main(int argc, char *argv[]) {
    const char *url1 = "http://www.baidu.com";
    const char *url2 = "https://cn.bing.com";

    try {
        curlpp::initialize();

        curlpp::Easy request1;
        curlpp::Easy request2;

        request1.setOpt(new curlpp::options::Url(url1));
        std::ostringstream os1;
        curlpp::options::WriteStream ws1(&os1);
        request1.setOpt(ws1);

        std::list<std::string> headers1;
		headers1.push_back("content-type:text/html; charset=utf-8");
        request1.setOpt(new curlpp::Options::HttpHeader(headers1));
        request1.setOpt(new curlpp::options::TimeoutMs(1000));


        request2.setOpt(new curlpp::options::Url(url2));
        std::ostringstream os2;
        curlpp::options::WriteStream ws2(&os2);
        request2.setOpt(ws2);
        request2.setOpt(new curlpp::options::TimeoutMs(1000));

        curlpp::Multi requests;
        requests.add(&request1);
        requests.add(&request2);

        /* we start some action by calling perform right away */
        int nbLeft = 0;
        while (!requests.perform(&nbLeft)) {
        };

        while (nbLeft) {
            // block until activity is detected on at least one of the handles or timeout_ms has passed
            requests.wait(100);
            while (!requests.perform(&nbLeft)) {
            };
        }

        std::cout << "NB lefts: " << nbLeft << std::endl;

        /* See how the transfers went */
        /*
           Multi::info returns a list of:
           std::pair< curlpp::Easy, curlpp::Multi::Info >
        */
        const curlpp::Multi::Msgs msgs = requests.info();
        for (auto pos = msgs.begin(); pos != msgs.end(); pos++) {
            if (pos->second.msg == CURLMSG_DONE) {
                /* Find out which handle this message is about */
                if (pos->first == &request1) {
                    std::cout << "First request completed with status " << pos->second.code << ",data:" << os1.str() << std::endl;
                } else if (pos->first == &request2) {
                    std::cout << "Second request completed with status " << pos->second.code << ",data:" << os2.str() << std::endl;
                }
            }
        }

        curlpp::terminate();

    } catch (curlpp::LogicError &e) {
        std::cout << e.what() << std::endl;
    } catch (curlpp::RuntimeError &e) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
