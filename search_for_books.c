#include <string.h>
#include "search_for_books.h"
#include "book_management.h"
#include "library.h"
#include "utility.h"

void find_book_by_title(const char *title,pBook head){
    pBook book = head->next;
    int flag = 0;
    while (book!=NULL)
    {
        if (strcmp(book->title,title)==0)
        {
            if (flag==0){
                printf("ID\t\ttitle\t\tauthors\t\tyear\t\tcopies\n");
            }
            printf("%u\t\t%s\t\t%s\t\t%u\t\t%u\n",book->id,book->title,book->authors,book->year,book->copies);
            flag = 1;
        }
        book = book->next;
    }
    if (flag==0){
        printf("Can't find this book！\n");
    }
    return;
}

void find_book_by_author(const char *authors,pBook head){
    pBook book = head->next;
    int flag = 0;
    while (book!=NULL)
    {
        if (strcmp(book->authors,authors)==0)
        {
            if (flag==0){
                printf("ID\t\ttitle\t\tauthors\t\tyear\t\tcopies\n");
            }
            printf("%u\t\t%s\t\t%s\t\t%u\t\t%u\n",book->id,book->title,book->authors,book->year,book->copies);
            flag = 1;
        }
        book = book->next;
    }
    if (flag==0){
        printf("Can't find this book！\n");
    }
    return;
}

void find_book_by_year(unsigned int year,pBook head){
    pBook book = head->next;
    int flag = 0;
    while (book!=NULL)
    {
        if (book->year==year)
        {
            if (flag==0){
                printf("ID\t\ttitle\t\tauthors\t\tyear\t\tcopies\n");
            }
            printf("%u\t\t%s\t\t%s\t\t%u\t\t%u\n",book->id,book->title,book->authors,book->year,book->copies);
            flag = 1;
        }
        book = book->next;
    }
    if (flag==0){
        printf("Can't find this book！\n");
    }
    return;
}



void search_for_books(pBook head){
    printf("\nLoading search menu...\n");
    int choice;
    while(1)
    {
        printf("\n Search book options\n 1.Find books by title\n 2.Find books by author\n 3.Find books by year\n 4.Return to previous menu\n Choice:");
        scanf("%d",&choice);
        if(1==choice)
        {
            const char title[20];
            printf("\nPlease enter title:\n");
            scanf("%s",title);
            find_book_by_title (title,head);
            choice = 0;
        }
        else if(2==choice)
        {
            const char authors[20];
            printf("\nPlease enter authors:\n");
            scanf("%s",authors);
            find_book_by_author (authors,head);
            choice = 0;
        }
        else if(3==choice)
        {
            unsigned int year;
            printf("\nPlease enter year:\n");
            scanf("%u",&year);
            find_book_by_year(year,head);
            choice = 0;
        }
        else if(4==choice)
        {
            return;
        }
        else
        {
            clear();
            printf("Invalid Choice");

        }
    }

};