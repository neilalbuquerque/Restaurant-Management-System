#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<time.h>

struct table
{
    int table_number;
    char name[30];
	int np;
    char phone_number[11];
    char email[40];
    int booked;
    struct table *next;
};

struct waitinglist
{
	char name[30];
	int np;
    char phone_number[11];
    char email[40];
	int token;
	struct waitinglist *next3;
	int table_type;
};
struct waitinglist *add_to_waitinglist(int);
struct table *add_from_waitinglist(struct table *,int );
struct waitinglist *startwl=NULL;
int token1=0;
struct waitinglist *w;
struct waitinglist *createwl(struct waitinglist	*);
struct waitinglist *del(struct waitinglist *);
struct waitinglist *wdisplay();
struct table *start_2=NULL;
struct table *start_4=NULL;
struct table *start_6=NULL;
int avail_2=5;
int avail_4=5;
int avail_6=5;
struct table *book_table();
struct table *checkout();
struct table *search();
struct table *display();
struct table *initialize(struct table *,int);
struct table *add(struct table *,int ,int);
void greetings();
void main_menu();
void display1(struct table *);
struct table *delete(struct table*,int);
int main()
{
    start_2=initialize(start_2,2);
	start_4=initialize(start_4,4);
    start_6=initialize(start_6,6);
	getch();
    greetings();
    main_menu();
    return 0;
}

void greetings()
{
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);
    system("cls");
	system("COLOR 1F");
    printf("\t\t         -----------------------------------------------------------\n");
	printf("\t\t        |                                                          |\n");
	printf("\t\t        |   OOOO OOOO  OOOOO OOOOO OOOOO OOOOO O   O  OOOO  OOOO   |\n");
	printf("\t\t        |  O     O   O O     O       O     O   OO  O O     O       |\n");
	printf("\t\t        |  O  OO OOOO  OOOO  OOOO    O     O   O O O O  OO  OOO    |\n");
	printf("\t\t        |  O   O O  O  O     O       O     O   O  OO O   O     O   |\n");
	printf("\t\t        |   OOO  O   O OOOOO OOOOO   O   OOOOO O   O  OOO  OOOO    |\n");
	printf("\t\t        |                                                          |\n");
	printf("\t\t        -----------------------------------------------------------\n");
	printf("\t\t\t     *************************************************\n");
	printf("\t\t\t     *                                               *\n");
	printf("\t\t\t     *       -----------------------------           *\n");
	printf("\t\t\t     *         WELCOME TO NSP RESTAURANT             *\n");
	printf("\t\t\t     *       -----------------------------           *\n");
	printf("\t\t\t     *          ITS FINGER LICKING GOOD!!            *\n");
	printf("\t\t\t     *                                               *\n");
	printf("\t\t\t     *                                               *\n");
	printf("\t\t\t     *             Bandra(w),Mumbai.                 *\n");
	printf("\t\t\t     *                  INDIA                        *\n");
	printf("\t\t\t     *      CONTACT US:8080408783,0610423280         *\n");
	printf("\t\t\t     *************************************************\n\n\n");
    printf("%s\n", asctime(tm));
	printf(" \n Press any key to continue:");
	getch();
    system("cls");
}
void main_menu(){
    int option;
    do{
    system("COLOR 2F");
    printf("\t\t****************************************************************************\n");
    printf("\t\t*                                MAIN MENU                                 * \n");
    printf("\t\t****************************************************************************\n");
    printf("\t\t*\t\t              1.BOOK A TABLE                               *\n");
    printf("\t\t*\t\t              2.CHECKOUT                                   *\n");
    printf("\t\t*\t\t              3.SEARCH DETAILS                             *\n");
    printf("\t\t*\t\t              4.DISPLAY DETAILS                            *\n");
	printf("\t\t*\t\t              5.DISPLAY WAITLIST                           *\n");
    printf("\t\t*\t\t              6.EXIT                                       *\n");
    printf("\t\t*__________________________________________________________________________*\n");
    printf("\nEnter your option: ");
    scanf("%d",&option);
    switch(option){
        case 1: system("cls");
                book_table();
                break;
        case 2: system("cls");
                checkout();
                break;
        case 3: system("cls");
                search();
                break;
        case 4: system("cls");
                display();
                break;
        case 5: system("cls");
				wdisplay();
				break;
		case 6: exit(1);

        default: printf("\nInvalid option!");
                 printf("...........Press any key to try again");
                 getch();
                 system("cls");
    }
    }while(option!=5);
	printf("");
}
struct table *book_table(struct table *start)
{
    struct table *new_table,*ptr;
    int n;
    system("COLOR 1F");
    mm:
    printf(" _______________________________________________\n");
    printf("| SR.NO | SEATING CAPACITY | TOTAL | AVAILABLE |\n");               
    printf("|_______|__________________|_______|___________|\n");
    printf("|   1.  | TABLE FOR 2      |   5   |     %d     |\n",avail_2);
    printf("|   2.  | TABLE FOR 4      |   5   |     %d     |\n",avail_4);
    printf("|   3.  | TABLE FOR 6      |   5   |     %d     |\n",avail_6);
    printf("|_______|__________________|_______|___________|\n");
    printf("Enter the number of people\n");
	scanf("%d",&n);
	if(n>0 && n<=2)
	{
		add(start_2,n,2);
	}
		if(n>2 && n<=4)
	{
		add(start_4,n,4);
	}
		if(n>4 && n<=6)
	{
		add(start_6,n,6);
	}
}
struct table *add(struct table *start1,int n,int c)
{

