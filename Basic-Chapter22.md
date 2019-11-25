# Basic C Programming Tutorial

## Chapter 22. File I/O

### Opening file

    fopen() function used to open existing file or create new file.

#### Prototype:

    FILE *fopen( const char * filename, const char * mode );

### Closing file

    fclose() function used to close a file.

    fclose() function returns EOF, if there is an error in closing the file.

#### Prototype:

    int fclose( FILE *fp );

### Writing a File

    fputc() function used to write the character value.

    fputs() function used to write the string s.

#### Prototype:

    int fputc( int c, FILE *fp );

    int fputs( const char *s, FILE *fp );

### Reading a File

    fgetc() function reads a character.

    fgets() function reads up to n - 1 characters from the input stream referenced by fp.

#### Prototype:

    int fgetc( FILE * fp );

    char *fgets( char *buf, int n, FILE *fp );

#### Binary I/O Functions

size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

 _This function used to read or write blocks of memories._