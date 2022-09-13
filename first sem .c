/* ######################################################################################
   ##********************	Entrance Examination Software   ***************************##
   ##							                                                       ##
   ##							PURBANCHAL UNIVERSITY                                  ##
   ##															  	       BIT I       ##
   ## Submitted to:- Kantipur City College       Prepared by:- John Subba, Bipul Shahi ##
   ######################################################################################	*/


#include<stdio.h>
#include<conio.h> //only for using getch() function    
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<pthread.h>

pthread_mutex_t mut1,mut2; //for creating a mutex lock on exit flag.
int time_to_exit=0;   // this global variable is the exit flag.

typedef struct exam_qn{  //to store question with its num.
	int qn_num;
	char question[400];
}exam;

typedef struct qn_answer{ //to store answer with its option and correct ans.
	int qn_num_ans;
	char answer[4][50];
	char correct_ans;
	
}ans;

typedef struct date_f{ //to store date from time library
	int year;
	char month[10];
	int day;
}d1;

typedef struct std_exam_performance{ //to store all required details of a std after exam.
	int std_num;
	int std_reg;
	char std_name[50];
	int std_score;
	char exam_taken[5];
	d1 exam_date;
	char result[5];
	
}exam_report;

typedef struct std_details{ //to store student details when adding them in database.
	int std_num;
	char std_name[40];
	int std_regi_num;
	char std_faculty[40];

}S;

typedef struct time_marks{
	int time;
	int pass_marks;
	int full_marks;
	int total_ques;
}tm;

//below is the list of all the functions used.
 
void rectangle_box();            //these functions are for drawing tables.
void second_rectangle_box();    
void result_table();
void detail_table();
void detail_table_2();
void timer_rectangle_box();
void coord_xy(short x, short y);
void Intro_page();


void admin_menu();           //these functions are for login.
void second_admin_menu();
void student_menu(char[],int);
char Admin_Login_prompt();
void Student_Login_prompt();


void student_details_add();  //these are functions related to add/remove,update,view of stds details.
void student_details_remove();
void student_details_update();
void student_details_viewer();
void student_exam_rank();
void student_detail_analyzer();
void exam_time_set();


void question_viewer();  //these are functions related to questions and answers modification.
void question_creator();
void question_add();
void question_modifier();
void answer_sheet_create_modify();


char Exam_instruction(); //these are functions related to exam.
void Exam_instruction_create();
void Student_exam(char[],int);
void rand1(int k, int *qn_arr1); //to generate random number and store in the provided array
void Qn_exam_display(int);
void exam_answer_display(int);
void exam_start_2(int *qn_arr1, char *ans_store);


void *date(d1 *);  // these are functions related to date and timer of exam.
void display_date();
void *timer1(void *time);


//#####################################################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
void main(){    //program starts here.                                                               
	coord_xy(40,15);                                                                                
    char menu_num;
	getchar();
    rectangle_box();
    fflush(stdin);
    Intro_page();
    system("cls");
    Entry:
        rectangle_box();
        coord_xy(40,2);
        printf(" ~~~~~~~~~~~~~~~~~~~~~~"); 
        coord_xy(40,3);
        printf(" Choose from the menu:\n");
        coord_xy(40,4);
        printf(" ~~~~~~~~~~~~~~~~~~~~~~");
        coord_xy(7,8);
        printf("----------------");
        coord_xy(7,9);printf("Admin Menu: [1]");
        coord_xy(7,10);
        printf("----------------");
        coord_xy(79,8);
        printf("-----------------");
        coord_xy(79,9);
        printf("Student Menu: [2]");
        coord_xy(79,10);
        printf("-----------------");
        coord_xy(79,14);
        printf("-----------------");
        coord_xy(79,15);
        printf("Exit Program: [3]");
        coord_xy(79,16);
        printf("-----------------");
        coord_xy(7,19);
        printf("----------------------------------");
        coord_xy(7,20);
        printf("Enter the desired menu number: ");
        coord_xy(7,21);
        printf("----------------------------------");
        coord_xy(38,20);
		scanf("%c",&menu_num);
        fflush(stdin);
        switch(menu_num){
            case '1':
                system("cls");
                fflush(stdin);
                switch(Admin_Login_prompt()){
                    case '6':
                        system("cls");
                        admin_menu();
                        break;
                    case '7':
                        exit(0);
                    	break;}
            case '2':
                system("cls");
                fflush(stdin);
                Student_Login_prompt();
                break;
            case '3':
                system("cls");
                exit(0);
            default:
                coord_xy(38,20);
                printf("                     ");
                goto Entry;}

	coord_xy(0,27);
	
} // program ends here.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#######################################################################################################



//number 1. //function to create main rectangle box.
void rectangle_box(){
	int x,y;
	coord_xy(5,2);display_date();
	coord_xy(1,1);
	printf("%c\n",201);
	for(y=2;y<25;y++){
		coord_xy(1,y);
		printf("%c\n",186);
	}
	coord_xy(1,25);
	printf("%c",200);
	for(x=2;x<110;x++){
		coord_xy(x,y);
		printf("%c\n",205);
	}
	coord_xy(110,25);
	printf("%c",188);
	for(y=24;y>=2;y--){
		coord_xy(110,y);
		printf("%c\n",186);
	}
	coord_xy(110,1);
	printf("%c",187);
	for(x=109;x>1;x--){
		coord_xy(x,y);
		printf("%c\n",205);
	}

}

//number 2. //function to create a rectangle box of different design.
void second_rectangle_box(){
	int x,y;
	for(y=6;y<=20;y++){
		coord_xy(5,y);
		printf("%c\n",219);
	}

	for(x=6;x<=106;x++){
		coord_xy(x,20);
		printf("%c\n",220);
		coord_xy(x,15);printf("%c",205);
	}
	coord_xy(106,20);
	printf("%c",219);
	for(y=20;y>6;y--){
		coord_xy(106,y);
		printf("%c\n",219);
	}
	coord_xy(106,6);
	printf("%c",220);
	for(x=106;x>=5;x--){
		coord_xy(x,y);
		printf("%c\n",220);
	}

}

//number 3. //function for custom coordinates for the cursor position.
void coord_xy(short x, short y)       //definition of goto xy coordinate function
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//number 4. //function to display admin login and provide access or not.
char Admin_Login_prompt(){
    char student_name[20]="admin", password[20]="admin", id[20], p[20],c;
    int n=1, x, y,i=0;

    while (n<=5){
        rectangle_box();
        coord_xy(40,5);
        printf("-----------------------------");
        coord_xy(40,6);
        printf("Admin Login Id: ");
        coord_xy(40,7);
        printf("-----------------------------");
        coord_xy(40,8);
        printf("Admin Password: ");
        coord_xy(40,9);
        printf("-----------------------------");
        coord_xy(57,6);
		scanf("%[^\n]", &id);
        fflush(stdin);
		do{
			coord_xy(57+i,8);
			c=getch();
			if(c==8){
				i--;
				coord_xy(57+i,8);printf(" ");
				continue;
			}
			p[i]=c;
			coord_xy(57+i,8);printf("*");
			i++;
			if(c=='\r'){
				coord_xy(57+(i-1),8);printf(" ");
			}
		}while(c!='\r'); 
		coord_xy(57+(i-1),8);             
		p[i-1]='\0'; //to let compiler know the end of char stored in p.
		i=0;
        fflush(stdin);

    	x=strcmp(id, student_name);
        y=strcmp(p, password);
    	if(x==0 && y==0){
        coord_xy(40,11);
        printf("Logged In Sucessfully!");
        coord_xy(65,11);getchar();
    	return '6';
        }
		else {
        coord_xy(40,12);
    	printf("Wrong Password! Try again!!!");
    	coord_xy(40,14);
    	printf("Attempts remaining: %d\n", 5-n);
    	coord_xy(57,6);
        getchar();
        n++;}
        system("cls");

        if(n>5){
        coord_xy(40,6);
        printf("Access Denied!!!");
        Sleep(2);
        return '7';
        }
       };
       
}

//number 5. //function to display second admin menu.
void second_admin_menu(){
	system("cls");
	fflush(stdin);
    char admin_menu_num_2;
	second:
		rectangle_box();
		coord_xy(40,2);
    	printf("-----------------------------");
    	coord_xy(40,3);
		printf("Choose Number from the menu:");
		coord_xy(40,4);
		printf("-----------------------------");
		coord_xy(5,7);
		printf("Write Instructions for Students:   [1]");
		coord_xy(5,9);
		printf("Student Details Analysis:          [2]");
		coord_xy(70,7);
		printf("Exam Rank Analysis:                  [4]");
		coord_xy(70,9);
		printf("Create/Update/Add in Answer sheet:   [5]");
		coord_xy(70,11);
		printf("Add Questions to Question Bank:      [6]");
		coord_xy(5,11);
		printf("Allocate Time and Marks for Exam:  [3]");
		coord_xy(70,21);printf("-------------------------");
		coord_xy(70,22);printf("Go to previous Menu  [7]");
		coord_xy(70,23);printf("-------------------------");
		coord_xy(5,21);printf("-------------------------------");
		coord_xy(5,22);printf("Enter your choice character: ");
		coord_xy(5,23);printf("-------------------------------");
		coord_xy(34,22);scanf("%c",&admin_menu_num_2);
		switch(admin_menu_num_2){
			case '1':
            	system("cls");
            	fflush(stdin);
            	Exam_instruction_create();
            	fflush(stdin);
            	system("cls");
            	goto second;
        	case '2':
            	system("cls");
            	student_detail_analyzer();
            	fflush(stdin);
            	system("cls");
            	goto second;
        	case '3':
	            system("cls");
	            exam_time_set();
	            fflush(stdin);
	            system("cls");
	            goto second;
        	case '4':
	            system("cls");
	            student_exam_rank();
	            fflush(stdin);
	            system("cls");
	            goto second;
        	case '5':
	            system("cls");
	            answer_sheet_create_modify();
	            fflush(stdin);
	            system("cls");
	            goto second;
	        case '6':
	        	system("cls");
	        	question_add();
	        	fflush(stdin);
	        	system("cls");
	        	goto second;
	        case '7':
	        	system("cls");
	        	admin_menu();
	        	fflush(stdin);
	        	system("cls");
	        	goto second;
	        default:
	        	coord_xy(34,22);printf("           ");
	        	goto second;

	}
	coord_xy(0,27);

}

