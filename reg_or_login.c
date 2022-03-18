#include "reg_or_login.h"
#include "book_management.h"
#include "utility.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//create new node for user
pNode createList()
{
    // initialize head node
    pNode pHead = (pNode)malloc(sizeof(LNode));
    pHead->next=NULL;

    // read file
    FILE *fp = fopen("user.txt","r+");
    if(NULL == fp)
    {
        printf("FILE NOT FOUND");
        exit(-1);
    }

    pNode cur = pHead;
    while(1)
    {
        pNode temp = (pNode)malloc(sizeof(LNode));
        if(!temp)
            exit(-1);

        if(3!=fscanf(fp,"%s%s%s",temp->username,temp->name,temp->pass))
        {
            free(temp);
            break;
        }
        cur->next=temp;
        cur = temp;
        cur->next = NULL;
    }
    return pHead;
}

//login
int login(pNode head)
{
    // If there are no data in user.txt
    if(NULL==head->next)
    {
        printf("You haven't been registered.\n");
        getchar();
        return 0;
    }
    char username[20];
    char pass[20];
    printf("enter your username:");
    scanf("%s",username);
    printf("enter your password:");
    scanf("%s",pass);
    pNode temp = head->next;
    while(temp)
    {
        if(0==strcmp(temp->username,username) && 0==strcmp(temp->pass,pass))
        {

            printf("success\n");
            getchar();
            if(0==strcmp("Librarian",username) && 0==strcmp("Librarian",pass)){
                return 2;
            }
            return 1;
        }
        temp = temp->next;
    }
    printf("Wrong User Name Or Password.");
    getchar();

}


void writeToFile(pNode head)
{
    FILE *fw = fopen("user.txt","a+");
    pNode temp=head->next;
    if(temp==NULL){
        printf(("temp is NULL"));
        return;
    }
    while(temp){
        fprintf(fw,temp->username);
        fprintf(fw,"\t");
        fprintf(fw,temp->name);
        fprintf(fw,"\t");
        fprintf(fw,temp->pass);
        fprintf(fw,"\n");
        temp  = temp->next;
    }
}



int registerUser(pNode head)
{
    pNode temp = head->next;

    char name[20];
    char username[20];
    char pass[20];
    printf("enter your name:");
    scanf("%s",name);
    printf("enter your username:");
    scanf("%s",username);
    printf("enter your password:");
    scanf("%s",pass);
    if(!temp)
    {
        temp = (pNode)malloc(sizeof(LNode));
        head->next = temp;
    }else {
        while(temp)
        {
            if(0==strcmp(temp->username,username))
            {
                printf("username already exits.");
                return 0;
            }
            temp = temp->next;
        }
        temp = head->next;
        while(temp->next)
        {
            temp = temp->next;
        }
        pNode last = (pNode)malloc(sizeof(LNode));
        temp->next = last;
        temp = last;
    }
    //表中有用户则在最后一个节点后生成新节点
    strcpy(temp->username,username);
    strcpy(temp->name,name);
    strcpy(temp->pass,pass);
    temp->next=NULL;
    return 1;
}

void menu() {
    printf("\n1.login\n");
    printf("2.register\n");
    printf("3.exit\n");
    printf("enter your choice:");
}

int reg_or_login()
{
    int choice;
    pNode head = createList();
    while(1)
    {
        menu();
        choice  = optionChoice();
        if(1==choice)
        {
            int y = login(head);
            if (y == 2){
                return 2;
            }else if(y == 1){
                return 1;
            }
        }
        else if(2==choice)
        {
            int x = registerUser(head);
            if(x==1){
                writeToFile(head);
            }
        }
        else if(3==choice)
        {
            return 0;
        }
        else
        {
            printf("Invalid Choice");
        }
    }
}

