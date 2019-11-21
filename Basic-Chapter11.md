# Basic C Programming Tutorial
## Chapter 10. Loops
* A loop statement allows us to execute a statement or group of statements multiple times.

### Types of Loop:

* while loop

* for loop

* do-while loop

* nested loop

### While loop:

while loop Repeats a statement or group of statements while a given condition is true. It tests the condition before executing the loop body.

### Syntax:

while(condition)

{

statement(s);

}

### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 10;

/* while loop execution */

while( a < 20 )

{

printf("value of a: %d\n", a);

a++;

}

return 0;

}

#### Result:

value of a: 10

value of a: 11

value of a: 12

value of a: 13

value of a: 14

value of a: 15

value of a: 16

value of a: 17

value of a: 18

value of a: 19

### for loop:

for loop Executes a sequence of statements multiple times and abbreviates the code that manages the loop varable.

### Syntax:

for ( init; condition; increment )

{

statement(s);

}

### Example:

#include <stdio.h>

int main ()

{

/* for loop execution */

for( int a = 10; a < 20; a = a + 1 )

{

printf("value of a: %d\n", a);

}

return 0;

}

### Result:

value of a: 10

value of a: 11

value of a: 12

value of a: 13

value of a: 14

value of a: 15

value of a: 16

value of a: 17

value of a: 18

value of a: 19

### do...while loop:

do...while loop It is more like a while statement, except that it tests the condition at the end of the loop body.

### Syntax:

do

{

statement(s);

}

while( condition );

### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 10;

/* do loop execution */

do

{

printf("value of a: %d\n", a);

a = a + 1;

}

while( a < 20 );

return 0;

}

### Result:

value of a: 10

value of a: 11

value of a: 12

value of a: 13

value of a: 14

value of a: 15

value of a: 16

value of a: 17

value of a: 18

value of a: 19

### Nested Loops:

nested loops You can use one or more loops inside any other while, for, or do..while loop.
 
### Syntax for nested for loop:

for ( init; condition; increment )

{

for ( init; condition; increment )

{

statement(s);

}

statement(s);

}

### Syntax for a nested while loop:

while(condition)

{

while(condition)

{

statement(s);

}

statement(s);

}

### Syntax for a nested do...while loop:

do

{

statement(s);

do

{

statement(s);

}while( condition );

}while( condition );

#### Hint:

* We can put any type of loop inside any other type of loop. 

* For example, a ‘for’ loop can be inside a ‘while’ loop or vice versa.

### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int i, j;

for(i=2; i<100; i++)

 {

for(j=2; j <= (i/j); j++)

if(!(i%j)) break; // if factor found, not prime

if(j > (i/j)) printf("%d is prime\n", i);

}

return 0;

}

### Result:

2 is prime

3 is prime

5 is prime

7 is prime

11 is prime

13 is prime

17 is prime

19 is prime

23 is prime

29 is prime

31 is prime

37 is prime

41 is prime

43 is prime

47 is prime

53 is prime

59 is prime

61 is prime

67 is prime

71 is prime

73 is prime

79 is prime

83 is prime

89 is prime

97 is prime

### Loop Control Statements:

Loop control statements change execution from its normal sequence. When execution leaves a scope, all automatic objects that were created in that scope are destroyed.


### Types of loop Control Statement:

* break

* continue

* goto

### Break Statement:

break statement Terminates the loop or switch statement and transfers execution to the statement immediately following the loop or switch.

### Syntax:

break;

### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 10;

/* while loop execution */

while( a < 20 )

{

printf("value of a: %d\n", a);

a++;

if( a > 15)

{

/* terminate the loop using break statement */

break;

}

}

return 0;

}

### Result:

value of a: 10

value of a: 11

value of a: 12

value of a: 13

value of a: 14

value of a: 15

### Continue statement:

continue statement Causes the loop to skip the remainder of its body and immediately retest its condition prior to reiterating.

### Syntax:

continue;

### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 10;

/* do loop execution */

do

{

if( a == 15)

{

/* skip the iteration */

a = a + 1;

continue;

}

printf("value of a: %d\n", a);

a++;

}while( a < 20 );

return 0;

}

### Result:

value of a: 10

value of a: 11

value of a: 12

value of a: 13

value of a: 14

value of a: 16

value of a: 17

value of a: 18

value of a: 19

### Goto Statement:

goto statement Transfers control to the labeled statement.

### Synatax:

goto label;

..

.

label: statement;

### Example:

#include <stdio.h>

int main ()

{

/* local variable definition */

int a = 10;

/* do loop execution */

LOOP:do

{

if( a == 15)

{

/* skip the iteration */

a = a + 1;

goto LOOP;

}

printf("value of a: %d\n", a);

a++;

}while( a < 20 );

return 0;

}

### Result:

value of a: 10

value of a: 11

value of a: 12

value of a: 13

value of a: 14

value of a: 16

value of a: 17

value of a: 18

value of a: 19

### The infinite loop:

A loop becomes an infinite loop if a condition never becomes false.

The for loop is traditionally used for this purpose. Since none of the three expressions that form the ‘for’ loop are required, you can make an endless loop by leaving the conditional expression empty.

### Example:

(img src"https://photos.app.goo.gl/RnvhZrcUamKd7QYPA") 

#### Hint:

 We can _terminate_ an infinite loop by pressing __Ctrl + C__ keys.

#### Image view:

(img src "https://photos.app.goo.gl/cEyaei5obsV8G18e7")

Here the last line of command shows that the infinite loop terminated by pressing __Ctrl + c__ key. 