//number 6. //function to display first admin menu.
void admin_menu(){
	fflush(stdin);
    char admin_menu_num;
    first:
    	rectangle_box();
    	coord_xy(40,2);
    	printf("-----------------------------");
    	coord_xy(40,3);
		printf("Choose Number from the menu:");
		coord_xy(40,4);
		printf("-----------------------------");
		coord_xy(5,7);
		printf("Add Student details:              [1]");
		coord_xy(5,9);
		printf("Remove Student details:           [2]");
		coord_xy(5,11);
		printf("View Student details:             [3]");
		coord_xy(5,13);
		printf("Update Existing Student details:  [4]");
		coord_xy(70,7);
		printf("View Exam Question bank:         [5]");
		coord_xy(70,9);
		printf("Create New Exam Question bank:   [6]");
		coord_xy(70,11);
		printf("Modify Existing Question bank:   [7]");
		coord_xy(70,13);
		printf("Exit Admin Menu:                 [8]");
		coord_xy(70,21);printf("---------------------");
		coord_xy(70,22);printf("Go to Next Menu  [9]");
		coord_xy(70,23);printf("---------------------");
		coord_xy(5,21);printf("-------------------------------");
		coord_xy(5,22);printf("Enter your choice character: ");
		coord_xy(5,23);printf("-------------------------------");
		coord_xy(34,22);scanf("%c",&admin_menu_num);
		switch(admin_menu_num){
        	case '1':
            	system("cls");
            	fflush(stdin);
            	student_details_add();
            	coord_xy(40,18);printf("Details successfully added...");
            	getchar();
            	fflush(stdin);
            	system("cls");
            	goto first;
        	case '2':
            	system("cls");
            	student_details_remove();
            	fflush(stdin);
            	system("cls");
            	goto first;
        	case '3':
	            system("cls");
	            student_details_viewer();
	            fflush(stdin);
	            system("cls");
	            goto first;
        	case '4':
	            system("cls");
	            student_details_update();
	            system("cls");
	            fflush(stdin);
	            rectangle_box();
	            fflush(stdin);
	            system("cls");
	            goto first;
        	case '5':
	            system("cls");
	            question_viewer();
	            fflush(stdin);
	            system("cls");
	            goto first;
			case '6':
	            system("cls");
	            question_creator();
	            fflush(stdin);
	            system("cls");
	            goto first;
	        case '7':
	            system("cls");
	            question_modifier();
	            fflush(stdin);
	            system("cls");
	            goto first;
	        case '8':
	            system("cls");
	            exit(0);
	        case '9':
	            system("cls");
	            second_admin_menu();
	            fflush(stdin);
	            break;
	        default:
	        	coord_xy(34,22);printf("             ");
	        	goto first;

	}
	coord_xy(0,27);

}

//number 7. //function to add students details in a file.
void student_details_add(){
	S s1,s2;
	int count=0;
	FILE *file = fopen("Student_details.bin","rb");
	while(fread(&s1,sizeof(s1),1,file)>0){
		if(count<s1.std_num){
			count=s1.std_num;
		}	
	}
	fclose(file);
	rectangle_box();
	coord_xy(42,2);printf("Add Student Details");
	coord_xy(42,3);printf("~~~~~~~~~~~~~~~~~~~");
	coord_xy(81,5);
	fflush(stdin);
	printf("Total Students till now: %d",count);
	fflush(stdin);
	coord_xy(39,9);printf("___________________________________________________");
	coord_xy(40,10);printf("Enter Student name: ");
	fflush(stdin);
	coord_xy(39,11);printf("___________________________________________________");
	coord_xy(40,12);
	printf("Enter Student faculty: ");
	fflush(stdin);
	coord_xy(39,13);printf("___________________________________________________");
	coord_xy(40,14);
	printf("Enter Student Symbol number: ");
	fflush(stdin);
	coord_xy(39,15);printf("___________________________________________________");
	coord_xy(70,10);scanf("%[^\n]",&s1.std_name);fflush(stdin);
	coord_xy(70,12);scanf("%[^\n]",&s1.std_faculty);fflush(stdin);
	diff_regis_num:
		coord_xy(70,14);printf("                     ");
		coord_xy(70,14);scanf("%d",&s1.std_regi_num);fflush(stdin);
		file = fopen("Student_details.bin","rb");
		while(fread(&s2,sizeof(s2),1,file)>0){
			if(s1.std_regi_num==s2.std_regi_num){
				coord_xy(40,16);printf("Same Registration Number cannot exits!\n");
				goto diff_regis_num;
					}	
				}
	fclose(file);
	file = fopen("Student_details.bin","ab");
	s1.std_num=count+1;
	fwrite(&s1,sizeof(s1),1,file);
	fclose(file);
}

//number 8. //functions to view students details from students file.
void student_details_viewer(){
    detail_table();
    coord_xy(42,2);printf("Student Details Table");
	coord_xy(42,3);printf("~~~~~~~~~~~~~~~~~~~~~");
	coord_xy(7,5);printf("Number: ");
	coord_xy(22,5);printf("Student Name: ");
	coord_xy(52,5);printf("Faculty: ");
	coord_xy(84,5);printf("Symbol no.:");
	S s1;
	int count=0;
	FILE *file1 = fopen("Student_details.bin","rb");
    while(fread(&s1,sizeof(s1),1,file1)>0){
    	if(count>17){
    		fflush(stdin);
			getchar();
			system("cls");
			detail_table();       
		    coord_xy(42,2);printf("Student Details Table");
			coord_xy(42,3);printf("~~~~~~~~~~~~~~~~~~~~~");
			coord_xy(7,5);printf("Number: ");
			coord_xy(22,5);printf("Student Name: ");
			coord_xy(52,5);printf("Faculty: ");
			coord_xy(84,5);printf("Symbol no.:");
			count=0;		
		}
		coord_xy(7,7+count);printf("%d",s1.std_num);
		coord_xy(22,7+count);printf("%s",s1.std_name);
		coord_xy(52,7+count);printf("%s",s1.std_faculty);
		coord_xy(85,7+count);printf("%d",s1.std_regi_num);
		count=count+2;
		}
		fflush(stdin);
		getchar();
        coord_xy(27,27);

	fclose(file1);
}

//number 9. // function to remove details of the students searching through name.
void student_details_remove(){
	system("cls");
	rectangle_box();
	coord_xy(42,2);printf("Remove Student Details");
	coord_xy(42,3);printf("~~~~~~~~~~~~~~~~~~~~~~");
	fflush(stdin);
	int flag1=0,numofstd=0;
	char temp;
	S s1;
	FILE *fupdate_o,*fupdate_n;
	char name[20];
	coord_xy(17,5);printf("Enter the Student name to search and delete: ");
	coord_xy(62,5);scanf("%[^\n]",&name);fflush(stdin);
	fupdate_o=fopen("Student_details.bin","rb");
	fupdate_n=fopen("Student_details_new.bin","wb");
	while(fread(&s1,sizeof(s1),1,fupdate_o)>0){
		if(strcmp(name,s1.std_name)==0){	
			flag1++;
			coord_xy(42,21);printf("                          ");
			coord_xy(32,8);printf("Record found of this name:");
			coord_xy(32,9);printf("______________________________________");
			coord_xy(56,10);printf("                ");
			coord_xy(32,10);printf("Student Num:            %d",s1.std_num);
			coord_xy(32,11);printf("______________________________________");
			coord_xy(56,12);printf("                          ");
			coord_xy(32,12);printf("Student name:           %s",s1.std_name);
			coord_xy(32,13);printf("______________________________________");
			coord_xy(55,14);printf("                                    ");
			coord_xy(32,14);printf("Student Faculty:        %s",s1.std_faculty);
			coord_xy(32,15);printf("______________________________________");
			coord_xy(56,16);printf("                ");
			coord_xy(32,16);printf("Student Symbol Number:  %d",s1.std_regi_num);
			coord_xy(32,17);printf("______________________________________");
			coord_xy(32,19);printf("Confirm to delete(y/n): ");
			coord_xy(57,19);printf("   ");
			coord_xy(57,19);scanf("%c",&temp);fflush(stdin);
			if(temp=='y'||temp=='Y'){
				fflush(stdin);
				coord_xy(42,21);printf("Now record is deleted!");
				getchar();
				numofstd=s1.std_num;
				continue;}
			else{
				coord_xy(42,21);printf("Record not deleted!");
				getchar();
				fwrite(&s1,sizeof(s1),1,fupdate_n);
				}
		}
		else{
			if(flag1==1){
				s1.std_num=numofstd;
				numofstd++;
			}
			fwrite(&s1,sizeof(s1),1,fupdate_n);	
		}
	}
	if(flag1==0){
		coord_xy(40,14);printf("Name not found in the record!");
		getchar();}
	fclose(fupdate_n);
	fclose(fupdate_o);
	remove("Student_details.bin");
	rename("Student_details_new.bin","Student_details.bin");	
}

