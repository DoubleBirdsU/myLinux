#
# makefile
#
# Created on: 2017-05-20 19:19:23
#     Author: 
#

SFMT=.c

OBMT=.o

CC=gcc

SRCS=$(wildcard *$(SFMT))

EXEC=myke

.SUFFIXES:$(SFMT) $(OBMT)

OBJS=$(SRCS:$(SFMT)=$(OBMT))

OBJSWP=$(SRCS:$(SFMT)=$(OBMT).swp)

start: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '------OK------'

$(SFMT)$(OBMT):
	$(CC) -Wall -g -o $@ -c $<

.PHONY:clean

clean:
	rm -f $(OBJS)
	rm -f core*

cleswp:
	rm -f $(OBJSWP)

