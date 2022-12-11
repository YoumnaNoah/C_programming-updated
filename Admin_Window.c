#include<stdio.h>
#include"STD_Types.h"
//#include"BIT_CALC.h"
#include"Final_proj_Interface.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
	FILE*fptr;
 
u8 ACC_ID_S[20];
client tot_clients[300];
client client_1;
u8 Change_status[10];
u8 filename[20];
client mem_1;
u8 num=0;
//the function checks the password and the username
//void choose_window(void){

//}
void admin_Pass(void){
	u8 Username[8] = "youmna"; //admin username
	u8 in_username[8];
	u8 comp_user;
	u8 password[]= "51610153"; //admin password
	u8 entry_pass[15];
	u8 comp;
printf("enter the username\n"); 
scanf("%s",&in_username);  //scan the username 
comp_user=strcmp(Username,in_username); //compare the input username with user 
if (comp_user==0) //condition check 0 means the two strings match
	{
	printf("enter your password\n");
	scanf("%s",&entry_pass); //scan password
	fflush(stdin);
	comp=strcmp(password,entry_pass); //compare the password entered with the one saved in the system
	if(comp==0) //conditions check 0 means the two passwords match
	{
		admin(); //call admin function  
	}
	else{
		printf("wrong password"); //else for the password check
	}

}
else{
	printf("wrong username\n"); //else for the username check
}
}

//admin function to choose the operation
void admin(void){
	bool again= true;	
	u8 admin_option;
	u8 check;
	
	
	while (again)
	{ 
	
	printf("enter 1 to create new account\n 2 to open existing account\n 5 to return to main_menu\n");
	scanf("%d",&admin_option); //scan admin option
	switch (admin_option){
		case new_account: create_acc();
				set_data(num);
				num++;
		break;
		
		case open_account:exis_acc(); //exis_acc();
		break;
		
		
		
	}
	printf("do you want to do another operation 1=yes 0=NO\n");
	scanf("%d",&check);
	fflush(stdin);
	again=check;
	
	}
}
//function to create new account
void create_acc(void){
	
	
	
		//int i=0;
			//fprintf(fptr,"client %d\n",i++);
		
		
	// get full name
	printf("enter the client's full name  at least 4names\n");
	scanf(" %[^\n]",&mem_1.name);
	fflush(stdin);
	strcpy(client_1.name,mem_1.name);
	 fprintf(fptr,"%s|",mem_1.name); //improved
	
	//get client address
	printf("enter client's address\n");
	scanf(" %[^\n]",&mem_1.address);
	fflush(stdin);
	//to test using array of objects
	strcpy(client_1.address,mem_1.address);
	fprintf(fptr,"%s|",mem_1.address);
	
	//get client's national ID
	printf("enter national ID\n");
	scanf("%s",&mem_1.National_ID);
	fflush(stdin);
	//to test using array of objects
	strcpy(client_1.National_ID,mem_1.National_ID);
	fprintf(fptr,"%s|",mem_1.National_ID);
	
	//get clients age
	printf("enter the client's age \n");
	scanf(" %d",&mem_1.age);
	fflush(stdin);
	//to test using array of objects
	client_1.age=mem_1.age;
	fprintf(fptr,"%d|",mem_1.age);
	
	
	if(mem_1.age<21) //enter guardian data if client is less than 21 years old
	{
		//get guardian's name
		printf("enter guardian name here\n");
		scanf(" %[^\n]",&mem_1.guardian);
		fflush(stdin);
		//to test using array of objects
		strcpy(client_1.guardian,mem_1.guardian);
		fprintf(fptr,"%s|",mem_1.guardian);
		
		//get guardian's ID
		printf("enter guardian's national ID here\n");
		scanf(" %[^\n]",&mem_1.guardian_nat_ID);
		fflush(stdin);
		//to test using array of objects
		strcpy(client_1.guardian_nat_ID,mem_1.guardian_nat_ID);
		fprintf(fptr,"%s|",mem_1.guardian_nat_ID);
	}
	else {
		printf("no guardian needed\n");
		}
	
	//generate random account ID .. still needs improvment
		srand(time(NULL));
	mem_1.Acc_ID = rand()%(9999999999 - 1000000000 + 1) + 1000000000;
	printf("The account ID is: %d\n",mem_1.Acc_ID);
	//fprintf(fptr,"%d|",mem_1.Acc_ID);
	//to test using array of objects
	client_1.Acc_ID = mem_1.Acc_ID;
	
	strcpy(mem_1.Account_status,"active");
	//to test using array of objects
	strcpy(client_1.Account_status,"Active");
	//fprintf(fptr,"%s|",mem_1.Account_status);

	//gets balance
	printf("enter the balance here\n");
	scanf("%d",&mem_1.Balance);
	fflush(stdin);
	client_1.Balance = mem_1.Balance;
	//fprintf(fptr,"%.2f|",mem_1.Balance);


	//generate random password ...still needs improvment 
		srand(time(NULL));
		
	mem_1.Acc_password= rand()%(9999999999 - 1000000000 + 1) + 1000000000;;
	printf("password is: %d\n",mem_1.Acc_password);
	//to test using array of objects
	client_1.Acc_password = mem_1.Acc_password;
	//fprintf(fptr,"%d|",mem_1.Acc_password);
	//fputs("#",fptr);
	
	sprintf(ACC_ID_S,"%d",mem_1.Acc_ID);// transform the account ID From int to string
	strcpy(filename,ACC_ID_S);  //place the string acc ID in the namefile variable
		fptr=fopen(strcat(filename,".dat"),"a+");  //concat. the filename with .dat then create file
		fwrite(&mem_1,sizeof(client),1,fptr); //write in file 
	if (fwrite!=0) //condition to check if the file was opened and appended succesfully
	{
		printf("Account created succesfully\n");
	}
	else 
	{
		printf("something went wrong\n");
	}
	fclose(fptr); //close file
	
}
	//store the data of the struct into array