	int a,i;
	struct table *ptr,*new_table;
	if(c==2)
	{
		ptr=start_2;
		a=avail_2;
		if(avail_2!=0)
		avail_2--;
	}
	if(c==4)
	{
		ptr=start_4;
		a=avail_4;
		if(avail_4!=0)
		avail_4--;
	}
	if(c==6)
	{
		ptr=start_6;
		a=avail_6;
		if(avail_6!=0)
		avail_6--;	  
	}
	if(a==0)
	{
		printf("YOU HAVE BEEN PLACED ON THE WAITLIST\n");
		add_to_waitinglist(2);
	}
    else if(a>0)
    {
		system("cls");
        printf("_____________________________________________________________________________\n");
        printf("                              BOOKING FOR A TABLE FOR %d                     \n",c);
        printf("_____________________________________________________________________________\n");
		while(ptr->booked==1)
    	{
			ptr=ptr->next;
		}
		printf("\n");
        ptr->booked=1;
        printf("Enter your name: ");
        scanf("%s",ptr->name);
		ptr->np=n;
        printf("\nEnter your phone no. : ");
        scanf("%s",ptr->phone_number);
        printf("\nEnter your email: ");
        scanf("%s",ptr->email);
        printf("\nTable number alloted: %d",ptr->table_number);
        printf("\n_____________________________________________________________________________\n");
        printf("RESERVATION DONE SUCCESSFULLY!\n");
		}
		                printf("\n\n.......Press any key to return to main menu");
                getch();
                system("cls");
	}

struct table *checkout(){
    int tn,ton,a;
	struct table *ptr;
    printf("Enter your table number:");
    scanf("%d",&tn);
        if(tn>=1 && tn<=5){
            ton=2;
            ptr=start_2;
			a=avail_2;
        }
        else if(tn>=6 && tn<=10){
            ton=4;
            ptr=start_4;
			a=avail_4;
        }
        else if(tn>=11 && tn<=15){
            ton=6;
            ptr=start_6;
			a=avail_6;
        }
		if(a==5)
		{
	        printf("\nNo tables have been allocated yet ");
	        printf("\n\n\n............Press any key to go to main menu.");
	        getch();
	        system("cls");
	        main_menu();
		}
		else
		{
        	while (ptr->table_number!=tn)
            	ptr=ptr->next;
	        printf("****************************************************************************\n");
	        printf("                                CHECK OUT                                   \n");
	        printf("****************************************************************************");
	        printf("\nTABLE NUMBER : %d",ptr->table_number);
	        printf("\nNAME         : %s",ptr->name);
	        printf("\nPHONE NUMBER : %s",ptr->phone_number);
	        printf("\nEMAIL        : %s",ptr->email);
	        printf("\nNO. OF PEOPLE: %d",ptr->np);
	        printf("\n____________________________________________________________________________");
	        printf("\nThank you for choosing us, we hope you've had a great time!");
	        delete(ptr,ton);
        }
    	printf("\n\n................Press any key to continue to the main menu");
    	getch();
    	system("cls");
}

struct table *delete(struct table *ptr,int tn)
{
	    ptr->booked=0;
		if(tn==2){
			avail_2++;
        }
        else if(tn==4){
           avail_4++;
        }
        else if(tn==6){
           avail_6++;
        }
		printf("1\t");
		if(startwl!=NULL)
		{printf("1\t");
			add_from_waitinglist(ptr,tn);
			}
}