//number 10. //functions to update the students details searching through name.
void student_details_update(){
	system("cls");
	rectangle_box();
	coord_xy(42,2);printf("Update Student Details");
	coord_xy(42,3);printf("~~~~~~~~~~~~~~~~~~~~~~");
	fflush(stdin);
	int flag1=0;
	S s1,s_temp;
	FILE *fupdate_o,*fupdate_n, *fupdate_duplicate;
	char name[20];
	coord_xy(17,5);printf("Enter the Student name to search and update: ");
	coord_xy(62,5);scanf("%[^\n]",&name);fflush(stdin);
	fupdate_o=fopen("Student_details.bin","rb");
	fupdate_n=fopen("Student_details_new.bin","wb");
	while(fread(&s1,sizeof(s1),1,fupdate_o)>0){
		if(strcmp(name,s1.std_name)==0){	
			flag1++;
			coord_xy(32,7);printf("Record found of this name:");
			coord_xy(32,8);printf("______________________________________");
			coord_xy(44,9);printf("                ");
			coord_xy(32,9);printf("Student Num:           %d",s1.std_num);
			coord_xy(32,10);printf("______________________________________");
			coord_xy(55,11);printf("                ");
			coord_xy(32,11);printf("Student name:          %s",s1.std_name);
			coord_xy(32,12);printf("______________________________________");
			coord_xy(55,13);printf("                ");
			coord_xy(32,13);printf("Student Faculty:       %s",s1.std_faculty);
			coord_xy(32,14);printf("______________________________________");
			coord_xy(55,15);printf("                ");
			coord_xy(32,15);printf("Student Symbol Number: %d",s1.std_regi_num);
			coord_xy(32,16);printf("______________________________________");
			coord_xy(32,18);printf("Enter New details for this Student: ");
			coord_xy(32,19);printf("______________________________________");
			coord_xy(55,20);printf("                ");
			coord_xy(32,20);printf("Student name: ");
			coord_xy(32,21);printf("______________________________________");
			coord_xy(55,22);printf("                ");
			coord_xy(32,22);printf("Student Faculty: ");
			coord_xy(32,23);printf("______________________________________");
			coord_xy(55,24);printf("                ");
			coord_xy(32,24);printf("Student Symbol Number: ");fflush(stdin);
			coord_xy(55,20);scanf("%[^\n]",&s1.std_name);fflush(stdin);
			coord_xy(55,22);scanf("%[^\n]",&s1.std_faculty);fflush(stdin);
			new_registration_number:
				coord_xy(55,24);printf("                          ");
				coord_xy(55,24);scanf("%d",&s1.std_regi_num);fflush(stdin);
				fupdate_duplicate=fopen("Student_details.bin","rb");
				while(fread(&s_temp,sizeof(s_temp),1,fupdate_duplicate)>0){
					if(s1.std_regi_num==s_temp.std_regi_num){
						coord_xy(35,27);printf("Updated details cannot have duplicate registration number!\n");
						fclose(fupdate_duplicate);
						goto new_registration_number;
					}
				
				}
			fwrite(&s1,sizeof(s1),1,fupdate_n);
			coord_xy(35,27);printf("                                                                           ");
			coord_xy(42,27);printf("Record Updated...");
			fclose(fupdate_duplicate);
			getchar();
		}
		else{
			fwrite(&s1,sizeof(s1),1,fupdate_n);	
		}
	}
	if(flag1==0){
		coord_xy(42,14);printf("Name not found in the record!");
		getchar();}
	fclose(fupdate_n);
	fclose(fupdate_o);
	remove("Student_details.bin");
	rename("Student_details_new.bin","Student_details.bin");	
}

//number 11. //functions to analyze the details of student exam report.
void student_detail_analyzer(){
	system("cls");
	exam_report s1;
	int count=0;
	FILE *file1;
	file1 = fopen("Student_exam_Performance.bin","rb");
	first:
		rectangle_box();
		detail_table_2();
		coord_xy(42,2);printf("Student Details Analysis");
		coord_xy(42,3);printf("~~~~~~~~~~~~~~~~~~~~~~~~");
		coord_xy(7,5);printf("Student Name: ");
		coord_xy(27,5);printf("Symbol no.: ");
		coord_xy(42,5);printf("Exam Taken: ");
		coord_xy(57,5);printf("Result: ");
		coord_xy(72,5);printf("Exam taken Date:");
		coord_xy(92,5);printf("Marks:");
		count=0;
		while(fread(&s1,sizeof(s1),1,file1)>0){
    	if(count>17){
    		fflush(stdin);
			getchar();
			system("cls");
			detail_table_2();       
		    coord_xy(42,2);printf("Student Details Analysis");
			coord_xy(42,3);printf("~~~~~~~~~~~~~~~~~~~~~~~~");
			coord_xy(7,5);printf("Student Name: ");
			coord_xy(27,5);printf("Symbol no.: ");
			coord_xy(42,5);printf("Exam Taken: ");
			coord_xy(57,5);printf("Result: ");
			coord_xy(72,5);printf("Exam taken Date:");
			coord_xy(92,5);printf("Marks:");
			count=0;		
		}
		coord_xy(7,7+count);printf("%s",s1.std_name);
		coord_xy(27,7+count);printf("%d",s1.std_reg);
		coord_xy(42,7+count);printf("%s",s1.exam_taken);
		coord_xy(57,7+count);printf("%s",s1.result);
		coord_xy(72,7+count);printf("%s %d, %d",s1.exam_date.month,s1.exam_date.day,s1.exam_date.year);
		coord_xy(92,7+count);printf("%d",s1.std_score); 
		count=count+2;
	}
	fflush(stdin);
	getchar();
	fclose(file1);		
				
}

//number 12. //functions to view the questions.
void question_viewer(){
	fflush(stdin);
	int y_axis=5,qn_count=0,i,flag=0;
    rectangle_box();
    coord_xy(40,2);printf("---------------");
    coord_xy(40,3);printf("Questions List:");
    coord_xy(40,4);printf("---------------");
    exam E1;
	FILE *file2 = fopen("Question bank.bin","rb");
	while((fread(&E1,sizeof(E1),1,file2))!=0){
		if(qn_count<E1.qn_num){
			qn_count=E1.qn_num;
		}
	}
	rewind(file2);
	coord_xy(85,2);printf("--------------------");
    coord_xy(85,3);printf("Total Questions: %d",qn_count);
    coord_xy(85,4);printf("--------------------");
	while((fread(&E1,sizeof(E1),1,file2))!=0){
			coord_xy(5,y_axis);
			printf("Qn.%d)",E1.qn_num);
			coord_xy(5,(y_axis+1));
			for(i=0;E1.question[i]!='\0';i++){
				if(i>207){
					flag=2;
					coord_xy(109,y_axis+2);printf("-");
					coord_xy(4+(i-207),y_axis+3);printf("%c",E1.question[i]);
					continue;	
				}
				if(i>103){
					flag=1;
					coord_xy(109,y_axis+1);printf("-");
					coord_xy(4+(i-103),y_axis+2);printf("%c",E1.question[i]);
					continue;	
				}
				coord_xy(5+i,(y_axis+1));printf("%c",E1.question[i]);
			}
			if(flag=2){
				y_axis=y_axis+2;
			}
			if(flag==1){
				y_axis++;
			}
			y_axis=y_axis+3;
    		getchar();
    		if(y_axis>20){
    			system("cls");
    			rectangle_box();
    			coord_xy(40,2);printf("---------------");
    			coord_xy(40,3);printf("Questions List:");
    			coord_xy(40,4);printf("---------------");
    			coord_xy(85,2);printf("--------------------");
    			coord_xy(85,3);printf("Total Questions: %d",qn_count);
    			coord_xy(85,4);printf("--------------------");
    			y_axis=5;
			}
	}
	fclose(file2);
	system("cls");
	rectangle_box();
	coord_xy(40,12);printf("Questions Bank File Ended!!!");getchar();
}

//number 13. //function to create questions from the beginning.
void question_creator(){
	fflush(stdin);
	rectangle_box();
	int qn_count=1;
	char temp;
	exam E1;
	FILE *file_qc, *file_tm;
	coord_xy(7,5);
	printf("WARNING!!! this will delete all the questions from previous question bank!!!");
	coord_xy(30,7);
	printf("Do you wish to proceed? Press 'Y' or 'N': ");
	scanf("%c",&temp);fflush(stdin);
	if(temp=='Y'||temp=='y'){
		file_qc = fopen("Question bank.bin","wb");
		do{
			system("cls");
			rectangle_box();
			coord_xy(40,5);
			printf("Enter your Questions below:");
			coord_xy(4,8);printf("%d.",qn_count);
			coord_xy(7,8);
			scanf("%[^\n]",&E1.question);fflush(stdin);
			E1.qn_num=qn_count;
			fwrite(&E1,sizeof(E1),1,file_qc);
			coord_xy(40,11);
			printf("Question written successfully..");
			coord_xy(85,3);
			printf("Questions Count: %d",qn_count);
			coord_xy(30,16);
			printf("Do you want to add another Question(y/n): ");
			temp=getchar();fflush(stdin);
			qn_count++;	
			}while(temp=='y'||temp=='Y');
		fclose(file_qc);
		}
	else{
		coord_xy(42,9);
		printf("Questions Not Created...");
		getchar();
	}
}

