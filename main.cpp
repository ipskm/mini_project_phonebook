//------>include library<------//
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//------>define function<------//
int menu(); //main menu (ฟังก์ชันเมนูหลัก)
void add(); //add contact (ฟังก์ชันเพิ่มรายชื่อ)
void find(); //search from list (ฟังก์ชันการค้นหา)
void del(); //delete from list (ฟังก์ชันลบรายชื่อ)
void disall(); //display all contact (ฟังก์ชันแสดงรายชื่อทั้งหมด)

//------>create node structure<------//
struct Node {
    char fname[20], lname[20], telnum[10]; //initiail datatype to keep first-name, last-name, phone-number
    struct Node *prev; //previous pointer
    struct Node *next; //next pointer
};
struct Node* head = NULL; //init head-pointer equal null
typedef  Node node; //define Node as node type
node *start, *temp; //init start-pointer and temp-pointer

//------>insert data in to node<------//
void add(){
    node *ptr, *prev;  //init pointer
    temp = (node *)malloc(sizeof(node)); //set temp insert data to node
    printf("First name : ");
    scanf("%s", temp -> fname);  //insert First-Name to fmane[20] by temp pointer
    printf("Last Name : ");
    scanf("%s", temp -> lname);  //insert Last-Name to lname[20] by temp pointer
    printf("Telephone Number : ");
    scanf("%s", temp -> telnum); //insert Tel-Number to telnum[10] by temp pointer
    temp -> next = NULL; //set next pointer equal NULL

    if(start == NULL) start = temp;  //check start pointer if equal null will define to temp
    else {
        prev = ptr = start;
        while (strcmp(temp -> fname, ptr -> fname) > 0) {
            prev = ptr;
            ptr = ptr -> next;
            if (ptr == NULL) break;
        }
        if (ptr == prev) {
            temp -> next = start;
            start = temp;
        } else if (ptr == NULL) {
            prev -> next = temp;
        } else {
            temp -> next = ptr;
            prev -> next = temp;
        }
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
    ptr = start;
    while (strcmp(ptr -> fname,str)!= 0){
        ptr = ptr -> next;
        if(ptr == NULL) break;
    }
    if(ptr != NULL){
        printf("First Name : %s\n",ptr -> fname);
        printf("Last Name : %s\n",ptr -> lname);
        printf("Telephone Number : %s\n",ptr -> telnum);
    }else{
        printf("No matching Record Found !\n");
    }
    getch();
}

//------>edit contact function<------//
void edit(){
    node *ptr;
    char str[20];
    if (start==NULL){
        printf("Directory id Empty....");
        getch();
        return ;
    }
    printf("First Name to Edit is : ");
    scanf("%s",str);
    ptr=start;
    while (strcmp(ptr -> fname,str) != 0){
        ptr = ptr -> next;
        if(ptr == NULL) break;
    }
    if(ptr != NULL){
        printf("Edit First Name : %s to : ", ptr -> fname);
        scanf("%s", ptr -> fname);
        printf("Edit Last Name : %s to : ", ptr -> lname);
        scanf("%s", ptr -> lname);
        printf("Edit Phone Number : %s to : ", ptr -> telnum);
        scanf("%s", ptr -> telnum);
    } else{
        printf("No Matching Records Found ! \n");
    }
    getch();
}

//------>delete contact function<------//
void del(){
    node *ptr, *prev, *temp;
    char str[20], yn = 'n';
    if (start == NULL){
        printf("Directory is Empty. \n");
        getch();
        return;
    }
    printf("First Name to Delete : ");
    scanf("%s", ptr);
    prev = ptr = start;
    while (strcmp(ptr -> fname, str) != 0){
        prev = ptr;
        ptr = ptr -> next;
        if (ptr == NULL) break;
    }
    if (ptr != NULL){
        printf("Are you sure to delete this record ? [y/n] : ");
        yn = getch();
        printf("\n\n---------------------------------------------------------\n");
        printf("First Name : %s\n",ptr -> fname);
        printf("Last Name : %s\n",ptr -> lname);
        printf("Phone Number : %s\n",ptr -> telnum);
        printf("---------------------------------------------------------\n\n");

        if(yn == 'y'){
            if (ptr == start) {
                temp = start -> next;
                free(start);
                start = temp;
            } else {
                temp = ptr -> next;
                free (start);
                prev -> next = temp;
            }
            printf("Record Deleted.");
        }else{
            printf("Record not deleted.");
        }
    } else {
        printf("Not Matching Record Found.");
    }
    getch();
}

//------>display all record<------//
void disall(){
    node *ptr;
    if(start == NULL){
        printf("Directory is Empty.");
        return;
    }
    for(ptr = start; ptr != NULL; ptr = ptr -> next){
        printf("First name: %s", ptr -> fname);
        printf("Last name:%s", ptr -> lname);
        printf("Telephone No.: %s", ptr -> telnum);
        printf("------------------------------\n");
    }
    getch();
}

//------>main menu function<------//
int menu(){
    int select_menu;

    printf(" 1. Add contact to your phonebook.\n");
    printf(" 2. Find contact in your phonebook.\n");
    printf(" 3. Delete contact from your phonebook.\n");
    printf(" 4. Edit contact information.\n");
    printf(" 5. Display all your contact.\n");
    printf(" 6. EXIT\n");
    printf("Enter your choice (1-6) : ");
    scanf("%d", &select_menu);
    return select_menu;
}


int main() {
    int ch;
    start = (node *)malloc(sizeof(node));
    start = NULL;
    do{
        ch=menu();
        switch (ch) {
            case 1:
                add();
                break;
            case 2:
                find();
                break;
            case 3:
                edit();
                break;
            case 4:
                del();
                break;
            case 5:
                disall();
                break;
        }
    }while (ch != 6);
}