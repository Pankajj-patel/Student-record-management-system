#include<stdio.h>
#include<conio.h>
#include<string.h>

void add_student();
void search_student();
void delete_student();
void students_record();
struct login id_pass();
void gotoxy(int,int);

struct student_data
{
 char first_name[15];
 char last_name[15];
 char roll_no[5];
 char class_[5];
}info;

struct RESET_ID_PASS
{
	char pass[8],id[8],security_code[8];
}reset;

struct login
{
	char pass[8],id[8];
};


main()
{
	FILE *fp;
	struct login ID_PASS;
while(1)
{	
	ID_PASS=id_pass();
	fp=fopen("ID_PASS.txt","r");
	fread(&reset,sizeof(struct RESET_ID_PASS),1,fp);
    if(strcmp(reset.id,ID_PASS.id)==0 && strcmp(reset.pass,ID_PASS.pass)==0)
	{
        char choice;
        char security_code[8];
	    while(1)
	    {
	    	system("cls");
	        printf("-------Student  Record Management System-------\n");
	        printf("1. Add Student -:");
	        printf("\n2. Search Student -:");
	        printf("\n3. Delete Student -:");
	        printf("\n4. Students Record -:");
	        printf("\n5. Exit -:");
	        printf("\n-------------------------------------------------\n"); 
            scanf("%c",&choice);
            if(choice>48&&choice<54)
			{
	        switch(choice)
	        {    
	        case 49:
	    	    system("cls");
	            add_student();
	            getch();
	            system("cls");
	            break;
   	        case 50:
   	    	    system("cls");
		        search_student();
		        printf("\n\nPress Enter key to Exit");
		        getch();
		        system("cls");
		        break;
	        case 51:
	    	    system("cls");
	    	    printf("Enter Security code :");
	    	    scanf("%s",&security_code);
	    	    if(strcmp(reset.security_code,security_code)==0)
		        delete_student();
		        else
		        printf("Wrong Code");
		        printf("\n\nPress Enter key to Exit");
		        getch();
		        system("cls");
			    break;
	        case 52:
	    	    system("cls");
		        students_record();
		        printf("\n\nPress Enter key to Exit");
		        getch();
		        system("cls");
		        break;
	        case 53:
	    	    system("cls");
	    	    printf("--------------Thank You--------------\n\n\t\t\t\tVisit Again");
	    	    printf("\n\nPress Enter key to Exit");
	    	    getch();
	           _Exit(0);  	  	  	  	  	  	   	
			}
		    }
        }
   }
    else
   {printf("\nYou Enterd Wrong Id And Password\n\n\t\t\t----Try again---\n\n");
    getch();}
fclose(fp);
}   	  
}

struct login id_pass(void)
{
	char security_code[8];
	struct login ID_PASS;
	
	FILE *fp;
	fp=fopen("ID_PASS.txt","r");
	fread(&reset,sizeof(struct RESET_ID_PASS),1,fp);
    while(1)
    {
	    char choice;
	    system("cls");
	    printf("------------Student Record Management System-------------\n\n");
	    printf("Choose Option As Follows----:\n\n");
	    printf("1. Login \n\n");
		printf("2. Reset Id and Password \n\n");
		printf("3. Forgot Id\n\n");
		printf("4. Forgot Password\n\n");
		printf("5. Exit \n");
		printf("\n------------------------------------------------\n");
	    scanf("%c",&choice);
	        if(choice>48 && choice<54)
	        { 
			   switch(choice)
		        {
		        case 49:
			        {
                    system("cls");
	                printf("-------------LOGIN PAGE--------------");
	                printf("\n\nEnter ID:");
	                scanf("%s",&ID_PASS.id);
	                printf("\nEnter Password:");
	                scanf("%s",&ID_PASS.pass);
	                system("cls");
	                return(ID_PASS);
	                break;
	                }
	            case 50:
	     	        {
		            printf("Enter Security Code: ");
		            scanf("%s",&security_code);
		            if(strcmp(reset.security_code,security_code)==0)
		            {
		    	    FILE *fp;
		    	    char  change_sc;
		    	    int a,b,c,check_sc=0;
		    	    fp=fopen("ID_PASS.txt","r+");
		    	    system("cls");
		    	    while(1)
		    	    {
		    	    int a,b,c,check_sc=0;
		    	    printf("--*Id & Security Code Must Contain Integer Only*--\n");
		            printf("--*Id & Security Code must be under 8 numbers Only*--\n");
		            printf("--*Password must be under 8 alphanumric Only*--\n\n");
		        
                    printf("-------------RESET ID----------------");
                    printf("\n\nEnter new ID :");
                    scanf("%s",&reset.id);
                    a=strlen(reset.id);
                    printf("-------------RESET PASSWORD-----------");
                    printf("\n\nEnter New Password :");
	                scanf("%s",&reset.pass);
	                b=strlen(reset.pass);
	                getch();
	                system("cls");
	                printf("Do you Want to change your Security Code (Y/N):");
	                scanf("%s",&change_sc);
	                if(change_sc=='y'||change_sc=='Y')
	                {
                    printf("-------------RESET SECURITY CODE-----------");
                    printf("\n\nEnter Security code :");
		            scanf("%s",&reset.security_code);
		            c=strlen(reset.security_code);
		            getch();
		            check_sc=1;
		            system("cls");
		            }
		            if(a<9 && b<9 && check_sc==0 || a<9 && b<9 && c<9)
		           {
		            printf("Your Request For Changing  Id/Password or Security Code is Successfull");
		            getch();
		            break;	
				   }
		            printf("Either Id/Password or security code is greater than 8,Hence Please Enter Again");
		            getch();
		        
		            }
				    fwrite(&reset,sizeof(struct RESET_ID_PASS),1,fp);
				    fclose(fp);    	    
		            }
      	            else
      	            {
			        printf("\t\t\tWrong Security_code\n");
			        getch();
			        system("cls");
			        }
                    break;
                    }
                case 51:
		            {
		            //FILE *fp;
		            char a[8];
			        //fp=fopen("ID_PASS.txt","r");
		        	printf("Enter Security Code-:");
			        scanf("%s",&a);
			        //fread(&reset,sizeof(struct RESET_ID_PASS),1,fp);
			        if(strcmp(a,reset.security_code)==0){
			        printf("Your User Id is :%s",reset.id);
		            getch();}
		            else{
		            printf("\nWrong Security Code");
			        getch();}
		            //fclose(fp);
		            system("cls");
		            break;
		            }
		        case 52:
		            {
		             //FILE *fp;
		            char a[8];
			        //fp=fopen("ID_PASS.txt","r");
			        printf("Enter Security Code-:");
			        scanf("%s",&a);
			        //fread(&reset,sizeof(struct RESET_ID_PASS),1,fp);
			        if(strcmp(a,reset.security_code)==0){
			        printf("Your User Password is :%s",reset.pass);
		            getch();}
		            else{
		            printf("\nWrong Security Code");
		            getch();}
			        //fclose(fp);
			        system("cls");
			        break;		
			        }
      	        case 53:
      	            _Exit(0); 
		        }
		    }     
	}
	fclose(fp);
}