struct table *add_from_waitinglist(struct table *ptr,int k)
{
	struct waitinglist *a,*temp,*ka;
	int tn,na;
    char n[30],phone[10], mail[40];

	a=startwl;
	temp=a;
	while(a->table_type!=k)
	{
		temp=a;
		a=a->next3;
	}
	printf("2\t");
/*	 phone=a->phone_number;*/
	strcpy(phone,a->phone_number);
	/*mail=(a->email);*/
	na=a->np;
	ptr->booked=1;
	strcpy(ptr->name,a->name);
	/*ptr->phone_number=phone;*/
	strcpy(ptr->phone_number,a->phone_number);
	strcpy(ptr->email,a->email);
	ptr->np=na;
		if(k==2){
			avail_2--;
        }
        else if(k==4){
           avail_4--;
        }
        else if(k==6){
           avail_6--;
        }
		printf("%p\t",temp);
		ka=temp;
		printf("%p\t",ka);
		printf("3\t");
	/*while(ka->next3!=NULL)
	{
		printf("5\t");
		ka=ka->next3;
		ka->token--;
	}*/
	/*token1--;*/
	printf("Token no. %d has been allotted a table\n",a->token);
	temp->next3=a->next3;
	printf("7\t");
	free(a);
	    	getch();
    	system("cls");
		main_menu();	 
}

struct table *initialize(struct table *start,int c)
{
    int i,a,b;
    struct table *new_node,*ptr;
    /*ptr=start;*/
    if(c==2)
    {
        a=1;
        b=5;
    }
    else if (c==4)
    {
        a=6;
		b=10;
    }
    else
    {
        a=11;
		b=15;
    }
    for(i=a;i<=b;i++)
    {
        new_node=(struct table*)malloc(sizeof(struct table));
        new_node->booked=0;
        new_node->table_number=i;
        if(start==NULL)
        {
            start=new_node;
            new_node->next=NULL;
        }
        else
        {
			ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
			ptr=new_node;
			new_node->next=NULL;
	     }
    }
    ptr->next=start;

	ptr=start;

	for(i=0;i<5;i++)
	{
		printf("%d",ptr->table_number);
		ptr=ptr->next;
	}
    return start;
}

struct waitinglist *add_to_waitinglist(int c)
{
	int a=c;
	struct waitinglist *wl,*ptr,*temp;
	wl=(struct waitinglist*)malloc(sizeof(struct waitinglist));
	printf("Enter your name: ");
    scanf("%s",wl->name);
	printf("Enter the number of people:");
	scanf("%d",&wl->np);
	printf("1\t");
    printf("\nEnter your phone no. : ");
    scanf("%s",wl->phone_number);
    printf("\nEnter your email: ");
    scanf("%s",wl->email);
	wl->token=++token1;
	printf("\nToken number alloted: %d",wl->token);
	wl->table_type=a;
	if(startwl==NULL)
	{ 	printf("1\t");
		startwl=wl;
		wl->next3=NULL;
	}
	else 
	{
		ptr=startwl;
		while(ptr->next3!=NULL)
		{
			printf("2 ");
			temp=ptr;
			ptr=ptr->next3;
		}
		ptr->next3=wl;
		ptr=wl;
		ptr->next3=NULL;	
	}  	   

}
struct waitinglist *wdisplay()
{
	struct waitinglist *wl;
	if(startwl== NULL)
		printf("\nNO ONE IS WAITING");
	else
	{
		wl=startwl;
		printf("\n");
		while(wl!=NULL)
		{
			printf("****************************************************************************\n");
        	printf("                                WAITING LIST                                \n");
        	printf("****************************************************************************");
        	printf("\nTOKEN NUMBER : %d",wl->token);
        	printf("\nNAME         : %s",wl->name);
        	printf("\nPHONE NUMBER : %s",wl->phone_number);
        	printf("\nEMAIL        : %s",wl->email);
        	printf("\nNO. OF PEOPLE: %d",wl->np);
        	printf("\n____________________________________________________________________________");
			wl=wl->next3;
			getch();
		}
	}
    printf("\n\n................Press any key to continue to the main menu");
	getch();
	system("cls");
	main_menu();

}

