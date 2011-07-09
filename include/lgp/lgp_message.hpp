/// \file lgp_message.hpp
/// \brief Description of the wchat::message class
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
///  lgp::Message is the class that will be used to create and manipulate messages.
///  These messages will be passed back and forth between various objects within the system.
///
///
/// File last updated 9 Jul 2011 09:35 UCT

#ifndef _LGP_MESSAGE_HPP_
#define _LGP_MESSAGE_HPP_

#include <lgp/lgp_objectdata.hpp>
#include <iostream>


namespace lgp {
  
	typedef ObjectData MessageType;
	
  /// \brief The message wrapper class.
  ///
  /// class lgp::Message is intended to hold data pertaining to messages that
  /// are being sent back and forth between objects.
  class Message
  {
  public:
    //Constructors and Destructor
    Message();
    Message(MessageType type, MessageType senderType, std::string sender, MessageType targetType, std::string target, std::string payload); 
    virtual ~Message();
    
    //Send and Recieve    
    virtual std::string pack_message(void);
    virtual void unpack_message(std::string message);
    
    virtual void set_message(MessageType type, MessageType senderType, std::string sender, MessageType targetType, std::string target, std::string payload);
    
    //Message Classification
    MessageType get_type(void);
    void        set_type(MessageType type);
    MessageType get_target_type(void);
    void        set_target_type(MessageType targetType);
    
    MessageType get_sender_type(void);
    void        set_sender_type(MessageType senderType);
    std::string get_sender(void);
    void        set_sender(std::string sender);
    
    
    
    
    //Target
    std::string get_target(void);
    void set_target(std::string target);
    
    //payload
    virtual std::string get_payload(void);
    virtual void set_payload(std::string payload);
  private:
    MessageType type_m;         // The Message Type
    MessageType targetType_m;   // The Target Type
    MessageType senderType_m;
    std::string sender_m;
    std::string target_m;       // A String representation of The Target
    std::string payload_m;      // Message Payload.
  }; //end class Message
  
  
} //end namespace lgp



#endif  //end #ifndef _LGP_MESSAGE_HPP_



