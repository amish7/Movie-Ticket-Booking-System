#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char username[10];
void login()
{
	int a = 0, i = 0;
	char my_username[10], c = ' ';
	char password[10], code[10];
	do
	{
		printf("\n  +++++++++++++++++++++++++++++  LOGIN FIRST  +++++++++++++++++++++++++++++  ");
		printf(" \n\n                 ENTER USERNAME:-");
		scanf("%s", &my_username);
		printf(" \n\n                 ENTER PASSWORD:-");
		while (i < 10)
		{
			password[i] = getch();
			c = password[i];
			if (c == 13) break;
			else printf("*");
			i++;
		}
		password[i] = '\0';
		//char code=password;
		i = 0;
		if (strcmp(my_username, "user") == 0 && strcmp(password, "pass") == 0)
		{
			strcpy(username, my_username);
			printf("  \n\n\n       WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
			printf("\n\n\n\t\t\t\tPress any key to continue...");
			getch();
			break;
		}
		if (strcmp(my_username, "admin") == 0 && strcmp(password, "admin") == 0)
		{
			strcpy(username, my_username);
			printf("  \n\n\n       WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
			printf("\n\n\n\t\t\t\tPress any key to continue...");
			getch();
			break;
		}
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();

	}
	while (a <= 2);
	if (a > 2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		getch();
	}
	system("cls");
}
struct my_book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
} b;
int seat = 60;
void inserting_movie();//function used by the admin to insert movies in the system
void viewAllMovies(); // function used by the user to view all the movies present in the system
void finding_movie(); // function used by the user to find all the movies present in the system using the movie code
void book_ticket(); // function used by the user for booking the available tickets
void findingOldRecord(); // function used by the user to see all the transactions till now
void main()
{
	login();
	int ch;
	do {
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n");
		printf("\t Moive Ticket booking ");
		printf("\n");
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\nEnter >1< To Insert Movie");
		printf("\nEnter >2< To View All Movie");
		printf("\nEnter >3< To Find Movie ");
		printf("\nEnter >4< To Book Tickets");
		printf("\nEnter >5< To View All Transactions");
		printf("\nEnter >0< To Exit ");

		printf("\nEnter your Choice ::");
		scanf("%d", &ch);
		system("cls");

		switch (ch)
		{
		case 1 : // calling the function for inserting movies
			inserting_movie();
			break;
		case 2: // calling the function for viewing the movies
			viewAllMovies();
			break;

		case 3: // calling the function for finding the movies
			finding_movie();
			break;

		case 4: // calling the function for booking the ticket
			book_ticket();
			break;
		case 5: // calling the function for checking the old record
			findingOldRecord();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Wrong choice !");
			break;
		}
	} while (ch != 0);
}

void finding_movie() //find details
{
	if (strcmp(username, "user") == 0)
	{
		struct my_book b;
		FILE *file1;
		char ch[20];
		printf("Enter movie code :");
		scanf("%s", ch);
		file1 = fopen("data.txt", "r");
		if (file1 == NULL)
		{
			printf("file does not found !");
			exit(1);
		}
		else
		{
			while (getc(file1) != EOF)
			{
				fscanf(file1, "%s %s %s %d", b.code, b.name, b.date, &b.cost);
				if (strcmp(b.code, ch) == 0)
				{
					printf("\n Record Found\n");
					printf("\n\t\tCode ::%s", b.code);
					printf("\n\t\tMovie name ::%s", b.name);
					printf("\n\t\tMovie date ::%s", b.date);
					printf("\n\t\tPrice of ticket ::%d", b.cost);
				}
			}
		}
		fclose(file1);
		system("cls");
	}
}
void viewAllMovies()
{
	if (strcmp(username, "user") == 0)
	{
		char ch;
		FILE *file1;
		file1 = fopen("data.txt", "r");
		if (file1 == NULL)
		{
			printf("file does not found !");
			exit(1);
		}
		else
		{
			system("cls");
			while ( ( ch = fgetc(file1) ) != EOF )
				printf("%c", ch);
		}
		fclose(file1);
	}
}
void book_ticket()
{
	if (strcmp(username, "user") == 0)
	{
		struct my_book b;
		FILE *file1;
		FILE *file2;
		int total_seat, mobile, total_amount;
		char name[20];
		char ch; //used in display all movies
		char movie_code[20]; //for searching
		// display all moives by default for movie code
		file1 = fopen("data.txt", "r");
		if (file1 == NULL)
		{
			printf("file does not found !");
			exit(1);
		}
		else
		{
			system("cls");
			while ( ( ch = fgetc(file1) ) != EOF )
				printf("%c", ch);
		}
		fclose(file1);
		//display ends
		printf("\n For Book ticket Choice Movie(Enter Movie Code First Latter Of Movie)\n");
		printf("\n Enter movie code :");
		scanf("%s", movie_code);
		//system("clear");
		file1 = fopen("data.txt", "r");
		if (file1 == NULL)
		{
			printf("file does not found !");
			exit(1);
		}
		else
		{
			while (getc(file1) != EOF)
			{
				fscanf(file1, "%s %s %s %d", b.code, b.name, b.date, &b.cost);
				if (strcmp(b.code, movie_code) == 0)
				{
					printf("\n Record Found\n");
					printf("\n\t\tCode ::%s", b.code);
					printf("\n\t\tMovie name ::%s", b.name);
					printf("\n\t\tdate name ::%s", b.date);
					printf("\n\t\tPrice of ticket::%d", b.cost);
				}
			}
		}
		printf("\n* Fill Deatails  *");
		printf("\n your name :");
		scanf("%s", name);
		printf("\n mobile number :");
		scanf("%d", &mobile);
		printf("\n Total number of tickets :");
		scanf("%d", &total_seat);
		total_amount = b.cost * total_seat;
		printf("\n ENJOY MOVIE \n");
		printf("\n\t\tName : %s", name);
		printf("\n\t\tMovie name : %s", b.name);
		printf("\n\t\tTotal seats : %d", total_seat);
		printf("\n\t\tCost per ticket : %d", b.cost);
		printf("\n\t\tTotal Amount : %d", total_amount);
		file2 = fopen("oldTransaction.txt", "a");
		if (file2 == NULL)
		{
			printf("FIle not Found");
		}
		else
		{
			fprintf(file2, "%s %d %d %d %s %d \n", name, mobile, total_seat, total_amount, b.name, b.cost);
			printf("\n Record insert Sucessfull to the old record file");
		}
		printf("\n");
		fclose(file2);
		fclose(file1);
	}
}
void findingOldRecord()
{
	if (strcmp(username, "user") == 0)
	{
		char ch;
		FILE *file1;	file1 = fopen("oldTransaction.txt", "r");
		if (file1 == NULL)
		{
			printf("file does not found !");
			exit(1);
		}
		else
		{
			system("cls");
			while ( ( ch = fgetc(file1) ) != EOF )
				printf("%c", ch);
		}
		fclose(file1);
	}
}
void inserting_movie()
{
	if (strcmp(username, "admin") == 0)
	{
		FILE *file1;
		struct my_book b;
		printf("Enter movie code :- ");
		scanf("%s", b.code);
		printf("Enter  name :- ");
		scanf("%s", b.name);
		printf("Enter Release Date:- ");
		scanf("%s", b.date);
		printf("Enter Ticket Price:- ");
		scanf("%d", &b.cost);
		file1 = fopen("data.txt", "a");
		if (file1 == NULL)
		{
			printf("FIle not Found");
		}
		else
		{
			fprintf(file1, "%s %s %s %d \n", b.code, b.name, b.date, b.cost);
			printf("Recorded Successfully");
		}
		printf("\n");
		fclose(file1);
		system("cls");
	}
	else
	{
		printf("MOVIE CANNOT BE ADDED BY USER, LOGIN USING ADMIN TO PERFORM THIS");
	}
}