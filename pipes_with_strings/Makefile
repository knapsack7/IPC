CC ?=gcc
JCC ?= javac
FLAGS ?= -Wall -O2
JFLAGS ?= -g -verbose

all: c_app StreamTest

c_app: c_app.c
	$(CC) $(FLAGS) -o c_app c_app.c

StreamTest: StreamTest.java
	$(JCC) $(JFLAGS) StreamTest.java $(LIBS)

    
clean:
	rm -f c_app StreamTest.class