struct table *search()
{
    int tn,ton,a;
	struct table *ptr;
    printf("Enter the table number you wish to search:");
    scanf("%d",&tn);
    if(tn<1 || tn>15)
	{
		printf("\n\nTable does not exist!! Enter a number between 1-15");
		getch();
		system("cls");
		search();
	}
	else if(tn>=1 && tn<=5)
	{
        ptr=start_2;
		a=avail_2;
    }
    else if(tn>=6 && tn<=10)
	{
        ptr=start_4;
		a=avail_4;
    }
    else if(tn>=11 && tn<=15)
	{
	    ptr=start_6;
		a=avail_6;
    }
	if(a==5)
	{
    	printf("\nNo tables have been allocated yet ");
        printf("\n\n\n............Press any key to go to main menu.");
        getch();
        system("cls");
        main_menu();
	}
	else
	{
        while (ptr->table_number!=tn)
        {
		    ptr=ptr->next;
		}
		printf("****************************************************************************\n");
        printf("                               TABLE NUMBER %d                              \n",ptr->table_number);
        printf("****************************************************************************");
        printf("\nTABLE NUMBER : %d",ptr->table_number);
        printf("\nNAME         : %s",ptr->name);
        printf("\nPHONE NUMBER : %s",ptr->phone_number);
        printf("\nEMAIL        : %s",ptr->email);
        printf("\nNO. OF PEOPLE: %d",ptr->np);
        printf("\n____________________________________________________________________________");
    }
    printf("\n\n................Press any key to continue to the main menu");
    getch();
    system("cls");	
    main_menu();   
}

struct table *display()
{
	int tn, a, i;
	struct table *ptr;	     
	ptr=start_2;
	printf("\nTABLE FOR 2\n");
	for(tn=1;tn<=5;tn++)
	{
		a=avail_2;
		if(a==5)
		{
       	   	   printf("\nNo tables for 2 have been allocated yet.");
			break;
		}
		else
		{
			if(ptr->booked==1)
			{
				printf("\n\n");
				printf("****************************************************************************\n");
			    printf("                               Table Number %d                              \n",ptr->table_number);
			    printf("****************************************************************************");
			    printf("\nNAME         : %s",ptr->name);
			    printf("\nPHONE NUMBER : %s",ptr->phone_number);
			    printf("\nEMAIL        : %s",ptr->email);
			    printf("\nNO. OF PEOPLE: %d",ptr->np);
			    printf("\n____________________________________________________________________________");	    		
				ptr=ptr->next;	   	   	   	   	   	   
			}
			else if(ptr->booked==0)
			{
				ptr=ptr->next;	   	   	   	   	   	   
			}
    	}
	}
	ptr=start_4;
	printf("\n\n\n\nTABLE FOR 4\n");
	for(tn=1;tn<=5;tn++)
	{
		a=avail_4;
		if(a==5)
		{
       	   	printf("\nNo tables for 4 have been allocated yet.");
			break;
		}
		else
		{
			if(ptr->booked==1)
			{
				printf("\n\n");
				printf("****************************************************************************\n");
			    printf("                               Table Number %d                              \n",ptr->table_number);
			    printf("****************************************************************************");
			    printf("\nNAME         : %s",ptr->name);
			    printf("\nPHONE NUMBER : %s",ptr->phone_number);
			    printf("\nEMAIL        : %s",ptr->email);
			    printf("\nNO. OF PEOPLE: %d",ptr->np);
			    printf("\n____________________________________________________________________________");	    		
				ptr=ptr->next;	   	   	   	   	   	   
			}
			else if(ptr->booked==0)
			{
				ptr=ptr->next;	   	   	   	   	   	   
			}
    	}
	}	
	ptr=start_6;
	printf("\n\n\n\nTABLE FOR 6\n");
	for(tn=1;tn<=5;tn++)
	{
		a=avail_6;
		if(a==5)
		{
       	   	   printf("\nNo tables for 6 have been allocated yet.");
			break;
		}
		else
		{
			if(ptr->booked==1)
			{
				printf("\n\n");
				printf("****************************************************************************\n");
		   	    printf("                               Table Number %d                              \n",ptr->table_number);
		   	    printf("****************************************************************************");
		   	    printf("\nNAME         : %s",ptr->name);
		   	    printf("\nPHONE NUMBER : %s",ptr->phone_number);
			    printf("\nEMAIL        : %s",ptr->email);
			    printf("\nNO. OF PEOPLE: %d",ptr->np);
			    printf("\n____________________________________________________________________________");	    		
				ptr=ptr->next;	   	   	   	   	   	   
			}
			else if(ptr->booked==0)
			{
				ptr=ptr->next;	   	   	   	   	   	   
			}
    	}
	}
	printf("\n\n\n............Press any key to go to main menu.");
    getch();
    system("cls");
    main_menu();
}

