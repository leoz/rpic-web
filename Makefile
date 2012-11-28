###############################################################################
# Makefile for the rpic-web
###############################################################################
CC=gcc
CFLAGS=	-W -Wall -I../mongoose -I../rpic-lib -pthread -g
LIBS=-ldl -L../mongoose -L../rpic-lib -lmongoose -lrpic

SOURCES=rpic-web.c
OBJECTS=$(SOURCES:.cpp=.o)
TARGETS=rpic-web

rpicweb_objects= rpic-web.o

all: $(SOURCES) $(TARGETS)

rpic-web: $(rpicweb_objects)
	$(CC) $(LDFLAGS) $(rpicweb_objects) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ rpic-web


