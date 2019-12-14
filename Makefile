world: new
new: twofile.o teofile2.o
    gcc -c twofile1.o
twofile1.o: twofile1.c
    gcc -c twofile1.c
twofile2.o: twofile2.c 
    gcc -c twofile2.c
clean:
    rm -rf *o hello