/// \file lgp_objectbase.hpp
/// \brief The Object Interface Class
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
///  lgp::ObjectBase is the interface class for the lgp::Object serries of classes.
///  
/// File last updated 01:00 UCT on 3 April 2011
///


#ifndef _LGP_OBJECTBASE_HPP_
#define _LGP_OBJECTBASE_HPP_



namespace lgp {
  
  typedef long int ObjectID;
  
  
  
  ///\brief lgp::ObjectBase will be the interface class for the Object classes.
  class ObjectBase
  {
  public:
    //Constructor and Destructor
    ObjectBase(){return;};   
    virtual ~ObjectBase(){return;};
    
    //interface functions
    
    //Identification
    virtual ObjectID getId(void)=0;           ///< Return an Object's Object ID
    virtual void setId(ObjectID newId);       ///< Set an Object's Object ID

    //Location
    virtual long int locX(void);              ///< X Coordinate
    virtual long int locY(void);              ///<Y Coordinate
    virtual long int locZ(void);              ///<Z Coordinate
    virtual void setLocX(long int x);
    virtual void setLocY(long int y);
    virtual void setLocZ(long int z);
    virtual void setLoc(long int x, long int y, long int z);
   
   
   
  };
  
  
  
} //end namespace lgp


#endif //end ifndef _LGP_OBJECTBASE_HPP_

