/// \file lgp_queu.hpp
/// \brief A templated linked list based stack
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
///  lgp::Stack is a simple linked list stack implementation.
///
///  libgamepieces is a library of tools to help build an RPG that I want to create.
///
/// File last updated 17 Jun 2010 16:23 UCT

#ifndef LGP_STACK_HPP_
#define LGP_STACK_HPP_

#include "lgp_node.hpp"

namespace lgp {



	 template <class T>
	 class Stack
	 {
		  protected:
				Node<T> * topM; //The top of the stack
				int sizeM;      //The size of the stack

		  public:
				Stack();            //Initialize an empty stack
				Stack(T value);     //Initialize the stack with a starting value
				~Stack();
				T top();            //Take a peak at the top of the stack
				T pop();            //Remove the top value from the stack, returning its value
				void push(T value); //Add a value to the stack.
				int size();         //return the size of the stack (as stored in sizeM)
	 };


	 
	 template <class T>
	 Stack<T>::Stack()
	 {
		  topM = NULL;
		  sizeM = 0;
	 }

	 template <class T>
	 Stack<T>::Stack(T value)
	 {
		  Node<T> * newNode = new Node<T>(value);
		  topM = newNode;
		  sizeM=1;		  
	 }

	 template <class T>
	 Stack<T>::~Stack()
	 {
		  while(size() > 0){pop();}
	 }

	 template <class T>
	 T Stack<T>::top()
	 {
		  return topM->getValue();
	 }

	 template <class T>
	 T Stack<T>::pop()
	 {
		  T value = top();              //Get the value of the first node.
		  Node<T> * deadNode = topM;    //Put the first node in a holding variable.
		  topM = deadNode->getNext();   //Change the top value to the next in line.
		  delete deadNode;              //Get rid of the unneeded node.
		  sizeM--;                      //Reduce the size by 1.
		  return value;                 //Return the value collected in step 1.
		  			//Eventually I will set this up to throw an exception
		         //if the list is empty.  It will probably do so already,
		         //but I want it to say something usefull.		  
	 }

	 template <class T>
	 void Stack<T>::push(T value)
	 {
		  Node<T> * newNode = new Node<T>(value);    //Initialize the new node with the given value.
		  newNode->setNext(topM);                    //Set the current top as the new nodes next.
		  topM = newNode;                            //Make the new node the new top.
		  sizeM++;                                   //Increment the size by 1
		  return;
	 }

	 template <class T>
	 int Stack<T>::size()
	 {
		  return sizeM;
	 }

		 


		  



} //end namespace lgp






#endif //end LGP_STACK_HPP_


