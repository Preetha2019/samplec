# Basic C Progrmming Tutorial
## Chapter 15. Pointers

### Needs of pointer:

    Dynamic memory allocation, cannot be performed without using pointers.

    Also, Some C programming tasks are performed more easily with pointers.

### Definition:

    Pointer is a variable whose value is the address of another variable.

### Declaration:

    data type *var-name;

#### Hint:

    The asterisk * used to declare a pointer

    Address can be accessed using ampersand (&) operator

### How to use pointer:

* Define a pointer variable
* Assign the address of a variable to a pointer
* Finally access the value at the address available in the pointer variable.

    _IMAGE_

        (img src"https://photos.app.goo.gl/RwSfBJ3YXJuSnmfY7")

#### Null pointer:
    
    If we do not have an exact address, assigning NULL value to a pointer is a good practice.

    _IMAGE_
    
        (img src"https://photos.app.goo.gl/uVAGGeUZKKnUf7XU7")

### Note:

    * Incrementing pointer: Used to access next value

    _IMAGE_

        (img src"https://photos.app.goo.gl/nUMaxngmpXkfzWbD8")

    * Decrementing pointer: Used to access previous value

    _IMAGE_

        (img src"https://photos.app.goo.gl/yuwL8bt9HvBPNKFAA")

    * Pointer comparison: Pointer compared using relational operator

    _IMAGE_

        (img src"https://photos.app.goo.gl/FuVA5prdAQDeZHAo7")

    * Pointer also used to access the variable of an array 

    _IMAGE_

        (img src"https://photos.app.goo.gl/h3CBPqA4ihiVj8zS7")

    * Array of pointer used to access the list of strings

    _IMAGE_

        (img src"https://photos.app.goo.gl/Tb4PRWLecuZL4fW8A")

    * Pointer to pointer also possible

    _IMAGE_

        (img src"https://photos.app.goo.gl/2Kb9Ybed23q4tnjE9")

    * Passing pointer to function is possible

    _IMAGE_

        (img src"https://photos.app.goo.gl/XXzuHqwfKWCNdf7U8")

    * Returning pointer from function: Pointer is used to return the sequence of array elements in c programming 

    _IMAGE_

        (img src"https://photos.app.goo.gl/GJVc3iAJCchyVnEW9")