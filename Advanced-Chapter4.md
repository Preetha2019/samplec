# Advanced C

## Chapter 4. Special Pointers and Their use

Pointers not only points to objects, but also used to obtain the program's name and any parameters that have been entered by user. We will see this kind of special pointers in this chapter.

### Command line Arguments:

* To pass arguments from the command line to c program command line arguments are used.
* It controls c program from outside instead of hard coding those values inside the code.
* It contains three parameters namely argc, argv[], envp[].
  
        * Where, argc refers to the number of arguments passed.
        * argv[] is a pointer array which points to each argument passed to the program.
        * envp[] is an array of char pointers, Which is used to get the environmental variables.
  
#### Example Program 4.1: Commandline Argument

![Pass an argument instead of hard coding- Example Program](images/Ex1-commarg-chapter4.png)

##### Note:
Here, argc holds the number of argument, argv[0] holds the name of the program itself and arg[1] is a pointer to the first command line argument supplied and argv[n] is the last argument. If no parameter supplied, argc will be one. Arguments are seperated by command line argument seperator space or comma. If arguments itself have space then double quotes"" or single quotes'' are used to pass different arguments. Environmental variable stands for dynamic object, it helps programs know what diectory to install files in, where to store temporary files and where to find user profile settings. In this example program, %2d represents , it will only allow an interger upto two digits long and %50s used to read 51 character long array.

#### Example Program 4.2: Justify.c

![Justify- Example Program](images/Ex2-justify-chapter4.png)

#### Example Program 4.3: Function Pointer

![Function Pointer- Example Program](images/Ex3-Funptr-chapter4.png)

### State machine:

* State machines consist of a controlling variable, whose value indicates the current operating status of the function.
  
* State machines enables to efficiently design a program