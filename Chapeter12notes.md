# Basic C Programming Tutorial

## Chapter 12. Functions

* A function is a group of statements that together perform a task. 

* Every C program has at least one function, which is main().

## Defining a Function:

* A function definition provides the actual body of the function.

### Syntax:

return_type function_name( parameter list )

{

body of the function

}

### Parts of Function:

* Return Type: The return_type is the data type of the value the function returns. Some functions performs without returning a value. Here, the return_type is the keyword void.

* Function Name: The function name and the parameter list together constitute the function signature.

* Parameters: Parameters are optional; that is, a function may contain no parameters. The parameter list refers to the type, order, and number of the parameters of a function.

* Function Body: The function body contains a collection of statements that define what the function does.

### Example:

/* function returning the max between two numbers */

int max(int num1, int num2)

{

/* local variable declaration */

int result;

if (num1 > num2)

result = num1;

else

result = num2;

return result;

}

### Declaring a Function:

A function declaration tells the compiler about a function's name, return type, and parameters.

### Syntax:

return_type function_name( parameter list );

For the above defined function max(),the function declaration is as follows:

int max(int num1, int num2);

Parameter names are not important in function declaration, only their type is required, so the following is also a valid declaration:

int max(int, int);

### Why Function Declaration is  needed???
 
 Function declaration is required when you define a function in one source file and you call that function in another file.

### Calling a Function:

* When a program calls a function, the program control is transferred to the called function.

* To call a function, you simply need to pass the required parameters along with the function name, and if the function returns a value, then you can store the returned value. For example:

### Why function call is needed???

* To use a function, you will have to call that function to perform the defined task.

### Example:

(img src"https://photos.app.goo.gl/ysa44Aaj5fH8oGp9A")

### Function Arguments:

If a function is to use arguments, it must declare variables that accept the values of the arguments. These variables are called the __formal parameters__ of the function.

### There are two ways in this arguments can be passed to a function:

* Call by value

* Call by reference

### Call by Value:

This method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.

### Example:

(img src"https://photos.app.goo.gl/ta8v6utM4HDxNikx8")

### Call by Reference:

This method copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.

### Example:

(img src"https://photos.app.goo.gl/NdktpYa9ni5gcBEy5")