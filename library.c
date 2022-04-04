#include "library.h"
#include "book_management.h"
#include "utility.h"
#include "librarian.h"
#include "user.h"
#include "reg_or_login.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create library list node and return
pBook create_Book_List()
{
    // initialize head node
    pBook pHead = (pBook)malloc(sizeof(Book));
    pHead->next=NULL;
    return pHead;
}

//load books from file to list node
void load_books(FILE *file,BookList* theBookList){
    pBook pHead =  theBookList->list;
    pBook cur = pHead;
    char title[100];
    char authors[100];
    while(1)
    {
        pBook temp = (pBook)malloc(sizeof(Book));

        // if the pointer is at the end of the file,break
        if(5!=fscanf(file,"%u\t%s\t%s\t%u\t%u\n",&temp->id,title,authors,&temp->year,&temp->copies))
        {
            free(temp);
            break;
        }else{
            //   copy the book from file to nodelist
            theBookList->length++;
            temp->title = (char*)malloc(sizeof(strlen(title)));
            temp->authors = (char*)malloc(sizeof(strlen(authors)));
            strcpy(temp->title,title);
            strcpy(temp->authors,authors);
            cur->next=temp;
            cur = temp;
            cur->next = NULL;
        }
    }
    fclose(file);
}

// display book
// input: the BoookList Struct
// output: if there are no book in the library,return 0; else, return 1
int display_book(BookList* theBookList){
    pBook head = theBookList->list;
    if(NULL==head->next)
    {
        printf("No book in the Library.\n");
        return 0;
    }
    //  display book
    pBook temp = head->next;
    printf("ID\t\tTitle\t\t\tAuthor\t\tyear\t\tcopies\n");
    while(temp)
    {
        printf("%u\t\t",temp->id);
        printf("%s\t\t\t",temp->title);
        printf("%s\t\t",temp->authors);
        printf("%u\t\t",temp->year);
        printf("%u\n",temp->copies);
        temp = temp->next;
    }
    return 1;
}

// init the library
// input: the pointer of bookFile and userFile
void run_library(char *bookFile,char *userFile) {
    int libraryOpen = 1;
    int option = 0;
    // create library list node
    pBook head = create_Book_List();
    BookList *theBookList = (BookList *) malloc(sizeof(BookList));
    theBookList->list = head;
    theBookList->length = 0;
    // open file, if can't find,exit
    FILE *fr = fopen(bookFile,"rb");
    if(fr==NULL)
    {
        printf("File open error.\n");
        exit(0);
    }
    // load the file into the node list
    load_books(fr,theBookList);

    // main menu
    while (libraryOpen) {
        printf("\n Main menu options\n 1 Register an account or login\n 2 Display all books\n 3 Quit\n Choice:");
        scanf("%d",&option);
        if(option == 1)
        {
            //  reg or login
            int x = reg_or_login(userFile);
            if(x==1){
                librarian_login(theBookList,bookFile);
            }else if(x == 0){
                clear();
            }else{
                user_login(x,theBookList,bookFile);
            }
            option = 0;
        } else if (option == 2) {
            //  display books
            display_book(theBookList);
            option = 0;
        } else if (option == 3) {
            // close library
            libraryOpen = 0;
            free(theBookList);
            printf("\nClosing\n");
        }else{
            // invalid choice warning
            clear();
            printf("\nUnknown option\n");
        }
    }
}