//number 14. //Question append function
void question_add(){
	fflush(stdin);
	exam E12;
	char temp;
	int qn_num=0;
	do{
	system("cls");
	coord_xy(45,2);printf("----------------");
	coord_xy(46,3);printf("Add Questions:");
	coord_xy(45,4);printf("----------------");
	rectangle_box();
	FILE *f1 = fopen("Question bank.bin","rb");
	while(fread(&E12,sizeof(E12),1,f1)>0){
		if(qn_num<E12.qn_num){
			qn_num=E12.qn_num;
		}
	}
	fclose(f1);
	coord_xy(72,3);printf("Total No. of Questions till now: %d",qn_num);
	f1 = fopen("Question bank.bin","ab");
	coord_xy(41,8);printf("Enter your Question below: ");
	coord_xy(4,10);printf("Qn.%d)",qn_num+1);
	coord_xy(11,10);scanf("%[^\n]",&E12.question);fflush(stdin);
	E12.qn_num = qn_num+1;
	fwrite(&E12,sizeof(E12),1,f1);
	coord_xy(41,20);printf("Question Successfully added...");
	fclose(f1);
	coord_xy(36,23);printf("Do you want to add another question[y/n]? ");scanf("%c",&temp);fflush(stdin);
	}while(temp=='Y'||temp=='y');
}
	
	
//number 15. //function to search question using number and modify it.
void question_modifier(){
	system("cls");
	rectangle_box();
	fflush(stdin);
	exam E1;
	int flag1=0,qn_num,k;
	FILE *fupdate_o,*fupdate_n;
	coord_xy(10,4);
	printf("Enter the Question number to search and update: ");
	scanf("%d",&qn_num);fflush(stdin);
	fupdate_o=fopen("Question bank.bin","rb");
	fupdate_n=fopen("Question bank_new.bin","wb");
	while(fread(&E1,sizeof(E1),1,fupdate_o)!=0){
		if(E1.qn_num==qn_num){
			flag1++;
			coord_xy(40,6);
			printf("Question number found!!!");
			coord_xy(10,8);
			printf("Question Number: %d",E1.qn_num);
			coord_xy(10,9);
			for(k=0;E1.question[k]!='\0';k++){
					if(k>198){
						coord_xy(109,10);printf("-");
						coord_xy(10+(k-199),11);printf("%c",E1.question[k]);
						continue;
					}
					if(k>99){
						coord_xy(109,9);printf("-");
						coord_xy(9+(k-99),10);printf("%c",E1.question[k]);
						continue;							
						}
					coord_xy(10+k,9);printf("%c",E1.question[k]);
				}
			coord_xy(10,12);printf("___________________________________________________________________________");
			coord_xy(10,13);printf("---------------------------------------------------------------------------");
			fflush(stdin);
			coord_xy(10,14);
			printf("Enter the New Question you want to update with:");
			//coord_xy(10,14);
			//printf("Enter Question Number: ");scanf("%d",&E1.qn_num);
			fflush(stdin);
			coord_xy(10,15);
			printf("Enter Question Name: ");scanf("%[^\n]",&E1.question);
			fflush(stdin);
			coord_xy(40,23);
			printf("Question Bank updated...");
			getchar();fflush(stdin);
			fwrite(&E1,sizeof(E1),1,fupdate_n);
			}
		else
		{
			fwrite(&E1,sizeof(E1),1,fupdate_n);	
		}	
	}
	if(flag1==0){
		coord_xy(40,12);
		printf("Question Number NOT found!!!");
		getchar();
	}
	fclose(fupdate_n);
	fclose(fupdate_o);
	remove("Question bank.bin");
	rename("Question bank_new.bin","Question bank.bin");
	
}

//number 16. //function to create and modify answer sheet.
void answer_sheet_create_modify(){
	int m1,i=0,j=0,k=0,qn_count=0,diff_temp=0;
	int flag1=0,qn_num,ans_count=0;//for answer update variable used.
	exam e1;
	ans a1;
	FILE *fupdate_o,*fupdate_n;//for answer update file pointer used.
	FILE *file_ans, *file_qn;
	here:
		system("cls");
		rectangle_box();
		coord_xy(7,4);printf("To Create new answer sheet:     [1]"); 	
		coord_xy(57,4);printf("To Add answers to the added questions:   [3]");
		coord_xy(57,5);printf("To return to the previous menu:          [4]");
		coord_xy(7,5);printf("To Modify existing one: 	       [2]");
		coord_xy(7,8);printf("Enter your choice number:");
		coord_xy(34,8);scanf("%d",&m1);fflush(stdin);
		if(m1==1||m1==2||m1==3||m1==4){
		file_qn = fopen("Question bank.bin","rb");
		while((fread(&e1,sizeof(e1),1,file_qn))!=0){
			if(qn_count<e1.qn_num){
				qn_count=e1.qn_num;
			}
		}
		rewind(file_qn);
		if(m1==1){
			char temp123;
			system("cls");
			rectangle_box();
			fflush(stdin);
			coord_xy(10,5);printf("Warning!!! This will Format previous Answer Sheet!");
			coord_xy(10,7);printf("Do you wish to proceed[y/n]: ");temp123=getchar();
			if(temp123=='Y'||temp123=='y'){
				system("cls");
				rectangle_box();
				file_ans = fopen("Answer_sheet.bin","wb");
				coord_xy(10,4);printf("There are Total of %d Questions: ",qn_count);
				for(i=0;i<qn_count;i++){
					coord_xy(10,5);printf("Enter 4 options for question no.%d:",i+1);
					while((fread(&e1,sizeof(e1),1,file_qn))>0){
					if(e1.qn_num==i+1){
						coord_xy(20,7);printf("Qn.%d)",e1.qn_num);
						for(k=0;e1.question[k]!='\0';k++){
							if(k>244){
								coord_xy(109,9);printf("-");
								coord_xy(26+(k-244),10);printf("%c",e1.question[k]);
								continue;
								
							}
							if(k>163){
								coord_xy(109,8);printf("-");
								coord_xy(26+(k-163),9);printf("%c",e1.question[k]);
								continue;
								
							}
							if(k>81){
								coord_xy(109,7);printf("-");
								coord_xy(26+(k-81),8);printf("%c",e1.question[k]);
								continue;
								
							}
							coord_xy(27+k,7);printf("%c",e1.question[k]);
							}
						}
						break;
					}
					for(j=0;j<4;j++){
						fflush(stdin);
						coord_xy(25,11+j);printf("Option %c:",97+j);coord_xy(36,11+j);scanf("%[^\n]",&a1.answer[j]);
						fflush(stdin);	
					}
					a1.qn_num_ans=i+1;
					coord_xy(10,12+j);printf("Enter Correct answer for question no.%d: ",e1.qn_num);
					coord_xy(50,12+j);scanf("%c",&a1.correct_ans);fflush(stdin);
					fwrite(&a1,sizeof(a1),1,file_ans);
					system("cls");
					rectangle_box();
					fflush(stdin);
					coord_xy(7,4);printf("There are Total of %d Questions: ",qn_count);
				}
				system("cls");
				rectangle_box();
				coord_xy(40,11);printf("Answer Sheet successfully created...");
			}
			else{
				system("cls");
				fflush(stdin);
				rectangle_box();
				coord_xy(40,11);printf("Answer Sheet not Formatted...");getchar();
				goto here;
			}
		}
		else if(m1==2){
			system("cls");
			rectangle_box();
			coord_xy(10,4);
			printf("Enter the Answer Number to search and update: ");
			scanf("%d",&qn_num);fflush(stdin);
			while((fread(&e1,sizeof(e1),1,file_qn))>0){
					if(e1.qn_num==qn_num){
						coord_xy(40,8);printf("Qn.%d)",qn_num);
						for(k=0;e1.question[k]!='\0';k++){
							if(k>184){
								coord_xy(109,10);printf("-");
								coord_xy(45+(k-184),11);printf("%c",e1.question[k]);
								continue;
								
							}
							if(k>123){
								coord_xy(109,9);printf("-");
								coord_xy(45+(k-122),10);printf("%c",e1.question[k]);
								continue;
								
							}
							if(k>61){
								coord_xy(109,8);printf("-");
								coord_xy(46+(k-61),9);printf("%c",e1.question[k]);
								continue;
								
							}
							coord_xy(47+k,8);printf("%c",e1.question[k]);
						}
						break;
					}
				}
			fupdate_o=fopen("Answer_sheet.bin","rb");
			fupdate_n=fopen("Answer_sheet_new.bin","wb");
			while(fread(&a1,sizeof(a1),1,fupdate_o)!=0){
				if(a1.qn_num_ans==qn_num){
					flag1++;
					coord_xy(40,6);printf("Answer number found!!!");
					coord_xy(10,8);printf("Answer of Qn.%d)",a1.qn_num_ans);
					for(i=0;i<4;i++){
					coord_xy(10,9+i);printf("Option %c: %s",97+i,a1.answer[i]);}
					coord_xy(10,13);printf("Correct Option of Qn.%d): %c",a1.qn_num_ans,a1.correct_ans);
					coord_xy(10,15);printf("______________________________________________________________");
					coord_xy(10,16);printf("--------------------------------------------------------------");
					coord_xy(10,17);printf("Enter new Options you want to update with: ");
					for(i=0;i<4;i++){
					coord_xy(10,18+i);printf("Option %c: ",97+i);
					coord_xy(20,18+i);scanf("%[^\n]",&a1.answer[i]);
					fflush(stdin);}
					coord_xy(10,19+i);printf("Enter Correct Option for this question: ");
					coord_xy(50,19+i);scanf("%c",&a1.correct_ans);fflush(stdin);
					fflush(stdin);
					fwrite(&a1,sizeof(a1),1,fupdate_n);
					}
				else{
					fwrite(&a1,sizeof(a1),1,fupdate_n);
				}
			}
			if(flag1==0){
				fflush(stdin);
				coord_xy(25,14);printf("Answer not found in the Answer sheet for the above question!!!");getchar();
			}
			fclose(fupdate_o);
			fclose(fupdate_n);
			remove("Answer_sheet.bin");
			rename("Answer_sheet_new.bin","Answer_sheet.bin");
			system("cls");
			fflush(stdin);
			rectangle_box();
			coord_xy(40,10);printf("Answer Sheet successfully updated...");
			getchar();
		}
		else if(m1==3){
			system("cls");
			rectangle_box();
			file_ans = fopen("Answer_sheet.bin","rb");
			ans_count=0;
			while(fread(&a1,sizeof(a1),1,file_ans)>0){
				if(ans_count<a1.qn_num_ans){
					ans_count=a1.qn_num_ans;
				}
			}
			fclose(file_ans);
			diff_temp = qn_count - ans_count;
			file_ans = fopen("Answer_sheet.bin","ab");
			coord_xy(10,4);printf("There are Total of %d Questions without answers...",diff_temp);getchar();
			printf("%d",ans_count);getchar();
			for(i=ans_count;i<qn_count;i++){
				coord_xy(10,5);
				printf("Enter your 4 Answer options for Qn.%d): ",(ans_count+1));
				while((fread(&e1,sizeof(e1),1,file_qn))>0){
					if(e1.qn_num==ans_count+1){
						coord_xy(10,8);printf("Qn.%d)",qn_num);
						for(k=0;e1.question[k]!='\0';k++){
							if(k>280){
								coord_xy(109,10);printf("-");
								coord_xy(15+(k-280),11);printf("%c",e1.question[k]);
								continue;
								
							}
							if(k>187){
								coord_xy(109,9);printf("-");
								coord_xy(15+(k-187),10);printf("%c",e1.question[k]);
								continue;
								
							}
							if(k>93){
								coord_xy(109,8);printf("-");
								coord_xy(15+(k-93),9);printf("%c",e1.question[k]);
								continue;
								
							}
							coord_xy(16+k,8);printf("%c",e1.question[k]);
						}
						break;
					}
				}
				for(j=0;j<4;j++){
					coord_xy(10,14+j);printf("Option %c:",97+j);coord_xy(21,14+j);scanf("%[^\n]",&a1.answer[j]);
					fflush(stdin);}
					a1.qn_num_ans=i+1;
					coord_xy(10,15+j);printf("Enter Correct answer for question no.%d: ",i+1);
					coord_xy(50,15+j);scanf("%c",&a1.correct_ans);fflush(stdin);
				fwrite(&a1,sizeof(a1),1,file_ans);
				system("cls");
				rectangle_box();
				ans_count++;
				coord_xy(7,4);printf("There are Total of %d Questions: ",(qn_count-ans_count));	
			}
			fclose(file_ans);
			system("cls");
			fflush(stdin);
			rectangle_box();
			coord_xy(40,10);printf("Answer Sheet successfully updated...");
			getchar();
		}
		else
			fclose(file_qn);
			return;
	}
	else{
		coord_xy(34,8);printf("           ");
		goto here;
	}
}

