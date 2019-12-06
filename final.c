/*
(19k-1396)
(19k-1483)
(19k-1373)
*/
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<conio.h>
struct date
{
  int d; int m; int y;	
}i;
struct data
{
	int an; char name[20]; struct date i; 
	char m[20];  char add[15]; 
    char city[20]; int dep;
	char pw[20];
}d;
struct form
{
	        char na[26];
			char re[26];
			char in[100];
			long int amount;
};
void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
}
void loading() 
{ 	
	int i ,j;
	system("cls");
	gotoxy(35,9);
	printf("LOADING");
	gotoxy(28,10);
 	printf("=====================");
	gotoxy(26,11);
	printf(" | ");
	gotoxy(48,11);
	printf(" | ");
	gotoxy(28,12);
	printf("=====================");
	gotoxy(33,14);
	printf("PLEASE WAIT...");
 	gotoxy(28,11);
	for(i=0;i<=20;i++)
	{
		for(j=0;j<=9000000;j++);
			printf("%c",177);
	}
	system("cls");	
}
transfer()
{
	system("cls");
	char name[20]; int tran,co=0;
	printf("\nEnter Account Title: "); fflush(stdin); gets(name);
	printf("\nEnter Amount You Want To Transfer: "); scanf("%d",&tran);
	FILE *ft; 
	ft=fopen("what.dat","rb+");
	if(ft==NULL) {  printf("Cannot open file!"); exit(11);  }
	rewind(ft);
      while(fread(&d,sizeof(d),1,ft)==1)
      {
    		if(strcmp(name,d.name)==0)
    		{
    			co++;
	           if(d.dep>tran)
	           {
	           	 char name1[20];
	           	 printf("\nEnter Account Title in which you want transfer: "); fflush(stdin); gets(name1);
	           	 rewind(ft); int co1=0;
	           	  while(fread(&d,sizeof(d),1,ft)==1)
                  {
                     	if(strcmp(name1,d.name)==0)
                     	{
                     		co1++;
                     		d.dep=d.dep+tran;
                     		printf("\nYou have successfully transfered Rupees %d in %s's Account!\nPress Anywhere To Continue!",tran,d.name);
                     		fclose(ft);
                     		fflush(stdin); panel3();
						}
                  }
                  if(co1==0)
                  {
                  	printf("No Such Account Title exists, therefore unable to transfer!\nPress Any key To Try Again!"); fflush(stdin); getche();
				    fclose(ft);
				    panel3();
				  }
			   }
			   else
			   {
			   	printf("\nYou have Insufficient Balance!\nPress Anywhere To Continue!");
				 fclose(ft);   
			   	fflush(stdin); panel3();
			   }
            }
      }
      if(co==0)
      {
      	printf("No Such Account Title exists!\nPress Any key To Try Again!"); fflush(stdin); getche();
				fclose(ft);
				panel3();
	  }
}
modify()
{
	system("cls");
	char name[20]; int co=0; 
	printf("\nEnter Account Title: "); fflush(stdin); gets(name);
	FILE *ft,*fp;
	fp=fopen("temp.dat","wb+");
	if(fp==NULL) {  printf("Cannot open file!"); exit(11);  }
	ft=fopen("what.dat","rb+");
	if(ft==NULL) {  printf("Cannot open file!"); exit(11);  }
	rewind(ft);
	 while(fread(&d,sizeof(d),1,ft)==1)
      {
    		if(strcmp(name,d.name)==0)
    		{
    			co++;
    			 printf("\nEnter Modified Address: "); fflush(stdin); gets(d.add);
	             printf("\nEnter Modified Mobile No: "); fflush(stdin); gets(d.m);
	             fseek(fp,0,SEEK_END);
                 fwrite(&d,sizeof(d),1,fp);
                 system("cls");
                 printf("\nChanges saved!");
                 
    			
    		}
    		
    		else
    		{
    			fseek(fp,0,SEEK_END);
    			fwrite(&d,sizeof(d),1,fp);
			}
    	
    }
    fclose(fp);
    fclose(ft);
    remove("what.dat");
    rename("temp.dat","what.dat");
    panel3();
    if(co==0)
    {
    	printf("No Such Account Title exists!\nPress Any key To Try Again!"); fflush(stdin); getche();
				
				panel3();
	}
}
list()
{
	system("cls");
	printf("\nRecords");
	FILE *ft;
    	ft=fopen("what.dat","rb+");
	if(ft==NULL) {  printf("Cannot open file!"); exit(11);  }
	rewind(ft);
	 while(fread(&d,sizeof(d),1,ft)==1)
      {
	  printf("%d\n%s\n%d %d %d\n%s\n%s\n%s\n%d\n%s",d.an,d.name,d.i.d,d.i.m,d.i.y,d.m,d.add,d.city,d.dep,d.pw);	
      }
      fclose(ft);
      printf("\nPress Anywhere to continue!"); getche();
      ad_panel();
}
void cheaquebook(void)
{
	system("cls");
	int choice,c;
	char p[32];
	printf("Which type of cheque you want to issue?\n\n");
	printf("1) Bearer\n2) Pay Order\n");
	printf("\nEnter Your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			xy:
			system("cls");
			printf("\n\nSelect Number of Pages:\n");
			printf("1) 25 Pages\n2) 50 Pages\n3) 100 Pages\n\n");
			scanf("%d",&c);
			if(c==1 || c==2 || c==3)
			{
			int i;	
			printf("\n\nYour checque has been issued");
			system("cls");
			gotoxy(5,2);
	        for(i=0; i<68; i++)
	        {
		     printf("_");
	        }
	        for(i=3; i<18; i++)
	        {
	        	gotoxy(4,i);
	        	printf("|");
	        	gotoxy(73,i);
	        	printf("|");
			}
			gotoxy(5,17);
			for(i=0; i<68; i++)
	        {
		     printf("_");
	        }
	        gotoxy(6,4);
	        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LEXUS BANK LIMITED CHECKBOOK \xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	        printf("Date : __ /__ /__");
	        gotoxy(6,6);
	        printf("PAY: _______________________________________________________xxxxx");
	        gotoxy(6,8);
	        printf("RUPEES: _________________________________________________________");
	        gotoxy(6,10);
	        printf("____________________________________");
	        printf("  |");
	        gotoxy(45,9);
	        printf("__________________________");
		    gotoxy(71,10);
		    printf("|");
			gotoxy(44,11);
			printf("|");
			printf(" PKR:");
			gotoxy(71,11);
			printf("|");
			gotoxy(44,12);
			printf("|__________________________|");
			gotoxy(6,16);
			printf("Do not write Below this Line:____________________________________");
			gotoxy(44,14);
			printf("Signature:_________________");
			gotoxy(25,19);
			printf("<PRESS any key to continue...>");
			fflush(stdin);
			getch();
			system("cls");
			printf("CheckBook Issued");
			getch();
			fflush(stdin);
			panel3();
	    }
			else
			{
				printf("Invalid Choice!!");
				Beep(500,700);
				goto xy;
			}
			break;
			
		case 2:
			reset:
			system("cls");
			char date[8];
			int i;
			struct form f;
			printf("\xB2\xB2\xB2\xB2\xB2\xB2 RECIEPT DETAILS: \xB2\xB2\xB2\xB2\xB2\xB2");
			printf("\n\n");
			printf("Date (dd/mm/yy): ");
		    scanf("%s",&date);
		    if(date[2]=='/' && date[5]=='/') 
		    {
			}
			else{
				printf("Not Valid");
				printf("\nPress any Key to continue");
				fflush(stdin);
				getch();
				goto reset;
			}
			printf("\nAccount Title:");
			fflush(stdin);
			gets(f.na);
			printf("\nReciept Name:");
			fflush(stdin);
			gets(f.re);
			printf("\nPay <Amount Inwords>:");
			fflush(stdin);
			gets(f.in);
			printf("\nPay <Amount digits>:");
			scanf("%ld",&f.amount);
			printf("\n\n\nPress Key to create continue...");
			fflush(stdin);
			getch();
			system("cls");
			gotoxy(5,2);
	        for(i=0; i<68; i++)
	        {
		     printf("_");
	        }
	        for(i=3; i<18; i++)
	        {
	        	gotoxy(4,i);
	        	printf("|");
	        	gotoxy(73,i);
	        	printf("|");
			}
			gotoxy(5,17);
			for(i=0; i<68; i++)
	        {
		     printf("_");
	        }
	        gotoxy(6,4);
	        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LEXUS BANK LIMITED CHECKBOOK \xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	        printf("Date : %s",date);
	        gotoxy(6,6);
	        printf("PAY: __%s_________________________________xxxxx",f.re);
	        gotoxy(6,8);
	        printf("RUPEES: _%s_________________________",f.in);
	        gotoxy(6,10);
	        printf("____________________________________");
	        printf("  |");
	        gotoxy(45,9);
	        printf("__________________________");
		    gotoxy(71,10);
		    printf("|");
			gotoxy(44,11);
			printf("|");
			printf(" PKR: %ld/=",f.amount);
			gotoxy(71,11);
			printf("|");
			gotoxy(44,12);
			printf("|__________________________|");
			gotoxy(6,16);
			printf("Do not write Below this Line:____________________________________");
			gotoxy(44,14);
			printf("Signature:_%s________",f.na);
			gotoxy(25,19);
			printf("<PRESS any key to continue...>");
		    getch();
			panel3();
			break;
			
		default:
			printf("\nInvalid Choice!!");
			Beep(500,700);
			goto reset;
			
	}

}
void erase(void)
{
	system("cls");
    FILE *fp,*ft;
    int c=0;char name[20];
    fp=fopen("what.dat","rb+");
    ft=fopen("temp.dat","wb+");
    if(fp==NULL || ft==NULL)
    {
    	printf("Cannot open file!");
    	panel1();
	}
    printf("Enter the account title of the customer you want to delete: "); 
    fflush(stdin); gets(name);
    rewind(fp);
    while (fread(&d,sizeof(d),1,fp)==1)
   {
   	   if(strcmp(name,d.name)==0)
   	   {
   	   	  c=c+1; printf("\nRecord Has Been Deleted!\nPress any key to continue!"); getch();
       }
        else
            {
            	fwrite(&d,sizeof(d),1,ft);
			}
   }
        if(c==0) 
            {
			
            printf("\n\t\tNo such Account Exists!\nPress any key to continue!"); fclose(ft); getch();
            ad_panel();
            }
       
   
   fclose(fp);
   fclose(ft);
   remove("what.dat");
   rename("temp.dat","what.dat"); getch();
   ad_panel();
}
void loan(void)
{
	system("cls");
	int prop,veh; 
	float income;
	char ask;
	printf("\n\t\tMaximum limit of loan: Rs.20,000,00\n\n");
	printf("Following are the eligiblity for Loan:\n\n");
	printf("Enter your Monthly Income: Rs."); 
	scanf("%f",&income);
	if(income < 10000 || income>100000)
	{
		printf("\n\t\tYou do not meet our requirement !!");
		printf("\n\nPress anywhere to continue");
		fflush(stdin); getche();
		panel3();
	}
	else if(income<=0)
	{
		printf("\n\n\t\tInvalid Entry!!");
		Beep(500,700);
		system("cls");
		loan();
	}
	else
	{
	printf("\n\nEnter Your Personal Details:\n\n");
	printf("How Many Properties do you have?\n");
	scanf("%d",&prop);
	printf("\nHow Many Vehicles do you have?\n");
	scanf("%d",&veh);
	
	if(income<=50000)
	{
		income=income*5;
		printf("\n\t\tYou are able to get Rs.%.2f loan\n",income);
		printf("\nDo you want to accept this amount?(y/n)\n\n");
		ask=getch();
		if(ask=='y')
		{
			printf("\n\t\tCongratulations! Your loan request has been accepted.\n");
			printf("\nPress anywhere to continue");
			fflush(stdin); getche();
			panel3();
		}
		else if(ask=='n')
		{
			printf("\n\t\tSorry, we can't provide you much loan\n");
			printf("\nPress anywhere to continue");
			fflush(stdin)   ; getche();
			panel3();
		}
		else if(ask!='y' || ask!='n')
		{
			printf("\nInvalid Entry!!");
			Beep(500,700);
			system("cls");
			loan();
		}
	}
	
	else if(income>50000 && income<=100000)
	{
		income=income*5;
		printf("\n\t\tYou are able to get Rs.%.2f loan\n",income);
		printf("\nDo you want to accept this amount?(y/n)\n\n");
		ask=getch();
		if(ask=='y')
		{
			printf("\n\t\tCongratulations! Your loan request has been accepted.\n"); 
			printf("\nPress anywhere to continue");
			fflush(stdin); getche();
			panel3();
		}
		else if(ask=='n')
		{
			printf("\n\t\tSorry, we can't provide you much loan\n");
			printf("\nPress anywhere to continue");
			fflush(stdin); getche(); 
			panel3();
		}
	    else if(ask!='y' || ask!='n')
		{
			printf("\nInvalid Entry!!");
			Beep(500,700);
			system("cls");
			loan();
		}
	}
	
}
}
welcome()
{
	system("cls");
	gotoxy(25,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(25,9);
	printf("  WELCOME TO LEXUS ONLINE BANKING"); gotoxy(25,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(25,25); printf("  (Press Any Key To Continue)");
    getche(); 
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
blink()
{ 
 	int i;
	while(i<=7)
    {
       printf("\n\n\n\n\n\n\n\n\t\t\t\t Initializing");
       if(i<7)
    {
     delay(200);
     system("cls");
     delay(230);
 }
      i++;
 }
}
panel()
{
	char cho; en:
	system("cls"); printf("\tPlease Select Between The Following Options!");
	gotoxy(20,6);
	printf("Press [1]. Admin");
	gotoxy(20,7);
	printf("Press [2]. Account Holder");
	gotoxy(20,8);
	printf("Press [3]. Exit");
	gotoxy(20,15);
	printf("Enter Your Choice: "); fflush(stdin);
	cho=getche();
	if(cho=='1'||cho=='2'||cho=='3')
	{
		
	}
	
	else
	{
		gotoxy(20,15);
		printf("Invalid Entry!Press Any Key To Try Again!"); getche();
		goto en;
	}
	
	if(cho == '1')
	{
		system("cls");
		loading();
		panel1();
	}
	
	else if(cho == '2')
	{
		system("cls");
		loading();
		panel2();
	}
	
	else
	{
		system("cls");
		printf("Thank You!");
		exit(1);
	}
}
panel1()
{   
    f:
	system("cls"); 
	int userid,temp1;
	char ch,alphabets1[26] = {'a','b','A','2','C','f','Z','h','8','j','x','l','7','6','Y','p','L','r','s','m','u','9','5','3','1','0'};
	char rString1[20],password[20];
	srand(time(NULL));
	userid = 100000+rand()%100000;
    int i=0;
	while(i<6)
	{
		int temp1 = rand() % 26;
		rString1[i] = alphabets1[temp1];
		i++;
	}
	gotoxy(0,10); printf("[Password= '%s']",rString1);
	gotoxy(25,5);
	printf("Admin Id : "); printf("%d",userid); 
	gotoxy(25,6); printf("Password : "); 
	for(i=0;i<6;i++)
    {
    ch = getch();
    password[i] = ch;
    ch = '*' ;
    printf("%c",ch);
    }
    password[i] = '\0';
	if(strcmp(password,rString1)==0)
	{
		ad_panel();
	
	}
	else
	{
	    gotoxy(20,7);
		printf("Invalid Password!Press Any Key To Try Again!"); getche();
		goto f;
	}
}
ad_panel()
{
	ad:
	system("cls"); char ch; 
	printf("Welcome to Admin Panel");
	printf("\n\n\t[1] List of All Records ");
	printf("\n\n\t[2] Delete A Record ");
	printf("\n\n\t[3] Main Menu");
	printf("\n\n\tEnter your choice : ");
	fflush(stdin); ch=getche();
	switch(ch)
	{
		case '1':
			list(); break;
			
		case '2':
		    erase(); break;
			
		case '3':
		    panel(); break;
			
		default:
		    printf("\nInvalid Entry!\nPress anywhere to continue!"); 	
			fflush(stdin); getch();
			goto ad;		
		
		
	}
		
}
panel2()
{
	e:  
	system("cls"); char ch2;
	gotoxy(10,5);
	printf("[1] Sign Up For a New Account"); gotoxy(10,6);
	printf("[2] Log Into An Existing Account"); gotoxy(10,7);
	printf("[3] Panel Menu:"); gotoxy(10,8);
	printf("\nEnter Your Choice: ");  fflush(stdin); ch2=getche();
	if(ch2=='1' || ch2=='2' || ch2=='3'){} else
	{
		printf("\nInvalid Entry!Press Any Key To Try Again!"); getche(); goto e;
	}
	switch(ch2)
	{
		case '1':
			
			
			system("cls"); char no='y'; int an;
			FILE *fp; 
			fp=fopen("what.dat","wb+");
			if(fp==NULL) {  printf("Cannot open file!"); exit(10);  }
			srand(time(NULL));
	        an = 100000+rand()%100000;
	        fseek(fp,0,SEEK_END);
		    d.an=an;	
			gotoxy(24,1); printf("-----------------");
		    gotoxy(23,2); printf("|"); gotoxy(41,2); printf("|"); 
			gotoxy(24,3); printf("-----------------");  
	        gotoxy(25,2); printf("ACCOUNT SIGN UP"); gotoxy(0,5);       
	        printf("\n\n\t=> Account Title :"); fflush(stdin); gets(d.name);
	        printf("\n\n\t=> Date (DD/MM/YY) :"); scanf("%d/%d/%d",&d.i.d,&d.i.m,&d.i.y);
	        printf("\n\n\t=> Mobile No :"); fflush(stdin); gets(d.m);
	        printf("\n\n\t=> Address :"); fflush(stdin); gets(d.add);
	        printf("\n\n\t=> City :"); fflush(stdin); gets(d.city);
	        in:
	        printf("\n\n\t=> Initial Deposit Amount: "); 
			scanf("%d",&d.dep);
			if(d.dep<1000)
			{
				printf("\nInvalid Amoount!\nPress Anywhere to Try Again"); fflush(stdin); getch();
				
				goto in;
			}
	        printf("\n\n\t=> Password :"); fflush(stdin); gets(d.pw);
	        fwrite(&d,sizeof(d),1,fp); fclose(fp);
	        printf("\nYou Have Successfully Signed Up !\nPress Any key To Continue!"); getche(); goto e;
	        break ;
	        /*printf("\nYou Have Successfully Registered Yourself!\nPress Anywhere To Continue ..."); fflush(stdin); getche(); 
	        panel2();*/
	        
	        
	    case '2':
	    	
			system("cls"); char title[30] ,pass[20]; int co=0; gotoxy(10,10);
		    printf("\n\t=> Account Title :"); fflush(stdin); gets(title);
		    printf("\n\t=> Password :"); fflush(stdin); gets(pass);
		    fp=fopen("what.dat","rb+");
			if(fp==NULL) {  printf("Cannot open file!"); exit(11);  }
		    rewind(fp); 
			while(fread(&d,sizeof(d),1,fp)==1)
			{
				if(strcmp(title,d.name)==0 && strcmp(pass,d.pw)==0)
				{
					co++;
					printf("\nYou Have Successfully Logged In!\nPress Any key To Continue!"); fflush(stdin); getche();
					fclose(fp);
					panel3();
				}
			}
			if(co==0)
			{ 
			  printf("\n\tNo Such Records exist!"); printf("\n\nPress anywhere to continue!"); fclose(fp); getch(); goto e;
			}
			
		   break ;
		   
		case '3':
			
			system("cls");
			panel(); 
			break;
			
	}
}
panel3()
{
	g:
	system("cls"); char c;
	gotoxy(24,1); printf("-----------");
	gotoxy(23,2); printf("|"); gotoxy(35,2); printf("|"); 
	gotoxy(24,3); printf("-----------");  
	gotoxy(25,2); printf("MAIN MENU"); gotoxy(0,5);
	printf("\n\t[1] Transaction");
	printf("\n\t[2] Transfer");
	printf("\n\t[3] Update Details");
	printf("\n\t[4] Loan Facility");
	printf("\n\t[5] Chequebook Issue");
	printf("\n\t[6] Log Out");
	printf("\n\tEnter Your Choice : "); fflush(stdin); c=getche();
	switch(c)
 	{
		case '1':
			
			transac();  break;
			
		case '4':
			
			loan();	break;
			
		case '5':
		
		    cheaquebook(); break;
			
		case '2':
			
			transfer();    break;
			
		case '3':
		
	        modify();  break;	
	    
		case '6':
			
			system("cls");
			panel2();
			break; 
			
		default:
		  
		    printf("\nInvalid Entry!Press Anywhere To Continue!"); fflush(stdin); getche();	
			goto g;	
	
		    		
	}
}
transac()
{   
    d:
    system("cls");
	int choice; FILE *ft;
	ft=fopen("what.dat","rb+");
	printf("\t\tTransaction Window:"); 
	printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n3.Main Menu\nEnter your choice(1 for deposit and 2 for withdraw and 3 for Main Menu):");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    		
    		system("cls");
			char name[20]; int depo,co=0; long int recsize=sizeof(d);
    		printf("\nEnter your Account Title: "); fflush(stdin); gets(name);
    		printf("\nHow much rupees are you willing to deposit? "); scanf("%d",&depo);
    		rewind(ft);
    		while(fread(&d,sizeof(d),1,ft)==1)
    		{
    	
    			if(strcmp(name,d.name)==0)
    			{
    				d.dep=d.dep+depo;
    				printf("\nAmount of %d Rupees Has Been Deposited in your Account!\nYour New Balance Is: %d",depo,d.dep);
    				co++;
    				fseek(ft,-recsize,SEEK_CUR);
    				fwrite(&d,sizeof(d),1,ft);
    				printf("\nPress Any key To Continue!"); fflush(stdin); getche();
    				fclose(ft);
    				panel3();
				}
			}
			if(co==0)
			{
				printf("No Such Account Title exists!\nPress Any key To Try Again!"); fflush(stdin); getche();
				fclose(ft);
				goto d;
			}
    		
    	case 2:
    		
    		system("cls");
			char name1[20]; int with,co1=0; long int recsize1=sizeof(d);
			ft=fopen("what.dat","rb+");
    		printf("\nEnter your Account Title: "); fflush(stdin); gets(name1);
    		printf("\nHow much rupees are you willing to Withdraw? "); scanf("%d",&with);
    		rewind(ft);
    		while(fread(&d,sizeof(d),1,ft)==1)
    		{
    			if(strcmp(name1,d.name)==0)
    			{
    				if(d.dep>=with)
    				{
					d.dep=d.dep-with;
    				printf("\nAmount of %d Rupees Has Been Withdrawed from your Account!\nYour New Balance Is: %d",with,d.dep);
    				co1++;
    				fseek(ft,-recsize1,SEEK_CUR);
    				fwrite(&d,sizeof(d),1,ft);
    				printf("\nPress Any key To Continue!"); fflush(stdin); getche();
    				fclose(ft);
    				panel3();
    			    }
    			    else 
    			    {
    			    	printf("\nSorry!\nCannot Process Request Due To Insufficient Balance"); 
    			    	fclose(ft); printf("\nPress Anywhere To Continue!"); fflush(stdin); getche(); 
    			    	panel3();
					}
				}
			}
			if(co1==0)
			{
				printf("No Such Account Title exists!\nPress Any key To Try Again!"); fclose(ft); fflush(stdin); getche();
				goto d;
			}
			
    	case 3:
    		
    		panel3();
    		break;
    		
	}
}
int main()
{
	 
	system("cls");
	system("color 3F"); 
	blink();
	welcome();
	loading();
	panel(); 
}
