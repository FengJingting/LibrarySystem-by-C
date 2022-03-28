#include <stdio.h>
#include "user.h"
#include <stdio.h>
#include "librarian.h"
#include "book_management.h"
#include "search_for_books.h"
#include "library.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "utility.h"

// create borrowed book list
pBook create_BorrowedBook_List()
{
    // initialize head node
    pBook pBorrowHead = (pBook)malloc(sizeof(Book));
    pBorrowHead->next=NULL;
    return pBorrowHead;
}

// diplay books user have borrowed
int display_Borrowed_book(BookList *theBorrowBookList){
    pBook BorrowHead = theBorrowBookList->list;
    if(NULL==BorrowHead->next)
    {
        printf("No book in your bookcase!\n");
        return 0;
    }
    printf("\nBorrowed Book List\n");
    pBook Borrowtemp = BorrowHead->next;
    printf("ID\tTitle\tAuthor\tyear\tcopies\n");
    while(Borrowtemp){
        printf("%u\t",Borrowtemp->id);
        printf("%s\t",Borrowtemp->title);
        printf("%s\t",Borrowtemp->authors);
        printf("%u\t",Borrowtemp->year);
        printf("%u\n",Borrowtemp->copies);
        if(!Borrowtemp->next){
            break;
        }else{
            Borrowtemp = Borrowtemp->next;
        }
    }
    return 1;
}
int add_Borrowed_book(BookList* theBookList,BookList *theBorrowBookList )
{
    pBook head = theBookList->list;
    pBook BorrowHead = theBorrowBookList->list;
    pBook temp = head->next;
    pBook Borrowtemp = BorrowHead->next;
    unsigned int id;
    printf("Enter the ID of the book you wish to add:");
    scanf("%u",&id);
    //  if the id is valid
    if (id<=0 ){
        printf("Invalid ID.\n");
        return 0;
    }
    int numBorrow = 0;
    while(Borrowtemp){
        numBorrow += Borrowtemp->copies ;
        Borrowtemp = Borrowtemp->next;
    }
    if (numBorrow == 10){
        printf("Max borrowed Num:10;Please return some book before borrow again.\n");
        return 0;
    }
    Borrowtemp = BorrowHead->next;

while(temp)
        {
            if(temp->id == id)
            {
                //   if copies of book is 0
                if(temp->copies == 0){
                    printf("This book can't be borrowed,you can come next time.\n");
                    return 0;
                }else{
                    temp->copies --;
                }


                if(!Borrowtemp)
                {
                    Borrowtemp = (pBook)malloc(sizeof(Book));
                    BorrowHead->next = Borrowtemp;
                }else{
                    while(Borrowtemp){
                        //  check if the user has borrowed this book
                        if(0==strcmp(Borrowtemp->title,temp->title)&&0==strcmp(Borrowtemp->authors,temp->authors)){
                            (Borrowtemp->copies)++;
                             return 1;
                        }

                        Borrowtemp = Borrowtemp->next;
                    }
                    Borrowtemp = BorrowHead->next;
                    while(Borrowtemp->next)
                    {
                        Borrowtemp = Borrowtemp->next;

                    }
                    pBook last = (pBook)malloc(sizeof(Book));
                    Borrowtemp->next = last;
                    Borrowtemp = last;

                }
                Borrowtemp->id = theBorrowBookList->length+1;
                char title[100];
                char authors[100];
                Borrowtemp->title = (char*)malloc(sizeof(strlen(title)));
                Borrowtemp->authors = (char*)malloc(sizeof(strlen(authors)));
                strcpy(Borrowtemp->title,temp->title);
                strcpy(Borrowtemp->authors,temp->authors);
                Borrowtemp->year = temp->year;
                Borrowtemp->copies = 1;
                Borrowtemp->next=NULL;
                return 1;
            }
        temp = temp->next;
        }
    printf("Invalid ID.\n");
    return 0;
}