//number 17. //function to check student login in student details file and provide access or not. 
void Student_Login_prompt(){
	S s1;
	FILE *f1;
    char name[50];
    int n=1,reg_id=0,x1=1,y1=1;
	start:
	    while (n<=5){
	        rectangle_box();
	        coord_xy(14,5);
	        printf("---------------------------------------------------------------------------");
	        coord_xy(15,6);
	        printf("Dear Student, Please Enter your Registered Name and Registration Number: ");
	        coord_xy(14,7);
	        printf("---------------------------------------------------------------------------");
	        coord_xy(30,10);
	        printf("-------------------------------------------");
	        coord_xy(30,11);
	        printf("Student Name: ");
	        coord_xy(30,12);
	        printf("-------------------------------------------");
	        coord_xy(30,13);
	        printf("Symbol Number: ");
	        coord_xy(30,14);
	        printf("-------------------------------------------");
	        coord_xy(50,11);
	        fflush(stdin);
	        scanf("%[^\n]",&name);
	        fflush(stdin);
	        coord_xy(50,13);
	        scanf("%d",&reg_id);
	        fflush(stdin);
	        
	        f1 = fopen("Student_details.bin","rb");
			while(fread(&s1,sizeof(s1),1,f1)>0){
				if(strcmp(name,s1.std_name)==0){
					x1=0;
					fflush(stdin);
					coord_xy(30,16);printf("Name found in Database...");
					getchar();
					rewind(f1);
					while(fread(&s1,sizeof(s1),1,f1)>0){
					if(reg_id==s1.std_regi_num){
						y1=0;
						coord_xy(30,17);printf("Symbol No. matched...");
						getchar();
						break;
					}
					//else{
						//coord_xy(30,17);printf("Symbol No. not matched!");
						coord_xy(30,17);printf("                         ");
						continue;
					//}
					}
				}
			}
			if(x1==1){
				coord_xy(30,17);printf("Student Name not found in Database!!!");
				getchar();
			}
			if(y1==1){
				coord_xy(30,18);printf("Symbol No. not matched!");
				getchar();
			}
			fclose(f1);
	    	if (x1==0 && y1==0){
	        coord_xy(30,18);
	        printf("Logged In Sucessfully!");
	        coord_xy(65,18);
	        getchar();
	        coord_xy(50,11);printf("                              ");
	        coord_xy(50,13);printf("                              ");
	        x1=1;y1=1;
	    	student_menu(name,reg_id);
	        }
			else{
	        coord_xy(30,19);
	    	printf("Wrong Login Info! Try again!!!");
	    	coord_xy(30,21);
	    	printf("Attempts remaining: %d\n", 5-n);
	    	coord_xy(50,11);
	        getchar();
	        n++;}
	        system("cls");
	
	        if(n>5){
	        fflush(stdin);
	        system("cls");
	        rectangle_box();
	        coord_xy(45,9);
	        printf("Access Denied!!!");
	        coord_xy(35,12);
	        printf("Confirm your details and Re-Login!!!");
	        getchar();
	        system("cls");
	        n=1;
	        goto start;
	        }
	    }

}

//number 18. //function that displays student menu.
void student_menu(char std_name[],int std_reg){
	system("cls");
    char std_menu;
    S_menu:
        rectangle_box();
        coord_xy(40,2);printf("-----------------------------");
        coord_xy(40,3);printf("Choose Number from the menu:");
        coord_xy(40,4);printf("-----------------------------");
        coord_xy(5,7);printf("-----------------------------");
        coord_xy(5,8);printf("Read Exam Instructions:  [1]");
        coord_xy(5,9);printf("-----------------------------");
        coord_xy(5,10);printf("-----------------------------");
        coord_xy(5,11);printf("Go to Exam:              [2]");
        coord_xy(5,12);printf("-----------------------------");
        coord_xy(5,13);printf("-----------------------------");
        coord_xy(5,14);printf("Exit menu:               [3]");
        coord_xy(5,15);printf("-----------------------------");
        fflush(stdin);
        coord_xy(5,17);printf("---------------------------------------");
        coord_xy(5,18);printf("Enter your choice number for option: ");
        coord_xy(5,19);printf("---------------------------------------");
        coord_xy(42,18);scanf("%c",&std_menu);
        switch(std_menu){
            case '1':
                system("cls");
                switch(Exam_instruction()){
                    case 'b':
                        system("cls");
                        goto S_menu;}
            case '2':
                system("cls");
               	Student_exam(std_name,std_reg);
                break;
            case '3':
                coord_xy(5,27);
                exit(0);
            default:
            	system("cls");
            	goto S_menu;


            }

	coord_xy(0,27);

}

//number 19. //function to write instructions for students.
void Exam_instruction_create(){
	system("cls");
	rectangle_box();
	int i,n=0;
	char w[100];
	FILE *file_i;
	coord_xy(40,2);printf("-------------------------");
	coord_xy(40,3);printf("Write your Instructions:");
	coord_xy(40,4);printf("-------------------------");
	file_i = fopen("Student_instructions.txt","w");
	coord_xy(5,7);
	printf("Enter the Number of Instructions you want to write: ");scanf("%d",&n);
	fflush(stdin);
	for(i=1;i<=n;i++){
	coord_xy(5,7+i);printf("%d. ",i);scanf("%[^\n]",&w);
	fflush(stdin);
	fprintf(file_i,"%s\n",w);
	}
	coord_xy(30,14);
	printf("Instructions successfully written...");
	coord_xy(65,14);getchar();
	fclose(file_i);	
}

