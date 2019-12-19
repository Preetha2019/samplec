# Advanced C Programming

## Part II Managing Data in C 

### Chapter 7. C Structures

To store the collection of different data types

#### Syntax:

struct tag_name //Here, tag_name used to define the Structure { //This brace signals the compiler that the next lines are member definitions.
    type member_name;
    type member_name;
    type member_name;
}structure_name = // This name used to declare the structure
 initializers_values";// Used to refer the data objects
The definition of structure provides the data object that can be referenced by structure name with initializers_values.So, the entire data object is refered by the structure_name.
If, both the tag_name and structure_name isn't provided, a compile time error will result. 
Structure name can be used as passed parameter to a function. Function can return the structure.
Two structures assigned by using assignment statement.

#### Example Program 7.1:Simple structure Program

(imgsrc"https://photos.app.goo.gl/zfjbwTmFnM5DfFgLA")

#### Example Program 7.2:Array of structure 

(imgsrc"https://photos.app.goo.gl/9bSC92DWmNvQq41LA")
Here, the initializers_values used to refer the data object
If the number of elements isn't specified in initializers_values, following code is used to find the number:
nNumberofMembers=(sizeof(structure_name) / sizeof(structure_name[0]))

#### Example Program 7.3:Using nNumberofMembers formula

(imgsrc"https://photos.app.goo.gl/xWvyJ1ja1YPphhHBA")

If a specified string is constant, the advanced program is used to save the space and it doesn't allocate additional space. 

#### Example Program 7.4:Effective use of memory space

(imgsrc"https://photos.app.goo.gl/bVVzrw3gqpGdzQsx7")

Here, the size of specified structure is 280 byte whereas the same structure accupied 2448 byte in the previous program. Because, here pointer is used.

#### Nested Structure:

It is used to have a members of structure be structures themselves.
According to the ANSI C standard, maximum limit of nesting is 35.

#### Example Program 7.5:Nested Structure

(imgsrc"https://photos.app.goo.gl/axA3QFnYdD6S7bzr6")

#### Bit fields in Structure:

It used to store the value of defined variables in a bit level. Hence it reduce the storage space of the variable. 

For example,

struct {
unsigned int bIsValid;
unsigned int bIsFullSize;
unsigned int bIsColor;
unsigned int bIsOpen;
unsigned int bIsSquare;
unsigned int bIsSoft;
unsigned int bIsLong;
unsigned int bIsWide;
unsigned int bIsBoxed;
unsigned int bIsWindowed;
} Status;

This structure requires 20 bytes.But using bit field it requires only 2 bytes(i.e)

struct {
unsigned int bIsValid:1;
unsigned int bIsFullSize:1;
unsigned int bIsColor:1;
unsigned int bIsOpen:1;
unsigned int bIsSquare:1;
unsigned int bIsSoft:1;
unsigned int bIsLong:1;
unsigned int bIsWide:1;
unsigned int bIsBoxed:1;
unsigned int bIsWindowed:1;
} Status;

We cannot determine the address of the bit field variable. This is the major limitation of bit field. If we use the address of opertor, the compile time error will result.

Typedef Keyword:

It used to define a type of variable. It also used to create any data type from simple variables, arrays, structures or unions.





















































































