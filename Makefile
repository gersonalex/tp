SUBDIRS= $(shell ls -d src/*/)
BUILD= $(shell ls -d build/*/)

K=gcc
L=-c

.PHONY: all clean $(SUBDIRS)

all:	$(SUBDIRS)

$(SUBDIRS):
	for dir in $(SUBDIRS); do\
		cd $@; $(K) $(L) main.c ;\
		$(K) main.o -o main;\
	done

clean:
	for subdir in $(SUBDIRS); do\
		(cd $${subdir}; $(MAKE) $@);\
	done