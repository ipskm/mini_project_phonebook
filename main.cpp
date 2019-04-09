//------>include libraly<------//
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//------>define function<------//
int menu(); //main menu
void add(); //add contact
void find(); //search from list
void del(); //delect from list
void disall(); //display all contact

//------>create node structor<------//
struct Node {
    char fname[20], lname[20], telnum[10];
    struct Node *prev;
    struct Node *next;
};
struct Node* head = NULL;
typedef  Node node;
node *start, *temp;

//------>insert data in to node<------//
void add(){
    node *ptr, *prev;
    temp = (node *)malloc(sizeof(node));
    printf("First name : ");
    scanf("%s", temp -> fname);
    printf("Last Name : ");
    scanf("%s", temp -> lname);
    printf("Telephone Number : ");
    scanf("%s", temp -> telnum);
    temp -> next = NULL;

    if(start==NULL) start=temp;
    else prev = ptr = start;
    while (strcmp(temp -> fname,ptr -> fname)>0){
        prev = ptr;
        ptr = ptr -> next;
        if (ptr == NULL) break;
    }
    if(ptr == prev){
        temp -> next=start;
        start = temp;
    }else if(ptr == NULL){
        prev -> next = temp;
    }else{
        temp -> next = ptr;
        prev -> next = temp;
    }

}

//------>find contact function<------//
void find(){
    node *ptr;
    char str[20];
    if(start == NULL){
        printf("Directory is Empty...");
        getch();
        return;
    }
    printf("First Name to Find : ");
    scanf("%s",&str);
    ptr=start;
    while (strcmp(ptr -> fname,str)!=0){
        ptr = ptr->next;
        if(ptr == NULL) break;
    }
    if(ptr != NULL){
        printf("First Name : %s\n",ptr -> fname);
        printf("Last Name : %s\n",ptr -> lname);
        printf("Telephone Number : %s\n",ptr -> telnum);
    }else{
        printf("No matching Recoard Found !\n");
    }
    getch();
}


//------>main menu function<------//
int menu(){
    int select_menu;

    printf(" 1. Add contact to your phonebook.");
    printf(" 2. Find contact in your phonebook.");
    printf(" 3. Delete contact from your phonebook.");
    printf(" 4. Edit contact information");
    printf(" 5. Display all your contact.");
    printf(" 6. EXIT");
    printf("Enter your choice (1-6) : ");
    scanf("%d", &select_menu);
    return select_menu;
}


int main() {

}