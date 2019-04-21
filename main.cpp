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
node *start, *temp; //init start-pointer and temp-pointer -> สร้างพอยเตอร์ start และ temp

//------>insert data in to node<------//
void add(){
    node *ptr, *prev;  //define pointer ptr and prev -> สร้างพอยต์เตอร์ ptr และ prev
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
        while (strcmp(temp -> fname, ptr -> fname) > 0) { //compare the string in fname(temp) and fname(ptr) is not equal to 0 -> เปรียบเทียบ string ใน nodeว่าไม่เท่ากับ 0
            prev = ptr; //set an previous pointer equal to ptr -> ให้ pointer prev ชี้ไปที่เดียวกับ ptr
            ptr = ptr -> next; //set pointer equal to next pointer(null) -> ให้ ptr ชี้ไปที่โหนดถัดไป
            if (ptr == NULL) break; //if ptr pointer equal null exit the loop -> ถ้า ptr มีค่าเป็น null (ชี้ถัดไปเรื่อย ๆ จนไม่มีโหนดให้ชี้) ให้ออกจากลูป
        }
        if (ptr == prev) { //if ptr pointer equal to prev -> ถ้า ptr ชี้ไปที่เดียวกับ prev ให้ temp ชี้ไปที่เดียวกับ start แล้วให้ start มีค่าเป็น temp
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
    node *ptr; //define the  pointer ptr -> สร้างพอยเตอร์ ptr
    char str[20]; //define variable str is char length 20 character -> สร้างตัวแปรไว้เก็บข้อมูล string 20 ตัวอักษร
    if(start == NULL){ //if start equal null print "Directory is Empty" -> ถ้า start มีค่าเท่ากับ null ให้แสดงผลว่าไม่มีโหนด
        printf("Directory is Empty...");
        getch();
        return; //return to main function -> กลับไปที่ฟังก์ชั่น main
    }
    printf("First Name to Find : "); //print sentence to get name to search -> แสดงผลให้ป้อนชื่อสำหรับค้นหา
    scanf("%s",&str); //get string from user -> รับค่าจากผู้ใช้งาน
    ptr = start; //set ptr equal to start -> ให้ ptr ชี้ไปที่เดียวกับ start
    while (strcmp(ptr -> fname,str)!= 0){ //compare string from user is equal data in some node -> เปรียบเทียบ string กับในโหนด
        ptr = ptr -> next; //set ptr equal next -> ให้ ptr ชี้ไปที่โหนดเดียวกัน
        if(ptr == NULL) break; //if ptr is null exit loop -> ถ้า ptr มีค่าเท่ากับ null ให้ออกจากลูป
    }
    if(ptr != NULL){ //if ptr isn't null will print data from search name -> ถ้า ptr ไม่เท่ากับ null หรือค้นหาเจอให้แสดงข้อมูลในโหนดนั้น ๆ ออกมา
        printf("First Name : %s\n",ptr -> fname);
        printf("Last Name : %s\n",ptr -> lname);
        printf("Telephone Number : %s\n",ptr -> telnum);
    }else{ //or no match found will print some sentence -> ถ้า ptr เท่ากับ null ให้แสดงผลว่าไม่เจอ
        printf("No matching Record Found !\n");
    }
    getch();
	return; //return to main function -> กลับไปที่ main ฟังก์ชัน
}

//------>edit contact function<------//
void edit(){
    node *ptr; //define ptr pointer -> สร้าง ptr พอยเตอร์
    char str[20]; //define variable str to keep string has length 20 -> สร้างตัวแปรไว้เก็บจ้อมูล string ขนาก 20 ตัวอักษร
    if (start==NULL){ //if start pointer is null print some sentence -> ถ้า start มีค่าเป็น null ให้แสดงผลว่าไม่มีข้อมูล
        printf("Directory id Empty....\n");
        getch();
        return ; //return to main function -> กลับไปที่ main ฟังก์ชัน
    }
    printf("First Name to Edit is : "); //print some sentence -> แสดงผลให้กรอกข้อมูลเพื่อค้นหา
    scanf("%s",str); //get string data from user -> รับข้อมูลจากผู้ใช้งานแล้วเก็บในตัวแปร str
    ptr=start; //set ptr equal to start -> ให้ ptr ชี้ไปที่เดียวกับ start
    while (strcmp(ptr -> fname,str) != 0){ //compare string from user is equal data in some node then will set ptr equal next -> เปรียบเทียบ string ที่รับค่ามากับ node ทุก ๆ node จนกว่าจะหมด
        ptr = ptr -> next;
        if(ptr == NULL) break; //if ptr is null will exit loop -> เมื่อ ptr เท่ากับ null ให้ออกจาก loop
    }
    if(ptr != NULL){ //if ptr isn't null will get data from user to change data into this node -> ถ้า ptr ไม่เท่ากับ null ให้แสดงผลข้อมุลในโหยดออกมาแล้วรับค่าจากผู้ใช้เข้าไปแทนที่ในโหนด
        printf("Edit First Name : %s to : ", ptr -> fname);
        scanf("%s", ptr -> fname); //get first-name
        printf("Edit Last Name : %s to : ", ptr -> lname);
        scanf("%s", ptr -> lname); //get last-name
        printf("Edit Phone Number : %s to : ", ptr -> telnum);
        scanf("%s", ptr -> telnum); //get telnum
    } else{ //or return not match -> ถ้าหาไม่เจอให้แสดงผลว่าไม่มีอะไรที่เหมือนกับคำที่ค้นหา
        printf("No Matching Records Found ! \n");
    }
	return; //return to main function -> กลับไปที่ main ฟังก์ชัน
    getch(); 
}

//------>delete contact function<------//
void del(){
    node *ptr, *prev, *temp; //define pointer ptr prev and temp
    char str[20], yn = 'n'; //create str variable to keep 20 charector and yn to keep accept answer
    if (start == NULL){ //if start pointer is equal null
        printf("Directory is Empty. \n"); //print "Directory is empty."
        getch();
        return; //return to main function
    }
    printf("First Name to Delete : "); //show some sentence 
    scanf("%s", str); //keep fname into str
    prev = ptr = start; //set pointer prev ptr same start
    while (strcmp(ptr -> fname, str) != 0){ //compare string to all node 
        prev = ptr; //set prev equal to ptr
        ptr = ptr -> next; //set ptr is next
        if (ptr == NULL) break; //if ptr equal null will exit loop
    }
    if (ptr != NULL){ //if ptr is not null 
        printf("\n\n---------------------------------------------------------\n");
        printf("First Name : %s\n",ptr -> fname);
        printf("Last Name : %s\n",ptr -> lname);
        printf("Phone Number : %s\n",ptr -> telnum);
        printf("---------------------------------------------------------\n\n");
		printf("Are you sure to delete this record ? [y/n] : "); //ask to delete
        yn = getch(); //get yn value
        if(yn == 'y'){ //if answer y will delete node
            if (ptr == start) {
                temp = start -> next;
                free(start);
                start = temp;
            } else {
                temp = ptr -> next;
                free (start);
                prev -> next = temp;
            }
            printf("Record Deleted.\n"); //print record is delete
        }else{
            printf("Record not deleted.\n"); //else is not delete will answer n
        }
    } else {
        printf("Not Matching Record Found.\n"); //or not match string
    }
    return; //return to main function
    getch();
}

//------>display all record<------//
void disall(){ 
    node *ptr; //define ptr i pointer
    if(start == NULL){ //if start equal null will show "Directory is Empty"
        printf("Directory is Empty.\n");
        return;
    }
    for(ptr = start; ptr != NULL; ptr = ptr -> next){ //loop to read data from all node 
		printf("------------------------------\n");
        printf("First name: %s \n", ptr -> fname); //show fname o this node
        printf("Last name:%s \n", ptr -> lname); //show lname from this node
        printf("Telephone No.: %s \n", ptr -> telnum); //show telnum from this node
        printf("------------------------------\n");
    }
    return; //return to main function
    getch();
}

//------>main menu function<------//
int menu(){
    int select_menu; //build select_menu to keep integer
	//display show menu
    printf("\n 1. Add contact to your phonebook.\n");
    printf(" 2. Find contact in your phonebook.\n");
    printf(" 3. Delete contact from your phonebook.\n");
    printf(" 4. Edit contact information.\n");
    printf(" 5. Display all your contact.\n");
    printf(" 6. EXIT\n");
    printf("Enter your choice (1-6) : ");
    scanf("%d", &select_menu); //keep integer to select_menu variable
    return select_menu; //return value
}

int main() {
    int ch; //define variable to keep value from menu function
    start = (node *)malloc(sizeof(node));
    start = NULL;
	//do while loop to run program
    do{
        ch=menu(); //get value from menu function
		//switch-case function
        switch (ch) {
            case 1: //when value is 1 do add() function
                add();
                break; //exit to menu
            case 2: //when value is 2 do find() function
                find(); 
                break;
            case 3: //when value is 3 do del() function
                del();
                break;
            case 4: //when value is 4 do edit() function
                edit();
                break;
            case 5: //when value is 5 do diall() function
                disall();
                break;
				//if value is equal 6 will end program
        }
    }while (ch != 6); //loop to how menu if value is not equal to 6
}