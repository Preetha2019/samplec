# Advanced C Programming

## Chapter 6. Seperate Compilation and Linking

* To make the program small, organised and effective, the compiling and linking the multiple source files are used.
* This isn't  difficult case to compile and link multiple source file than the single source file.
  
## A Couple of things necessary to make multisource file:

* To define each variable that will be shared between different part of the program using _extern_ keyword.
* To make single copy of prototype only, and which should placed in a shared header file.

### Options in linker command:

* Linker accepts multiline commands. 
* While linking, linker requires minimum of the name of the compiler output.
* The linker commands has a number of options. 
* These options tell the linker to include line number information for the debugger (/linenumbers), align objects on 16-byte boundaries (/al:16), not use the default libraries (/nod) that the compiler inserts in the OBJ files, and create a load map used for debugging (/map).

### Parameters in linker:

* After the options are input obj file, we can omit the obj extension. Many obj file seperated by blanks as per our requirements. The multiline command used when several objects are needed.
* After the output filename specified, this filename receives EXE extension if no extention is specified. If no filename is provided to output, the executable filename is derived from the first obj file. 
* Next, the linker map file used for the debugging. There is not necessary to specify the map file, this filename is derived the executable file's name.
* The final parameters are the libraries. This parameter also have more than one name seperated by the blank. If we have specified nod option, we must specify all the necessary libraries. Else, we must specifty the special libraries need for this program. When we specify the library that is not needed, it doesn't cause an error also the linker does not load extra code for this unneeded libraries.

### There are two types of header file:

* #include"file.h"
  
    Here, the file to be included with the delimiter "and" character. It states that, when the compiler searches the file to be included, the search start with current directory only not on the standard system directory.This process continues recursively until all directories in the chain of included files have been searched. If the file still has not been found, the search continues as though the second format has been specified.

* #include<file.h>

    Here, the file to be included with the delimiter <and> character. It stated that, when the compiler searches the file to be included, the search stars with the directories specified on the compile command line (using the /I option) and then the directories specified using the environment variable include. The current directory is not searched unless it has been specified in one of these two places. If the file cannot be found, the compiler issues an error message and the compile ends. Always, the compiler’s error message provides the necessary name and line number of the include file.

_To write effective large projects, the following include files are used_

* #include statemnet
   It includes the file
  
  ### Example:

  #include<stdio.h>
  #include<conio.h>
  #include<stdlib.h>
  #include “defines.h”
  #include “typedef.h”
  #include “vars.h”
  #include “prototyp.h”

* #define statement
  It helps prevent the use of the same identifier being defined for two purposes.

  ### Example:

  _#ifndef College_
    If the Collegename isn't specified before #ifndef statement, it returns true otherwise returns false statement.

  #ifndef MAX
  #ifndef MIN
  #ifndef MACRO
  #ifndef STUDENT

  ### Illustration:

(img src"https://photos.app.goo.gl/FkcHBWKoLb1W9ZDn9")

  _#ifdef College_
    If the Collegename is specified before #ifndef statement, it returns true otherwise returns false statement.

  #ifdef MAX
  #ifdef MIN
  #ifdef MACRO
  #ifdef STUDENT

* #typedef statement
   It used to give a name to user defined data type and also it is used to define the variable defined in typedef. It not only include for a stucture but also for the pointers to may point to structure.

  ### Example:

 #ifndef TYPEDEF_H

 #define TYPEDEF_H

typedef struct

{

char FontList[MAXFONT][LF_FACESIZE]; // MAXFONT is 50. LF_FACESIZE // is in windows.h file.

BYTE CharSet[MAXFONT]; // The font’s character set

BYTE PitchAndFamily[MAXFONT]; // The font’s pitch and // family

BYTE VectorOrRaster[MAXFONT]; // The font’s type

BYTE FontType[MAXFONT]; // RASTER_FONTTYPE, // DEVICE_FONTTYPE, or // TRUETYPE_FONTTYPE // (windows.h)

int nSizeIndex; // Index to the font size.

int nFontIndex; // Index to the font.

int nSizeList[MAX_SIZE]; // List of font’s sizes.

} FONTSPECS;

