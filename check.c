####This target will compile
        hello : world
                    world : twofile1.o twofile2.o
                                gcc twofile1.o
                                    twofile1.o : twofile1.c
                                                     gcc -
    c twofile.c
        twofile2.o : twofile2.c
                         gcc -
    c twofile2.c
        clean : rm -
    rf *o hello