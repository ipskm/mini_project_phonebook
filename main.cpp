//------>include library<------//
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//------>define function<------//
int menu(); //main menu -> ฟังก์ชันเมนูหลัก
void add(); //add contact -> ฟังก์ชันเพิ่มรายชื่อ
void find(); //search from list -> ฟังก์ชันการค้นหา
void del(); //delete from list -> ฟังก์ชันลบรายชื่อ
void disall(); //display all contact -> ฟังก์ชันแสดงรายชื่อทั้งหมด

//------>create node structure<------//
struct Node {
    char fname[20], lname[20], telnum[10]; //initiail datatype to keep first-name, last-name, phone-number -> สร้างรูปแบบการเก็บข้อมูลในโหนด
    struct Node *prev; //previous pointer -> สร้างพอยเตอร์เพื่อชี้ตัวข้างหน้า
    struct Node *next; //next pointer -> สร้างพอยเตอร์เพื่อชี้ตัวถัดไป
};
struct Node* head = NULL; //init head-pointer equal null -> กำหนดให้พอยเตอร์เฮดมีค่าเท่ากับ null
typedef  Node node; //define Node as node type -> ตั้งค่าการเขียนจาก Node เป็น node
node *start, *temp; //init start-pointer and temp-pointer -> สร้างพอยเตอร์ สตาร์ทและเทม

//------>insert data in to node<------//
void add(){
    node *ptr, *prev;  //init pointer -> สร้างพอยต์เตอร์
    temp = (node *)malloc(sizeof(node)); //set temp insert data to node -> ให้ temp เป็นตัวแปรเก็บข้อมูล
    printf("First name : ");
    scanf("%s", temp -> fname);  //insert First-Name to fmane[20] by temp pointer -> รับค่าและเก็บข้อมูลเข้าโหนด
    printf("Last Name : ");
    scanf("%s", temp -> lname);  //insert Last-Name to lname[20] by temp pointer -> รับค่าและเก็บข้อมูลเข้าโหนด
    printf("Telephone Number : ");
    scanf("%s", temp -> telnum); //insert Tel-Number to telnum[10] by temp pointer -> รับค่าและเก็บข้อมูลเข้าโหนด
    temp -> next = NULL; //set next pointer equal NULL -> ให้พอยต์เตอร์ next มีค่าเป็น null

    if(start == NULL) start = temp;  //check start pointer if equal null will define to temp -> ตรวจสอบว่าพอยเตอร์ start มีค่าเท่ากับ null ไหม ถ้าใช่ให้ start มีค่าเท่ากับ temp แทน
    else {
        prev = ptr = start; //define prev ptr start pointer to the same node -> ให้พอย์เตอร์ prev ptr และ start ชี้ไปที่โหนดเดียวกัน
        while (strcmp(temp -> fname, ptr -> fname) > 0) { //loop read data from node to compare isn't equal to 0 -> วนลูปเพื่ออ่านข้อมูลจากโหนด เพื่อเปรียบเทียบว่ามีข้อมูลอยู่ในโหนดว่าไม่ได้ว่างหรือมีค่าเท่ากับ 0
            prev = ptr; //define pointer prev equal to ptr -> ให้พอยต์เตอร์ prev ชี้ไปที่โหนดเดียวกันกับ ptr
            ptr = ptr -> next; //define ptr equal to next -> ให้พอยต์เตอร์ ptr มีค่าเท่ากับ next
            if (ptr == NULL) break; //if ptr is null will exit loop -> เมื่อ ptr มีค่าเท่ากับ null ให้ออกจากลูป
        }
        if (ptr == prev) { //if ptr equal to prev will set start pointer equal to temp -> ถ้า ptr ชี้ไปที่โหนดเดียวกันกับ prev จะให้ temp มีค่าเป็น start
            temp -> next = start;
            start = temp;
        } else if (ptr == NULL) { //if ptr equal to null will set prev equal temp -> ถ้า ptr เป็น null ให้ prev ชี้ไปที่โหนดเดียวกันกับ temp
            prev -> next = temp;
        } else { //else is not all above will set temp equal ptr and prev equal temp -> แต่ถ้าไม่เข้าเงื่อนไขใดเลย ให้ temp ชี้ไปที่โหนดเดียวกันกับ ptr และ prev ชี้ไปที่โหนดเดียวกันกับ temp
            temp -> next = ptr;
            prev -> next = temp;
        }
    }
	return;
}

//------>find contact function<------//
void find(){
    node *ptr; //define the  pointer ptr
    char str[20]; //define variable str is char length 20 character
    if(start == NULL){ //if start equal null print "Directory is Empty"
        printf("Directory is Empty...");
        getch();
        return; //return to main function
    }
    printf("First Name to Find : "); //print sentence to get name to search
    scanf("%s",&str); //get string from user
    ptr = start; //set ptr equal to start
    while (strcmp(ptr -> fname,str)!= 0){ //compare string from user is equal data in some node
        ptr = ptr -> next;
        if(ptr == NULL) break; //if ptr is null exit loop
    }
    if(ptr != NULL){ //if ptr isn't null will print data from search name
        printf("First Name : %s\n",ptr -> fname);
        printf("Last Name : %s\n",ptr -> lname);
        printf("Telephone Number : %s\n",ptr -> telnum);
    }else{ //or no match found will print some sentence
        printf("No matching Record Found !\n");
    }
    getch();
	return;
}

//------>edit contact function<------//
void edit(){
    node *ptr; //define ptr pointer
    char str[20]; //define variable str to keep string has length 20
    if (start==NULL){ //if start pointer is null print some sentence
        printf("Directory id Empty....");
        getch();
        return ;
    }
    printf("First Name to Edit is : "); //print some sentence
    scanf("%s",str); //get string data from user
    ptr=start; //set ptr equal to start
    while (strcmp(ptr -> fname,str) != 0){ //compare string from user is equal data in some node then will set ptr equal next
        ptr = ptr -> next;
        if(ptr == NULL) break; //if ptr is null will exit loop
    }
    if(ptr != NULL){ //if ptr isn't null will get data from user to change data into this node
        printf("Edit First Name : %s to : ", ptr -> fname);
        scanf("%s", ptr -> fname); //get first-name
        printf("Edit Last Name : %s to : ", ptr -> lname);
        scanf("%s", ptr -> lname); //get last-name
        printf("Edit Phone Number : %s to : ", ptr -> telnum);
        scanf("%s", ptr -> telnum); //get telnum
    } else{ //or return not match
        printf("No Matching Records Found ! \n");
    }
	return;
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
    scanf("%s", str);
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
            printf("Record Deleted.\n");
        }else{
            printf("Record not deleted.\n");
        }
    } else {
        printf("Not Matching Record Found.\n");
    }
    return;
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
		printf("------------------------------\n");
        printf("First name: %s \n", ptr -> fname);
        printf("Last name:%s \n", ptr -> lname);
        printf("Telephone No.: %s \n", ptr -> telnum);
        printf("------------------------------\n");
    }
    return;
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
                del();
                break;
            case 4:
                edit();
                break;
            case 5:
                disall();
                break;
        }
    }while (ch != 6);
}