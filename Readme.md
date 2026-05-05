# Data Structure

### What is the Data Structure ?
- The Data Structure is a systematic way to organize the data so that it can be used effiently.

### Abstract Data Type (ADT)
- A data type where you only define what operation can be done. Not how they are done internally. like ATM Machine.
- ADT has 2 parts one is Data and other one is operation
- Implement ADT using array and structure.
- ADT tells us what is to be done and data structure tells how to do it.

### Types Of Data Structure
1. Linear Data Structure
2. Non Linear Data Structure
3. Static Data Structure
4. Dynamic Data Structure

### Time Complexity
- We would be able to know which operation on which data structure will take less time.

### Linked List Type
1. Single Linked List
2. Doubly Linked List
3. Circular Linked List

### 1. Single Linked List
- That made of node that consist of two parts which is data and link
- Data is an actual data and link is a address of the nwxt node which is linked to the linklist.
``` base
[ Data | Link1 ] --> [ Data | Link2 ]
```

#### Traversing a single Linked List:
- Travesing a single linked list means visiting each node of a single linked list untill the end node is reached.
- Our job is to calculate the total number of nodes by traversing the linked list.

### 2. Doubly Linked List
- They each node has an extra pointer that points to the previous node, together with the next pointer and data similar to the singly linked list.
``` base
[ Prev | Data | Next ] --> <-- [ Prev | Data | Next ]
```

#### Why used the Doubly Linked List ?
- Deletion operation is faster in doubly linked list, If the pointer to the node is given.
- Inserting a new node before a given node is easier in doubly linked list.
- Bidirectional Traversal.
- Reversal is easy compare to the singly linked list.

### 3. Circular Linked List
- There are a two types of circular linked list available.
    - A. Circular Singly Linked List
    - B. Circular Doubly Linked List

- Circular Singly Linked List
    - Circular linked list is similar to the singly linked list except that the last node of the circular singly linked list points to the first node.

- Circular Doubly Linked List
    - Circular doubly linked list is similar to the doubly linked list except that the last node of the circular doubly linked list points to the first node and the first node of the circular doubly linked list points to the last node.

### What is Polynomial ?
- The word polynomial comes from poly ( Which means many ) and nomial ( Which means terms ).
- So polynomial is an expression with many terms.
- Each terms of a polynomial has a coefficient and an exponent.
```
5x³ - 3x² + 2x + 1

- Heat 5 is coefficient and 3 is exponent.
- Below has a representation of this type of polynimial in linked list
- [5 | 3 | next] --> [-3 | 2 | next] --> [2 | 1 | next] --> [1 | 0 | next]
```
- So for representing the polynomial expression, we will use a sorted linked list which would be in descending order based on the exponents.