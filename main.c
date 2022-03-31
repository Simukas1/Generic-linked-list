/* 
* Program, who creates linked list, and then it can remove given element with it, with some basic UI
*  Author: Simonas Jarukaitis
* Studies program: software engineering
* Semester: 1
* Group: 2
* E-mail: simasjarukaitis@gmail.com
* Date: 16/01/2022
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_int(void* n);
void print_float(void* f);
void print_char(void* c);

int num_validate_status();
int num_validate_int();
float num_validate_float();
int num_validate_status_linked_list();

void print_linked_list_options();

void its_int(int status); //if user chose int type
void its_float(int status); //if user chose float type
void its_char(int status); //if user chose char type

int main()
{
    const int linked_list_options_size = 9;
    printf("Hello, this program will create linked list, and it will remove your given element\n");
    printf("Please enter your linked list data type:\n1 : int\n2 : float\n3 : char\n");
    int status = num_validate_status();
    if (status == 1) {
        its_int(status);
        return 0;
    }
    else if (status == 2) {
        its_float(status);
        return 0;
    }
    else {
        its_char(status);
        return 0;
    }
}

void print_int(void* n) {
    printf("%d ", *(int*)n);
}

void print_float(void* f) {
    printf("%f ", *(float*)f);
}

void print_char(void* c) {
    printf("%c ", *(char*)c);
}

int num_validate_status() {
    int num = 0;
    while (1) {
        if ((scanf("%d", &num) == 1 && num < 4 && num > 0 && getchar() == '\n')) {
            return num;
        }
        else {
            printf("wrong input, please input a number, 1, 2 or 3: ");
            while (getchar() != '\n') {
                ;
            }
        }
    }
}

int num_validate_status_linked_list() {
    int num = 0;
    while (1) {
        if ((scanf("%d", &num) == 1 && num < 9 && num > 0 && getchar() == '\n')) {
            return num;
        }
        else {
            printf("wrong input, please input a number, from interval [1;8] ");
            while (getchar() != '\n') {
                ;
            }
        }
    }
}

int num_validate_int() {
    int num = 0;
    while (1) {
        if ((scanf("%d", &num) == 1 && getchar() == '\n')) {
            return num;
        }
        else {
            printf("wrong input, please input an integer ");
            while (getchar() != '\n') {
                ;
            }
        }
    }
}

float num_validate_float() {
    float num = 0;
    while (1) {
        if ((scanf("%f", &num) == 1 && getchar() == '\n')) {
            return num;
        }
        else {
            printf("wrong input, please input a real number ");
            while (getchar() != '\n') {
                ;
            }
        }
    }
}

void print_linked_list_options() {
    printf(
        "1 : add element to linked list\n"
        "2 : delete element from linked list\n"
        "3 : get linked list size\n"
        "4 : print linked list\n"
        "5 : push element to linked list\n"
        "6 : pop element from linked list\n"
        "7 : delete value from linked list\n"
        "8 : delete linked list\n");
}

void its_int(int status) {
    system("cls");
    printf("So you have chosen int type linked list!\n");
    printf("Hold on, let me create your linked list :)\n");
    Node* head = create_linked_list();
    while (status != 8) {
        printf("Now please select your options\n");
        print_linked_list_options();
        status = num_validate_status_linked_list();
        if (status == 1) {
            system("cls");
            printf("Please input a number, which you want to place to linked list\n");
            int num = num_validate_int();
            printf("Now please enter a position\n");
            int position = num_validate_int();
            add_element_to_linked_list(&num, sizeof(int), position, &head);
        }
        else if (status == 2) {
            system("cls");
            printf("Please input position of a number, which you want to  delete\n");
            int position = num_validate_int();
            delete_element_from_linked_list(position, &head);
        }
        else if (status == 3) {
            system("cls");
            printf("your linked list size is: %d\n", linked_list_size(&head));
        }
        else if (status == 4) {
            system("cls");
            print_linked_list(head, print_int);
        }
        else if (status == 5) {
            system("cls");
            printf("please enter elment, which you want to push to linked list\n");
            int num = num_validate_int();
            push_element_to_linked_list(&head, &num, sizeof(num));
        }
        else if (status == 6) {
            system("cls");
            printf("your popped element is: ");
            print_int(pop_element_from_linked_list(&head));
            putchar('\n');
        }
        else if (status == 7) {
            printf("Please enter a value, which you want to delete from your linked list\n");
            int number = num_validate_int();
            delete_value_from_linked_list(&head, &number, sizeof(int));
        }
        else {
            printf("Now I will deleate your linked list. It was fun working with you ^^\nGoodbye!");
            delete_linked_list(&head);
            return;
        }
    }
}

void its_float(int status) {
    system("cls");
    printf("So you have chosen float type linked list!\n");
    printf("Hold on, let me create your linked list :)\n");
    Node* head = create_linked_list();
    while (status != 8) {
        printf("Now please select your options\n");
        print_linked_list_options();
        status = num_validate_status_linked_list();
        if (status == 1) {
            system("cls");
            printf("Please input a number, which you want to place to linked list\n");
            float num = num_validate_float();
            printf("Now please enter a position\n");
            int position = num_validate_int();
            add_element_to_linked_list(&num, sizeof(float), position, &head);
        }
        else if (status == 2) {
            system("cls");
            printf("Please input position of a number, which you want to  delete\n");
            int position = num_validate_int();
            delete_element_from_linked_list(position, &head);
        }
        else if (status == 3) {
            system("cls");
            printf("your linked list size is: %d\n", linked_list_size(&head));
        }
        else if (status == 4) {
            system("cls");
            print_linked_list(head, print_float);
        }
        else if (status == 5) {
            system("cls");
            printf("please enter elment, which you want to push to linked list\n");
            float num = num_validate_float();
            push_element_to_linked_list(&head, &num, sizeof(float));
        }
        else if (status == 6) {
            system("cls");
            printf("your popped element is: ");
            print_float(pop_element_from_linked_list(&head));
            putchar('\n');
        }
        else if (status == 7) {
            printf("Please enter a value, which you want to delete from your linked list\n");
            float number = num_validate_float();
            delete_value_from_linked_list(&head, &number, sizeof(int));
        }
        else {
            printf("Now I will deleate your linked list. It was fun working with you ^^\nGoodbye!");
            delete_linked_list(&head);
            return;
        }
    }
}

void its_char(int status) {
    system("cls");
    printf("So you have chosen char type linked list!\n");
    printf("Hold on, let me create your linked list :)\n");
    Node* head = create_linked_list();
    while (status != 8) {
        printf("Now please select your options\n");
        print_linked_list_options();
        status = num_validate_status_linked_list();
        if (status == 1) {
            system("cls");
            printf("Please input a char, which you want to place to linked list\n");
            char c = getchar();
            printf("Now please enter a position\n");
            int position = num_validate_int();
            add_element_to_linked_list(&c, sizeof(float), position, &head);
        }
        else if (status == 2) {
            system("cls");
            printf("Please input position of a char, which you want to  delete\n");
            int position = num_validate_int();
            delete_element_from_linked_list(position, &head);
        }
        else if (status == 3) {
            system("cls");
            printf("your linked list size is: %d\n", linked_list_size(&head));
        }
        else if (status == 4) {
            system("cls");
            print_linked_list(head, print_char);
        }
        else if (status == 5) {
            system("cls");
            printf("please enter elment, which you want to push to linked list\n");
            char c = getchar();
            push_element_to_linked_list(&head, &c, sizeof(float));
        }
        else if (status == 6) {
            system("cls");
            printf("your popped element is: ");
            print_char(pop_element_from_linked_list(&head));
            putchar('\n');
        }
        else if (status == 7) {
            printf("Please enter a char, which you want to delete from your linked list\n");
            char c = getchar();
            delete_value_from_linked_list(&head, &c, sizeof(int));
        }
        else {
            printf("Now I will deleate your linked list. It was fun working with you ^^\nGoodbye!");
            delete_linked_list(&head);
            return;
        }
    }
}