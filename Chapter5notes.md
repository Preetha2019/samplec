# Basic C Programming Tutorial

## Chapter5-in-Basic-C

### Data types:

 * It is a system used to declaring variables and functions of different types. 

 * It determines the how much space occupies  in storage.
 
 ### Classification of data types:

### Basic Types:

They are arithmetic types and are further classified into: 

(a) integer types and (b) floating-point types.

### Enumerated types:

* They are again arithmetic types and they are used to define variables that can only assign certain discrete integer values throughout the program.

#### Example Program:

(img src"https://photos.app.goo.gl/h2bMe1TtEiD3hjfW8")

### The type void:

* It indicates that no value is available.

* It is used in three kinds of situations:
  
_Types and Description_

1 Function returns as void

  * A function with no return value has the return type as void. 
  * 
2 Function arguments as void

  * A function with no parameter can accept a void. 
  * 
3 Pointers to void

  * A pointer of type void * represents the address of an object, but not its type.

### Derived types:

* They include (a) Pointer types, (b) Array types, (c) Structure types, (d)Union types, and (e) Function types.

* The array types and structure types are referred collectively as the aggregate types.

#### Integer Types

_Type- Storage size- Value range_

char- 1 byte- -128 to 127 or 0 to 255

unsigned char- 1 byte- 0 to 255

signed char- 1 byte- -128 to 127

int- 2 or 4 bytes- -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647

unsigned int- 2 or 4 byte-s 0 to 65,535 or 0 to 4,294,967,295

short- 2 bytes- -32,768 to 32,767

unsigned short- 2 bytes- 0 to 65,535

long- 4 bytes- -2,147,483,648 to 2,147,483,647

unsigned long- 4 bytes- 0 to 4,294,967,295

##### Hint:

* Sizeof operator used to get the exact size of a type or a variable on a particular platform .

* The header file limits.h defines the size of data types.
   
##### Example:

#include <stdio.h>

#include <limits.h>

int main()

{

printf("Storage size for int : %d \n", sizeof(int));

return 0;

}

##### Result:

Storage size for int : 4

#### Floating-Point Types:

_Type- Storage size- Value range- Precision_

float- 4 byte- 1.2E-38 to 3.4E+38- 6 decimal places

double- 8 byte- 2.3E-308 to 1.7E+308- 15 decimal places

long double- 10 byte 3.4E-4932 to 1.1E+4932- 19 decimal places

##### Hint:
* The header file float.h defines float data type.

##### Example:

#include <stdio.h>

#include <float.h>

int main()

{

printf("Storage size for float : %d \n", sizeof(float));

printf("Minimum float positive value: %E\n", FLT_MIN );

printf("Maximum float positive value: %E\n", FLT_MAX );

printf("Precision value: %d\n", FLT_DIG );

return 0;

}

##### Result:

Storage size for float : 4

Minimum float positive value: 1.175494E-38

Maximum float positive value: 3.402823E+38

Precision value: 6