# Basic C Programming Tutorial

## Chapter 8. Storage Class

* A storage class represents the visibility and a location of a variable.

#### A Storage Class used to define the following things:

* The variable scope.

* The location whether the variable will be stored.

* The initialized value of a variable.

* A lifetime of a variable.

#### There are four types of standard storage class in C:

* auto

* extern

* static

* register

### Auto Storage Class:

* Auto stands for automatic storage class.

* A variable is in auto storage class by default if it is not explicitly specified.

#### Example:

#include <stdio.h>

int main( )

{

  auto int j = 1;

  {

    auto int j= 2;

    {

      auto int j = 3;

      printf ( " %d ", j);

    }

    printf ( "\t %d ",j);

  }

  printf( "%d\n", j);
  
  }

#### OUTPUT:

 3 2 1 

 ### Extern Storage Class:

  * Extern storage class is used when we have global functions or variables which are shared between two or more files
 
 #### Example:
 
  First File: main.c

#include <stdio.h>

extern i;

main()

 {

   printf("value of the external integer is = %d\n", i);

   return 0;

   }

Second File:original.c

#include <stdio.h>

i=48;

#### Result:

 value of the external integer is = 48

 ### Static Storage Class:

 * The static variables are used within function/ file as local static variables. 

 * They can also be used as a global variable.

 * Static local variable is a local variable that retains and stores its value between function calls or block and remains visible only to the function or block in which it is defined.

 * Static global variables are global variables visible only to the file in which it is declared.

 ##### Hint:

 *  static variable has a default initial value zero and is initialized only once in its lifetime.

 #### Example:

#include <stdio.h> /* function declaration */

void next(void);

static int counter = 7; /* global variable */

main()

 {

 while(counter<10)

  {

      next();

      counter++; 
      
        }

return 0;

}

void next( void ) {    /* function definition */

   static int iteration = 13; /* local static variable */

   iteration ++;

   printf("iteration=%d and counter= %d\n", iteration, counter);
   
   }

Result:

iteration=14 and counter= 7

iteration=15 and counter= 8

iteration=16 and counter= 9

### Register Storage Class:

* Register storage class used to store local variables within functions or blocks in CPU registers instead of RAM to have quick access to these variables.

#### Example:

#include <stdio.h> /* function declaration */

main()

 {

register int  weight;

int *ptr=&weight ;/*it produces an error when the compilation occurs ,we cannot get a memory location when dealing with CPU register*/}

}

#### OUTPUT:

error: address of register variable 'weight' requested