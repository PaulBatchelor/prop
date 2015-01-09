.PHONY: default all clean install uninstall testing

FLEX_OBJS= prp.yy.o prp.tab.o parser.o 
PS_OBJS= gen_ps.o

OBJS=main.o 

TESTS=testing/test_main testing/test_gen_ps

PRP_OBJS= $(OBJS) $(FLEX_OBJS) $(PS_OBJS)

FLEX_FILES=prp.yy.c prp.yy.h

PRP_LIBS=-lfl -lm

DEBUG_FLAGS=-DDEBUG_BISON=0

default: prp

%.o: %.c %.h
	gcc -c $(DEBUG_FLAGS) $< 

prp.tab.o: prp.tab.c prp.tab.h
	gcc -c $(DEBUG_FLAGS) $< 

testing: $(TESTS)

testing/test_main: testing/test_main.c $(OBJS)
	gcc $<  $(OBJS)  -o $@

testing/test_gen_ps: testing/test_gen_ps.c $(OBJS)
	gcc $<  $(PS_OBJS)  -o $@ $(OBJS) $(PRP_LIBS)

prp.tab.c: prp.y
	bison -p prp -d prp.y 

prp.yy.c: prp.l prp.tab.c 
	flex -P prp -o prp.yy.c --header-file=prp.yy.h prp.l

prp: $(PRP_OBJS) $(FLEX_FILES) 
	gcc $(PRP_OBJS) $(PRP_LIBS)  -o prp 

all: prp

clean: 
	rm -rf $(PRP_OBJS) prp prop.yy.* prop.tab.* $(FLEX_FILES) $(TESTS)

uninstall:
	rm -rf /usr/local/bin/prp

install:
	cp prp /usr/local/bin/
