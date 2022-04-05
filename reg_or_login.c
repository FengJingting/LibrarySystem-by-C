#include "reg_or_login.h"
#include "book_management.h"
#include "utility.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//create new node for user
pNode createList()
{
    // initialize head node
    pNode pHead = (pNode)malloc(sizeof(LNode));
    pHead->next=NULL;
    return pHead;
}

// load user information from file to the list
void load_user(pNode head,char *userFile){
    // read file
    FILE *fp = fopen(userFile,"r+");
    if(NULL == fp)
    {
        printf("FILE NOT FOUND");
        exit(-1);
    }
    pNode cur = head;
    while(1)
    {
        pNode temp = (pNode)malloc(sizeof(LNode));
        // if the pointer is at the end of the file,break
        if(4!=fscanf(fp,"%d%s%s%s",&temp->userid,temp->username,temp->name,temp->pass))
        {
            free(temp);
            break;
        }else{
            cur->next=temp;
            cur = temp;
            cur->next = NULL;
        }
    }
    fclose(fp);
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
                return temp->userid;
            }
            return temp->userid;
        }
        temp = temp->next;
    }
    printf("Wrong User Name Or Password.");
    return 0;

}


void writeToFile(pNode head,char *userFile)
{
    FILE *fw = fopen(userFile,"w+");
    pNode temp=head->next;
    if(temp==NULL){
        printf(("temp is NULL"));
        return;
    }
    while(temp){
        fprintf(fw,"%d\t%s\t%s\t%s\n", temp->userid, temp->username, temp->name, temp->pass);
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
    int userid = 1;
    if(!temp)
    {
        temp = (pNode)malloc(sizeof(LNode));
        head->next = temp;
    }else {
        while(temp)
        {
            userid++;
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
    temp->userid = userid;
    strcpy(temp->username,username);
    strcpy(temp->name,name);
    strcpy(temp->pass,pass);
    temp->next=NULL;
    // create user's borrowed book file
    if (userid!=1){
        char number[20];
        sprintf(number,"%d",userid);
        char *suffix = ".txt";
        strcat(number, suffix);
        FILE *fw = fopen(number,"w+");
        fclose(fw);
    }
    return 1;
}

int reg_or_login(char *userFile)
{
    int choice;
    pNode head = createList();
    load_user(head,userFile);
    while(1)
    {
        printf("\n Register or Login Menu\n 1.login\n 2 register\n 3 Quit\n Choice:");
        scanf("%d",&choice);
        if(1==choice)
        {
            int y = login(head);
            if (y == 0){
                choice=0;
            }else{
                choice=0;
                return y;
            }
        }
        else if(2==choice)
        {
            int x = registerUser(head);
            if(x==1){
                writeToFile(head,userFile);
            }
            choice=0;
        }
        else if(3==choice)
        {
            return 0;
        }
        else
        {
            clear();
            printf("Invalid Choice");
        }
    }
}