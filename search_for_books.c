#include <string.h>
#include "search_for_books.h"
#include "book_management.h"


void find_book_by_title(const char *title,pBook head){
    pBook book = head->next;
    while (book!=NULL)
    {
        if (strcmp(book->title,title)!=0)
        {
            book = book->next;
        }
        else
        {
            printf("ID\t\ttitle\t\tauthors\t\tyear\t\tcopies\n");
            printf("%u\t\t%s\t\t%s\t\t%u\t\t%u\n",book->id,book->title,book->authors,book->year,book->copies);
            return;
        }
    }
    if (book == NULL)
    {
        printf("Book Title doesn't exit！\n");
    }

}

void find_book_by_author(const char *authors,pBook head){
    pBook book = head->next;
    while (book!=NULL)
    {
        if (strcmp(book->authors,authors)!=0)
        {
            book = book->next;
        }
        else
        {
            printf("ID\t\ttitle\t\tauthors\t\tyear\t\tcopies\n");
            printf("%u\t\t%s\t\t%s\t\t%u\t\t%u\n",book->id,book->title,book->authors,book->year,book->copies);
            return;
        }
    }
    if (book == NULL)
    {
        printf("Book' Author doesn't exit！\n");
    }

}

void find_book_by_year(unsigned int year,pBook head){
    pBook book = head->next;
    while (book!=NULL)
    {
        if (book->year != year)
        {
            book = book->next;
        }
        else
        {
            printf("ID\t\ttitle\t\tauthors\t\tyear\t\tcopies\n");
            printf("%u\t\t%s\t\t%s\t\t%u\t\t%u\n",book->id,book->title,book->authors,book->year,book->copies);
            return;
        }
    }
    if (book == NULL)
    {
        printf("Book year doesn't exit！\n");
    }

}

int Search_Menu()
{
    int choice;
    printf("\n1.Find books by title\n");
    printf("2.Find books by author\n");
    printf("3.Find books by year\n");
    printf("4.Return to previous menu\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    return choice;
}
void search_for_books(pBook head){
    printf("\nLoading search menu...\n");
    int choice;
    while(1)
    {
        choice = Search_Menu();
        if(1==choice)
        {
            const char title[20];
            printf("\n1.Please enter title:\n");
            scanf("%s",title);
            find_book_by_title (title,head);
        }
        else if(2==choice)
        {
            const char authors[20];
            printf("\n1.Please enter authors:\n");

            scanf("%s",authors);
            find_book_by_author (authors,head);
        }
        else if(3==choice)
        {
            unsigned int year;
            printf("\n1.Please enter year:\n");
            scanf("%u",&year);
            find_book_by_year(year,head);
        }
        else if(4==choice)
        {
            return;
        }
        else
        {
            printf("Invalid Choice");
        }
    }

};