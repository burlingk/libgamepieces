/// \file lgp_dicebag.cpp
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
///  contain a handful of basic functions for dealing with random numbers
///  in an RPG related manner.  They are designed to simulate a bag of dice.
///
///  libgamepieces is a library of tools to help build an RPG that I want to create.
///
/// File last updated 13:45 UCT on 1 October 2009
///
///

#include <lgp/random.hpp>
#include <lgp/dicebag.hpp>

#include <sstream>

namespace lgp
{
  //returns a number between 1 and sides.
  int dX(int sides)
  {
    //Make sure they want at least 1 side
    if(sides < 1)
      {
      throw InvalidValueException() << invalid_int_value(sides) << invalid_parameter("sides") << throwing_function("dX(int sides)") << throwing_file( __FILE__ );
      }

    //We don't want a d1, but who knows what the program might ask for.
    if(sides == 1){return 1;}

    //If everything went as it should, we will now return a random number between 1 and sides.
    return(random(1,sides));
  }



  //D100
  //d100()     === 1d100
  //d100(3)    === 3d100
  //d100(3,10) === 3d100+10
  int d100(int number=1, int mods=0)
  {
    //They cannot ask for fewer than 1 die.
    if(number < 1)
      {
      throw InvalidValueException() << invalid_int_value(number) << invalid_parameter("number") << throwing_function("d100(int number, int mods)") << throwing_file( __FILE__ );
      }



    int value = 0;
    for(int i = 0; i < number; i++)
      {
       value += dX(100);
      }
    value += mods;

    return(value);
  } //end d100()

  int d30(int number=1, int mods=0)
  {
    //They cannot ask for fewer than 1 die.
    if(number < 1)
      {
      throw InvalidValueException() << invalid_int_value(number) << invalid_parameter("number") << throwing_function("d30(int number, int mods)") << throwing_file( __FILE__ );
      }

    int value = 0;
    for(int i = 0; i < number; i++)
      {
       value += dX(30);
      }
    value += mods;

    return(value);
  } //end d30


  int d20(int number=1, int mods=0)
  {
    //They cannot ask for fewer than 1 die.
    if(number < 1)
      {
      throw InvalidValueException() << invalid_int_value(number) << invalid_parameter("number") << throwing_function("d20(int number, int mods)") << throwing_file( __FILE__ );
      }

    int value = 0;
    for(int i = 0; i < number; i++)
      {
       value += dX(20);
      }
    value += mods;

    return(value);
  } //end d20

  int d12(int number=1, int mods=0)
  {
    //They cannot ask for fewer than 1 die.
    if(number < 1)
      {
      throw InvalidValueException() << invalid_int_value(number) << invalid_parameter("number") << throwing_function("d12(int number, int mods)") << throwing_file( __FILE__ );
      }

    int value = 0;
    for(int i = 0; i < number; i++)
      {
       value += dX(12);
      }
    value += mods;

    return(value);
  }//end d12()

  int d10(int number=1, int mods=0)
  {
    //They cannot ask for fewer than 1 die.
    if(number < 1)
      {
      throw InvalidValueException() << invalid_int_value(number) << invalid_parameter("number") << throwing_function("d10(int number, int mods)") << throwing_file( __FILE__ );
      }

    int value = 0;
    for(int i = 0; i < number; i++)
      {
       value += dX(10);
      }
    value += mods;

    return(value);
  }//end d10()

  int d8(int number=1, int mods=0)
  {
    //They cannot ask for fewer than 1 die.
    if(number < 1)
      {
      throw InvalidValueException() << invalid_int_value(number) << invalid_parameter("number") << throwing_function("d8(int number, int mods)") << throwing_file( __FILE__ );
      }

    int value = 0;
    for(int i = 0; i < number; i++)
      {
       value += dX(8);
      }
    value += mods;

    return(value);
  }//end d8()

  int d6(int number=1, int mods=0)
  {
    //They cannot ask for fewer than 1 die.
    if(number < 1)
      {
      throw InvalidValueException() << invalid_int_value(number) << invalid_parameter("number") << throwing_function("d6(int number, int mods)") << throwing_file( __FILE__ );
      }

    int value = 0;
    for(int i = 0; i < number; i++)
      {
       value += dX(6);
      }
    value += mods;

    return(value);
  }//end d6()

  int d3(int number=1, int mods=0)
  {
    //They cannot ask for fewer than 1 die.
    if(number < 1)
      {
      throw InvalidValueException() << invalid_int_value(number) << invalid_parameter("number") << throwing_function("d3(int number, int mods)") << throwing_file( __FILE__ );
      }

    int value = 0;
    for(int i = 0; i < number; i++)
      {
       value += dX(3);
      }
    value += mods;

    return(value);
  } //end d3()

  //Fudge dice!!!!!!!
  int dF(int dice)
  {
    //They cannot ask for fewer than 1 die.
    if(dice < 1)
      {
      throw InvalidValueException() << invalid_int_value(dice) << invalid_parameter("dice") << throwing_function("dF(int dice)") << throwing_file( __FILE__ );
      }

    int value = 0;
    for(int i = 0; i < dice; i++)
      {
       value += (dX(3)-2);
      }
    return(value);
  }// end dF()




}//end namespace lgp




