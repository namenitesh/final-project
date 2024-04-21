// Including system libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i ; char c ;
#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 50
#define MAX_STUDENT_NAME 50

// Use of a structure // Use of arrays
// Define a struct to represent book records
struct Book {
	char studentname[MAX_STUDENT_NAME];
	int symbolno;
    int bookId;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
}books[MAX_BOOKS];

// Arguments Passed by reference
// Function to read book details from user input 
void readBook( struct Book *book ) {
	printf("Enter Student's name : ");
    scanf("%s", book->studentname);
    printf("Enter Symbol number : ");
    scanf("%d", &book->symbolno);
    printf("Enter Book ID: ");
    scanf("%d", &book->bookId);
    printf("Enter Title: ");
    scanf("%s", book->title);
    printf("Enter Author: ");
    scanf("%s", book->author);
}

// Arguments Passed by reference
// Function to display book details
void displayBook( struct Book *book ) {
	printf("Student's name: %s\n", book->studentname);
	printf("Symbol number: %d\n", book->symbolno);
    printf("Book ID: %d\n", book->bookId);
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
}

// Arguments Passed by value // File Handling 
// Function to write book records to a file
void writeToFile( struct Book books[], int numBooks ) {
    FILE *file = fopen("library_records.txt", "w");
    if ( file == NULL ) {
        printf("Error opening file for writing.\n");
        exit(1);
    }
    for (i = 0; i < numBooks; i++) {
        fprintf(file, "Student's name = %s \nSymbol number = %d \nBookId = %d \nTitle = %s \nAuthor = %s\n========================== \n", books[i].studentname, books[i].symbolno, books[i].bookId, books[i].title, books[i].author);
    }

    fclose( file );
}

// File Handling 
// Function to show all data in file
void datainfile() {
	FILE *file = fopen("library_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file \n");
        exit(1);
    }
    	do{
    		c = fgetc(file);
    		putchar(c);
		}while( c != EOF );
    fclose( file );
}

int main() {
    int numBooks, choice ;
    
	do{
    	printf(" 1) Take new entries of books :\n");
    	printf(" 2) Show stored data :\n");
    	printf(" 3) Exit program : \n\n");
    	printf("Make your choice : ");
    	scanf("%d",&choice);
    	printf("\n");
    	switch(choice) {
    	
    	case 1:
			printf("Enter the number of books to add : ");
    		scanf("%d", &numBooks);

    		// Read book details
    		for (i = 0; i < numBooks; i++) {
        		printf("\nEnter details for book %d:\n", i + 1);
        		readBook(&books[i]);
    		}

    		// Display book details
    		printf("\nLibrary Book Details:\n");
    		for (i = 0; i < numBooks; i++) {
        		displayBook(&books[i]);
        		printf("\n");
    		}

    		// Write book records to a file
    		writeToFile(books, numBooks);
    		printf("\nLibrary records written to 'library_records.txt'.\n");
    		break;
	
		case 2:
			// show data in file
    		datainfile();
			break;
			
		case 3:
			break;
	
		default: 
			printf("\n Invalid choice !!");
			break;
	}

}while( choice != 3 );

return 0;
}

