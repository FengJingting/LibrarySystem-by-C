#include <stdio.h>
#include "libararian.h"
#include "book_management.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//pBook create_Book_List()
//{
//    // initialize head node
//    pBook pHead = (pBook)malloc(sizeof(Book));
//    pHead->next=NULL;
//
//    // read file
//    FILE *fp = fopen("books.txt","r+");
//    if(NULL == fp)
//    {
//        printf("BOOK FILE NOT FOUND");
//        exit(-1);
//    }
//
//    pBook cur = pHead;
//    while(1)
//    {
//        pBook temp = (pBook)malloc(sizeof(Book));
//        if(!temp)
//            exit(-1);
//
//        if(5!=fscanf(fp,"%d%s%s%d%d",temp->id,temp->title,temp->authors,temp->year,temp->copies))
//        {
//            free(temp);
//            break;
//        }
//        cur->next=temp;
//        cur = temp;
//        cur->next = NULL;
//    }
//    return pHead;
//}
//
//int add_book(Book book)
//{
//    pNode temp = head->next;
//    //当表中无用户直接在头结点后注册
//    char name[20];
//    char pass[20];
//    printf("enter your name:");
//    scanf("%s",name);
//    printf("enter your password:");
//    scanf("%s",pass);
//    if(!temp)
//    {
//        temp = (pNode)malloc(sizeof(LNode));
//        head->next = temp;
//    }else {
//        while(temp)
//        {
//            if(0==strcmp(temp->name,name) && 0==strcmp(temp->pass,pass))
//            {
//                printf("username already exits.");
//                return 0;
//            }
//            temp = temp->next;
//        }
//        temp = head->next;
//        while(temp->next)
//        {
//            temp = temp->next;
//        }
//        pNode last = (pNode)malloc(sizeof(LNode));
//        temp->next = last;
//        temp = last;
//    }
//    //表中有用户则在最后一个节点后生成新节点
//    strcpy(temp->name,name);
//    strcpy(temp->pass,pass);
//    temp->next=NULL;
//    return 1;
//}
//int remove_book(Book book){
//
//};
////写入txt文件，每一行存在一个用户
//void writeToFile(pBook head)
//{
//    FILE *fw = fopen("books.txt","a+");
//    pBook temp=head->next;
//    if(temp==NULL){
//        printf(("temp is NULL"));
//        return;
//    }
//    while(temp){
//        fprintf(fw,temp->id);
//        fprintf(fw,"\t");
//        fprintf(fw,temp->title);
//        fprintf(fw,"\t");
//        fprintf(fw,temp->authors);
//        fprintf(fw,"\t");
//        fprintf(fw,temp->year);
//        fprintf(fw,"\t");
//        fprintf(fw,temp->copies);
//        fprintf(fw,"\n");
//        temp  = temp->next;
//    }
//}

int menu()
{
    int choice;
    printf("\n1.Add a book\n");
    printf("2.Remove a book\n");
    printf("3.Search for books\n");
    printf("4.Display all books\n");
    printf("5.Log out\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    return choice;
}
int librarian_login(){
    int choice;
    printf("librarian login\n");
//    while(1)
//    {
//        choice = menu();
//        if(1==choice)
//        {
//
//        }
//        else if(2==choice)
//        {
//
//
//        }
//        else if(3==choice)
//        {
//
//        }
//        else if(4==choice)
//        {
//
//        }
//        else if(5==choice)
//        {
//            return 0;
//        }
//        else
//        {
//            printf("Invalid Choice");
//        }
//    }
}

