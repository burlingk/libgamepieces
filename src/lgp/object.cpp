/// \file lgp_object.cpp
/// \brief The Base Class for Objects that represent real things in the world
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
///  lgp::Object is the base for the various objects that represent real things within the game world.
///  
/// File last updated 07:13 UCT on 1 April 2011
///


#include <lgp/object.hpp>

namespace lgp {
  
	Object::Object() : id_m(0), type_m(NULLOBJECT), access_m(PRIVATE), voice_m(PRIVATE)
	{
		return;
	}

	Object::Object(ObjectID id, ObjectData type, ObjectData access, ObjectData voice) 
                : id_m(id), type_m(type), access_m(access), voice_m(voice)
	{
		return;
	}

	
	Object::~Object()
	{
		return;
	}
	
	ObjectID Object::get_id(void)
	{
		return id_m;
	}
	
	ObjectData Object::get_type(void)
	{
		return type_m;
	}
	
	
	void Object::accept_message(std::string message)
	{
		Message newMessage;
		newMessage.unpack_message(message);
		messageQueue_m.push(newMessage);
	}
	
	// Example of a cycle function that doesn't really do anyting.
	//
	// void Object::cycle(void)
	// {
	//   if(messageQueue_m.empty()){return;}
	//   
	//   messageQueue_m.pop();
	//   return;
	// }
  //
  // In this example, the cycle just processes the Queue by
  // removing the message at the top of the queue (if there is one).
  //
  // For a "real" object, this is where you would process the Message
  // Queue in some meaningful way.  It is also where you will have the
  // Object do whatever it would do in a given cycle.  This may include
  // checking a timer to see if it needs to do something time based, or
  // checking something in the "environment" around it to see if it needs
  // to perform some given task.
  //
  // For example, an Object representing a network connection might check
  // to see how long it has been since the connection was active, in case
  // it needs to time out, or send a request to see if the connection is
  // still alive.
  //
  // For the purpose of class lgp::Object, this function is null.  This is
  // because lgp::Object is intended as a purely(well, mostly) virtual 
  // interface class. The reason that there is no default implementation
  // for Object::cycle() is because there really is no default behavior
  // that can be said to be valid for all objects in a system.  It is
  // important that the developer implements the functionality for the
  // Objects in his/her system.
  
} //end namespace lgp



