/// \file lgp_dicenode.cpp
/// \brief A linked list node representing a roll of a die.
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
///  lgp_dicenode.o and lgp_dicestack.o are part of libegamepieces.  They
///  are a couple of classes for dealing with groups of numbers that represent
///  a set if die rolls.  They will be implemented from the ground up with the
///  idea that the roll and the modifier will be stored separately so that the user
///  can request either or both.
///
///  They will also be implemented in a form that is intended to make it easier to
///  derive classes from them.  As such, most methods will be set as virtual and most
///  member data will be set as protected.  This will give developers the ability to
///  access any aspect of a derived class without having to modify my code unless they
///  want to.
///
///  libgamepieces is a library of tools to help build an RPG that I want to create.
///
/// File last updated 17:10 UTC on 6 Oct 2009
///
///
///
///


#include <lgp/dicenode.hpp>
#include <lgp/exceptions.hpp>


namespace lgp
{
  //first Constructors and Destructor

  /// \brief The Default constuctor.  Assumes d6+0.
  ///
  /// This is the default constructor.  If the constructor is called without
  /// any arguments then the default is a six sided die with no modifiers.
  ///
  /// I personally would discourage the use of the default constructor.  However,
  /// actively preventing the use of the default constructor would also effectively
  /// prevent inheritance.  So, instead of preventing it, we will make sure that if
  /// it is called it produces useable data.
  ///
  /// The reason that I am assuming a six sided die for the default is because it
  /// is the closest thing to a universal standard when it comes to dice.  Most games
  /// that use dice will have a six sider of some sort.  Many games only use six sided
  /// dice.  Quite often, if you talk to someone about dice, they will automaticall think
  /// of six siders unless you specify otherwise.  This makes it a good default.
  ///
  /// Example: DiceNode myDie;
  DiceNode::DiceNode()
  {
    sidesM = 6;
    modM   = 0;
    rollM  = dX(6);
    nextPtrM = NULL;
  }

  /// \brief A constructor that lets you simulate an unmodified die roll.
  ///
  /// This is a better option than the default.  It lets you specify the number of sides for
  /// the roll.  This version of the constructor behaves like the default except that it lets
  /// you decide how many sides the die has.
  ///
  /// Example:  DiceNode myDie(8);  //Creates a d8.
  DiceNode::DiceNode(int sides)
  {
    if(sides < 1)
      {
      throw InvalidValueException() << invalid_int_value(sides) << invalid_parameter("sides") << throwing_function("DiceNode::DiceNode(int sides)") << throwing_file( __FILE__ );
      }
    sidesM = sides;
    modM   = 0;
    rollM  = dX(sides);
    nextPtrM = NULL;
  }

  /// \brief A constructore to simulate a modified die roll.
  ///
  /// This constructor is better than the default.  It lets you specify a modifier for
  /// the roll at the time of creation.  Again, it's usage is similare to the other
  /// constructors.
  ///
  /// Example:  DiceNode myDie(10,2);  //Creates a die roll for 1d10+2
  DiceNode::DiceNode(int sides, int mod)
  {
    if(sides < 1)
      {
      throw InvalidValueException() << invalid_int_value(sides) << invalid_parameter("sides") << throwing_function("DiceNode::DiceNode(int sides, int mod)") << throwing_file( __FILE__ );
      }
    sidesM = sides;
    modM   = mod;
    rollM  = dX(sides);
    nextPtrM = NULL;
  }

  /// \brief The destructor.  Only here for polymorphic reasons.
  ///
  /// class DiceNode does not allocate memory for anything.  It stores simple values
  /// and a pointer to an object that something else created.  It is not intended to
  /// do any memory management.  That should all be handled by other code.  For this
  /// reason, the destructor has nothing to do.
  DiceNode::~DiceNode()
  {
    return;
  }


  /// \brief The = operator.
  DiceNode & DiceNode::operator=(DiceNode & node)
  {
    sidesM = node.getSides();
    rollM  = node.getRoll();
    modM   = node.getMod();
    return *this;
  }



  //Roll related setters.

  /// \brief Reroll the die.
  ///
  /// This method rerolls the die using the same number of sides and the same
  /// modifier that is already set for the die.  It returns the new value of
  /// the die.
  int DiceNode::roll(void)
  {
    rollM = dX(sidesM);
    return getResult();
  }

  /// \brief reroll the roll using a different die.
  ///
  /// This method changes the number of sides that the die has, but
  /// keeps the existing modifier.
  int DiceNode::roll(int sides)
  {
    if(sides < 1)
      {
      throw InvalidValueException() << invalid_int_value(sides) << invalid_parameter("sides") << throwing_function("DiceNode::roll(int sides)") << throwing_file( __FILE__ );
      }
    sidesM = sides;
    rollM = dX(sidesM);
    return getResult();
  }

  /// \brief Reroll the roll with a different die and different modifiers.
  ///
  /// This method changes the die roll entirely.  It sets a new type of die,
  /// and a new modifier.
  int DiceNode::roll(int sides, int mod)
  {
    if(sides < 1)
      {
      throw InvalidValueException() << invalid_int_value(sides) << invalid_parameter("sides") << throwing_function("DiceNode::roll(int sides, int mod)") << throwing_file( __FILE__ );
      }
    sidesM = sides;
    rollM = dX(sidesM);
    modM = mod;
    return getResult();
  }

  /// \brief Lets you manually set the modifier for the die roll.
  int DiceNode::setMod(int value)
  {
    modM = value;
    return getResult();
  }

  /// \brief Lets you manually set the value for the roll.
  int DiceNode::setRoll(int value)
  {
    rollM = value;
    return getResult();
  }

  /// \brief Lets you manually change the type of die.  If(rollM > sides) it rerolls.
  int DiceNode::setSides(int sides)
  {
    if(sides < 1)
      {
      throw InvalidValueException() << invalid_int_value(sides) << invalid_parameter("sides") << throwing_function("DiceNode::setSides(int sides)") << throwing_file( __FILE__ );
      }
    sidesM = sides;
    if(rollM > sidesM){rollM = dX(sidesM);}
    return getResult();
  }

  //Now for Roll related getters.

  /// \brief Returns the value on the die (rollM)
  int DiceNode::getRoll(void)
  {
    return rollM;
  }

  /// \brief returns the modifier (modM)
  int DiceNode::getMod(void)
  {
    return modM;
  }

  /// \brief returns the type of die (sidesM)
  int DiceNode::getSides(void)
  {
    return sidesM;
  }

  /// \brief Returns the total value of the die
  int DiceNode::getResult(void)
  {
    return (rollM+modM);
  }


  //Pointer setter and getter

  /// \brief Returns a pointer to the next die in the list.
  DiceNode * DiceNode::getNext(void)
  {
    return nextPtrM;
  }

  /// \brief Set the link to the next die in the list
  void DiceNode::setNext(DiceNode * node)
  {
    nextPtrM = node;
    return;
  }




} //end namespace lgp




