# Advanced C Programming

## Chapter 6. Seperate Compilation and Linking

* To make the program small, organised and effective, the compiling and linking the multiple source files are used.
* This isn't  difficult case to compile and link multiple source file than the single source file.
  
## A Couple of things necessary to make multisource file:

* To define each variable that will be shared between different part of the program using _extern_ keyword.
* To make single copy of prototype only, and which should placed in a shared header file.