# Basic C Programing Tutorial

## Chapter 13. Scope Rules:

* It is a region of the program where a defined variable can have its existence and beyond that variable it cannot be accessed.

#### There are three places where variables can be declared in C programming language:

     Inside a function or a block which is called local variables.

     Outside of all functions which is called global variables.

     In the definition of function parameters which are called formal parameters.

### Hnt:

A program can have same name for local and global variables but the value of local variable inside a function will take preference. Here is an example:

### Illustration:

(img src"https://photos.app.goo.gl/CAt3CW91z1cNUVds8")

### Formal Parameter:

Formal parameters are local variable, they have a precedence over global variables

### Initialization of Variables:

* Global variables are initialized automatically by the system when you define them.

* Local variables aren't initialized by system, it should initialized by ourself.

### Hint:

__Data Type__    -   __Initial Default Value__

    int          -           0

    char         -          '\0'

    float        -           0

    double       -           0

    pointer      -          NULL

### Why we need __Iniitialization__???

* Uninitialized variables will take some garbage value already available at their memory location.
* So, initialization is good program practice