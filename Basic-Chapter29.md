# Basic C Programming Tutorial

## Chapter 29. Memory Management

    Memory management function defined in <stdlib.h> header file.

#### There are four kind of function in memory management:

* malloc() function:

    "malloc" or "memory allocation" method in C is used to dynamically allocate a single large block of memory with the specified size.

    ### Syntax:

    ptr = (cast-type*) malloc(byte-size);

    _Illustration_

(img src"https://photos.app.goo.gl/RjLSZyY39LqUqNJt9")    

    ## Example Program:

(img src"https://photos.app.goo.gl/r1Choty6YC6FTMuL7")

* calloc() function:

    "calloc" or "contiguous allocation" method in C is used to dynamically allocate the specified number of blocks of memory of the specified type.
    
     It initializes each block with a default value '0'.

     ### Syntax:

     ptr = (cast-type*)calloc(n, element-size);

     _Illustration_

(img src"https://photos.app.goo.gl/dNwkLYqYKFHUAFTA8")

* free() function:

    "free" method in C is used to dynamically de-allocate the memory.

    It helps to reduce wastage of memory by freeing it.

    ### Syntax:

    free(ptr);

    _Illustration_

(img src"https://photos.app.goo.gl/XXHT4BqVgxqxexwg7")

* realloc() function:

    "realloc" or "re-allocation" method in C is used to dynamically change the memory allocation of a previously allocated memory. 

    ### Syntax:

    ptr = realloc(ptr, newSize);

    _Illustration_

(img src"https://photos.app.goo.gl/fQGKyqqiNrfXFHmN9")

    ## Example Program

(img src"https://photos.app.goo.gl/fyxVynf9iNgfCWxE9")