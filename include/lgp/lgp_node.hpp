/// \file lgp_node.hpp
/// \brief A templated node for a linked list based stack
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
///  lgp::Stack is a simple linked list stack implementation. lgp::Node is the node
///  for that implementation.
///
///  libgamepieces is a library of tools to help build an RPG that I want to create.
///
/// File last updated 17 Jun 2010 16:23 UCT
#ifndef LGP_NODE_HPP_
#define LGP_NODE_HPP_

#include <cstddef>

namespace lgp {

	 template <class T>
	 class Node
	 {
		  protected:
				T valueM;
				Node<T> * nextM;
		  public:
				Node();
				Node(T value);
				~Node();
				Node<T> * getNext();
				void setNext(Node<T> * next);
				T getValue();
				void setValue(T value);
	 };

	 template <class T>
	 Node<T>::Node()
	 {
		  valueM = NULL;
		  return;
	 }

	 template <class T>
	 Node<T>::Node(T value)
	 {
		  valueM = value;
		  return;
	 }	 

	 template <class T>
	 Node<T>::~Node()
	 {
		  return;
	 }

	 template <class T>
	 Node<T> * Node<T>::getNext()
	 {
		  return nextM;
	 }

	 template <class T>
	 void Node<T>::setNext(Node<T> * next)
	 {
		  nextM = next;
		  return;
	 }

	 template <class T>
	 T Node<T>::getValue()
	 {
		  return valueM;
	 }

	 template <class T>
	 void Node<T>::setValue(T value)
	 {
		  valueM = value;
		  return;
	 }


} //end namespace lgp






#endif //end LGP_NODE_HPP_

