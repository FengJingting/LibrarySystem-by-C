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

int add_Borrowed_book(pBook Borrowhead,pBook head)
{

    pBook temp = head->next;
    pBook Borrowtemp = Borrowhead->next;
    unsigned int id;
    printf("Enter the ID of the book you wish to add:");
    scanf("%u",&id);
    if (id<=0 ){
        printf("ID error.");
        return 0;
    }
    int bookNum = 0;
    while(Borrowtemp){
        bookNum ++ ;
        Borrowtemp = Borrowtemp->next;
    }
    Borrowtemp = (pBook)malloc(sizeof(Book));
    while(temp)
    {
        if(temp->id == id)
            {
                Borrowtemp->id = bookNum;
                printf("%u",Borrowtemp->id);
                strcpy(temp->title,Borrowtemp->title);
                printf("%s",Borrowtemp->title);
                strcpy(temp->authors,Borrowtemp->authors);
                temp->year = Borrowtemp->year;
                temp->copies = Borrowtemp->copies;
                Borrowtemp->next=NULL;
                return 1;
            }
        temp = temp->next;

    }

    return 0;
}
//int remove_Borrowed_book(pBook head){
//    pBook temp = head->next;
//    pBook tail = head;
//    unsigned int id;
//    printf("Enter the id of the book you wish to return:");
//    scanf("%u",id);
//    pBook p;
//    if(!temp)
//    {
//        printf("There are no book in the library!");
//    }else {
//        while (temp) {
//            if (temp->id == id) {
//                temp = temp->next;
//                tail = tail->next;
//            }else{
//                tail->next = temp->next;
//                free(temp);
//                return 1;
//            }
//
//        }
//    }
//    printf("Book doesn't exist!");
//    return 0;
//
//
//};
//
int display_Borrowed_book(pBook head){
    printf("Borrowed Book List.\n");
    if(NULL==head->next)
    {
        printf("You haven't borrowed any book.\n");
        getchar();
        return 0;
    }
    pBook temp = head->next;
    printf("ID\t\tTitle\t\tAuthor\t\tyear\n");
    while(temp)
    {
        printf("%u\t\t",temp->id);
        printf("%s\t\t",temp->title);
        printf("%s\t\t",temp->authors);
        printf("%u\t\t",temp->year);

        temp = temp->next;
    }
    return 1;
}

int Book_Borrowed_Menu()
{
    int choice;
    printf("\nUser Menu\n");
    printf("\n1.Borrow a book\n");
    printf("2.Return a book\n");
    printf("3.Search for books\n");
    printf("4.Display all books\n");
    printf("5.Log out\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    return choice;
}

void user_login(pBook head){
    int choice = 0;
    int userLoggedIn = 1;
    pBook BorrowHead = create_BorrowedBook_List();
    while(userLoggedIn)
    {
        choice = Book_Borrowed_Menu();
        if(1==choice)
        {
            display_book(head);
            int x = add_Borrowed_book(BorrowHead,head);
            if(x==1){
                printf("Successfully add book!\n");
                display_Borrowed_book(BorrowHead);
            }

        }
        else if(2==choice)
        {
//            int x = remove_Borrowed_book(BorrowHead);
//            if(x==1){
//                printf("Successfully remove book!\n");
//                display_Borrowed_book(BorrowHead);
//            }


        }
        else if(3==choice)
        {
            search_for_books(head);
        }
        else if(4==choice)
        {
//            display_book(head);
        }
        else if(5==choice)
        {
            return;
        }
        else
        {
            printf("Invalid Choice");
        }
    }
}


