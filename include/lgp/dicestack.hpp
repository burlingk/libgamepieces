/// \file lgp_dicestack.hpp
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
/// File last updated 12:22 UTC on 26 Sept 2009

#ifndef LGP_DICESTACK_HPP_
#define LGP_DICESTACK_HPP_

#include <lgp/dicenode.hpp>



namespace lgp
{

  /// \brief A class representing a set of die rolls.
  ///
  /// class DiceStack represents a list of die rolls.  It provides the tools to
  /// add rolls, remove rolls, and even modify rolls directly.  All of its moving
  /// pieces are declared virtual, so that if someone things they can do a better
  /// job, or just wants to do it differently, they are free to do so.
  class DiceStack
  {
  protected:
    DiceNode * firstNodePtrM;  ///< \brief Pointer to first node in the list.
    int countM;                 ///< \brief Number of rolls in the set.
  public:
    DiceStack();
    virtual ~DiceStack();
    virtual void addRoll(int sides, int mods=0);
    virtual int showRoll(int index=0);
    virtual int removeRoll(int index=0);
    virtual DiceNode & die(int index=0);
    virtual bool isEmpty(void);
    virtual int size(void);
    virtual bool empty(void);
  }; //end class DiceStack

}//end namespace lgp



#endif /* LGP_DICESTACK_HPP_ */


