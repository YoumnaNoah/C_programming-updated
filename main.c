#include<stdio.h>
#include"STD_Types.h"
#include"Final_proj_Interface.h"
#include "string.h"
#include <stdlib.h>

//extern wrong_count;
 
void main(){
	u8 Mode;
	do{
	
printf("enter 1 to enter admin mode\nenter 2 to enter client mode\n");
printf("enter 3 to exit system\n");
scanf("%d",&Mode);
fflush(stdin);
//choose Mode 

	
	switch(Mode){
		
		case admin_mode : 
		admin_Pass();
		break;
		
		case Client_mode: client_Mode();
			
		break;
		
		case exit_system: break;
		break;
		
	}
	}while(Mode!=3);
}
