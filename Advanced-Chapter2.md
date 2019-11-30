# Advanced C

## CHAPTER 2 DATA TYPES, CONSTANTS, VARIABLES AND ARRAYS

### Data Types:

* The C language supports a number of data types. 

### C's Data Types:

#### Type- Size- Description:

* char- 1- byte Used for characters or integer variables.
* int- 2 or 4- bytes Used for integer values.
* float- 4- bytes Floating-point numbers.
* double- 8- bytes Floating-point numbers.
* long- 4- bytes integer value. 
* short- 2- bytes integer value.
* unsigned int hold values between 0 and 65,535. (It holds only positive numbers)
* signed int hold values between -32,768 and 32,767.
  
#### Hint:
* A number of useful identifiers are defined in the limits.h header file in ANSI C.
* Other identifiers generally are defined in float.h
  
### Constants:
All homes are buildings, but not all buildings are homes. All literals are _constants_, but
_not all constants are literals_.

__Example:__
(img scr"https://photos.app.goo.gl/7GUBujTazSkqNuxp9")

## Definitions Versus Declaration:
* When a data object is declared, only its attributes are made known to the compiler. When an object is defined, not only are its attributes made known, but also the object is created. For a variable, memory is allocated to hold it; for a function, its code is compiled into an object module.
* __DEFINITION = DECLARATION + SPACE RESERVATION__
  
##### Following are examples of declarations:
* extern int a;//Declaring a variable without definting
* struct_tag Example (int a;int b;};//Declaring a struct
* int myfunc{int a, int b};//Declaring a function
##### Following are examples of definitions:
* int a;
* int b=0;
* int myfunc{int a, int b}{return a+b;}
* struct_tag Example example;

### Variables:
    Variable data object can be modified.
    Variables can be any of data type like int, float, char, structure or union.

### Why we need __Iniitialization__???

* Uninitialized variables will take some garbage value already available at their memory location.
* So, initialization is good program practice
  
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

#### Scope Rules:
    It is a region of the program where a defined variable can have its existence and beyond that variable it cannot be accessed.

#### Example:

(img src"https://photos.app.goo.gl/uYT25eB5FKVb4FTW9")

#### Life span:
    Life span indicates how long the variable or function going to be here.

#### Example:

(img src"https://photos.app.goo.gl/GSZKRx2M8rVDSU9X6")

#### Type Casting:
It used to converting a variable of one data type into another data type.

(img src"https://photos.app.goo.gl/GDZSzLGb551QyhLg9")

#### Arrays:

### Need of Array :

* To store a collection of data which possess same data type we need an Array.

### How to declare an Arrays:

datatype arrayName [ arraySize ];

### How to  Access an Array Elements:
 * Declare an Array
 * Initialize the elements of an array
 * Access elements of an array by calling with arrayName

### Example:

(img src "https://photos.app.goo.gl/DZH1Gte2RdWVLwxL9")


## Concepts of Array:

    C supports multi dimentional array

    ### Declaration of multidimensional array:

    datatype name[size1][size2]...[sizeN];

(img src"https://photos.app.goo.gl/bW75SHpyRXjsG7Zi9")

### Need of declaring a formal parameter:

    To pass a single-dimension array as an argument in a function, we need to declare a formal parameter in one of following three ways

       #### Way-1
        *Formal parameters as a pointer:
void myFunction(int *param)

{

.

.

.

}

     #### Way-2
        *Formal parameters as a sized array:

void myFunction(int param[10])

{

.

.

.

}

    #### Way-3
        *Formal parameters as an unsized array:

void myFunction(int param[])

{

.

.

.

}

#### Hint
    
    C does not allow to return an entire array as an argument to a function. 
     * Function with pointer used to return array
     * pointer without function used to return array

### Returning array from function:

#include <stdio.h>

#include <stdlib.h>//RAND_MAX macro defined in thsi header file

/* function to generate and return random numbers */

int * getRandom( )

{

static int r[10];

int i;

/* set the seed */

_Note:_ Here A seed value is a value used to initialize a pseudo-random number generator (PRNG)

srand( (unsigned)time( NULL ) );

_Note:_
    
    The srand() function sets its argument as the seed for a  new  sequence of  pseudo-random  integers  to be returned by rand().  These sequences are repeatable by calling srand() with the same seed value.

    No matter how many times you execute your program, these very same values will be generated each time.

    We need to make things more random.
    
    time(NULL) return the number (after conversion) of seconds since about midnight 1970-01-01. That number changes every second

    So,when we seed with time, we get the number used by the formula that generates the sequences of pseudo-random numbers (the seed value) constantly changes


for ( i = 0; i < 10; ++i)

{

r[i] = rand();

printf( "r[%d] = %d\n", i, r[i]);

}

return r;

}

/* main function to call above defined function */

int main ()

{

/* a pointer to an int */

int *p;

int i;

p = getRandom();

for ( i = 0; i < 10; i++ )

{

printf( "*(p + %d) : %d\n", i, *(p + i));//Once you store the address of the first element in ‘p’, you can access the array elements using *p, *(p+1), *(p+2), and so on. <--- This is legitimate way of accessing at data

}

return 0;

}

### Result:

r[0] = 313959809

r[1] = 1759055877

r[2] = 1113101911

r[3] = 2133832223

r[4] = 2073354073

r[5] = 167288147

r[6] = 1827471542

r[7] = 834791014

r[8] = 1901409888

r[9] = 1990469526

*(p + 0) : 313959809

*(p + 1) : 1759055877

*(p + 2) : 1113101911

*(p + 3) : 2133832223

*(p + 4) : 2073354073

*(p + 5) : 167288147

*(p + 6) : 1827471542

*(p + 7) : 834791014

*(p + 8) : 1901409888

*(p + 9) : 1990469526

### Pointer to an array

    Elements of array accessed by pointer without function call

#### Example:

(img src"https://photos.app.goo.gl/GQkHaFEPuYJW9SCB9")