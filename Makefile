#   File:       Makefile
#   Author:     Kenneth M. Burling Jr. (a.k.a. Emry)
#   Brief:      Early makefile for the libgamepieces project.
#   Version:    Alpha-0.001
#
#   Copyright:  copyright (C) 2009, 2010, 2011, Kenneth M. Burling Jr.  All rights Reserved.
#               You may use this file as you see fit under the terms of the
#               BSD License.  If you wish to use it under other licensing terms
#               please contact me at burlingk@gmail.com.  See legal.txt for more details.
#
#
#   File last updated 00:30 UTC on 2 Jan 2011

#
#   The compiler of choice for this project is primarily the GNU
#   C++ compiler, but it should compile on other compilers as well.
#   (This has not been tested yet).
#



# On some non-standard systems you may need to specify the location
# of the boost library.
#BOOST = -I/path/to/boost

BOOST = $(empty)
INCLUDES = -I./include ${BOOST}
LIBS     = -L./lib

VERSION = lgp-0.03-r1

#The switch to use for debugging information.
DEBUG = -ggdb

#
# The following variables point to the programs used to compile
# the project.  The defaults listed here are the most common
# defaults on a Linux system.  You may need to change these if you
# are on a windows box, or on a Linux/Unix system that uses a
# different compiler package.  If you are crosscompiling for
# another platform, then you may need to change these as well.
# 
CC  = gcc
CPP = g++
AR  = ar


# $(LGPMODULES) is the list of pieces for the LGP library.


LGPMODULES = dicebag \
             dicenode \
             dicestack \
             random \
             message \
             object

LGPOBJECTS := $(addsuffix .o,$(LGPMODULES))

TESTS = test_message

all: lib/libgamepieces.a tests

#
# This rule will be the one to compile the modules with
# source files located in src/lgp
$(LGPOBJECTS): %.o: src/lgp/%.cpp include/lgp/%.hpp include/lgp/objectdata.hpp
	$(CPP) -c $(INCLUDES) -o $@ $<

tests: bin/test/test_message

bin/test/test_message: src/test/test_message.cpp lib/libgamepieces.a
	$(CPP) $(INCLUDES) $(LIBS) -o bin/test/test_message src/test/test_message.cpp -lgamepieces 


#
# libgamepieces.a
#
lib/libgamepieces.a: $(LGPOBJECTS)
	$(AR) rcs lib/libgamepieces.a $(LGPOBJECTS)

bin/game: lib/libgamepieces.a src/game/main.cpp
	$(CPP) $(INCLUDES) $(LIBS) $(DEBUG) src/game/main.cpp -lgamepieces -o bin/game

game: bin/game

# General Maintenance Rules.

clean:
	rm -rf lib/libgamepieces.a
	rm -rf $(LGPOBJECTS)
	rm -rf bin/test/test_message
	rm -rf /bin/game
	

docs:
	doxygen

docclean:
	rm -rf doc/html

rebuild: clean all

#
# homeinstall is a target to install/update a copy of the lib in a personal lib directory.
# It attempts to install the lib at $HOME/lib/libgamepieces.a
#
# If there is no $HOME/lib directory, then it should create one.
#
homeinstall: lib/libgamepieces.a
	mkdir -p $(HOME)/lib
	cp -v lib/libgamepieces.a $(HOME)/lib/libgamepieces.a
	mkdir -p $(HOME)/include/lgp
	cp -v include/lgp/*.hpp $(HOME)/include/lgp/                                                                    

#####
# distclean is to be run before making commits, pushes, or creating a tarball.
#####

distclean:  docclean clean



