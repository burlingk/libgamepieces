/// \file lgp_message.cpp
/// \brief Description of the lgp::message class
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

#include <lgp/lgp_message.hpp>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <vector>


namespace lgp {
  ///\brief The default constructor that does crap.
  Message::Message() : type_m(lgp::NULLMESSAGE), senderType_m(lgp::NULLMESSAGE), sender_m(""), targetType_m(lgp::NULLMESSAGE), target_m(""), payload_m("")
  {
  }
  
  ///\brief a more useful constructor
  ///
  /// This version of the constructor initializes all the values to something useful.
  Message::Message(MessageType type, MessageType senderType, std::string sender, MessageType targetType, std::string target, std::string payload) :
  type_m(type), senderType_m(senderType), sender_m(sender), targetType_m(targetType), target_m(target), payload_m(payload)
  {
  }
  
  
  //\brief Not much to do in the destructor.
  Message::~Message(){}
  
  //Message Classification.
  //These are used to set the attributes that deside what kind of message
  //you are dealing with.
  
  /// \brief Returns the Type of the Message you are dealing with.
  ///
  /// This is the attribute that tells the recipient if the message
  /// is for communications, or a command, or a request for information.
  MessageType Message::get_type(void)
  {
    return type_m;
  }
  
  /// \brief Set the Type of Message you are dealing with.
  void Message::set_type(MessageType type)
  {
    type_m = type;
    return;
  }
  
  
  /// \brief Returns the type of target the message is for.
  /// 
  /// This is the attribute that tells the system what kind of target
  /// the message is intended for.  This will be used in determining
  /// who the recipient of the message is.
  MessageType Message::get_target_type(void)
  {
    return targetType_m;
  }
  
  /// \brief Sets the value of the target Type
  void Message::set_target_type(MessageType targetType)
  {
    targetType_m = targetType;
    return;
  }
  
  
  //Target
  /// \brief get a string representation of the target's identifier.
  ///
  /// This will return the identifier for the target.  For some targets
  /// this may be a unique name, and for others, it may be a number.
  std::string Message::get_target(void)
  {
    return target_m;
  }
  
  /// \brief This lets you manually name your target.
  void Message::set_target(std::string target)
  {
    target_m = target;
  }
  
  
  //payload
  /// \brief Returns the contents of the message payload.
  ///
  /// The payload is the string that represents the "body" of
  /// the message.  Just what this information represents will
  /// vary from one message type to another.
  std::string Message::get_payload(void)
  {
  	return payload_m;
  }
  
  /// \brief Set the value of the payload string.
  void Message::set_payload(std::string payload)
  {
  	payload_m = payload;
  	return;
  }
  
  //Message Handling related functions.
  
  /// \brief This lets you set the values of every part of the message in one line.
  ///
  /// The arguments passed to this method are directly related to member variables
  /// in the Message class.
  void Message::set_message(MessageType type, MessageType senderType, std::string sender, MessageType targetType, std::string target, std::string payload)
  {
  	type_m       = type;
  	senderType_m = senderType;
  	sender_m     = sender;
  	targetType_m = targetType;
  	target_m     = target;
  	payload_m    = payload;
  	return;
  }
  
  /// \brief Prepares a message for transmission over the line.
  ///  
  /// This method packages the message.  It returns a string value that
  /// represents the form of the message as it should be transmitted over the
  /// line between the client and the server, or between servers.
  ///  
  /// The format of the packed message is currently as follows: <br />
  /// MESSAGE_TYPE SENDER_TYPE SENDER TARGET_TYPE TARGET PAYLOAD
  /// 
  /// What the payload consists of is entirely up to the object that
  /// creates the message.  That is why the first information provided is
  /// the Message Type.
  std::string Message::pack_message(void)
  {
  	using boost::lexical_cast;
  	std::stringstream message("");
  	
  	message << lexical_cast<std::string>(type_m) << "\t";
  	
  	message << lexical_cast<std::string>(senderType_m) << "\t";
  	message << sender_m << "\t";
  	
  	message << lexical_cast<std::string>(targetType_m) << "\t";
  	message << target_m << "\t";
  	  	
  	message << payload_m;
  	
  	return message.str();
  }
  
  
  /// \brief Use an incoming message to fill in the Message object.
  ///
  /// This function will use boost::tokenizer to convert the incoming
  /// message into a message object.
  ///
  /// We start by converting the first three elements of the string into
  /// their representative data values, and then we iterate through the rest
  /// of the list to recreate the string that represents the payload.
  ///
  /// The original version of this code used boost::tokenizer to split the
  /// message into pieces, but that was clobbering the non-whitespace punctuation
  /// in the payload, so I switched to a std::vector<> and used boost::split instead.
  /// 
  /// I have conciously chosen to coment out the errant code instead of deleting it
  /// to serve as a warning to those who may wish to try similar tasks.
  /// 
  /// MESSAGE_TYPE SENDER_TYPE SENDER TARGET_TYPE TARGET PAYLOAD
  void Message::unpack_message(std::string message)
  {
  	//using boost::tokenizer;
  	using boost::lexical_cast;
  	
  	typedef std::vector< std::string > split_vector_type;
  	split_vector_type packedMessage;
  	boost::split(packedMessage, message, boost::is_any_of("\t\n "), boost::token_compress_on);
  	
  	 	
  	//tokenizer<> packedMessage(message);
  	//tokenizer<>::iterator iterator;
  	
  	std::vector<std::string>::iterator iterator;
  	
  	iterator = packedMessage.begin();
  	int type = lexical_cast<int>(*iterator);
  	type_m = static_cast<MessageType>(type);
  	
  	iterator++;
  	int senderType = lexical_cast<int>(*iterator);
  	senderType_m = static_cast<MessageType>(senderType);
  	
  	iterator++;
  	sender_m = *iterator;
  	
  	iterator++;
  	int targetType = lexical_cast<int>(*iterator);
  	targetType_m = static_cast<MessageType>(targetType);
  	
  	iterator++;
  	target_m = *iterator;
  	
  	std::string payload("");
  	std::stringstream payload_temp;
  	
  	iterator++;
  	for(iterator; iterator!=packedMessage.end(); ++iterator)
  	{
  		payload_temp << *iterator << " ";
  	}
  	
  	payload = payload_temp.str();
  	boost::trim_right(payload);
  	
  	payload_m = payload;
  	
  	return;
  	
  }//end Message::unpack_message(std::string message)
  
  
  /// \brief Return the type of sender.
  MessageType Message::get_sender_type(void)
  {
  	return senderType_m;
  }
  
  /// \brief Set the type of sender.
  void Message::set_sender_type(MessageType senderType)
  {
  	senderType_m = senderType;
  }
  
  /// \brief Return the ID of the sender.
  std::string Message::get_sender(void)
  {
  	return sender_m;
  }
  
  /// \brief Set the ID of the sender.
  void Message::set_sender(std::string sender)
  {
  	sender_m = sender;
  }
  
} //end namespace lgp




