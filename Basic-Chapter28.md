# Basic C Programming Tutorial

## Chapter 28. Variable Arguments

To define a function which can accept variable number of parameters, this kind of variable arguments used with the help of stdarg.h header file.

### Note:

    * Create a va_list type variable in the function definition. This type is defined in stdarg.h header file.
    * Use int parameter and va_start macro to initialize the va_list variable to an argument list. The macro va_start is defined in stdarg.h header file.
    * Use va_arg macro and va_list variable to access each item in argument list.
    * Use a macro va_end to clean up the memory assigned to va_list variable.

### Example for this function definition:

int func(int, ... )// here three dots(...) called elipses, before this elipses int must be placed, which represents the number of argument passed. 

{

.

.

.

}

int main()

{

func(1, 2, 3);

func(1, 2, 3, 4);// we may add variable number of argument

}

### Example Program:

(img src"https://photos.app.goo.gl/YMV2kvkmEan7qoy79")