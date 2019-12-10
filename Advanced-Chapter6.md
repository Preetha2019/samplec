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