int remove_Borrowed_book(BookList* theBookList,BookList *theBorrowBookList){
    pBook head = theBookList->list;
    pBook Htemp = head->next;
    pBook Borrowhead = theBorrowBookList->list;
    pBook temp = Borrowhead->next;
    pBook tail = Borrowhead;
    unsigned int id;
    printf("Enter the id of the book you wish to return:");
    scanf("%u",&id);
    if(id<=0){
        printf("Invalid id.");
        return 0;
    }
    if(!temp)
    {
        printf("You haven't borrow a book!");
    }else {
        while (temp) {
            if (temp->id == id) {
                if (temp->copies == 1){
                    theBorrowBookList->length--;
                    temp = temp->next;
                    tail->next = temp;
                    temp = Borrowhead->next;
                    int num=1;
                    while(temp){
                        temp->id = num;
                        num++;
                        temp = temp->next;
                    }
                }else{
                    temp->copies -- ;
                }
                while(Htemp){
                    if (Htemp->id == id){
                        Htemp->copies++;
                    }
                    Htemp = Htemp->next;
                }
                return 1;
            }else{
                temp = temp->next;
                tail = tail->next;
            }

        }
    }
    printf("Invalid id.\n");
    return 0;
};


void store_borrowed_books(FILE *fw,pBook head){
    pBook temp=head->next;
//    if(temp==NULL){
//        printf(("NodeList is NULL"));
//        return;
//    }
    while(temp){
        fprintf(fw,"%u\t%s\t%s\t%u\t%u\n", temp->id, temp->title, temp->authors, temp->year, temp->copies);
        temp  = temp->next;
    }
    free(temp);
    fclose(fw);
}

int Book_Borrowed_Menu()
{
    int choice;
    printf("\nUser Menu");
    printf("\n1.Borrow a book\n");
    printf("2.Return a book\n");
    printf("3.Search for books\n");
    printf("4.Display borrowed books\n");
    printf("5.Display all books in library\n");
    printf("6.Log out\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    return choice;
}

void user_login(int userid,BookList* theBookList){
    // open the user's own file
    char number[20];
    itoa(userid, number,10);
    char *suffix = ".txt";
    strcat(number, suffix);
    FILE *fr = fopen(number,"rb");
    // the book node list
    pBook head = theBookList->list;
    int choice = 0;
    int userLoggedIn = 1;
    // create the borrowed node list
    pBook BorrowHead = create_BorrowedBook_List();
    BookList *theBorrowBookList = (BookList *) malloc(sizeof(BookList));
    theBorrowBookList->list = BorrowHead;
    theBorrowBookList->length = 0;

    if(fr==NULL)
    {
        printf("File open error.\n");
        exit(0);
    }
    load_books(fr,theBorrowBookList);

    while(userLoggedIn)
    {
        choice = Book_Borrowed_Menu();
        if(1==choice)
        {
            display_book(theBookList);
            int x = add_Borrowed_book(theBookList,theBorrowBookList);
            if(x==1){
                printf("Successfully add book!\n");
                display_Borrowed_book(theBorrowBookList);
            }

        }
        else if(2==choice)
        {
            display_Borrowed_book(theBorrowBookList);
            int x = remove_Borrowed_book(theBookList,theBorrowBookList);
            if(x==1){
                printf("Successfully remove book!\n");
                display_Borrowed_book(theBorrowBookList);
            }


        }
        else if(3==choice)
        {
            search_for_books(head);
        }
        else if(4==choice)
        {
            display_Borrowed_book(theBorrowBookList);

        }
        else if(5==choice)
        {
            display_book(theBookList);

        }
        else if(6==choice)
        {
            FILE *fw = fopen(number,"wt");
            store_borrowed_books(fw,BorrowHead);
            store_books(head);
            return;
        }
        else
        {
            clear();
            printf("Invalid Choice");
        }
    }
}


