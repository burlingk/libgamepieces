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
CXX = g++
AR  = ar


# $(LGPMODULES) is the list of pieces for the LGP library.


LGPMODULES = lgp_dicebag \
             lgp_dicenode \
             lgp_dicestack \
             lgp_random

LGPOBJECTS := $(addsuffix .o,$(LGPMODULES))


all: lib/libgamepieces.a

#
# This rule will be the one to compile the modules with
# source files located in src/lgp
$(LGPOBJECTS): %.o: src/lgp/%.cpp
	$(CXX) -c $(INCLUDES) -o $@ $<



#
# libgamepieces.a
#
lib/libgamepieces.a: $(LGPOBJECTS)
	$(AR) rcs lib/libgamepieces.a $(LGPOBJECTS)


#lib/libgamepieces.a: obj/lgp_dicebag.o obj/lgp_random.o obj/lgp_dicenode.o obj/lgp_object.o \
#	obj/lgp_thing.o obj/lgp_creature.o obj/lgp_world.o include/lgp_array.hpp include/lgp.hpp \
#	obj/lgp_generator.o obj/lgp_message.o obj/lgp_gencreature.o
#	${AR} rcs lib/libgamepieces.a obj/lgp_dicebag.o obj/lgp_random.o obj/lgp_dicenode.o obj/lgp_object.o \
#	obj/lgp_thing.o obj/lgp_creature.o obj/lgp_world.o obj/lgp_generator.o obj/lgp_message.o obj/lgp_gencreature.o
	

# General Maintenance Rules.

clean:
	rm -rf lib/libgamepieces.a
	rm -rf $(LGPOBJECTS)

docs:
	doxygen

docclean:
	rm -rf doc/html

rebuild: clean all

#####
# distclean is to be run before making commits, pushes, or creating a tarball.
#####
distclean:  docclean clean
