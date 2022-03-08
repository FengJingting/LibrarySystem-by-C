#include "library.h"
#include "utility.h"
#include "reg_or_login.h"
#include "book_management.h"
#include "search_for_books.h"
#include "user.h"
#include "librarian.h"
#include "libararian.h"
#include <stdio.h>
#include <malloc.h>

void main_menu();
void display_books();
pBook create_Book_List();

void  run_library(){
    pBook head = create_Book_List();
    main_menu();
}

void main_menu() {
    int libraryOpen = 1;
    int option = 0;

    while (libraryOpen) {
        printf("\n Main menu options\n 1 Register an account or login\n 2 Display all books\n 3 Quit\n Choice:");
        scanf("%d",&option);

        if(option == 1)
        {
                int x = reg_or_login();
                if(x==1){
                    user_login();
                }else if(x==2) {
                    librarian_login();
                }else{
                    continue;
                }
        } else if (option == 2) {
            display_books();
        } else if (option == 3) {
            libraryOpen = 0;
            printf("\nClosing\n");
        } else{
            printf("%d",option);
            printf("\nUnknown option\n");
        }

    }
}

void display_books(){

};

