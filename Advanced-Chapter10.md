# Advanced C Programming
TODO:
Complete further learning and document
* 1[sort numbers](images/testMallocCreationsImg0.png) and

* ![sortTexts](images/testMallocCreationsImg1.png)

## Chapter 10. Data Management: Sorts, Lists and Indexes

* Sorting is the process of aligning the data in an alphabetical order.

* Merging is the process of combining two sorted files and creating a resultant, sorted file.

* Purging discards the line if it is the same as the previous line, or saves the line if it is different from the previous line.

* Indexing is the process of accessing data in a file. 

* A linked list is a linear data structure. The elements in a linked list are linked using pointers. It consists of nodes where each node contains a data field and a reference(link) to the next node in the list.

* Dynamic memory allocation is used. Because we can't tell how many data will be provided by user.
  
* In a disk based list, there is no possible to have all the list's members in same size. So, we move to union. The size of disk is determined by the largest member.

### Example Program 10.1: Linked List

(imgsrc"https://photos.app.goo.gl/ftHEYpYYbr5A5fBx6")

* In a double linked list, each membershave not onlyits successor in the list, but also to its precessors in this list notice that the end of the pointer is discussed and double disk libnked list id usd and it is very useful and very helpful.

* Indexing used to access specific data objects. Each record in the index file needs to contain only the key value and a pointer to its corresponding data object.

* A linked list presents data that appears to be sorted, but the list can be searched only with a linear search. An indexed list is easy to search, but it must be resorted when an index value is added, deleted, or changed. The solution is B-tree. Here, specific data items are accessed easily by B-tree programs and it works with in memoryand file based data structure.
