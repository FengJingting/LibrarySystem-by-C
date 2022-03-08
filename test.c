////
//// Created by udii on 2022-03-05.
////
//
//#include "reg_or_login.h"
//#include "book_management.h"
//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//#include <stdlib.h>
//
////create new node for user
//pNode createList()
//{
//    // initialize head node
//    pNode pHead = (pNode)malloc(sizeof(LNode));
//    pHead->next=NULL;
//
//    // read file
//    FILE *fp = fopen("user.txt","r+");
//    if(NULL == fp)
//    {
//        printf("FILE NOT FOUND");
//        exit(-1);
//    }
//
//    pNode cur = pHead;
//    while(1)
//    {
//        pNode temp = (pNode)malloc(sizeof(LNode));
//        if(!temp)
//            exit(-1);
//
//        if(2!=fscanf(fp,"%s%s",temp->name,temp->pass))
//        {
//            free(temp);
//            break;
//        }
//
//        //让当前节点(链表的尾部)的后面加上读取到数据的节点
//        cur->next=temp;
//
//        //让当前的节点为链表尾部
//        cur = temp;
//
//        //使最后一个节点指向空，方便以后判断
//        cur->next = NULL;
//    }
//    return pHead;
//}
//
////登录函数
//int login(pNode head)
//{
//    // If there are no data in user.txt
//    if(NULL==head->next)
//    {
//        printf("You haven't been registered.\n");
//        getchar();
//        return 0;
//    }
//    char name[20];
//    char pass[20];
//    printf("enter your name:");
//    scanf("%s",name);
//    printf("enter your password:");
//    scanf("%s",pass);
//    pNode temp = head->next;
//    while(temp)
//    {
//        if(0==strcmp(temp->name,name) && 0==strcmp(temp->pass,pass))
//        {
//            printf("success");
//            getchar();
//            return 1;
//        }else if(0==strcmp(temp->name,name) && 0!=strcmp(temp->pass,pass)){
//            printf("wrong password");
//            getchar();
//            return 1;
//        }else if(0!=strcmp(temp->name,name)){
//            printf("wrong username");
//            getchar();
//            return 1;
//        }
//        temp = temp->next;
//    }
//    printf("You haven't been registered.");
//    getchar();
//
//}
//
////写入txt文件，每一行存在一个用户
//void writeToFile(pNode head)
//{
//    FILE *fw = fopen("user.txt","a+");
//    pNode temp=head->next;
//    if(temp==NULL){
//        return;
//    }
//    while(temp){
//        fprintf(fw,temp->name);
//        fprintf(fw,"\t");
//        fprintf(fw,temp->pass);
//        fprintf(fw,"\n");
//        temp  = temp->next;
//    }
//}
//
//
////注册用户
//void registerUser(pNode head)
//{
//    pNode temp = head->next;
//    //当表中无用户直接在头结点后注册
//    if(!temp)
//    {
//        temp = (pNode)malloc(sizeof(LNode));
//        head->next = temp;
//        return;
//    }
//
//    while(temp)
//    {
//        if(0==strcmp(temp->name,name) && 0==strcmp(temp->pass,pass))
//        {
//            printf("success");
//            getchar();
//            return 1;
//        }else if(0==strcmp(temp->name,name) && 0!=strcmp(temp->pass,pass)){
//            printf("wrong password");
//            getchar();
//            return 1;
//        }else if(0!=strcmp(temp->name,name)){
//            printf("wrong username");
//            getchar();
//            return 1;
//        }
//        temp = temp->next;
//    }
//    //表中有用户则在最后一个节点后生成新节点
//    while(temp->next)
//    {
//        temp = temp->next;
//    }
//    pNode last = (pNode)malloc(sizeof(LNode));
//    temp->next = last;
//    temp = last;
//}
//printf("enter your name:");
//scanf("%s",temp->name);
//printf("enter your password:");
//scanf("%s",temp->pass);
//temp->next=NULL;
//}
//int menu()
//{
//    int choice;
//    printf("\n1.login\n");
//    printf("2.register\n");
//    printf("3.exit\n");
//    printf("enter your choice:");
//    scanf("%d",&choice);
//    return choice;
//}
//void reg_or_login()
//{
//    int choice;
//    pNode head = createList();
//    while(1)
//    {
//        choice = menu();
//        if(1==choice)
//        {
//            login(head);
//        }
//        else if(2==choice)
//        {
//            registerUser(head);
//            writeToFile(head);
//        }
//        else if(3==choice)
//        {
//            return;
//        }
//        else
//        {
//            printf("Invalid Choice");
//        }
//    }
//}
//
