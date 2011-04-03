/// \file lgp_gamesystem.hpp
/// \brief The base class to represent a game system.
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
///  lgp::GameSystem is the class that game systems will derive from.  It is the core of the plugale game system
///  interface for the libgamepieces library.  The game system is an important aspect of any game, especially RPG's
///  where the player will be expected to have more insite into the system than in most games.
///  
///  The game system plays a strong roll in determining how different aspects of the game world will be modeled and
///  how they will be presented to the player.  It has a big impact on how the characters interact with their world.
///  
/// File last updated 01:00 UCT on 3 April 2011
///


#ifndef _LGP_GAMESYSTEM_HPP_
#define _LGP_GAMESYSTEM_HPP_


#include <iostream>


namespace lgp {
  class GameSystem
  {
  public:
    
  private:
    std::string gameSystemNameM;
    std::string gameSystemVersionM;
    
    
  };//end class lgp::GameSystem
  
  
  
  
  
} //end namespace lgp






#endif //end ifndef _LGP_GAMESYSTEM_HPP_
