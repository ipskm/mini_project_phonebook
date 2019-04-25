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
    temp = (node *)malloc(sizeof(node)); //reserve space in RAM for temp -> จองพื้นที่ในแรมสำหรับ temp
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
    node *ptr, *prev, *temp; //define pointer ptr prev and temp -> สร้างพอยเตอร์ prev ptr และ temp
    char str[20], yn = 'n'; //create str variable to keep 20 charector and yn to keep accept answer -> สร้างตัวแปรไว้เก็บข้อมูลตัวอักษร 20 ตัว และสร้างตัวแปรเก็บค่าการตอบ
    if (start == NULL){ //if start pointer is equal null -> เมื่อ start เป็น null หมายถึงว่่าไม่มีโหนดใด ๆ ที่บันทึกในโปรแกรม
        printf("Directory is Empty. \n"); //print "Directory is empty." -> แสดงข้อความว่าไม่มีข้อมูล
        getch();
        return; //return to main function -> กลับไปที่ฟังก์ชันหลัก
    }
    printf("First Name to Delete : "); //show some sentence -> แสดงข้อความว่าให้กรอกข้อมูลเพื่อค้นหาชื่อที่ต้องการลบ
    scanf("%s", str); //keep fname into str -> รับค่าจากผู้ใช้งานและเก็บไว้ที่ตัวแปร str
    prev = ptr = start; //set pointer prev ptr same start -> ให้ทั้ง 3 พอยเตอร์มีค่าเท่ากับเพื่อเริ่มการค้นหาจากโหนดแรก
    while (strcmp(ptr -> fname, str) != 0){ //compare string to all node -> ลูปการเปรียบเทียบข้อมูลในโหนดนั้น ๆ 
        prev = ptr; //set prev equal to ptr -> ให้ ค่าของ prev มีค่าเท่ากับ ptr หรือพอยเตอร์ที่ชี้กับโหนด
        ptr = ptr -> next; //set ptr is next -> ให้ ptr ชี้ไปที่โหนดถัดไป
        if (ptr == NULL) break; //if ptr equal null will exit loop -> ถ้า ptr ไม่มีโหนดให้ชี้ต่อไปให้ออกจากลูป
    }
    if (ptr != NULL){ //if ptr is not null  -> ถ้า ptr ไม่เท่ากับ null หรือค้นหาเจอให้แสดงผลข้อมูลจากโหนดนั้น ๆ 
        printf("\n\n---------------------------------------------------------\n");
        printf("First Name : %s\n",ptr -> fname);
        printf("Last Name : %s\n",ptr -> lname);
        printf("Phone Number : %s\n",ptr -> telnum);
        printf("---------------------------------------------------------\n\n");
		printf("Are you sure to delete this record ? [y/n] : "); //ask to delete -> ถามเพื่อความมั่นใจว่าจะทำการลบข้อมูลออก
        yn = getch(); //get yn value -> รับค่าจากผู้ใช้งาน
        if(yn == 'y'){ //if answer y will delete node -> ถ้าตอบว่าใช่ให้ทำการลบโหนดนั้น ๆ ทิ้งไป
            if (ptr == start) {
                temp = start -> next;
                free(start);
                start = temp;
            } else {
                temp = ptr -> next;
                free (start);
                prev -> next = temp;
            }
            printf("Record Deleted.\n"); //print record is delete -> แสดงผลว่าได้ทำการลบออกเรียบร้อยแล้ว
        }else{
            printf("Record not deleted.\n"); //else is not delete will answer n -> ถ้าตอบว่าไม่จะแสดงผลออกมาว่าไม่ได้ทำการลบข้อมูลนั้น ๆ ออก
        }
    } else {
        printf("Not Matching Record Found.\n"); //or not match string -> กรณีที่ไม่สามารถค้นหาได้หรือไม่ตรงกับข้อมูลใด ๆ ในโปรแกรม
    }
    return; //return to main function -> กลับไปที่ฟังก์ชันหลัก
    getch();
}

//------>display all record<------//
void disall(){ 
    node *ptr; //define ptr pointer -> สร้างพอยเตอร์ ptr
    if(start == NULL){ //if start equal null will show "Directory is Empty" -> กรณีที่ไม่มีข้อมูลในโปรแกรมจะแสดงผลออกมาว่าไม่มีข้อมูลและกลับไปที่ฟังก์ชันหลัก
        printf("Directory is Empty.\n");
        return;
    }
    for(ptr = start; ptr != NULL; ptr = ptr -> next){ //loop to read data from all node -> วงวนการแสดงผลข้อมูลในโหนดทั้งหมดที่มีในโปรแกรม
		printf("------------------------------\n");
        printf("First name: %s \n", ptr -> fname); //show fname from this node -> แสดงชื่อ
        printf("Last name:%s \n", ptr -> lname); //show lname from this node -> แสดงนามสกุล
        printf("Telephone No.: %s \n", ptr -> telnum); //show telnum from this node -> แสดงเบอร์โทรศัพท์
        printf("------------------------------\n");
    }
    return; //return to main function -> กลับไปที่ฟังก์ชันหลัก
    getch();
}

