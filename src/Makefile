.PHONY: default all clean

OBJS=main.o prp.yy.o prp_parser.o

FLEX_FILES=prp.yy.c prp.yy.h

PRP_LIBS=-lfl 

default: prp

%.o: %.c %.h
	gcc -c $< 

testing: testing.c $(OBJS)
	gcc $<  $(OBJS) -o $@

prp.yy.c: prp.l
	flex -o prp.yy.c --header-file=prp.yy.h prp.l

prp: $(OBJS) $(FLEX_FILES) 
	gcc $(OBJS) $(PRP_LIBS) -o prp 

all: nrt

clean: 
	rm -rf $(OBJS) testing prp prp.yy.* $(FLEX_FILES)
