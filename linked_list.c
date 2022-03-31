/*
*
* Basic functions, created to work with generic linked list
* Author: Simonas Jarukaitis
* Studies program: software engineering
* Semester: 1
* Group: 2
* E-mail: simasjarukaitis@gmail.com
* Date: 16/01/2022
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct Node* create_linked_list() {
	struct Node* head;
	head = NULL;
	return head;
}

void delete_linked_list(struct Node** head) {
	Node* current_element = *head, * next_element = NULL;
	while (current_element) {
		next_element = current_element->next;
		free(current_element);
		current_element = next_element;
	}
	*head = NULL;
}

void push_element_to_linked_list(Node** head, void* new_data, size_t data_size) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("Sorry, I couldn't allocate memory\n");
		return;
	}
	new_node->data = malloc(sizeof(data_size));
	if (new_node->data == NULL) {
		printf("Wow, how did we even got here? 0.o\n");
		return;
	}
	if (new_node == NULL) {
		printf("Sorry, I could not allocate memory :(\n");
		return;
	}
	new_node->data = malloc(data_size);
	new_node->next = (*head);
	if (new_node->data == NULL) {
		printf("Sorry, I could not allocate memory :(\n");
		return;
	}
	memcpy(new_node->data, new_data, data_size);
	(*head) = new_node;
}

void* pop_element_from_linked_list(Node** head) {
	void* popped_data;
	Node* last = *head;
	if (head == NULL || !last || last->data == NULL) {
		return NULL;
	}
	popped_data = last->data;
	*head = last->next;
	return popped_data;
}

void add_element_to_linked_list(void* new_data, size_t data_size, int position, Node** head) {
	Node* new_element = (Node*)malloc(sizeof(Node));
	if (new_element == NULL) {
		printf("Sorry, could not allocate memory :(\n");
		return;
	}
	new_element->data = malloc(sizeof(data_size));
	if (new_element->data == NULL) {
		printf("Wow, how did we even got here? 0.o\n");
		return;
	}
	memcpy(new_element->data, new_data, data_size);
	Node* temporary = *head;
	if (position == 1) {
		new_element->next = temporary;
		*head = new_element;
		printf("I have added your element to your given position ^^\n");
		return;
	}
	if (temporary == NULL) {
		printf("Sorry, your linked list does not have this place :(\n");
		return;
	}
	for (int i = 1; i < position - 1; ++i) {
		if (temporary->next == NULL) {
			printf("Sorry, your linked list does not have this place :(\n");
			return;
		}
		temporary = temporary->next;
	}
	new_element->next = temporary->next;
	temporary->next = new_element;
	printf("I have added your element to your given position ^^\n");
}

void delete_element_from_linked_list(int position, Node** head) {
	if (*head == NULL) {
		printf("Wow, something is wrong, how head can be NULL? 0.o\n");
		return;
	}
	Node* temporary = *head;
	if (position == 1) {
		*head = temporary->next;
		free(temporary);
		printf("I have successfully deleted element from linked list ^^\n");
		return;
	}
	for (int i = 2; temporary != NULL && i < position - 1; ++i) {
		temporary = temporary->next;
	}
	if (temporary == NULL || temporary->next == NULL) {
		printf("Your linked list doesn't have element at your given position :(\n");
		return;
	}
	Node* next = temporary->next->next;
	free(temporary->next);
	temporary->next = next;
	printf("I have successfully deleted element from linked list ^^\n");
}

int linked_list_size(Node** head) {
	int ans = 0;
	Node* current_element = *head, * next_element = NULL;
	while (current_element != NULL) {
		next_element = current_element->next;
		ans++;
		current_element = next_element;
	}
	return ans;
}

void print_linked_list(Node* head, void (*print)(void*)) {
	while (head != NULL) {
		(*print)(head->data);
		head = head->next;
	}
	putchar('\n');
}

void delete_value_from_linked_list(Node** head, void* value, size_t value_size) {
	if (head == NULL) {
		printf("I couldn't find your value :(\n");
		return;
	}
	Node* temporary = *head;
	if (memcmp(temporary->data, value, value_size) == 0) {
		*head = temporary->next;
		free(temporary);
		printf("I removed your given element :)\n");
		return;
	}
	while (memcmp(temporary->next->data, value, value_size) != 0) {
		if (temporary->next->next == NULL) {
			printf("Sorry, I couldn't find your element :(\n");
			return;
		}
		temporary = temporary->next;
	}
	if (temporary == NULL || temporary->next == NULL) {
		printf("I couldn't find your value :(\n");
		return;
	}
	Node* next = temporary->next->next;
	free(temporary->next);
	temporary->next = next;
	printf("I removed your given element :)\n");
}

void* get_value_from_linked_list(Node** head, int position) {
	if (position < 1) {
		printf("You have entered bad postinion! \n");
		return NULL;
	}
	Node* current_element = *head, * next_element = NULL;
	for (int i = 1; i < position; ++i) {
		if (current_element->next != NULL) {
			current_element = current_element->next;
		}
		else {
			printf("You have entered bad positinion! \n");
			return NULL;
		}
	}
	void* returned_data = current_element->data;
	return returned_data;
}