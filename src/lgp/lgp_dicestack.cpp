/// \file lgp_dicestack.cpp
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

#include <iostream>       // Possibly temporary.

#include <lgp/lgp_dicestack.hpp>

namespace lgp
{
  /// \brief The constructor.  Set everything to null or 0.
  DiceStack::DiceStack()
  {
    firstNodePtrM = NULL;
    countM = 0;
  }

  /// \brief The destructor.
  ///
  /// DiceStack is a container, so if it is going to be destroyed,
  /// it needs to be emptied first.  We will do this by repeating calls
  /// to removeRoll(0) until the list is empty.
  DiceStack::~DiceStack()
  {
    if(isEmpty()){return;}                     //If it is already empty, we are done.
    while(!isEmpty()){removeRoll(0);}          //Otherwise, empty it first. :-)
    return;
  }

  /// \brief Add a roll to the stack.
  ///
  /// addRoll() lets you add a roll to the stack.  int sides represents the kind of die
  /// you are rolling.  For instance, 4 would represent a d4.  sides must be at least 1.
  /// Of course, a 1 sided die will always return 1.  mods can be omitted if there is no modifier,
  /// and can be any integer value.
  ///
  /// example:   1d4.  MyDice.addRoll(4);
  ///
  /// example:  1d6+2. MyDice.addRoll(6,2);
  void DiceStack::addRoll(int sides, int mods)
  {
    try
    {
      DiceNode * node = new DiceNode(sides,mods);
      node->setNext(firstNodePtrM);
      firstNodePtrM = node;
      countM++;
    }
    catch(InvalidValueException &e)
    {
      e << called_from("DiceStack::addRoll(int sides, int mods)") << called_from_file(__FILE__);
      throw;
    }



  }

  /// \brief Shows the result of a requested roll.  The default index is 0, or the first roll.
  int DiceStack::showRoll(int index)
  {
    if(index < 0 || index >= size())
      {
        throw OutOfRangeException() << invalid_int_value(index) << invalid_parameter("index") << throwing_function("DiceStack::showRoll(int index)") << throwing_file( __FILE__ ) << min_range(0) << max_range(size()-1);
      }
    if(index == 0){return firstNodePtrM->getResult();}

    DiceNode * currentNode = firstNodePtrM;

    for(int x = 0; x < index; x++)
      {
      currentNode = currentNode->getNext();
      }
    return currentNode->getResult();
  }//end DiceStack::showRoll()


  /// \brief Removes a roll from the list, and returns its value.
  ///
  /// Iterates through the list until it gets to index,
  /// collects the value of index, and then removes it,
  /// and then returns its value.
  int DiceStack::removeRoll(int index)
  {
    if(index < 0 || index >= size())
      {
        throw OutOfRangeException() << invalid_int_value(index) << invalid_parameter("index") << throwing_function("DiceStack::removeRoll(int index)") << throwing_file( __FILE__ ) << min_range(0) << max_range(size()-1);
      }
    int value = 0;
    if(index == 0)  //If index is 0, there is no hunting required.
      {
      DiceNode * oldFirst = firstNodePtrM;       //Step 1: Make a holder for the current first node.
      firstNodePtrM = oldFirst->getNext();       //Step 2: Make the second node the first node.
      value = oldFirst->getResult();             //Step 3: Get the value of the old first node.
      delete oldFirst;                           //Step 4: Delete the old first node.
      countM --;                                 //Step 5: decrement the count.
      return value;                              //Step 6: Return the value.
                                                 //Note: The order of steps 2 and 3 are unimportant,
                                                 //      But everything else should stay in this order.
      }//end if(index == 0)

    DiceNode * previous = firstNodePtrM;         //Step 1:  Create iterators.
    DiceNode * current = previous->getNext();

    for(int count = 1; count < index; count++)   //Step 2:  Find the roll
      {
      previous = current;
      current = current->getNext();
      }

    value = current->getResult();               //Step 3:  Capture the value.

    previous->setNext(current->getNext());        //Step 4:  Cut "current" out of the chain.

    delete current;                             //Step 5:  Delete current.
    countM--;                                   //Step 6:  Decrement the count.
    return value;                               //Step 7:  Return the value.
  }//end DiceStack::removeRoll()

  /// \brief Returns a reference to one of the dice in the list.
  DiceNode & DiceStack::die(int index)
  {
    if(index < 0 || index >= size())
      {
        throw OutOfRangeException() << invalid_int_value(index) << invalid_parameter("index") << throwing_function("DiceStack::die(int index)") << throwing_file( __FILE__ ) << min_range(0) << max_range(size()-1);
      }
    if(index == 0){return *firstNodePtrM;}

    DiceNode * currentNode = firstNodePtrM;

    for(int x = 0; x < index; x++)
      {
      currentNode = currentNode->getNext();
      }
    return *currentNode;
  }//end DiceStack::die()

  /// \brief Returns true if the list is empty.  Otherwise it returns false.
  bool DiceStack::isEmpty(void)
  {
    if(size() == 0){return true;}
    else{return false;}
  }


  /// \brief Returns the value of countM
  int DiceStack::size(void)
  {
    return countM;
  }

  bool DiceStack::empty(void)
  {
  	return (countM <= 0);
  }
}//end namespace lgp



