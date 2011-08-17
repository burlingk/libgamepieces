
/// \file lgp_objectdata.hpp
/// \brief enum ObjectData will declare various enumerated constants for object related information.
/// \author Kenneth. M. Burling Jr. (a.k.a Emry)
/// \version Alpha-0.001
///
/// copyright: Copyright &copy; 2011 K. M. Burling Jr.<br>
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
/// lgp::ObjectData will define enums representing the various types and
/// functions or objects.  As I am structuring everything to either be an
/// object or be held by an objection, some of the values may be specific to
/// certain kinds of objects.  This list will grow with time as the project
/// as a whole grows.
///
///
/// File last updated 4 Jun 2011 20:00 UCT

#ifndef _LGP_OBJECTDATA_HPP_
#define _LGP_OBJECTDATA_HPP_


namespace lgp {
  
  ///
  enum ObjectData {
  	NULLOBJECT=0,
  	NULLMESSAGE=0,   //The Null Message.  Every system needs one.
  	
  	//Message Types
    MSG,                  //A message that is intended to be sent to a target
    COMMAND,              //A Command that should be processed by the target
    INFOREQUEST,          //A request for information
    INFORESPONSE,         //A response to a request for information
    
    //Object Scope
    GLOBAL,
    LOCAL,
    PRIVATE,
    
    //Target and Sender types
    USER,                 //The message targets a user
    SERVER,               //The message targets a server
    CHANNEL,              //The message targets a channel
    
    ALLUSERS=9999         //A Global Message (targets all users)
  }; //end enum ObjectData
  
  
  
  
} //end namespace lgp




#endif //end #ifndef _LGP_OBJECTDATA_HPP_



