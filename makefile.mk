all: twofile.exe

twofile.exe: twofile1.o twofile2.o
	gcc -o twofile.exe twofile1.o

twofile1.o: twofile1.c
	gcc -o twofile1.c

twofile2.o: twofile2.c
	gcc -o twofile2.c

clean:
	rm -f *o twofile.exe