//------>main menu function<------//
int menu(){
    int select_menu; //build select_menu to keep integer -> สร้างตัวแปรเพื่อเก็บค่าจากผู้ใช้งาน
	//display show menu -> แสดงผลเมนูหลักให้ผู้ใช้งาน
    printf("\n 1. Add contact to your phonebook.\n");
    printf(" 2. Find contact in your phonebook.\n");
    printf(" 3. Delete contact from your phonebook.\n");
    printf(" 4. Edit contact information.\n");
    printf(" 5. Display all your contact.\n");
    printf(" 6. EXIT\n");
    printf("Enter your choice (1-6) : ");
    scanf("%d", &select_menu); //keep integer to select_menu variable -> รับค่าตัวเลขเมนูจากผู้ใช้งาน
    return select_menu; //return value -> ส่งค่ากลับออกไปจากฟังก์ชัน
}

int main() {
    int ch; //define variable to keep value from menu function -> สร้างตัวแปรเพื่อรับค่าจากฟังก์ชันเมนูหลัก
    start = (node *)malloc(sizeof(node)); //reserve space in RAM for start -> จองพื้นที่ในแรมสำหรับ start
    start = NULL;
	//do while loop to run program -> วงวนหลักของการทำงานในโปรแกรมโดยการแสดงผลวนไปเรื่อย ๆ จนกว่าค่าที่ได้รับเป็น 6
    do{
        ch=menu(); //get value from menu function -> เรียกใช้งานฟังก์ชันเมนูเพื่อรับค่าจากฟังก์ชันมาเก็บไว้ในตัวแปร
		//switch-case function -> เรียกใช้งานฟังก์ชันการเลือกตามเคสต่าง ๆ 
        switch (ch) {
            case 1: //when value is 1 do add() function -> เมื่อค่าจากฟังก์ชั่นเมนูเป็น 1 เรียกใช้งานฟังก์ชันการเพิ่มรายชื่อ
                add();
                break; //exit to menu -> เมื่อจบการทำงานที่ฟังก์ชันจะออกจากเคสเข้าสูฟังก์ชันเมนูเพื่อรอรับค่าต่อไป
            case 2: //when value is 2 do find() function -> เมื่อค่าจากฟังก์ชั่นเมนูเป็น 2 เรียกใช้งานฟังก์ชันการค้นหารายชื่อ
                find(); 
                break; //exit to menu -> เมื่อจบการทำงานที่ฟังก์ชันจะออกจากเคสเข้าสูฟังก์ชันเมนูเพื่อรอรับค่าต่อไป
            case 3: //when value is 3 do del() function -> เมื่อค่าจากฟังก์ชั่นเมนูเป็น 3 เรียกใช้งานฟังก์ชันการลบรายชื่อ
                del();
                break; //exit to menu -> เมื่อจบการทำงานที่ฟังก์ชันจะออกจากเคสเข้าสูฟังก์ชันเมนูเพื่อรอรับค่าต่อไป
            case 4: //when value is 4 do edit() function -> เมื่อค่าจากฟังก์ชั่นเมนูเป็น 4 เรียกใช้งานฟังก์ชันการแก้ไขรายชื่อ
                edit();
                break; //exit to menu -> เมื่อจบการทำงานที่ฟังก์ชันจะออกจากเคสเข้าสูฟังก์ชันเมนูเพื่อรอรับค่าต่อไป
            case 5: //when value is 5 do diall() function -> เมื่อค่าจากฟังก์ชั่นเมนูเป็น 5 เรียกใช้งานฟังก์ชันการแสดงรายชื่อทั้งหมดที่มี
                disall();
                break; //exit to menu -> เมื่อจบการทำงานที่ฟังก์ชันจะออกจากเคสเข้าสูฟังก์ชันเมนูเพื่อรอรับค่าต่อไป
				//if value is equal 6 will end program -> เมื่อค่าจากฟังก์ชั่นเมนูเป็น 6 จะสิ้นสุดการทำงานของโปรแกรม
        }
    }while (ch != 6); //loop to how menu if value is not equal to 6 -> วงวนจะทำงานไปเรื่อย ๆ เมื่อทุกค่าที่รับเข้ามาไม่เท่ากับ 6
}

//Coding by ipskm 