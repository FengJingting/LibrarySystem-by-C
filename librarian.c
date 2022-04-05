#include <stdio.h>
#include "library.h"
#include "book_management.h"
#include "search_for_books.h"
#include "utility.h"
#include <string.h>
#include <stdlib.h>

// librarian add a book
// input: the booklist struct
// output: if successfully add book,return 1,else return 0
int add_book(BookList* theBookList)
{
    pBook head = theBookList->list;
    pBook temp = head->next;
    char title[100];
    char authors[100];
    unsigned int year;
    unsigned int copies;
    printf("Enter the title of the book you wish to add:(PLease input '_' instead of ' ':");
    scanf("\n");
    fgets(title,30,stdin);
    // pretreatment
    if( title[ strlen(title) - 1 ] == '\n' )
    {
        title[ strlen(title) - 1] = '\0';
    }
    // add the information of book
    printf("Enter the author of the book you wish to add:(PLease input ',' instead of ' ':");
    scanf("%s",authors);
    printf("Enter the year of the book you wish to add was released:");
    scanf("%u",&year);
    if(year>=2022 || year<=1500){
        printf("Invalid year!");
        return 0;
    }
    printf("Enter the number of copies of the book:");
    scanf("%u",&copies);
    if(copies>=1000 || copies<=0){
        printf("Invalid copies!");
        return 0;
    }
    int numbooks = 0;

    if(!temp)
    {
        temp = (pBook)malloc(sizeof(Book));
        head->next = temp;

    }else {
        while(temp)
        {
            if(0 == (strcmp(temp->title,title)) && 0 == (strcmp(temp->authors,authors)) && temp->year == year)
            {
                // if the book already exits,ask librarian to choose an option
                printf("\nBook already exits,do you want to add copies based on it?\n 1 Yes\n 2 No\nEnter your choice:");
                int option;
                scanf("%d",&option);
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
            numbooks++;
            temp = temp->next;
        }
        temp = head->next;
        // new node
        while(temp->next)
        {
            temp = temp->next;
        }
        pBook last = (pBook)malloc(sizeof(Book));
        temp->next = last;
        temp = last;

    }
    // copy the information to the listnode
    theBookList->length = numbooks+1;
    temp->id = theBookList->length;
    temp->title = (char*)malloc(sizeof(strlen(title)));
    temp->authors = (char*)malloc(sizeof(strlen(authors)));
    strcpy(temp->title,title);
    strcpy(temp->authors,authors);
    temp->year = year;
    temp->copies = copies;
    temp->next=NULL;
    return 1;
}

// librarian remove a book
// input: the booklist struct
// output: if successfully remove book,return 1,else return 0
int remove_book(BookList* theBookList){
    pBook head = theBookList->list;
    pBook temp = head->next;
    pBook tail = head;
    if(!temp)
    {
        // if there are no book in the library,return
        printf("There are no book in the library!");
        return 0;
    }else {
        unsigned int id;
        printf("Enter the id of the book you wish to remove:");
        scanf("%u",&id);
        while (temp) {
            if (temp->id == id) {
                // ask the librarian if remove all copies or just one book
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
                    if (temp->copies == 1 || temp->copies == 0 ){
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
// input: the head of nodelist and the file pointer
void store_books(pBook head,char *bookFile){
    FILE *fw = fopen(bookFile,"wt");
    pBook temp=head->next;
    while(temp){
        fprintf(fw,"%u\t%s\t%s\t%u\t%u\n", temp->id, temp->title, temp->authors, temp->year, temp->copies);
        temp  = temp->next;
    }
    free(temp);
    fclose(fw);
}

// librarian login menu
void librarian_login(BookList* theBookList,char *bookFile){
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
            clear();
            choice = 0;
        }
        else if(2==choice)
        {
            // remove a book
            int display_book(theBookList);
            int x = remove_book(theBookList);
            if(x==1){
                printf("Successfully remove book!\n");
                display_book(theBookList);
            }
            choice = 0;
            clear();
        }
        else if(3==choice)
        {
            // search for book
            search_for_books(head);
            choice = 0;
        }
        else if(4==choice)
        {
            // display book
            display_book(theBookList);
            choice = 0;
        }
        else if(5==choice)
        {
            // store books and log out
            store_books(head,bookFile);
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