//number 20. //functions to display instructions for students.
char Exam_instruction(){
    char menu_num1,w,w1[100];
    int line=0,i;
    Inst_menu:
        rectangle_box();
       	coord_xy(30,2);printf("----------------------------------------------------");        
        coord_xy(30,3);printf("Instructions for Students, Please read Carefully!!!");
        coord_xy(30,4);printf("----------------------------------------------------");
        FILE *file_instruction = fopen("Student_instructions.txt","r");
        while((w=getc(file_instruction))!=EOF){
                if(w=='\n'){
                	line++;
				}
			}
		rewind(file_instruction);
		for(i=1;i<=line;i++){
			fgets(w1,100,file_instruction);
			coord_xy(5,7+i);printf("%d. %s",i,w1);
		}
		fflush(stdin);
        coord_xy(4,22);printf("----------------------------------------");        
        coord_xy(4,23);printf("Press [b] to return to student menu: ");
        coord_xy(4,24);printf("----------------------------------------");
        coord_xy(42,23);scanf("%c",&menu_num1);
        if(menu_num1=='b'){
            fclose(file_instruction);
            return 'b';}
        else{
            coord_xy(41,23);printf("                ");
            line=0;
            goto Inst_menu;}
}

//number 21. //function to start exam process.
void Student_exam(char std_name[],int std_reg){
	fflush(stdin);
	system("cls");
	rectangle_box();
	coord_xy(50,2);printf("--------------");       
    coord_xy(50,3);printf("Entrance Exam");
    coord_xy(50,4);printf("--------------");
    FILE *file_for_ans, *f12, *ftime_exam;
    exam e1; 
	tm tm44;
    ans a2;
	exam_report r1;
    int qn_num_store,i=0,score=0,qn_count=0,std_num=0,timeset=0,*qn_arr1;
    char ans_num, *ans_store, *correct, temp;
    
    f12 = fopen("Student_exam_Performance.bin","rb");
    while(fread(&r1,sizeof(r1),1,f12)>0){
    	if((strcmp(std_name,r1.std_name)==0)&&(std_reg==r1.std_reg)){
    		rectangle_box();
    		coord_xy(40,10);printf("Sorry!!! You have already given your Exam.");
    		coord_xy(50,14);printf("Thank You!!!");
    		fflush(stdin);
    		getchar();
    		coord_xy(40,27);exit(1);
		}
	}
	fclose(f12);
	
    ftime_exam = fopen("exam_time_set.bin","rb");
	fread(&tm44,sizeof(tm44),1,ftime_exam);
	fclose(ftime_exam);
	qn_count = tm44.total_ques;
	
	ans_store = (char *)calloc(qn_count,sizeof(char));
	
	correct = (char *)calloc(qn_count,sizeof(char));
	
	qn_arr1 = (int *)calloc(qn_count,sizeof(int));
	
	rand1(qn_count,qn_arr1);
	fflush(stdin);
	
    for(i=0;qn_arr1[i]!='\0';i++){
    	f12 =fopen("Answer_sheet.bin","rb");
	    while(fread(&a2,sizeof(a2),1,f12)>0){
	    	if(a2.qn_num_ans==qn_arr1[i]){
	    		correct[i]=a2.correct_ans;
	    		break;
			}
		}
		fclose(f12);
	}
	fflush(stdin);
    
    exam_start_2(qn_arr1, ans_store);
    
	for(i=0;i<qn_count;i++){
		if(ans_store[i]==correct[i]){
			score++;
			continue;
		}
	}
	free(ans_store);
	free(correct);
	free(qn_arr1);
	system("cls");
	rectangle_box();
	file_for_ans = fopen("Student_exam_Performance.bin","rb");
	while(fread(&r1,sizeof(r1),1,file_for_ans)>0){
		if(std_num<r1.std_num){
			std_num=r1.std_num;
		}
	}
	fclose(file_for_ans);
	timer_rectangle_box();
	coord_xy(47,10);printf("EXAM has ended!!!");
	coord_xy(47,12);printf("All the Best!!!");
	fflush(stdin);
	file_for_ans = fopen("Student_exam_Performance.bin","ab");
	r1.std_num=std_num+1;
	strcpy(r1.std_name,std_name);
	if(score>tm44.pass_marks){
		strcpy(r1.result,"Passed");
	}
	else{
		strcpy(r1.result,"Failed");
	}
	strcpy(r1.exam_taken,"Yes");
	date(&r1.exam_date);
	r1.std_score=score;
	r1.std_reg=std_reg;
	fwrite(&r1,sizeof(r1),1,file_for_ans);
	fclose(file_for_ans);
	fflush(stdin);
	coord_xy(47,22);printf("Proceed to Result...");getchar();
	system("cls");
	rectangle_box();
	if(score>=tm44.pass_marks){
		coord_xy(40,12);printf("Congratulations, You have Passed!!!");
	}
	else{
    	coord_xy(40,12);printf("You have Failed!!! Good luck Next Time!");
	}
	fflush(stdin);	
    getchar();
}

//number 22. //functions to display questions.
void Qn_exam_display(int x){
	FILE *file_disp;
	file_disp = fopen("Question bank.bin","rb");
	exam e1;
	int k=0;
	while(fread(&e1,sizeof(e1),1,file_disp)>0){
		if(e1.qn_num==x){
			//coord_xy(7,8);printf("%d)",e1.qn_num);
			for(k=0;e1.question[k]!='\0';k++){
				if(k>282){
					coord_xy(9+(k-282),11);printf("%c",e1.question[k]);
					continue;
				}
				if(k>188){
					coord_xy(9+(k-188),10);printf("%c",e1.question[k]);
					continue;
				}
				if(k>94){
					coord_xy(9+(k-94),9);printf("%c",e1.question[k]);
					continue;
				}
				coord_xy(10+k,8);printf("%c",e1.question[k]);
			}
			break;
		}
	}
	fclose(file_disp);
}

//number 23. //function to display answer options.
void exam_answer_display(int y){
	FILE *file1_disp;
	file1_disp = fopen("Answer_sheet.bin","rb");
	if(file1_disp==NULL){
		printf("fail to open file...");
	}
	ans e2;
	while(fread(&e2,sizeof(e2),1,file1_disp)!=EOF){
		if(e2.qn_num_ans==y){
			coord_xy(14,16);printf("a) %s",e2.answer[0]);
			coord_xy(60,16);printf("b) %s",e2.answer[1]);
			coord_xy(14,18);printf("c) %s",e2.answer[2]);
			coord_xy(60,18);printf("d) %s",e2.answer[3]);
			coord_xy(27,22);
			break;
			
		}
	}
	fclose(file1_disp);
}

//number 24. //function to display exam rank.
void student_exam_rank(){
	system("cls");
	rectangle_box();       
    coord_xy(50,2);printf("Student Rank Table");
    coord_xy(50,3);printf("~~~~~~~~~~~~~~~~~~");
    coord_xy(6,5);printf("Student Name: ");
    coord_xy(37,5);printf("Student Symbol No: ");
    coord_xy(62,5);printf("Marks Obt.: ");
    coord_xy(87,5);printf("Rank: ");
	result_table();
	int i=0,j,range=0,y=0,std_num1=0,std_num2=0;
	exam_report r12, *r_new; tm tm4;
	FILE *f12 = fopen("exam_time_set.bin","rb");
	fread(&tm4,sizeof(tm4),1,f12);
	fclose(f12);
	FILE *f123 = fopen("Student_exam_Performance.bin","rb");
	while(fread(&r12,sizeof(r12),1,f123)>0){
		if(std_num1<r12.std_num){
			std_num1=r12.std_num;
		}
	}
	rewind(f123);
	r_new = (exam_report *)calloc(std_num1,sizeof(exam_report));
	f123 = fopen("Student_exam_Performance.bin","rb");
	while(fread(&r12,sizeof(r12),1,f123)>0){
			r_new[i]=r12;
			i++;
	}
	range=i;
	fclose(f123);
	getchar();
	for(i=0;i<range;i++){
		for(j=i+1;j<range;j++){
			if(r_new[i].std_score<r_new[j].std_score){
				r12=r_new[i];
				r_new[i]=r_new[j];
				r_new[j]=r12;
			}
		}
	}
	
	f123 = fopen("Student_exam_Rank_sorted.bin","wb");
	for(i=0;i<range;i++){
		r12=r_new[i];
		fwrite(&r12,sizeof(r12),1,f123);
		fflush(stdin);
	}
	fclose(f123);
	
	free(r_new);
	f123 = fopen("Student_exam_Rank_sorted.bin","rb");
	while(fread(&r12,sizeof(r12),1,f123)>0){
		if(r12.std_score>tm4.pass_marks){
			std_num2++;
		}
	}
	
	rewind(f123);
	fflush(stdin);
	coord_xy(5,3);printf("Total Students to give Exam: %d",std_num1);
	coord_xy(87,2);printf("Students Passed: %d",std_num2);
	coord_xy(87,3);printf("Students Failed: %d",(std_num1-std_num2));
	i=1;y=7;
	while(fread(&r12,sizeof(r12),1,f123)>0){
		if(i==10){
			y=7;
			getchar();
			fflush(stdin);
			system("cls");
			rectangle_box();
			coord_xy(5,3);printf("Total Students to give Exam: %d",std_num1);
			coord_xy(87,2);printf("Students Passed: %d",std_num2);
			coord_xy(87,3);printf("Students Failed: %d",(std_num1-std_num2));      
		    coord_xy(50,2);printf("Student Rank Table");
		    coord_xy(50,3);printf("~~~~~~~~~~~~~~~~~~");
		    coord_xy(6,5);printf("Student Name: ");
		    coord_xy(37,5);printf("Student Symbol No: ");
		    coord_xy(62,5);printf("Marks Obt.: ");
		    coord_xy(87,5);printf("Rank: ");
			result_table();			
		}
		coord_xy(6,y);printf("%s",r12.std_name);
		coord_xy(37,y);printf("%d",r12.std_reg);
		coord_xy(62,y);printf("%d",r12.std_score);
		coord_xy(87,y);printf("%d",i);
		i++;y=y+2;
	}
	getchar();
	fflush(stdin);
	fclose(f123);
	
}

