## Chapter 3.Program Structure
### Parts of C:
* Preprocessor Commands
* Functions
* Variables
* Statements & Expressions
* Comments
### Example:

#include <stdio.h>

int main()

{

/* my first program in C */

printf("Hello, World! \n");

return 0;

}
### Description:
1. The first line of the program #include <stdio.h> is a preprocessor command, which tells a C compiler to include stdio.h file before going to actual compilation.
2. The next line int main() is the main function where the program execution begins.
3. The next line /*...*/ will be ignored by the compiler and it has been put to add additional comments in the program. So such lines are called comments in the program.
4. The next line printf(...) is another function available in C which causes the message "Hello, World!" to be displayed on the screen.
5. The next line return 0; terminates the main() function and returns the value 0.
### Compile and Execute C Program
1. Open a text editor and add the above-mentioned code.
2. Save the file as hello.c
3. Open a command prompt and go to the directory where you have saved the file.
4. Type _gcc hello.c -o hel.exe_ and press enter to compile your code.
5. If there are no errors in your code, the command prompt will take you to the next line.
6. Now, type hel to execute your program.
7. You will see the output "Hello World" printed on the screen.
