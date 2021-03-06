CC=gcc
CFLAGS=-Wall -g -std=c99 -D_GNU_SOURCE -lgc

all: test_vm

compiler.o: compiler.c object.h prims.h type.h utilities.h
	$(CC) $(CFLAGS) -c $< -o $@

macros.o: macros.c object.h prims.h type.h utilities.h
	$(CC) $(CFLAGS) -c $< -o $@

object.o: object.c object.h type.h
	$(CC) $(CFLAGS) -c $< -o $@

prims.o: prims.c object.h type.h utilities.h
	$(CC) $(CFLAGS) -c $< -o $@

utilities.o: utilities.c object.h type.h
	$(CC) $(CFLAGS) -c $< -o $@

vm.o: vm.c object.h type.h prims.h utilities.h
	$(CC) $(CFLAGS) -c $< -o $@

# Test Drivers
compiler_test.o: compiler_test.c macros.h object.h type.h prims.h compiler.h
	$(CC) $(CFLAGS) -c $< -o $@

repl_test.o: repl_test.c compiler.h macros.h object.h prims.h vm.h
	$(CC) $(CFLAGS) -c $< -o $@

vm_test.o: vm_test.c compiler.h macros.h object.h prims.h type.h vm.h
	$(CC) $(CFLAGS) -c $< -o $@

# Test Executable
test_compiler: compiler_test.o compiler.o macros.o object.o prims.o utilities.o vm.o
	if [ ! -d bin ]; then mkdir bin; fi
	cp init.scm bin/
	$(CC) $^ -o bin/$@ $(CFLAGS)

test_repl: repl_test.o compiler.o macros.o object.o prims.o utilities.o vm.c
	if [ ! -d bin ]; then mkdir bin; fi
	cp init.scm bin/
	$(CC) $^ -o bin/$@ $(CFLAGS)

test_vm: vm_test.o compiler.o macros.o object.o prims.o utilities.o vm.o
	if [ ! -d bin ]; then mkdir bin; fi
	cp init.scm bin/
	$(CC) $^ -o bin/$@ $(CFLAGS)

.PHONY: clean dir

clean:
	rm -f *.o