//number 25. //function to draw a table with different columns number.
void result_table(){
	int x,y;
	coord_xy(4,4);printf("%c",201);
	for(y=5;y<=23;y++){
		coord_xy(4,y);
		printf("%c\n",186);
	}
	coord_xy(4,24);printf("%c",200);
	for(x=5;x<100;x++){
		coord_xy(x,24);
		printf("%c\n",205);
	}
	for(y=6;y<24;y+=2){
		for(x=5;x<100;x++){
			coord_xy(x,y);
			printf("%c\n",196);
		}
	}
	for(y=23;y>3;y--){
		coord_xy(35,y);
		printf("%c",221);
	}
	
	for(y=23;y>3;y--){
		coord_xy(60,y);
		printf("%c",221);
	}
	for(y=23;y>4;y--){
		coord_xy(85,y);
		printf("%c",221);
	}
	coord_xy(100,24);printf("%c",188);
	for(y=23;y>4;y--){
		coord_xy(100,y);
		printf("%c\n",186);
	}
	coord_xy(100,4);printf("%c",187);
	for(x=99;x>=5;x--){
		coord_xy(x,4);
		printf("%c\n",205);
	}
	
}

//number 26. //function to draw a table with different columns number.
void detail_table(){
	int x,y;
	coord_xy(4,4);printf("%c",201);
	for(y=5;y<=23;y++){
		coord_xy(4,y);
		printf("%c\n",186);
	}
	coord_xy(4,24);printf("%c",200);
	for(x=5;x<100;x++){
		coord_xy(x,24);
		printf("%c\n",205);
	}
	for(y=6;y<24;y+=2){
		for(x=5;x<100;x++){
			coord_xy(x,y);
			printf("%c\n",196);
		}
	}
	for(y=23;y>3;y--){
		coord_xy(15,y);
		printf("%c",221);
	}
	
	for(y=23;y>3;y--){
		coord_xy(45,y);
		printf("%c",221);
	}
	for(y=23;y>4;y--){
		coord_xy(80,y);
		printf("%c",221);
	}
	coord_xy(100,24);printf("%c",188);
	for(y=23;y>4;y--){
		coord_xy(100,y);
		printf("%c\n",186);
	}
	coord_xy(100,4);printf("%c",187);
	for(x=99;x>=5;x--){
		coord_xy(x,4);
		printf("%c\n",205);
	}
}

//number 27. //function to draw a table with different columns number.
void detail_table_2(){
	int x,y;
	coord_xy(4,4);printf("%c",201);
	for(y=5;y<=23;y++){
		coord_xy(4,y);
		printf("%c\n",186);
	}
	coord_xy(4,24);printf("%c",200);
	for(x=5;x<100;x++){
		coord_xy(x,24);
		printf("%c\n",205);
	}
	for(y=6;y<24;y+=2){
		for(x=5;x<100;x++){
			coord_xy(x,y);
			printf("%c\n",196);
		}
	}
	for(y=23;y>3;y--){
		coord_xy(25,y);
		printf("%c",221);
	}
	
	for(y=23;y>3;y--){
		coord_xy(40,y);
		printf("%c",221);
	}
	for(y=23;y>4;y--){
		coord_xy(55,y);
		printf("%c",221);
	}
		for(y=23;y>4;y--){
		coord_xy(70,y);
		printf("%c",221);
	}
		for(y=23;y>4;y--){
		coord_xy(90,y);
		printf("%c",221);
	}
	coord_xy(100,24);printf("%c",188);
	for(y=23;y>4;y--){
		coord_xy(100,y);
		printf("%c\n",186);
	}
	coord_xy(100,4);printf("%c",187);
	for(x=99;x>=5;x--){
		coord_xy(x,4);
		printf("%c\n",205);
	}
}

//number 28. //storing the date of exam function
void *date(d1 *exam_date){
    time_t t1;
    t1 = time(NULL);
    struct tm time1 = *localtime(&t1);
    int m;
    m = time1.tm_mon+1;
    switch(m)
    {
        case 1:
            strcpy(exam_date->month,"January-");
            break;
        case 2:
            strcpy(exam_date->month,"February-");
            break;
        case 3:
            strcpy(exam_date->month,"March-");
            break;
        case 4:
            strcpy(exam_date->month,"April-");
            break;
        case 5:
            strcpy(exam_date->month,"May-");
            break;
        case 6:
            strcpy(exam_date->month,"June-");
            break;
        case 7:
            strcpy(exam_date->month,"July-");
            break;
        case 8:
            strcpy(exam_date->month,"August-");
            break;
        case 9:
            strcpy(exam_date->month,"September-");
            break;
        case 10:
            strcpy(exam_date->month,"October-");
            break;
        case 11:
            strcpy(exam_date->month,"November-");
            break;
        case 12:
            strcpy(exam_date->month,"December-");
            break;
    }
    exam_date->day=time1.tm_mday;
    exam_date->year=(time1.tm_year+1900);
}

//number 29. //displaying date function.
void display_date(){
    time_t t1;
    t1 = time(NULL);
    struct tm time1 = *localtime(&t1);
    int m;
    printf("Date: ");
    m = time1.tm_mon+1;
    switch(m)
    {
        case 1:
            printf("January-");
            break;
        case 2:
            printf("February-");
            break;
        case 3:
            printf("March-");
            break;
        case 4:
            printf("April-");
            break;
        case 5:
            printf("May-");
            break;
        case 6:
            printf("June-");
            break;
        case 7:
            printf("July-");
            break;
        case 8:
            printf("August-");
            break;
        case 9:
            printf("September-");
            break;
        case 10:
            printf("October-");
            break;
        case 11:
            printf("November-");
            break;
        case 12:
            printf("December-");
            break;
    }
    printf("%d, ",time1.tm_mday);
    printf("%d",time1.tm_year+1900);
}

//number 30. //timer function
void *timer1(void *timeset){  //definition of timer function.
	pthread_mutex_init(&mut1,NULL);
	pthread_t id2;
	id2 = pthread_self();
	int h=0,m=0,sec=0; 
	int *s = timeset;
	sec = *s * 60;
	if(sec>=60){
		m=sec/60;
		sec = sec-(m*60);
		if(m>=60){
			h=m/60;
			m = m-(h*60);
		}
	}
	fflush(stdin);
	while(h>0||m>0||sec>0){
				while(m>0||sec>0){
					while(sec>0){
						sleep(1);
						coord_xy(27,22);
						coord_xy(80,3);printf("%.2d : ",h);
						coord_xy(27,22);
						coord_xy(90,3);printf("%.2d : ",m);
						coord_xy(27,22);
						coord_xy(101,3);printf("%.2d",sec);
						coord_xy(27,22);
						if(time_to_exit==1){
							pthread_exit(&id2);
						}
						sec--;
						}
					if(m>0){
					sec=60;
					m--;
					}
				}
			if(h>0){
			m=60;
			h--;
		}
	}
	
	pthread_mutex_lock(&mut1);
	if(sec == 0){
		time_to_exit=1;
	}
	pthread_mutex_unlock(&mut1);
	
	pthread_mutex_destroy(&mut1);
}

//number 31. //exam function itself.
void exam_start_2(int *qn_arr1, char *ans_store){
	tm tm5;
	int i,z=1,timeset=0;
	pthread_mutex_init(&mut2,NULL);
	char ans_num,temp;
	FILE *f12;
	pthread_t id1;
	
	f12 = fopen("exam_time_set.bin","rb");
	
	fread(&tm5,sizeof(tm5),1,f12);
	fclose(f12);
	
	timeset = tm5.time;
	system("cls");
	coord_xy(50,2);printf("--------------");       
    coord_xy(50,3);printf("Entrance Exam");
    coord_xy(50,4);printf("--------------");
	rectangle_box();
	coord_xy(35,10);printf("Total number of questions:    %d Questions",tm5.total_ques);
	coord_xy(35,11);printf("Total time to complete Exam:  %d Minutes",timeset);
	coord_xy(45,16);printf("Good Luck...");
	fflush(stdin);
	getchar();
	
	pthread_create(&id1,NULL,timer1,&timeset);
	
	for(i=0;i<tm5.total_ques;i++){
    	system("cls");
    	coord_xy(50,2);printf("--------------");       
    	coord_xy(50,3);printf("Entrance Exam");
    	coord_xy(50,4);printf("--------------");
    	timer_rectangle_box();
    	coord_xy(7,4);printf("Full-Marks: %d",tm5.full_marks);
    	coord_xy(7,5);printf("Pass-Marks: %d",tm5.pass_marks);
    	rectangle_box();
    	if(time_to_exit==1){
    		system("cls");
    		rectangle_box();
    		coord_xy(47,10);printf("Time is Up!!!");
    		fflush(stdin);
    		coord_xy(61,10);getchar();
    		break;
		}
    	fflush(stdin);
    	second_rectangle_box();
    	coord_xy(14,10);
    	coord_xy(7,8);printf("%d)",z);
		Qn_exam_display(qn_arr1[i]);
		exam_answer_display(qn_arr1[i]);
		coord_xy(14,22);
		printf("Your Answer: ");      
        value:
        	coord_xy(27,22);
        	scanf("%c",&ans_num);fflush(stdin);
        	if((ans_num>='a'&&ans_num<='d')||(ans_num>='A'&&ans_num<='D')){
        		coord_xy(44,22);printf("Your Answer: %c",ans_num);
        		coord_xy(14,22);printf("Confirm Y/N: ");
        		coord_xy(27,22);printf("          ");
        		coord_xy(27,22);scanf("%c",&temp);
        		if(temp=='Y'||temp=='y'){
        			ans_store[i]=ans_num;
        			z++;
					continue;}
        		else{
        			coord_xy(27,22);printf("                                ");
        			coord_xy(14,22);printf("Your Answer: ");
        			goto value;
        		}
			}
			else{
				coord_xy(27,22);printf("       ");
        		coord_xy(27,22);
				goto value;
			}
	}
	pthread_mutex_lock(&mut2);
	time_to_exit=1;
	pthread_mutex_unlock(&mut2);
	return;
}

