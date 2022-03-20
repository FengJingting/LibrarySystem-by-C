#include "library.h"
#include "book_management.h"
#include "utility.h"
#include "librarian.h"
#include "user.h"
#include "reg_or_login.h"
#include <stdio.h>
#include <malloc.h>

//create library list node
pBook create_Book_List()
{
    // initialize head node
    pBook pHead = (pBook)malloc(sizeof(Book));
    pHead->next=NULL;
    return pHead;
}

//load books from file to list node
void load_books(FILE *file,pBook pHead){
//     initialize head node
        pBook cur = pHead;
    while(1)
    {
        pBook temp = (pBook)malloc(sizeof(Book));
    // if the pointer is at the end of the file,break
        if(5!=fscanf(file,"%u\t%s\t%s\t%u\t%u\n",&temp->id,&temp->title,&temp->authors,&temp->year,&temp->copies))
        {
//            printf("%d",fscanf(file,"%u\t%s\t%s\t%u\t%u\n",&(temp->id),&temp->title,&temp->authors,&temp->year,&temp->copies));
            free(temp);
            break;
        }
        cur->next=temp;
        cur = temp;
        cur->next = NULL;

    }
    fclose(file);
}

// display book
int display_book(pBook head){
    // if no book in the library
    if(NULL==head->next)
    {
        printf("No book in the Library.\n");
        return 0;
    }
    //  display book
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
    return 1;
}

void main_menu() {
    int libraryOpen = 1;
    int option = 0;
    // create library list node
    pBook head = create_Book_List();
    // open file
    FILE *fr = fopen("books.txt","rb");
    if(fr==NULL)
    {
        printf("File open error.\n");
        exit(0);
    }
    load_books(fr,head);


    while (libraryOpen) {
        printf("\n Main menu options\n 1 Register an account or login\n 2 Display all books\n 3 Quit\n Choice:");
//        option = optionChoice();
        scanf("%d",&option);
        if(option == 1)
        {
            librarian_login(head);
//            int x = reg_or_login();
//            if(x==1){
//                printf(" user_login");
//                  user_login(head);
//            }else if(x==2) {
//                librarian_login(head);
//            }else{
//                continue;
//            }
        } else if (option == 2) {
            display_book(head);
        } else if (option == 3) {
            libraryOpen = 0;
            printf("\nClosing\n");
        }else{
            printf("\nUnknown option\n");
        }
    }
}

void  run_library(){
    main_menu();
}