#include <stdio.h>
#include "libararian.h"
#include "book_management.h"
#include "search_for_books.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

pBook create_Book_List()
{
    // initialize head node
    pBook pHead = (pBook)malloc(sizeof(Book));
    pHead->next=NULL;
    return pHead;
}

int add_book(pBook head)
{
    pBook temp = head->next;
    char title[20];
    char authors[20];
    unsigned int year;
    unsigned int copies;
    printf("Enter the title of the book you wish to add:");
    scanf("%s",title);
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
            if(temp->title == title)
            {
                printf("Book already exits.");
                return 0;
            }
            temp = temp->next;
        }
        temp = head->next;

        while(temp->next)
        {
            temp = temp->next;
            bookNum ++ ;
        }
        pBook last = (pBook)malloc(sizeof(Book));
        temp->next = last;
        temp = last;
    }
    //表中有用户则在最后一个节点后生成新节点
    temp->id = bookNum;
    strcpy(temp->title,title);
    strcpy(temp->authors,authors);
    temp->year = year;
    temp->copies = copies;
    temp->next=NULL;
    return 1;
}
int remove_book(pBook head){
    pBook temp = head->next;
    pBook tail = head;
    char title[20];
    printf("Enter the title of the book you wish to remove:");
    scanf("%s",title);
    pBook p;
    if(!temp)
    {
        printf("There are no book in the library!");
    }else {
        while (temp) {
            if (strcmp(temp->title,title) != 0) {
                temp = temp->next;
                tail = tail->next;
            }else{
                tail->next = temp->next;
                free(temp);
                return 1;
            }

        }
    }
    printf("Book doesn't exist!");
    return 0;


};

int display_book(pBook head){
    if(NULL==head->next)
    {
        printf("No book in the Library.\n");
        getchar();
        return 0;
    }
    pBook temp = head->next;
    printf("ID\t\tTitle\t\tAuthor\t\tyear\t\tcopies\n");
    while(temp)
    {
        printf("%u\t\t",temp->id);
        printf("%s\t\t",temp->title);
        printf("%s\t\t",temp->authors);
        printf("%u\t\t",temp->year);
        printf("%u\n",temp->copies);

        temp = temp->next;
    }
    getchar();
    return 1;
}

int Book_Menu()
{
    int choice;
    printf("\nLibrarian Menu\n");
    printf("\n1.Add a book\n");
    printf("2.Remove a book\n");
    printf("3.Search for books\n");
    printf("4.Display all books\n");
    printf("5.Log out\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    return choice;
}
int librarian_login(){
    int choice;
    pBook head = create_Book_List();
    while(1)
    {
        choice = Book_Menu();
        if(1==choice)
        {
            int x = add_book(head);
            if(x==1){
                printf("Successfully add book!\n");
                display_book(head);
            }

        }
        else if(2==choice)
        {
            int x = remove_book(head);
            if(x==1){
                printf("Successfully remove book!\n");
                display_book(head);
            }


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
            return 0;
        }
        else
        {
            printf("Invalid Choice");
        }
    }
}

