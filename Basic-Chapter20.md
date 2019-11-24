# Basic C Programming Tutorial

## Chapter 20. Typedef

    Typedef is the actual definition of a new type.

### Note:
    
    typedef with structure to define a new data type and then use that data type to define structure variables directly

### typedef vs #define:

* typedef is limited to giving symbolic names to types only, whereas #define can be used to define an alias for values as well, e.g., you can define 1 as ONE, 3.14 as PI, etc.
  
    __Example__

(img src"https://photos.app.goo.gl/3FzdFEpprN7qk7QF6")


* typedef interpretation is performed by the compiler where #define statements are performed by preprocessor.
  
* #define should not be terminated with a semicolon, but typedef should be terminated with semicolon.

* #define will just copy-paste the definition values at the point of use

* typedef follows the scope rule. In case of #define, no scope rule is followed
  
    __Example__

(img src"https://photos.app.goo.gl/Ezv5UFAo6KtgSQqq6")