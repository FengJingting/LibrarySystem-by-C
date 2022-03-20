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

pBook create_BorrowedBook_List()
{
    // initialize head node
    pBook pBorrowHead = (pBook)malloc(sizeof(Book));
    pBorrowHead->next=NULL;
    return pBorrowHead;
}
int display_Borrowed_book(pBook BorrowHead){
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

//    pBook temp = head->next;

//    while(temp)
//    {

//
//        temp = temp->next;
//    }
    return 1;
}
int add_Borrowed_book(pBook head,pBook BorrowHead)
{
    pBook temp = head->next;
    pBook Borrowtemp = BorrowHead->next;
    unsigned int id;
    printf("Enter the ID of the book you wish to add:");

    scanf("%u",&id);
//    if (id<=0 ){
//        printf("ID error.");
//        return 0;
//    }
//    int bookNum = 0;
//    while(Borrowtemp){
//        bookNum ++ ;
//        Borrowtemp = Borrowtemp->next;
//    }

while(temp)
        {
            if(temp->id == id)
            {
                //   if copies of book is 0
                if(temp->copies == 0){
                    printf("No book can be borrowed,you can come next time.");
                    return 0;
                }else{
                    temp->copies --;
                }

                int num = 1;
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
                        num++;
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
                Borrowtemp->id = num;
                strcpy(Borrowtemp->title,temp->title);
                strcpy(Borrowtemp->authors,temp->authors);
                Borrowtemp->year = temp->year;
                Borrowtemp->copies = 1;
                Borrowtemp->next=NULL;
                return 1;
            }
        temp = temp->next;
        }
    return 0;
}

int remove_Borrowed_book(pBook Borrowhead){
    pBook temp = Borrowhead->next;
    pBook tail = Borrowhead;
    unsigned int id;
    printf("Enter the id of the book you wish to return:");
    scanf("%u",&id);
    pBook p;
    if(!temp)
    {
        printf("You haven't borrow a book!");
    }else {
        while (temp) {
            if (temp->id == id) {
                if (temp->copies == 1){
                    temp = temp->next;
                    tail->next = temp;

                }else{
                    temp->copies -- ;

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


void store_borrowed_books(pBook head){
    FILE *fw = fopen("borrowbooks.txt","wt");
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
    printf("\nUser Menu\n");
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

void user_login(pBook head){
    int choice = 0;
    int userLoggedIn = 1;
    pBook BorrowHead = create_BorrowedBook_List();
    FILE *fr = fopen("borrowbooks.txt","rb");
    if(fr==NULL)
    {
        printf("File open error.\n");
        exit(0);
    }
    load_books(fr,BorrowHead);

    while(userLoggedIn)
    {
        choice = Book_Borrowed_Menu();
        if(1==choice)
        {
            display_book(head);
            int x = add_Borrowed_book(head,BorrowHead);
            if(x==1){
                printf("Successfully add book!\n");
                display_Borrowed_book(BorrowHead);
            }

        }
        else if(2==choice)
        {
            display_Borrowed_book(BorrowHead);
            int x = remove_Borrowed_book(BorrowHead);
            if(x==1){
                printf("Successfully remove book!\n");
                display_Borrowed_book(BorrowHead);
            }


        }
        else if(3==choice)
        {
            search_for_books(head);
        }
        else if(4==choice)
        {
            display_Borrowed_book(BorrowHead);

        }
        else if(5==choice)
        {
            display_book(head);

        }
        else if(6==choice)
        {
            store_borrowed_books(BorrowHead);
            return;
        }
        else
        {
            printf("Invalid Choice");
        }
    }
}


