# Basic C Programming Tutorial 

## Chapter 7. Constants and Literals

### Constants:

* Constants can be an integer constant, a floating constant, a character constant, or a string literal. There are enumeration constants as well.

### Literals:

* Constants refer to fixed values that the program may not alter during its execution. 

* These fixed values are also called literals.

#### Integer Literals

* An integer literal can be a decimal, octal, or hexadecimal constant. A prefix specifies the base or radix: 0x or 0X for hexadecimal, 0 for octal, and nothing for decimal.

* An integer literal can also have a suffix that is a combination of U and L, for unsigned and long, respectively. The suffix can be uppercase or lowercase and can be in any order.

##### Example:

212 /* Legal */

215u /* Legal */

0xFeeL /* Legal */

078 /* Illegal: 8 is not an octal digit */

032UU /* Illegal: cannot repeat a suffix */

85 /* decimal */

0213 /* octal */

0x4b /* hexadecimal */

30 /* int */

30u /* unsigned int */

30l /* long */

30ul /* unsigned long */

#### Floating-point Literals:

* A floating-point literal has an integer part, a decimal point, a fractional part, and an exponent part. You can represent floating point literals either in decimal form or exponential form.

* While representing decimal form, you must include the decimal point, the exponent, or both; and while representing exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

##### Example:

3.14159 /* Legal */

314159E-5L /* Legal */

510E /* Illegal: incomplete exponent */

210f /* Illegal: no decimal or exponent */

.e55 /* Illegal: missing integer or fraction */

#### Character Constants:

* Character literals are enclosed in single quotes, e.g., 'x' can be stored in a simple variable of char type.

* A character literal can be a plain character (e.g., 'x'), an escape sequence (e.g.,'\t'), or a universal character (e.g., '\u02C0').

* There are certain characters in C that represent special meaning when preceded by a backslash, for example, newline (\n) or tab (\t). Here, you have a list of such escape sequence codes:

_Escape sequence- Meaning_

\\ \ character

\' ' character

\" " character

\? ? character

\a Alert or bell

\b Backspace

\f Form feed

\n Newline

\r Carriage return

\t Horizontal tab

\v Vertical tab

\ooo Octal number of one to three digits

\xhh . . . Hexadecimal number of one or more digits

##### Example:

#include <stdio.h>

int main()

{

printf("Hello\tWorld\n\n");

return 0;

}

##### Result:

Hello World

#### String Literals

* String literals or constants are enclosed in double quotes "". A string contains characters that are similar to character literals: plain characters, escape sequences, and universal characters.

* You can break a long line into multiple lines using string literals and separating them using whitespaces.

##### Example:

"hello, dear"

"hello, \
dear"

"hello, " "d" "ear"

#### Defining Constants:

* There are two simple ways in C to define constants:

 Using #define preprocessor

_#define identifier value_

##### Example:

#include <stdio.h>

#define LENGTH 10

#define WIDTH 5

#define NEWLINE '\n'

int main()

{

int area;

area = LENGTH * WIDTH;

printf("value of area : %d", area);

printf("%c", NEWLINE);

return 0;

}

##### Result:

value of area : 50

 Using const keyword

_const type variable = value;_

##### Example:

#include <stdio.h>

int main()

{

const int LENGTH = 10;

const int WIDTH = 5;

const char NEWLINE = '\n';

int area;

area = LENGTH * WIDTH;

printf("value of area : %d", area);

printf("%c", NEWLINE);

return 0;

}

##### Result:

value of area : 50