CC = g++
CFLAGS = -g -Wall

bitwise: main.o student.o
		$(CC) main.o student.o -o bitwise

copy: main-copy.o student-copy.o
		$(CC)  main-copy.o student-copy.o -o copy

assign: main-ass.o student-ass.o
		$(CC) -DASSIGN main-ass.o student-ass.o -o assign


student-copy.o:	student.cc
		$(CC) $(CFLAGS) -DCOPY -c student.cc -o student-copy.o

main-copy.o:	main.cc
		$(CC) $(CFLAGS) -DCOPY -c main.cc -o main-copy.o


student-ass.o:	student.cc
		$(CC) $(CFLAGS) -DASSIGN -c student.cc  -o student-ass.o

main-ass.o:	main.cc
		$(CC) $(CFLAGS) -DASSIGN -c main.cc -o main-ass.o


main.o: main.cc
		$(CC) $(CFLAGS) -c main.cc

student.o: student.cc
		$(CC) $(CFLAGS) -c student.cc

.PHONY: clean

clean:
	rm -f *.o bitwise assign copy