void set_data(u16 index){
		strcpy(tot_clients[index].name,client_1.name);
		strcpy(tot_clients[index].address,client_1.address);
		strcpy(tot_clients[index].National_ID,client_1.National_ID);
		tot_clients[index].age=client_1.age;
		tot_clients[index].Acc_ID = client_1.Acc_ID;
		strcpy(tot_clients[index].guardian,client_1.guardian);
		strcpy(tot_clients[index].guardian_nat_ID,client_1.guardian_nat_ID);
		strcpy(tot_clients[index].Account_status,client_1.Account_status);
		tot_clients[index].Balance=client_1.Balance;
		tot_clients[index].Acc_password=client_1.Acc_password;
		
	}
	
//open existing account
void exis_acc(void){
	//u32 content[1000];
	u8 exis_acc_option;
	u32 i;
	u32 ID_OP_A;
	//fgets(content,10000,fptr);
	
	//get the ID Account you wat to operate on
	printf("enter the account ID of the account you want to open\n");
	scanf("%d",&ID_OP_A);
	fflush(stdin);
	//search for the iD in the array to compare it with the entered value
	for(i=0;i<300;i++){
		if(tot_clients[i].Acc_ID == ID_OP_A){
			num=i;
		}
	}
	                             // file handling part need improvment
		printf("enter the account ID again \n");
	scanf("%s",&ACC_ID_S); //scan the sender account ID as a string
	strcpy(filename,ACC_ID_S); //place  the account ID as the filename
	
	fptr = fopen(strcat(filename,".dat"),"r"); //concat.the file name with .dat and then open the file
	if (fptr == NULL)
	{
		printf("Error opening file.\n");
		
	}
	
	//fread(&mem_1,sizeof(client),1,fptr);
	//fclose(fptr);
	
	
	//print possible operations to perforn on exisiting account
	printf("enter 1 to make transaction\n  ");
	printf("enter 2 to change_status\n");
	printf("enter 3 to get cash \n");
	printf("enter 4 to deposit\n ");
	printf("enter 5 to return to main menu\n");
	
	//scan the user choice
	scanf("%d",&exis_acc_option);
	fflush(stdin);
	switch (exis_acc_option){
		case Make_transaction: make_trans();
		break;
		
		case change_status: change_stat();
		break;
		
		case  get_cash:withdraw();
		break;
		
		case deposit: deposit_fun();
		break;
		
		
		case main_menu_return: break;
		
		
	}
}
//function make transaction
void make_trans(void){
	u32 transfer_amount;
	u8  ACC_Transfer_ID[20];
	
	
	printf("enter the account ID you want to transfer to:\n");
		
		scanf(" %[^\n]",&ACC_Transfer_ID); //
		fflush(stdin);
		printf("Enter the ammount of money you want to transfer\n"); 
		scanf("%d",&transfer_amount);
		fflush(stdin);
		if(transfer_amount<tot_clients[num].Balance) //check the balance before transfer
		{ 
		tot_clients[num].Balance=tot_clients[num].Balance-transfer_amount; //subtract the ammount from the original balance and update the balance ammount
		printf("balance update: %d\n",tot_clients[num].Balance);//print the balance update to the client
		}
		else 
		{
			printf("The balance is not enough to complete the transaction\n");
		}
}
//change status function
void change_stat(void){
	printf("enter the status you want to update\n");
	scanf("%s",&Change_status); //scan new status
	fflush(stdin);
	strcpy(tot_clients[num].Account_status,Change_status);//update the new status into the array
}
//withdraw function
void withdraw(void){
	u32 withdrawn_amount;
	
	printf("Enter the ammount of money you want to withdraw\n"); 
		scanf("%d\n",&withdrawn_amount); //scan the ammount of withdrawl
		fflush(stdin);
		if(withdrawn_amount<tot_clients[num].Balance)//check the balance
		{ 
		tot_clients[num].Balance=tot_clients[num].Balance-withdrawn_amount; //subtract the ammount from the original balance and update the balance ammount
		printf("%d\n",tot_clients[num].Balance);
		}
		else 
		{
			printf("The balance is not enough to complete the withdrawl\n");
}
}

//deposit into account function
void deposit_fun(void){
	u32 deposit_ammount;
	printf("enter the amount of money you want to deposit\n");
		scanf("%d",&deposit_ammount);
		fflush(stdin);
		tot_clients[num].Balance=tot_clients[num].Balance+deposit_ammount;
		printf("balance update is %d\n",tot_clients[num].Balance);
}
