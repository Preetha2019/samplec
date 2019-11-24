# Basic C Programming Tutorial
## Chapter 18. Union

    Union used for the storage of heterogeneous data in same memory location.

        __Example Program__

(img src"https://photos.app.goo.gl/qn8PiYB2MH8Ffcmg8")

### There are three aspects of working with structures:(same as structure)

1. Defining a union type:

        union [union tag name]

        {

        member definition;

        member definition;

        ...

        member definition;

        } [variable name];


2. Declaring variable and constants(1.e. objects)

3. Accesssing union member using member access operato(.)

### Note:

    If we use many variables at a time, the values of union got corrupted 

    Example Program:

(img src"https://photos.app.goo.gl/n4TEqTaABdoYp7y46")

### Note:

    Values of member of union printed very well because one member is being used at a time.
    
    Example Program:

(img src"https://photos.app.goo.gl/NWTNsexew9AJZugz8")