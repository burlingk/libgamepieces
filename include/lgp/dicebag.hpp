/// \file lgp_dicebag.hpp
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
///  lgp_dicebag.hpp and lgp_dicebag.cpp are part of libegamepieces.  They
///  contain a handfull of basic functions for dealign with random numbers
///  in an RPG related manner.  They are designed to simulate a bag of dice.
///
///  libgamepieces is a library of tools to help build an RPG that I want to create.
///
/// File last updated 13:43 UTC on 13 Jan 2011

#ifndef LGP_DICEBAG_HPP_
#define LGP_DICEBAG_HPP_

#include <lgp/exceptions.hpp>



/// \namespace lgp
/// \brief The namespace used for holding components of the libgamepieces library.
///
/// This namespace will be used to hold the parts of the libgamepieces library.  Some
/// of these parts will be in the form of functions, and others will be classes.
namespace lgp
{
  /// \brief  a single generic die roll.
  ///
  /// Takes a single integer as the argument representing the number of sides that the die has.
  /// The return value is a number between 1 and sides, representing the number rolled on the die.
  /// This function represents a single unmodified die roll, and also serves as the core of the other
  /// dice related functions.
  int   dX(int sides); /*throw(InvalidValueException)*/

  /// \brief Nd100.  Number defaults to 1, and mods defaults to 0.  If you want to use a modifier
  ///  though, you have to include number, even if it is just 1.
  ///
  ///
  ///  example:    d100();     returns 1d100
  ///              d100(2);    returns 2d100
  ///              d100(1,10); returns 1d100 + 10
  ///              d100(,10);  is a syntax error
  ///  The same format is used for the other related functions.
  int d100(int number, int mods);

  /// \brief Nd30
  int  d30(int number, int mods);

  /// \brief Nd20
  int  d20(int number, int mods);

  /// \brief Nd12
  int  d12(int number, int mods);

  /// \brief Nd10
  int  d10(int number, int mods);

  /// \brief Nd8
  int   d8(int number, int mods);

  /// \brief Nd6
  int   d6(int number, int mods);

  /// \brief Nd4
  int   d4(int number, int mods);

  /// \brief Nd3
  int   d3(int number, int mods);

  /// \brief NdF
  ///
  ///  dF() represents a roll of fudge dice.  Each roll of a dF returns a value between -1 and +1
  int   dF(int dice); /*throw(InvalidValueException)*/


  //Following are helper functions to make code more readable.

  /// \brief If the value is less than 1, it raises an exception.
  ///
  /// The parameters are so that the calling function can set it up and not have to manually type every
  /// line every time.  Standard usage would be similar to:
  ///
  ///  try{lessThanOneExceptionCheck(sides, "sides", "int dX(int)", "lgp_dicebag.cpp");}
  ///  catch(InvalidValueException exception){throw;}
  ///
  ///   assume sides = -3
  ///   this would set exception.getMessagbe() to return "Exception: Invalid value (-3) privided for sides in function 'int dX(int)' in file lgp_dicebag.cpp."
  ///

}




#endif /* LGP_DICEBAG_HPP_ */


