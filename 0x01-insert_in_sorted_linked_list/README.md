# 0x01. Insert in sorted linked list

## Tasks

0. Insert in sorted linked list
Technical interview preparation:

* You are not allowed to google anything
* Whiteboard first
Write a function in C that inserts a number into a sorted singly linked list.

* Prototype: listint_t \*insert_node(listint_t **head, int number);
* Return: the address of the new node, or NULL if it failed

## Output:

```
carrie@ubuntu:0x01$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
carrie@ubuntu:0x01$ ./insert
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
```
