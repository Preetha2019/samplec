# Advanced C Programming
## Chapter 9. Disk Files and Other IO

* ANSI offers collection of file IO functions.
* We can write a file in unformatted manner and our program can write a file in formatted manner.
* Here, unformatted refers to machine readable manner and formatted file refers to the people readable manner.
* Eight character is the format for the disk filename and three characters is the format for the extension.
* If a file consist of only text, it may contain EOF(End of File) file.
* All files also have attributes, as follows:
        Normal-> No special attributes are set for the file.
        Directory-> The file is a directory. The directory attribute can be used with the hidden attribute.
        Hidden-> The file’s name is not displayed when you issue a DIR command without the /A:H option.
        System-> The file is used only by the operating system. Generally, only the two files belonging to the operating system have the system attribute.
        Read-> only The file can be only read, not written or deleted.
        Archive-> The file has not been backed up since it was last changed. BACKUP and XCOPY can use and change the archive attribute.
* Except read attribute, others must be set using DOS ATTRIB command. 
* When a file is opened, the program typically must specify the filename and the mode: read, write, or both read and write.
* Identifier returned by opened file usedt o call the read and write function.
* If the program has finished with the file, the file should be closed or the file should be temporarly deleted.
* ftell() and fgetpos() functions used to return the correct position of the data object.