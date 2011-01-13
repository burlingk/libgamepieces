/// \file lgp_random.hpp
/// \brief A set of functions to deal with randome numbers.
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
///  randomnumbers.hpp and randomnumbers.cpp are part of libemtools.  They
///  contain a handfull of basic functions for dealign with random numbers.
///
///  libemtools is a library of basic tools that I am putting together as I go.
///
/// File last updated 14:34 JST on 9 Sept 2009


#ifndef RANDOMNUMBERS_HPP_
#define RANDOMNUMBERS_HPP_

//<cstdlib> provides the function int rand(void).
//int rand(void) returns a random number between 0 and RAND_MAX
//RAND_MAX is a very big number.

#include <cstdlib>

//<ctime> includes the time related functions and constants that will be used
//as the seed for the random number generator.
#include <ctime>

//For the moment the namespace for the library will be called emtool.
//When I come up with something better I will update everything.  I would
//prefer for this to happen while the library is still in alpha stage.
namespace lgp
{
  ///void seed(void); seeds the random number generator with the current time.
  ///on most systems this will be an unsigned int representation of the current time in seconds
  ///counting from some event.
  void seed(void);

  ///void seed(unsigned int newSeed); lets you pick the seed yourself.  newSeed is an unsigned integer.
  ///This function is effectively just a wrapper for the std::srand() function.
  void seed(unsigned int newSeed);

  ///int random(int max) will return a random integer value betweeon 0 and max-1
  int random(int max);

  ///int random(int min, int max) will return a value between min and max.
  int random(int min, int max);


}









#endif /* RANDOMNUMBERS_HPP_ */


