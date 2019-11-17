# Basic C Programming Tutorial
## Chapter 6. Variables
## Definitions Versus Declaration:
* Both data objects (variables) and functions are defined or declared.
* The difference between defining and declaring a data object is that, when a data
object is declared, only its attributes are made known to the compiler. When an object
is defined, not only are its attributes made known, but also the object is created. For
a variable, memory is allocated to hold it; for a function, its code is compiled into an
object module.
* you may say __DEFINITION__= DECLARATION+ SPACE RESERVATION
##### Following are examples of declarations:
* extern int a;//Declaring a variable without definting
* struct_tag Example (int a;int b;};//Declaring a struct
* int myfunc{int a, int b};//Declaring a function
##### Following are examples of definitions:
* int a;
* int b=0;
* int myfunc{int a, int b}{return a+b;}
* struct_tag Example example;
#### Lvalues and Rvalues in C
##### lvalue : 
* Expressions that refer to a memory location are called "lvalue"
expressions. An lvalue may appear as either the left-hand or right-hand
side of an assignment.
##### Example:

int g = 20; // valid statement

##### rvalue : 
* The term rvalue refers to a data value that is stored at some
address in memory. An rvalue is an expression that cannot have a value
assigned to it which means an rvalue may appear on the right-hand side
but not on the left-hand side of an assignment.
##### Example:

10 = 20; // invalid statement; would generate compile-time error