typedef FONTSPECS *PFONTSPECS;

typedef FONTSPECS NEAR *NPFONTSPECS;

typedef FONTSPECS FAR *LPFONTSPECS;

 #endif /* TYPEDEF_H */


* vars statement:
  It defines and declares the variables. It includes all the global variables. Thus it uses extern keyword and it doesn't includes static vaariables. Because it only known in the current file.

  ### Example:

 #ifndef VARS_H

 #define VARS_H

 #ifndef EXTERN

 #define EXTERN /*NULL, do variable declarations */

 #define INITIALIZE_EXTERN

 #endif /* EXTERN */

EXTERN char szBuffer[257]; /* Scratch buffer, contents undefined */

EXTERN char szFileName[129]; /* Input filename */

EXTERN int nErrorCount; /* How many errors so far? */

EXTERN int nErrorValue

 #if defined(INITIALIZE_EXTERN) /* Do the initialization */

= {NO_ERROR} /* Initialized */

 #endif

;

 #if defined (INITIALIZE_EXTERN)

 #undef INITIALIZE_EXTERN

 #endif

 #endif /* VARS_H */

### Illustration:

  Here,

   * The variable extern shares the data between teo files.
  
   * twofile.h file used to include all header files.
  
   * define.h used to define the user defined variable. So, it first searches file in current directory.
  
(img src"https://photos.app.goo.gl/c77akuwAtd2DJ7Ei8")

* prototyp statement:
  
It contains function prototype for each program's funtion.

  ### Example:

ifndef PROTOTYP_H

 #define PROTOTYP_H

/* source file return name(parameters); */

/* ADDARRAY.C */ int ArrayAdd(LPARRAY, LPARRAY);

/* SUBARRAY.C */ int ArraySubtract(LPARRAY, LPARRAY);

/* UTILITY.C */ void ErrorMessage(LPSTR szSubString, WORD wError,

long lSomething);

 #endif /* PROTOYTP_H */

### Object Utility Library(LIB):

* It is used to maintain library files.

* It performs the following functions:
   
• Adds an object module to the library

• Deletes an existing object module from the library

• Replaces an existing object module in the library by performing a delete
followed by an add

• Extracts an object module from the library

• Maps a library and provides a listing of the library’s contents, the sizes of the library’s members, and the member’s entry points and other external names

### MAKE files:

* MAKE file has the variables. If this varaiable defined referenced by enclosing it within the parentheses and preceding the opening parentheses with a dollar sign. So, It have the capability to quickly add new source.If this isn't defined, the result is blank, no error will be generated.
  
  #### Example:
  
   Here, variable(includes) is defined:

  includes = twofile.h define.h typedef.h vars.h prototyp.h

* It looks at the date on which one file was created or last modified and compares it to the date of another file. If the first file is older than the second, the MAKE performs some specified action, such as compiling, linking, or another command that can be called from the command prompt.
* To automate the process of creating a large program that has multiple source file the MAKE file is used.

### Step by step Procedure to create make file in c and c++:

__Step 1:__

* Create a new file in text editor and put name as Makefile(here spelling is important)
  
  In make file we can give command with "####" delimiter

  Ex: #### This target will compile 

__Step 2:__

* Makefile have a target name before colon and this name haasa the dependency on the file that has declared after colon with one whitespace.

  "target name": "Dependency file"

  Ex: hello: world

__Step 3:__

* After the target name, next line must declare the command for execution and it should be spaced with single tab.
  
 For c program:

    gcc twofile1.c twofile2.c -o world

For c++ program:

    g++ twofile1.cpp twofile2.cpp -o world

__Step 4:__

* Then compile this program in compiler with "make" and "target name", then we have the exectable file corresponds to that target name.
  
        _Hint:_ _Make always detects the first target and execute first target until any target name is specified._

               _If any changes in particular file ,it only execute that file unless execute all the files._

__Step 5:__

* After that we can execute the program.












