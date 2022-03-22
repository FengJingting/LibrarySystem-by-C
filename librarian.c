#include <stdio.h>
#include "library.h"
#include "book_management.h"
#include "search_for_books.h"
#include "utility.h"
#include <string.h>
#include <stdlib.h>


int add_book(pBook head)
{
    pBook temp = head->next;
    char title[20];
    char authors[20];
    unsigned int year;
    unsigned int copies;
    printf("Enter the title of the book you wish to add:");
    scanf("\n");
    gets(title);
    printf("Enter the author of the book you wish to add:");
    scanf("%s",authors);
    printf("Enter the year of the book you wish to add was released:");
    scanf("%u",&year);
    printf("Enter the number of copies of the book:");
    scanf("%u",&copies);

    int bookNum = 1;
    if(!temp)
    {
        temp = (pBook)malloc(sizeof(Book));
        head->next = temp;
    }else {
        while(temp)
        {
            bookNum ++ ;
            if(0 == (strcmp(temp->title,title)) && 0 == (strcmp(temp->authors,authors)) && temp->year == year)
            {
                printf("\nBook already exits,do you want to add copies based on it?\n 1 Yes\n 2 No\nEnter your choice:");
                int option;
                scanf("%d",&option);
                if (1==option){
                    temp->copies += copies;
                    return 1;
                }else{
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
    temp->id = bookNum;
    strcpy(temp->title,title);
    strcpy(temp->authors,authors);
    temp->year = year;
    temp->copies = copies;
    temp->next=NULL;
//    free(temp);
    return 1;
}

int remove_book(pBook head){
    pBook temp = head->next;
    pBook tail = head;
    unsigned int id;
    printf("Enter the id of the book you wish to remove:");
    scanf("%u",&id);
    pBook p;
    if(!temp)
    {
        printf("There are no book in the library!");
    }else {
        while (temp) {
            if (temp->id == id) {
                if (temp->copies == 0){
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

void store_books(pBook head){
    FILE *fw = fopen("books.txt","wt");
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

void librarian_login(pBook head){
    int choice = 0;
    int librarianLoggedIn = 1;
    while(librarianLoggedIn)
    {
        printf("\n Librarian options\n 1.Add a book\n 2.Remove a book\n 3.Search for books\n 4.Display all books\n 5.Log out\n Choice:");
        scanf("%d",&choice);
        if(1==choice)
        {
            int x = add_book(head);
            store_books(head);
            if(x==1){
                printf("Successfully add book!\n");
                display_book(head);
            }
        }
        else if(2==choice)
        {
            display_book(head);
            int x = remove_book(head);
            if(x==1){
                printf("Successfully remove book!\n");
                display_book(head);
            }
        }
        else if(0==choice)
        {
            printf("please continue");
        }
        else if(3==choice)
        {
            search_for_books(head);
        }
        else if(4==choice)
        {
            display_book(head);
        }
        else if(5==choice)
        {
            librarianLoggedIn = 0;
        }
        else
        {
            fflush(stdin);
            printf("Invalid Choice");

        }
    }

}



