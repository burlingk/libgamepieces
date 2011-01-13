/// \file lgp_queue.hpp
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
///  lgp::Queue is a simple linked list queue implementation.
///
///  libgamepieces is a library of tools to help build an RPG that I want to create.
///
/// File last updated 17 Jun 2010 16:23 UCT

#ifndef LGP_QUEUE_HPP_
#define LGP_QUEUE_HPP_

#include "lgp_node.hpp"

namespace lgp {



	 template <class T>
	 class Queue
	 {
		  protected:
				Node<T> * frontM; //The front of the Queue
				Node<T> * backM;  //The Back of the Queue
				int sizeM;        //The size of the Queue

		  public:
				Queue();            //Initialize an empty queue
				Queue(T value);     //Initialize the queue with a starting value
				~Queue();
				T front();            //Take a peak at the top of the stack
				T pop();            //Remove the top value from the stack, returning its value
				void push(T value); //Add a value to the stack.
				int size();         //return the size of the stack (as stored in sizeM)
	 };


	 
	 template <class T>
	 Queue<T>::Queue()
	 {
		  frontM = NULL;
		  backM  = NULL;
		  sizeM  = 0;
	 }

	 template <class T>
	 Queue<T>::Queue(T value)
	 {
		  Node<T> * newNode = new Node<T>(value);
		  frontM = newNode;
		  backM  = newNode;
		  sizeM  = 1;		  
	 }

	 template <class T>
	 Queue<T>::~Queue()
	 {
		  while(size() > 0){pop();}
	 }

	 template <class T>
	 T Queue<T>::front()
	 {
		  return frontM->getValue();
	 }

	 template <class T>
	 T Queue<T>::pop()
	 {
		  T value = front();              //Get the value of the first node.
		  Node<T> * deadNode = frontM;    //Put the first node in a holding variable.
		  frontM = deadNode->getNext();   //Change the front value to the next in line.
		  delete deadNode;                //Get rid of the unneeded node.
		  sizeM--;                        //Reduce the size by 1.
		  return value;                   //Return the value collected in step 1.
		  			//Eventually I will set this up to throw an exception
		         //if the list is empty.  It will probably do so already,
		         //but I want it to say something usefull.		  
	 }

	 template <class T>
	 void Queue<T>::push(T value)
	 {
		  Node<T> * newNode = new Node<T>(value);    //Initialize the new node with the given value.
		  if(size() <= 0)
		  {
				frontM = newNode;
				backM = newNode;
		  }
		  else
		  {
				backM->setNext(newNode);                   //Link the new node in after the last node.
				backM = newNode;                           //Make the new node the new back.
		  }
		  sizeM++;                                      //Increment the size by 1
		  return;
	 }

	 template <class T>
	 int Queue<T>::size()
	 {
		  return sizeM;
	 }	 


	 



} //end namespace lgp






#endif //end LGP_QUEUE_HPP_



