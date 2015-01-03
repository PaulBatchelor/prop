.PHONY: default all clean install uninstall

FLEX_OBJS= prp.yy.o prp.tab.o parser.o 
PS_OBJS= gen_ps.o

OBJS=main.o 


PRP_OBJS= $(OBJS) $(FLEX_OBJS) $(PS_OBJS)

FLEX_FILES=prp.yy.c prp.yy.h

PRP_LIBS=-lfl 

DEBUG_FLAGS=-DDEBUG_BISON=0

default: prp

%.o: %.c %.h
	gcc -c $(DEBUG_FLAGS) $< 

testing: testing.c $(OBJS)
	gcc $<  $(OBJS)  -o $@

prp.tab.c: prp.y
	bison -d  prp.y 

prp.yy.c: prp.l prp.tab.c 
	flex -o prp.yy.c --header-file=prp.yy.h prp.l

prp: $(PRP_OBJS) $(FLEX_FILES) 
	gcc $(PRP_OBJS) $(PRP_LIBS)  -o prp 

all: prp

clean: 
	rm -rf $(PRP_OBJS) testing prp prp.yy.* $(FLEX_FILES)

uninstall:
	rm -rf /usr/local/bin/prp

install:
	cp prp /usr/local/bin/
