# Basic C Programing Tutorial
## Chapter 13. Scope Rules:

* A scope in any programming is a region of the program where a defined variable can have its existence and beyond that variable it cannot be accessed.

#### There are three places where variables can be declared in C programming language:

     Inside a function or a block which is called local variables.

     Outside of all functions which is called global variables.

     In the definition of function parameters which are called formal parameters.

### Local Variable:

#include <stdio.h>

int main ()

{

/* local variable declaration */

int a, b;

int c;

/* actual initialization */

a = 10;

b = 20;

c = a + b;

printf ("value of a = %d, b = %d and c = %d\n", a, b, c);

return 0;

}

### Global variable:

#include <stdio.h>

/* global variable declaration */

int g;

int main ()

{

/* local variable declaration */

int a, b;

/* actual initialization */

a = 10;

b = 20;

g = a + b;

printf ("value of a = %d, b = %d and g = %d\n", a, b, g);

return 0;

}

### Hnt:

A program can have same name for local and global variables but the value of local variable inside a function will take preference. Here is an example:

### Example:

#include <stdio.h>

/* global variable declaration */

int g = 20;

int main ()

{

/* local variable declaration */

int g = 10;

printf ("value of g = %d\n", g);

return 0;

}

### Result:

value of g = 10

### Formal Parameter:

#include <stdio.h>

/* global variable declaration */

int a = 20;

int main ()

{

/* local variable declaration in main function */

int a = 10;

int b = 20;

int c = 0;

printf ("value of a in main() = %d\n", a);

c = sum( a, b);

printf ("value of c in main() = %d\n", c);

return 0;

}

/* function to add two integers */

int sum(int a, int b)

{
    
printf ("value of a in sum() = %d\n", a);

printf ("value of b in sum() = %d\n", b);

return a + b;

}

### Result:

value of a in main() = 10

value of a in sum() = 10

value of b in sum() = 20

value of c in main() = 30

### Initialization of Variables:

* Global variables are initialized automatically by the system when you define them.

* Local variables aren't  initialized by system, it should initialized by ourself.

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