void add_student()
{
  char add;
  FILE *fp;
  do
  {
   printf("-----------Enter Details of Students-----------");
   fp=fopen("student_data.txt","a");
   printf("\nEnter first name:");
   scanf("%s",&info.first_name);
   printf("\nEnter last name:");
   scanf("%s",&info.last_name);
   printf("\nEnter roll_no:");
   scanf("%s",&info.roll_no);
   printf("\nEnter class:");
   scanf("%s",&info.class_);
   
   if(fp==NULL)
   {printf("can't open file\n");}
   else
   {printf("\nRecord Stored Sucessfully\n");
   printf("\n-----------------------------------------------\n");}
   fwrite(&info,sizeof(struct student_data),1,fp);
   fclose(fp);
   printf("Do you want to add more(y/n):");
   scanf("%s",&add);
  }
  while(add=='y'||add=='Y');
}

void search_student()
{
	FILE *fp;
	char roll_no[5];
	fp=fopen("student_data.txt","r");
	printf("-----------------Search Result----------------");
	printf("\nEnter Roll no :");
	scanf("%s",&roll_no);
	while(fread(&info,sizeof(struct student_data),1,fp))
	{
		if(strcmp(info.roll_no,roll_no)==0)
		{	
		printf("\n\n\nStudent Name: %s %s",info.first_name,info.last_name);
    	printf("\nRoll no: %s",info.roll_no);
    	printf("\nClass: %s",info.class_);
		printf("\n\n-----------------------------------------------\n");
		getch();
		}
		if(roll_no==0)
		{
		printf("Record Not Found!!!");
		getch();
		system("cls");
	    }
	}
	fclose(fp);
}

void delete_student()
{
	FILE *fp,*fpp;
    struct student_data info;
    char roll_no[5];
	int found=0;
    printf("\n\n----------------- Delete Student Record----------------");
    fp=fopen("student_data.txt","r");
    fpp=fopen("temp.txt","w");
    printf("\n\nEnter Roll No:");
    scanf("%s",&roll_no);
    if(fp==NULL)
   {printf("can't open file\n");}
   	while(fread(&info,sizeof(struct student_data),1,fp))
	{
		if(strcmp(info.roll_no,roll_no)==0){
		found=1;
		printf("\n\nStudent Name: %s %s",info.first_name,info.last_name);
    	printf("\nRoll no: %s",info.roll_no);
    	printf("\nClass: %s",info.class_);
		printf("\n\n-----------------------------------------------\n");
	    }
		else{fwrite(&info,sizeof(struct student_data),1,fpp);}	
    }
    fclose(fp);
    fclose(fpp);
    if(found)
    {
    remove("student_data.txt");
    rename("temp.txt","student_data.txt");
    printf("Record Deleted successfully");
	}
	else
	{
		printf("\nRecord Not Found");
	}
}

void students_record()
{  
    FILE *fp;
    struct student_data info;
    fp=fopen("student_data.txt","r");
    printf("\t\t-----------------student Records----------------");
    if(fp==NULL)
    {printf("\ncan't open file");}
    else
    while(fread(&info,sizeof(struct student_data),1,fp))
    {
    	printf("\n\nStudent Name: %s %s",info.first_name,info.last_name);
    	printf("\nRoll no: %s",info.roll_no);
    	printf("\nClass: %s",info.class_);
		printf("\n\n-----------------------------------------------\n");	
	}
	fclose(fp);
}
