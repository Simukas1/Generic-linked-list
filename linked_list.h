/*
* Declare a structure used for the generic linked list.
* As well declaring some functions.
* Author: Simonas Jarukaitis
* Studies program: software engineering
* Semester: 1
* Group: 2
* E-mail: simasjarukaitis@gmail.com
* Date: 16/01/2022
*
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
	void* data;
	struct Node* next;
}Node;

Node* create_linked_list();
void delete_linked_list(Node** head);
void add_element_to_linked_list(void* new_data, size_t data_size, int position, Node** head);
void delete_element_from_linked_list(int position, Node** head);
int linked_list_size(Node** head);
void print_linked_list(Node* head, void (*print)(void*));
void push_element_to_linked_list(Node** head, void* new_data, size_t data_size);
void* pop_element_from_linked_list(Node** head);
void delete_value_from_linked_list(Node** head, void* value, size_t value_size);
void* get_value_from_linked_list(Node** head, int position);

#endif