/// \file test_message.cpp
/// \brief The wchat::Message unit test
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
/// Every project should be well tested, and I hope to make unit tests and the like a part of
/// my day to day practices.  Here I will put together the tests for the wchat project.
///
///
/// File last updated 9 Jun 2011 09:49 UCT


#define BOOST_TEST_MODULE MessageTest

#include <boost/test/included/unit_test.hpp> 

#include <lgp/message.hpp>
#include <boost/lexical_cast.hpp>

BOOST_AUTO_TEST_CASE(message_test)
{
	using boost::lexical_cast;
	
	lgp::Message testMessage;
	BOOST_CHECK(testMessage.get_type() == lgp::NULLMESSAGE);	                  //Testing default constructor.
	
	testMessage.set_type(lgp::MSG);                                             //Make the message type a message.
	BOOST_CHECK(testMessage.get_type() == lgp::MSG);                            //Ensure that the assignment worked propperly.
	
	testMessage.set_sender_type(lgp::USER);                                     //Set the sender type
	BOOST_CHECK(testMessage.get_sender_type() == lgp::USER);                     //Ensure that the assignment worked propperly.
	
	testMessage.set_sender("Bob");                                                 //Set the sender
	BOOST_CHECK(testMessage.get_sender() == "Bob");                               //Ensure that the value was set propperly.
	
	testMessage.set_target_type(lgp::CHANNEL);                                  //Set the target type
	BOOST_CHECK(testMessage.get_target_type() == lgp::CHANNEL);                  //Ensure that the value was set propperly
	
	testMessage.set_target("GLOBAL");                                             //Set the target name
	BOOST_CHECK(testMessage.get_target() == "GLOBAL");                            //Ensure that it was set propperly.
	
	std::string payload = "This is not very usefull.";                            //Assign a payload to the Message
	testMessage.set_payload(payload);                  
	BOOST_CHECK(testMessage.get_payload() == payload);                            //Test that the payload was set propperly.
	
	lgp::Message newTestMessage(lgp::MSG, lgp::USER, "Joe", lgp::USER,    //Testing the alternate constructor. 
		                            "Bob", "This is a test message!!");
	
	BOOST_CHECK(newTestMessage.get_type() == lgp::MSG);                         //Test that all assertions are correct..
	BOOST_CHECK(newTestMessage.get_sender_type() == lgp::USER);
	BOOST_CHECK(newTestMessage.get_sender() == "Joe");
	BOOST_CHECK(newTestMessage.get_target_type() == lgp::USER);
	BOOST_CHECK(newTestMessage.get_target() == "Bob");
	BOOST_CHECK(newTestMessage.get_payload() == "This is a test message!!");
	
	std::stringstream tempMessage("");                                            //Manually pack a test message.
	tempMessage << lexical_cast<std::string>(lgp::MSG) << "\t"
	            << lexical_cast<std::string>(lgp::USER) << "\t"
	            << "Samuel" << "\t"
	            << lexical_cast<std::string>(lgp::CHANNEL) << "\t"
	            << "LOCAL" << "\t"
	            << "This is just a local message.";
	            
	testMessage.unpack_message(tempMessage.str());                                //Unpack the message.
	BOOST_CHECK(testMessage.pack_message() == tempMessage.str());                 //Verify that messages are packing and unpacking properly.
	
	
	
	
	
	/// MESSAGE_TYPE SENDER_TYPE SENDER TARGET_TYPE TARGET PAYLOAD
	
	
	
	
}//end BOOST_AUTO_TEST_CASE(message_test)

