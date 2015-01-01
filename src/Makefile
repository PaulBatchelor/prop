.PHONY: default all clean

FLEX_OBJS= prp.yy.o prp.tab.o prp_parser.o 
OBJS=main.o 
FLEX_FILES=prp.yy.c prp.yy.h

PRP_LIBS=-lfl 

default: prp

%.o: %.c %.h
	gcc -c $< 

testing: testing.c $(OBJS)
	gcc $<  $(OBJS) -o $@

prp.tab.c: prp.y
	bison -d prp.y 

prp.yy.c: prp.l prp.tab.c 
	flex -o prp.yy.c --header-file=prp.yy.h prp.l

prp: $(OBJS) $(FLEX_FILES) $(FLEX_OBJS)
	gcc $(OBJS) $(FLEX_OBJS) $(PRP_LIBS) -o prp 

all: nrt

clean: 
	rm -rf $(OBJS) testing prp prp.yy.* $(FLEX_FILES)
