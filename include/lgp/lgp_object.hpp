/// \file lgp_object.hpp
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
///  lgp::Object is the base interface class for various objects within the system
///  
/// File last updated 01:00 UCT on 3 April 2011
///



#ifndef _LGP_OBJECT_HPP_
#define _LGP_OBJECT_HPP_

#include <iostream>

#include <lgp/ObjectData.hpp>
#include <lgp/lgp_message.hpp>

namespace lgp {
  
	/// \brief A type identifying an Object ID.
	///
	/// At the moment, ObjectID is a long int.  this may change at
	/// some future date.  I am also considdering a basic string type
	/// as object ID's
	typedef long int ObjectID;
	
  class Object 
  {
  public:
  	Object();
  	virtual ~Object();
  	
  	virtual ObjectID get_id(void);
  	virtual ObjectData type(void);
  	
  	virtual void accept_message(std::string message);
  	virtual void cycle(void);
  	
  private:
  	ObjectData type_m;
  	ObjectData access_m;
  	ObjectData voice_m;
  	
  	//MessageQueue messageQueue_m;
  	
  };
  
} //end namespace lgp


#endif //end ifndef _LGP_OBJECT_HPP_

