/// \file lgp_dicenode.hpp
/// \brief A linked list node representing a roll of a die.
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
/// File last updated 13:43 UTC on 13 Jan 2011
#ifndef LGP_DICENODE_HPP_
#define LGP_DICENODE_HPP_

#include <lgp/lgp_dicebag.hpp>

namespace lgp
{

/// \brief A class representing a single die roll in a list of rolls.
///
/// class DiceNode represents a single die in a group of dice.  It is
/// intended primarily to be used as a node by lgp::DiceStack.  It will
/// store three main pieces of data.  rollM will represent the value of the roll
/// itself, modM will represent the modifier that was assigned to the roll,
/// and sidesM will represent the number of sides the die has.
///
/// It will also store a pointer linking it to the next roll in the chain, nextPtrM.
class DiceNode
{
protected:
  int sidesM;          ///< \brief The number of sides on the die.
  int rollM;           ///< \brief The value rolled on the die.
  int modM;            ///< \brief The die modifier.
  DiceNode * nextPtrM; ///< \brief The pointer to the next node in the chain.
public:
  //First the constructors and destructor.
  DiceNode();
  DiceNode(int sides);
  DiceNode(int sides, int mod);
  virtual ~DiceNode();

  //Roll related setters.
  virtual int roll(void);               //reroll based on the current data
  virtual int roll(int sides);          //roll the die.  The die now has a number of sides equal to sides.
  virtual int roll(int sides, int mod); //The same as above, except it includes a modifier.
  virtual int setMod(int mod);          //Reset the modifier, but do not change the roll.
  virtual int setRoll(int value);       //"cheat" by setting the value rolled.
  virtual int setSides(int sides);      //change the number of sides the die has.
  virtual DiceNode & operator=(DiceNode & node); ///

  //Roll related getters.
  int getRoll(void);            //returns rollM;
  int getMod(void);             //returns modM;
  int getSides(void);           //returns sidesM;
  int getResult(void);          //returns rollM+modM;

  //Pointer related setters and getters
  DiceNode * getNext(void);     //return a pointer to the next node.
  void setNext(DiceNode * node);//sets the link to the next node in the list.
}; //end class DiceNode


} //end namespace lgp
#endif /* LGP_DICENODE_HPP_ */