//number 32. //time allocation for exam function.
void exam_time_set(){
	system("cls");
	rectangle_box();
	tm tm1;exam m1;
	int chk_ques=0;
	FILE *f2 = fopen("Question bank.bin","rb");
	while(fread(&m1,sizeof(m1),1,f2)>0){
		if(chk_ques<m1.qn_num){
			chk_ques=m1.qn_num;
		}
	}
	fclose(f2);
	FILE *f1 = fopen("exam_time_set.bin","wb");
	coord_xy(70,2);printf("Total Questions in Question Bank: %d",chk_ques);
	coord_xy(10,4);printf("Enter the Time, Number of Questions, Full-Marks and Pass-Marks you want to allocate for Exam: ");
	coord_xy(3,5);printf("----------------------------------------------------------------------------------------------------------");
	chk_point_0:
		fflush(stdin);
		coord_xy(35,6);printf("Enter the number of Questions for one Exam Set: ");
		coord_xy(84,6);scanf("%d",&tm1.total_ques);
		if((tm1.total_ques<=0)||(tm1.total_ques>chk_ques)){
			coord_xy(84,6);printf("                 ");
			coord_xy(35,7);printf("Enter Valid number for Total questions!!!");
			goto chk_point_0;
		}
		coord_xy(3,8);printf("----------------------------------------------------------------------------------------------------------");
		chk_point_1:
			coord_xy(35,9);printf("Enter the Time in (minutes): ");
			fflush(stdin);
			coord_xy(64,9);scanf("%d",&tm1.time);
			if((tm1.time<=0)||(tm1.time>=600)){
				coord_xy(64,9);printf("               ");
				coord_xy(35,10);printf("Enter Valid Time!!!");
				goto chk_point_1;
			}
			fflush(stdin);
			coord_xy(3,11);printf("----------------------------------------------------------------------------------------------------------");
			coord_xy(35,12);printf("Enter Full Marks for Exam: ");
			chk_point_2:
				coord_xy(64,12);scanf("%d",&tm1.full_marks);
				fflush(stdin);
				if((tm1.full_marks<=0)||(tm1.full_marks>1000)){
					coord_xy(64,12);printf("              ");
					coord_xy(35,13);printf("Enter Reasonable Full Marks!!!");
					goto chk_point_2;
				}
			coord_xy(3,14);printf("----------------------------------------------------------------------------------------------------------");
			coord_xy(35,15);printf("Enter Pass Marks for Exam: ");
			chk_point_3:
				coord_xy(64,15);scanf("%d",&tm1.pass_marks);
				fflush(stdin);
				if((tm1.pass_marks<=0)||(tm1.pass_marks>(tm1.full_marks/2))){
					coord_xy(64,15);printf("               ");
					coord_xy(35,16);printf("Enter Reasonable Pass Marks!!!");
					goto chk_point_3;
				}
	fwrite(&tm1,sizeof(tm1),1,f1);
	coord_xy(3,17);printf("__________________________________________________________________________________________________________");
	coord_xy(3,18);printf("----------------------------------------------------------------------------------------------------------");
	coord_xy(34,19);printf("|");coord_xy(34,20);printf("|");coord_xy(34,21);printf("|");coord_xy(34,22);printf("|");coord_xy(34,23);printf("|");coord_xy(34,24);printf("|");
	coord_xy(82,19);printf("|");coord_xy(82,20);printf("|");coord_xy(82,21);printf("|");coord_xy(82,22);printf("|");coord_xy(82,23);printf("|");coord_xy(82,24);printf("|");
	coord_xy(35,20);printf("Exam set successfully allocated:   %d questions",tm1.total_ques);
	coord_xy(35,21);printf("Time successfully allocated:       %d minutes",tm1.time);
	coord_xy(35,22);printf("Full-Marks successfully allocated: %d Marks",tm1.full_marks);
	coord_xy(35,23);printf("Pass-Marks successfully allocated: %d Marks",tm1.pass_marks);
	coord_xy(35,24);printf("-----------------------------------------------");
	fclose(f1);
	coord_xy(81,24);getchar();
}

//number 33. //intro page display function.
void Intro_page(){
	int i=0;
	for(i=4;i<11;i++){
		coord_xy(30,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(27+i,4);printf("%c",178);usleep(100);
		coord_xy(27+i,7);printf("%c",178);usleep(1000);
		coord_xy(27+i,10);printf("%c",178);usleep(100);
		coord_xy(37+i,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(51-i,i);printf("%c%c",178,178);usleep(100);
		coord_xy(61-i,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(55+i,i);printf("%c%c",178,178);usleep(100);
		coord_xy(51+i,8);printf("%c",178);usleep(1000);
		coord_xy(62,8);printf("%c",178);usleep(100);
		coord_xy(69,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(64+i,4);printf("%c",178);usleep(100);
		coord_xy(75,(i+4)/2);printf("%c%c",178,178);usleep(1000);
		coord_xy(73+i,4);printf("%c",178);usleep(100);
		coord_xy(81,i);printf("%c%c",178,178);usleep(1000);
	}
	coord_xy(27,13);printf(" ____    ____     ___     ____   ____       _      __  __ ");usleep(100000);
	coord_xy(27,14);printf("|  _ \\  |  _ \\   / _ \\   / ___| |  _ \\     / \\    |  \\/  |");usleep(100000);
	coord_xy(27,15);printf("| |_) | | |_) | | | | | | |  _  | |_) |   / _ \\   | |\\/| |");usleep(100000);
	coord_xy(27,16);printf("|  __/  |  _ <  | |_| | | |_| | |  _ <   / ___ \\  | |  | |");usleep(100000);
	coord_xy(27,17);printf("|_|     |_| \\_\\  \\___/   \\____| |_| \\_\\ /_/   \\_\\ |_|  |_|");usleep(100000);
	
	coord_xy(15,19);printf("	  _       _   _             _                        ___      _  _   __ ___ ___    "); usleep(100000); 
	coord_xy(15,20);printf("	 |_) | | |_) |_)  /\\  |\\ | /  |_|  /\\  |    | | |\\ |  | \\  / |_ |_) (_   |   | \\_/ ");usleep(100000);
	coord_xy(15,21);printf("	 |   |_| | \\ |_) /--\\ | \\| \\_ | | /--\\ |_   |_| | \\| _|_ \\/  |_ | \\ __) _|_  |  |  ");usleep(100000);
	
	coord_xy(17,23);printf("WELCOME>>>  ");coord_xy(28,23);printf("Press any key to continue...");
	coord_xy(56,23);getchar();
                                                                                   
							                                                    	
}

//number 34. //Random questions generator function.
void rand1(int k, int *qn_arr1){
	int i,j,temp,flag11=0,range=0;
	exam e19;
	time_t t1;
	FILE *f1 = fopen("Question bank.bin","rb");
	while(fread(&e19,sizeof(e19),1,f1)>0){
		if(range<e19.qn_num){
			range=e19.qn_num;
		}
	}
	fclose(f1);
	range=range+1;
	srand(time(&t1));
	for(i=0;i<k;i++){
		temp = rand()%range;
		if(temp==0){
			i=i-1;
			continue;
		}
		for(j=0;j<i;j++){
			if(temp==qn_arr1[j]){
				flag11=1;
				break;
			}
		}
		if(flag11==1){
			i=i-1;
			flag11=0;
			continue;
		}
		qn_arr1[i]=temp;
	}
}

//number 35. //Timer rectangle box.
void timer_rectangle_box(){
	int x,y;
	for(y=3;y<=5;y++){
		coord_xy(75,y);
		printf("%c\n",219);
	}
	for(y=3;y<=5;y++){
		coord_xy(86,y);printf("|");
	}
	for(y=3;y<=5;y++){
		coord_xy(96,y);printf("|");
	}
	
	for(x=76;x<=106;x++){
		coord_xy(x,5);
		printf("%c\n",220);
	}
	coord_xy(106,5);
	printf("%c",219);
	for(y=5;y>2;y--){
		coord_xy(106,y);
		printf("%c\n",219);
	}
	coord_xy(106,2);
	printf("%c",220);
	for(x=75;x<=106;x++){
		coord_xy(x,2);
		printf("%c\n",220);
	}
	coord_xy(79,4);printf("Hours");
	coord_xy(88,4);printf("Minutes");
	coord_xy(98,4);printf("Seconds");

}





