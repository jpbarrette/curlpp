/*
 *    Copyright (c) <2002-2008> <Jean-Philippe Barrette-LaPierre>
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

#ifndef CURLPP_FILE_TRAIT_HPP
#define CURLPP_FILE_TRAIT_HPP

#include "curlpp/buildconfig.h"
#include "curlpp/storage_trait.hpp"

namespace curlpp
{


	/**
	* Base class for 'FILE' storage trait.
	*/

	CURLPPAPI class file_trait
	{

	public:

		/**
		* close the file if it has been specified using a file name and has not
		* already been closed by a call to 'close'.
		*/
		virtual ~file_trait();

		/**
		* Returns the file size. The file has to be opened before for this to
		* succeed.
		*/
		bool size(long & size);

		/**
		* Returns file name. Returns NULL if the file xas specified using the 'FILE'
		* constructor. If the file is not open or an error occured, false is returned.
		*/
		const char * name()
		{
			return m_filename.c_str();
		}

		/**
		* open the file using 'open_mode'. Returns true if the file was already
		* open or has been open successfully.
		*/
		bool open(const char * open_mode);

		/**
		* close the file. Returns true if the file was already closed or closed
		* successfully. Returns false if the file was specified using the 'FILE'
		* constructor.
		*/
		bool close();

	protected:

		FILE * m_file;
		std::string m_filename;

		/**
		* 'FILE' constructor. The file will never be closed. It's the caller
		* responsibility to close it.
		*/
		file_trait(FILE * file);

		/**
		* File name constructor. The file will be opened and closed when needed.
		*/
		file_trait(const char * filename);

	};


	/**
	* this class is fo ouput FILE *
	*/

	CURLPPAPI class ofile_trait : public curlpp::output_trait, public curlpp::file_trait
	{

	public:

		ofile_trait(FILE * file);
		ofile_trait(const char * filename);

		size_t write(void * buffer, size_t size);

	};


	/**
	* this class is for intput FILE *
	*/

	CURLPPAPI class ifile_trait : public input_trait, public file_trait
	{

	public:

		ifile_trait(FILE * file);
		ifile_trait(const char * filename);

		size_t read(void * buffer, size_t size);

	};


	/**
	* standard input trait
	*/
	static ifile_trait stdin_trait(stdin);


	/**
	* standard output trait
	*/
	static ofile_trait stdout_trait(stdout);


} // namespace curlpp

namespace cURLpp = curlpp;


#endif // #ifndef CURLPP_FILE_TRAIT_HPP
