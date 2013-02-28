###############################################################################
#  Copyright (C) 2012 - 2013, Leonid Zolotarev
#
#  Licensed under the terms of the BSD license, see file COPYING
#  for details.
#
#  Raspberry Pi Car Controller
#
#  Makefile for the rpic-web
#
###############################################################################

CC=gcc
CFLAGS=	-W -Wall -I../mongoose -I../rpic-lib -pthread -g
LIBS=-ldl -L../mongoose -L../rpic-lib -lmongoose -lrpic

SOURCES=rpic-web.c rpic-sys.c
OBJECTS=$(SOURCES:.cpp=.o)
TARGETS=rpic-web

rpicweb_objects= rpic-web.o rpic-sys.o

all: $(SOURCES) $(TARGETS)

rpic-web: $(rpicweb_objects)
	$(CC) $(LDFLAGS) $(rpicweb_objects) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ rpic-web
	rm -f rpicweb/*~
	rm -f rpicweb/custom/*~
	rm -f rpicweb/rpic/*~
	rm -f rpicweb/video/*~
	rm -f rpicweb/video_off/*~

###############################################################################

