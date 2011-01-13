/// \file lgp_random.cpp
/// \brief A set of functions to deal with random numbers.
/// \author Kenneth. M. Burling Jr. (a.k.a. Emry)
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
///  lgp_random.hpp and lgp_random.cpp are part of libgamepieces.  They
///  contain a handful of basic functions for dealign with random numbers.
///
///
///
/// File last updated 18:30 UTC on 12 Jun 2010
#include <lgp/lgp_random.hpp>


namespace lgp
{
  //Just a direct wrapper for srand();
  void seed(unsigned int newSeed)
  {
    srand(newSeed);
    random(100);
    return;
  }

  //The same as seed(unsigned int) except that it provides a default value
  //in the form of the current system time.
  void seed(void)
  {
    srand(static_cast<unsigned int>(time(NULL)));
    random(100);
    return;
  }

  //This function will return a random value between 0 and max-1
  //To do this, we generate a random number and multiply it by our desired maximum value.
  //We then divide that number by RAND_MAX+1.
  //This has the effect of producing a fractional number and multiplying it by are desired maximum.
  //We then convert the number to an integer and return it.  This will produce a number between
  //0 and max-1.  This mimics the behavior of the rand(int) and random(int) functions implemented in most
  //other languages.
  int random(int max)
  {
    double value = (static_cast<double>(max) * static_cast<double>(rand()))/(static_cast<double>(RAND_MAX)+1.0);
    return(static_cast<int>(value));
  }

  //int random(int min, int max);
  //Here we modify the formula above to give us a value that is between min and max.
  //First, instead of using max as the multiplier, we use (max+1-min).
  int random(int min, int max)
  {
    double value = (static_cast<double>(max-min+1) * static_cast<double>(rand()))/(static_cast<double>(RAND_MAX)+1.0);
    value = value + static_cast<double>(min);
    return static_cast<int>(value);
  }



}

