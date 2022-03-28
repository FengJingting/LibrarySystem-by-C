#include <stdio.h>
#include "library.h"
#include "book_management.h"
#include "search_for_books.h"
#include "utility.h"
#include <string.h>
#include <stdlib.h>

// librarian add a book
int add_book(BookList* theBookList)
{
    pBook head = theBookList->list;
    pBook temp = head->next;
    char title[100];
    char authors[100];
    unsigned int year;
    unsigned int copies;
    printf("Enter the title of the book you wish to add:");
    scanf("\n");
    fgets(title,30,stdin);
    // pretreatment
    if( title[ strlen(title) - 1 ] == '\n' )
    {
        title[ strlen(title) - 1] = '\0';
    }
    // add the information of book
    printf("Enter the author of the book you wish to add:");
    scanf("%s",authors);
    printf("Enter the year of the book you wish to add was released:");
    scanf("%u",&year);
    printf("Enter the number of copies of the book:");
    scanf("%u",&copies);
    if(!temp)
    {
        temp = (pBook)malloc(sizeof(Book));
        head->next = temp;
    }else {
        while(temp)
        {
            if(0 == (strcmp(temp->title,title)) && 0 == (strcmp(temp->authors,authors)) && temp->year == year)
            {
                // if the book already exits
                printf("\nBook already exits,do you want to add copies based on it?\n 1 Yes\n 2 No\nEnter your choice:");
                int option;
                scanf("%d",&option);
                printf("%d",option);
                if (1==option){
                    temp->copies += copies;
                    return 1;
                }else if(2==option){
                    return 0;
                }else{
                    printf("Invalid Choice!");
                    clear();
                    return 0;
                }
            }
            temp = temp->next;
        }
        temp = head->next;

        while(temp->next)
        {
            temp = temp->next;
        }
        pBook last = (pBook)malloc(sizeof(Book));
        temp->next = last;
        temp = last;
    }
    // copy the information to the listnode
    temp->id = theBookList->length+1;
    temp->title = (char*)malloc(sizeof(strlen(title)));
    temp->authors = (char*)malloc(sizeof(strlen(authors)));
    strcpy(temp->title,title);
    strcpy(temp->authors,authors);
    temp->year = year;
    temp->copies = copies;
    temp->next=NULL;
//    free(temp);
    return 1;
}

// librarian remove a book
int remove_book(BookList* theBookList){
    pBook  head = theBookList->list;
    pBook temp = head->next;
    pBook tail = head;
    unsigned int id;
    printf("Enter the id of the book you wish to remove:");
    scanf("%u",&id);
    if(!temp)
    {
        // if there are no book in the library
        printf("There are no book in the library!");
    }else {
        while (temp) {
            if (temp->id == id) {
                // remove all copies or just one book
                printf("You want\n1.Remove all the copies\n2.Remove one copy\nEnter your choice: ");
                int choice;
                scanf("%d",&choice);
                // if remove all copies
                if(choice == 1){
                    temp = temp->next;
                    tail->next = temp;
                    temp = head->next;
                    theBookList->length--;
                    int num=1;
                    while(temp){
                        temp->id = num;
                        num++;
                        temp = temp->next;
                    }
                }else{
                    // if remove just one copy
                    if (temp->copies == 1){
                        temp = temp->next;
                        tail->next = temp;
                        temp = head->next;
                        int num=1;
                        while(temp){
                            temp->id = num;
                            num++;
                            temp = temp->next;
                        }
                    }else{
                        temp->copies -- ;
                    }
                }
                return 1;
            }else{
                temp = temp->next;
                tail = tail->next;
            }
        }
    }
    printf("Book doesn't exist!");
    return 0;
};

// store the book information from nodelist to file
void store_books(pBook head){
    FILE *fw = fopen("books.txt","wt");
    pBook temp=head->next;
    while(temp){
        fprintf(fw,"%u\t%s\t%s\t%u\t%u\n", temp->id, temp->title, temp->authors, temp->year, temp->copies);
        temp  = temp->next;
    }
    free(temp);
    fclose(fw);
}

// librarian login menu
void librarian_login(BookList* theBookList){
    pBook head = theBookList->list;
    int choice = 0;
    int librarianLoggedIn = 1;
    while(librarianLoggedIn)
    {
        printf("\n Librarian options\n 1.Add a book\n 2.Remove a book\n 3.Search for books\n 4.Display all books\n 5.Log out\n Choice:");
        scanf("%d",&choice);
        if(1==choice)
        {
            // add a book
            int x = add_book(theBookList);
            if(x==1){
                printf("Successfully add book!\n");
                display_book(theBookList);
            }
        }
        else if(2==choice)
        {
            // remove a book
            display_book(theBookList);
            int x = remove_book(theBookList);
            if(x==1){
                printf("Successfully remove book!\n");
                display_book(theBookList);
            }
        }
        else if(3==choice)
        {
            // search for book
            search_for_books(head);
        }
        else if(4==choice)
        {
            // display book
            display_book(theBookList);
        }
        else if(5==choice)
        {
            // store books and log out
            store_books(head);
            librarianLoggedIn = 0;
        }
        else
        {
            // handle invalid option
            clear();
            printf("Invalid Choice");
        }
    }
}



