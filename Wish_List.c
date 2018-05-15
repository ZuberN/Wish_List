//Zuber Najam
//12-08-2017
//Wish_List.c 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ENTRIES 40

typedef struct {
	char name[20];
	char type[20];
	int id;
	int quantity;
	double price;
	double rating;
} giftbag;

void initializeEntries(giftbag list[], int *size)
{
	strcpy(list[0].name, "Gameboy");
	strcpy(list[0].type, "Electronics");
	list[0].id = 300;
	list[0].quantity = 10;
	list[0].price = 30.00;
	list[0].rating = 5.0;

	strcpy(list[1].name, "Toothbrush");
	strcpy(list[1].type, "Hygiene");
	list[1].id = 301;
	list[1].quantity = 4;
	list[1].price = 1.25;
	list[1].rating = 1.0;

	strcpy(list[2].name, "Barbie");
	strcpy(list[2].type, "Toys");
	list[2].id = 302;
	list[2].quantity = 8;
	list[2].price = 15.00;
	list[2].rating = 3.2;

	strcpy(list[3].name, "iPhone 5S");
	strcpy(list[3].type, "Electronics");
	list[3].id = 303;
	list[3].quantity = 2;
	list[3].price = 50.25;
	list[3].rating = 4.5;

	strcpy(list[4].name, "PS4");
	strcpy(list[4].type, "Electronics");
	list[4].id = 304;
	list[4].quantity = 1;
	list[4].price = 400.00;
	list[4].rating = 5.0;

	strcpy(list[5].name, "Pony");
	strcpy(list[5].type, "Pet");
	list[5].id = 305;
	list[5].quantity = 1;
	list[5].price = 1000.00;
	list[5].rating = 5.0;

	*size = 6;
	return;
}
char menu() {
	char enter;
	printf("\n***************************************\n");
	printf("Please select from the options below:\n");
	printf("A - ADD a new gift\n");
	printf("D - DELETE an gift\n");
	printf("P - PRINT entire catalog\n");
	printf("S - SAVE the current catalog\n");
	printf("C - CLEAR the entire catalog\n");
	printf("U - UPDATE the quantity\n");
	printf("Q - QUIT\n");
	printf("What would you like to do: ");
	scanf(" %c", &enter);
	return enter;
}

void addEntry(giftbag list[], int *size)
{
	printf("\nEnter name : ");
	scanf("%s", list[*size].name);
	printf("\nEnter type : ");
	scanf("%s", list[*size].type);
	printf("\nEnter id : ");
	scanf("%d", &list[*size].id);
	printf("\nEnter quantity : ");
	scanf("%d", &list[*size].quantity);
	printf("\nEnter price : ");
	scanf("%lf", &list[*size].price);
	printf("\nEnter rating : ");
	scanf("%lf", &list[*size].rating);
	(*size)++;
	return;
}
void deleteEntry(giftbag list[], int *size)
{
	int i, id;
	printf("List of ID #'s:\n");
	for (i = 0; i<*size; i++)
		printf("%d ", list[i].id);
	printf("\nPlease enter the I.D.: ");
	scanf("%d", &id);
	for (i = 0; i<*size; i++)
	{
		if (list[i].id == id)
		{
			strcpy(list[i].type, list[*size - 1].type);
			strcpy(list[i].name, list[*size - 1].name);
			list[i].id = list[*size - 1].id;
			list[i].quantity = list[*size - 1].quantity;
			list[i].price = list[*size - 1].price;
			list[i].rating = list[*size - 1].rating;
			(*size)--;
		}
	}
	return;
}
void display(giftbag list[], int *size)
{
	int i;
	if (*size == 0)printf("*****Catalog is empty*****\n");
	for (i = 0; i<*size; i++)
	{
		printf("---Catalog Entry %d---\n", i + 1);
		printf("TYPE: %s\n", list[i].type);
		printf("NAME: %s\n", list[i].name);
		printf("I.D.#: %d\n", list[i].id);
		printf("QTY:    %d\n", list[i].quantity);
		printf("PRICE:   $%.2f\n", list[i].price);
		printf("CUSTOM RATING: %.1f\n\n", list[i].rating);
	}
	return;
}
void createList(giftbag list[], int *size)
{
	FILE *f;
	int i;
	f = fopen("Records.txt", "w");
	if (f == 0)
	{
		printf("Error!\n");
		exit(1);
	}
	if (*size == 0)
		fprintf(f, "*****WishList Empty*****\n");
	for (i = 0; i<*size; i++)
	{
		fprintf(f, "---WishList Entry %d---\n", i + 1);
		fprintf(f, "TYPE: %s\n", list[i].type);
		fprintf(f, "NAME: %s\n", list[i].name);
		fprintf(f, "I.D.#: %d\n", list[i].id);
		fprintf(f, "QTY:    %d\n", list[i].quantity);
		fprintf(f, "PRICE:   $%.2f\n", list[i].price);
		fprintf(f, "Rating: %.2f\n\n", list[i].rating);
	}
	fclose(f);
	return;
}
void clearList(giftbag list[], int *size)
{
	*size = 0;
	return;
}
void update(giftbag list[], int *size)
{
	int i, id;
	int quantity_new;
	printf("List of ID #'s:\n");
	for (i = 0; i<*size; i++)
		printf("%d ", list[i].id);
	printf("\nPlease enter the I.D.: ");
	scanf("%d", &id);
	for (i = 0; i<*size; i++)
	{
		if (list[i].id == id)
		{
			printf("---Catalog Entry %d---\n", i + 1);
			printf("TYPE: %s\n", list[i].type);
			printf("NAME: %s\n", list[i].name);
			printf("I.D.#: %d\n", list[i].id);
			printf("QTY:    %d\n", list[i].quantity);
			printf("PRICE:   $%.2f\n", list[i].price);
			printf("Rating: %.2f\n\n", list[i].rating);
			printf("Please enter the updated quantity: ");
			scanf("%d", &quantity_new);
			list[i].quantity = quantity_new;
		}
	}
	return;
}
int main() {
	giftbag list[MAX_ENTRIES];
	int size = 0;
	initializeEntries(list, &size);
	printf("Welcome to Make A Wish Foundations Wishlist! This program allows you to create an inventory to track gift items.\n");
	printf("The previous 6 gifts have already been entered for you.\n");
	while (1) {
		char sel = menu();
		if (sel == 'A' || sel == 'a') {
			addEntry(list, &size);
		}
		else if (sel == 'D' || sel == 'd') {
			deleteEntry(list, &size);
		}
		else if (sel == 'P' || sel == 'p') {
			display(list, &size);
		}
		else if (sel == 'S' || sel == 's') {
			createList(list, &size);
		}
		else if (sel == 'C' || sel == 'c') {
			clearList(list, &size);
		}
		else if (sel == 'U' || sel == 'u') {
			update(list, &size);
		}
		else if (sel == 'Q' || sel == 'q') {
			printf("Goodbye.\n");
		}
		else printf("Enter a valid command\n");
	}
	return 0;
}