# The main Makefile is in the src directory

all:	
	echo "Building in src directory, product will go to bin directory"
	(cd src; make ../bin/parser;)

# Docker image.  Do this on your workstation platform (laptop, etc),
# not from within docker.

clean:
	rm -f a.out
	rm  -f codegen/code.c
	(cd src; make clean)
	

image:
	(cd src; make clean;)
	docker build --tag=proj2 .
