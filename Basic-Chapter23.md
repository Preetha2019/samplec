# Basic C Programming Tutorial

## Chapter 23. Preprocessors

All preprocessor commands begin with a hash symbol (#).
 
#### Important preprocessor directives & Description:

#define -- Substitutes a preprocessor macro.

#### Example:

#define MAX_ARRAY_LENGTH 20

#include -- Inserts a particular header from another file.

#### Example:

#include <stdio.h>

#include "myheader.h"

#undef -- Undefines a preprocessor macro.

#### Example:

#undef FILE_SIZE

#define FILE_SIZE 42

#ifdef -- Returns true if this macro is defined.

#### Example:

#ifdef DEBUG

/* Your debugging statements here */

#endif

#ifndef -- Returns true if this macro is not defined.

#### Example:

#ifndef MESSAGE

#define MESSAGE "You wish!"

#endif

#if -- Tests if a compile time condition is true.

#else -- The alternative for #if.

#elif -- #else and #if in one statement.

#endif -- Ends preprocessor conditional.

#error -- Prints error message on stderr.

#pragma -- Issues special commands to the compiler, using a standardized method

### Predefined Macros:

predefined macros should not be directly modified.

#### Example Program:

(img src"https://photos.app.goo.gl/g1ViojB38JMNPT5t7")


### Preprocessor Operators:

* The Macro Continuation (\) Operator
    
    It (\) is used to continue a macro that is too long for a single line. 
    
    For example:

        #define message_for(a, b) \
        
        printf(#a " and " #b ": We love you!\n")

* The Stringize (#) Operator
  
    It (#) is used only in a macro having a specified argument or parameter list. 
    
    For example:

(img src"https://photos.app.goo.gl/sgi2DHXkrdPATLsA9")

* The Token Pasting (##) Operator:
  
    The token-pasting operator (##) within a macro definition combines two arguments.

    For example:

(img src"https://photos.app.goo.gl/9U4Hk7FGvJzoUho16")    

* The Defined() Operator:
 
    The preprocessor defined operator is used in constant expressions to determine if an identifier is defined using #define. 

    for Example:

(img src"https://photos.app.goo.gl/ivmEzqhRCobCAHyK7")

* Parameterized Macros:
    One of the powerful functions of the CPP is the ability to simulate functions using parameterized macros.

    For example:

(img src"https://photos.app.goo.gl/n3uzgKgSNUkv31Tb9")