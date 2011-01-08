/// \file lgp_baseobject.hpp
/// \brief The base object class for the LGP objects
/// \author Kenneth. M. Burling Jr. (a.k.a. Emry)
/// \version lgp-0.03-r1
///
/// copyright: Copyright &copy; 2008, 2009, 2010, 2011 K. M. Burling Jr.<br>
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
///
/// This is the bas object class for LGP Objects.
///
/// File last updated 12:50 UTC on 8 Jan 2011

#ifndef BASEOBJECT_HPP
#define	BASEOBJECT_HPP

/// \brief lgp::BaseObject is the base object class/interface.
///
/// This class will primarily be an interface, so there is not a whole lot
/// that we will put here in the way of variables.  I may change this at some
/// future point of course.
///
/// One of the first things I am adding to it is long int objectID(void);
/// This will return the object ID of the object.  This presents our first
/// assumption about objects.  Every object will have a unique Object ID.
/// For the moment, this is a 
class BaseObject {
public:
    BaseObject();
    BaseObject(const BaseObject& orig);
    virtual ~BaseObject();
    virtual long int objectId(void);
private:

};

#endif	/* BASEOBJECT_HPP */

