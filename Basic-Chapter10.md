# Basic C Programming Tutorial

## Chapter 10. Decision Making

* Decision-making structures used to test the condition then execute the next statement.

* C programming language assumes any __non-zero__ and __non-null values__ as __true__, and if it is either __zero__ 
  
or__null__, then it is assumed as __false__ value.

## Types of Decision Making:

* if statement

* if...elase statement

* nested if statement

*switch statement

* nested switch statement

### if statement:

 An if statement consists of a boolean expression followed by one or more statements.

 ####Syntax:
 
if(boolean_expression)

{

/* statement(s) will execute if the boolean expression is true */

}

#### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 10;

/* check the boolean condition using if statement */

if( a < 20 )

{

/* if condition is true then print the following */

printf("a is less than 20\n" );

}

printf("value of a is : %d\n", a);

return 0;

}

#### Result:

a is less than 20;

value of a is : 10

### if...elase statement:

* if...else statement An if statement can be followed by an optional else statement, which executes when the Boolean expression is false.

#### Syntax:

if(boolean_expression)

{

/* statement(s) will execute if the boolean expression is true */

}

else

{

/* statement(s) will execute if the boolean expression is false */

}

#### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 100;

/* check the boolean condition */

if( a < 20 )

{

/* if condition is true then print the following */

printf("a is less than 20\n" );

}

else

{

/* if condition is false then print the following */

printf("a is not less than 20\n" );

}

printf("value of a is : %d\n", a);

return 0;

}

#### Result:

a is not less than 20;

value of a is : 100

### if...else if...else Statement:

An if statement can be followed by an optional else if...else statement, which is very useful to test various conditions using single if...else if statement.

### Syntax:

if(boolean_expression 1)

{

/* Executes when the boolean expression 1 is true */

}

else if( boolean_expression 2)

{

/* Executes when the boolean expression 2 is true */

}

else if( boolean_expression 3)

{

/* Executes when the boolean expression 3 is true */

}

else

{

/* executes when the none of the above condition is true */

}

### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 100;

/* check the boolean condition */

if( a == 10 )

{

/* if condition is true then print the following */

printf("Value of a is 10\n" );

}

else if( a == 20 )

{

/* if else if condition is true */

printf("Value of a is 20\n" );

}

else if( a == 30 )

{

/* if else if condition is true */

printf("Value of a is 30\n" );

}

else

{

/* if none of the conditions is true */

printf("None of the values is matching\n" );

}

printf("Exact value of a is: %d\n", a );

return 0;

}

#### Result:

None of the values is matching

Exact value of a is: 100

### Nested if satement:

* nested if statements You can use one if or else if statement inside another if or else if statement(s).

#### Syntax:

if( boolean_expression 1)

{

/* Executes when the boolean expression 1 is true */

if(boolean_expression 2)

{

/* Executes when the boolean expression 2 is true */

}

}

#### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 100;

int b = 200;

/* check the boolean condition */

if( a == 100 )

{

/* if condition is true then check the following */

if( b == 200 )

{

/* if condition is true then print the following */

printf("Value of a is 100 and b is 200\n" );

}
}

printf("Exact value of a is : %d\n", a );

printf("Exact value of b is : %d\n", b );

return 0;

}

#### Result:

Value of a is 100 and b is 200

Exact value of a is : 100

Exact value of b is : 200

### Switch Statement:

* switch statement A switch statement allows a variable to be tested for equality against a list of values.

#### Syntax:

switch(expression){

case constant-expression :

statement(s);

break; /* optional */

case constant-expression :

statement(s);

break; /* optional */

/* you can have any number of case statements */

default : /* Optional */

statement(s);

#### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

char grade = 'B';

switch(grade)

{

case 'A' :

printf("Excellent!\n" );

break;

case 'B' :

case 'C' :

printf("Well done\n" );

break;

case 'D' :

printf("You passed\n" );

break;

case 'F' :

printf("Better try again\n" );

break;

default :

printf("Invalid grade\n" );

}

printf("Your grade is %c\n", grade );

return 0;

}

}

#### Result:

Well done

Your grade is B

### Nested Switch statement:

*nested switch statements You can use one switch statement inside another switch statement(s).

Syntax:

switch(ch1) {

case 'A':

printf("This A is part of outer switch" );

switch(ch2) {

case 'A':

printf("This A is part of inner switch" );

break;

case 'B': /* case code */

}

break;

case 'B': /* case code */

}

#### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 100;

int b = 200;

switch(a) {

case 100:

printf("This is part of outer switch\n", a );

switch(b) {

case 200:

printf("This is part of inner switch\n", a );

}

}

printf("Exact value of a is : %d\n", a );

printf("Exact value of b is : %d\n", b );

return 0;

}

### Result:

This is part of outer switch

This is part of inner switch

Exact value of a is : 100

Exact value of b is : 200