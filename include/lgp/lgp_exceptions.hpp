/// \file lgp_exceptions.hpp
/// \brief lgp Exceptoins.  Part of the libgamepieces library.
/// \author Kenneth. M. Burling Jr. (a.k.a Emry)
/// \version Alpha-0.001
///
/// copyright: Copyright &copy; 2008, 2009, 2010 K. M. Burling Jr.<br>
///            All Rights Reserved
///
/// Redistribution and use in source and binary forms, with or without modification, are permitted provided that
/// the following conditions are met:
///
/// * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
/// * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
///   disclaimer in the documentation and/or other materials provided with the distribution.
/// * Neither the name of the libgamepieces project team, nor the names of its contributors may be used to endorse or
///   promote products derived  from this software without specific prior written permission.
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
/// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
/// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
/// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
/// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
/// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
/// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
/// lgp_exceptions.hpp is a part of libgamepieces.  It is the portion that will deal with
/// exceptions.
///
///
///
///  libgamepieces is a library of tools to help build an RPG that I want to create.
///
///
///  Revision History: <br>
///  1 Oct 09:<br>
///  > Totally removed the original lgp_exception.cpp and lgp_exception.hpp<br>
///  > Recreated exceptions based on boost::exception.  Much more readable, much less code.  Compatible License.
///
///  Exceptions are now handled using exceptions derived from boost::exception.
///
///  throw InvalidValueException() << invalid_value(sides) << invalid_parameter("sides") << throwing_function("dX(int sides)") << throwing_file( __FILE__ );
///
///  catch(boost::exception & e){ std::cerr << "OMG!" << boost::diagnostic_information(e); }
///
///
/// File last updated 13:30 UCT on 1 October 2009


#ifndef LGP_EXCEPTIONS_HPP_
#define LGP_EXCEPTIONS_HPP_

#include <boost/exception.hpp>


namespace lgp
{

  //Exceptions
  /// \brief Thrown when an invalid value is passed to a function.
  struct InvalidValueException: virtual boost::exception, virtual std::exception { };

  /// \brief Thrown when the program tries to access an empty list.
  struct EmptyListException:    virtual boost::exception, virtual std::exception { };

  /// \brief Thrown when an out of range value is requested, such as a non-existant index in an array or list.
  struct OutOfRangeException:   virtual boost::exception, virtual std::exception { };

  //Common Tags

  //Identifying the Function that threw the exception
  typedef boost::error_info<struct tag_throwing_function,const char *> throwing_function;   ///< The function that three the exception
  typedef boost::error_info<struct tag_throwing_file,const char*> throwing_file;            ///< The file the throwing exception is in Usually

  //Identyfying the function that called the function that threw the exception
  typedef boost::error_info<struct tag_called_from, const char*> called_from;               ///< Where was the failing function called from?
  typedef boost::error_info<struct tag_called_from_file, const char*> called_from_file;     ///< Which file was the calling function in?

  //Identifying the variable and value that caused the exception.
  typedef boost::error_info<struct tag_invalid_int_value,int> invalid_int_value;            ///< The invalid value that was passed
  typedef boost::error_info<struct tag_invalid_parameter, const char*> invalid_parameter;   ///< The parameter that the invalid value was assigned too.

  //Identifying Propper values
  typedef boost::error_info<struct tag_max_range,int> max_range;                            ///< Informational.  Maximum valid value.
  typedef boost::error_info<struct tag_min_range,int> min_range;                            ///< Informational.  Minimum valid value.







}//end namespace lgp



#endif /* LGP_EXCEPTIONS_HPP_ */

