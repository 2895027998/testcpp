#include<iostream>
#include<string>
#include<string.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include"head.h"

using namespace std;

node* load(){
    int i=0;
    node *head,*tail,*p;
    head=tail=new node;

    tail->next=NULL;
    ifstream in("D:\\program\\git\\C++\\tongxunlu\\test.txt");
    if(! in.is_open())
    {cout<<"erro opening file"<<endl;}
    else{ while(!in.eof()){
             p=new node;
             in.read(p->info.no,9);
            in.read(p->info.num,15);
            
           printf("正在读取第%d个数据\n",i);
            i++;
            p->next=NULL;
           tail->next=p;
           tail=p;
        
            

    }
    } 
    in.close();
    return head;
}

int add(node* head){
    printf("请问你是否添加联系人？<y/n>");
    char h;
    cin>>h;
    if(h=='Y'||h=='y'){
        node* p;
      while(h=='Y'||h=='y'){
        p=new node;
        printf("请输入姓名\n");
        fflush(stdin);
        scanf("%s",p->info.no);
        printf("请输入手机号\n");
        fflush(stdin);
        scanf("%s",p->info.num);

        p->next=head->next;
        head->next=p;
        printf("请问是否还要添加联系人？<y/n>");
        fflush(stdin);
        cin>>h;
        }
    
    
    }
    return 0;
}

int freelist(node*head){
    node*p1,*p2;
    p1=p2=head;
    ofstream out("D:\\program\\git\\C++\\tongxunlu\\test.txt",ios::app);
    if(!out.is_open()){
        printf("打开失败\n");
    }
    else{
        while(p1->next!=NULL){
            p1=p1->next;
         out.write(p1->info.no,9);
         out.write(p1->info.num,15);
         out<<endl;
        }
    }

        out.close();
        printf("保存成功");
        p1=head;
        p2=p2->next;
    while(p2!=NULL){
        delete(p1);
        p1=p2;
        p2=p2->next;
    }
    delete(p1);
    return 0;
}

int view(node*head){
    node *p1;
    p1=head;
    if(head->next==NULL){
        printf("链表为空\n");
        return 0;
    }
    printf(".......................................\n");
    printf("姓名            手机号\n");
    p1=head->next;
    while(p1!=NULL){
        printf("%-11s   %s\n",p1->info.no,p1->info.num);
       
        p1=p1->next;
    }
    return 0;
}

int search(node *head){
    if(head->next==NULL){
        printf("链表为空\n");
        return 0;
    }
    node *p1,*p2;
    p1=head->next;
    p2=head;
    int i=0;
    printf("您希望通过姓名还是手机号查找？<y=姓名\n=手机号>\n");
    fflush(stdin);
    char ch=getchar();
    if(ch=='Y'||ch=='y'){
        printf("请输入你想要查找的姓名\n");
        char name[9];
        fflush(stdin);
        gets(name);
        while(p1!=NULL){
            if(strcmp(p1->info.no,name)==0){
                printf("%-11s    %s\n",p1->info.no,p1->info.num);
                i=1;
            }
            p2=p1;
            p1=p1->next;
        }
      if(i==0){
          printf("没有找到该信息\n");
          return 0;
      }

    }else if(ch=='n'||ch=='N'){
        printf("请输入你想查找的手机号\n");
        char tele[15];
        fflush(stdin);
        gets(tele);
        i=0;
        while(p1!=NULL){
            if(strcmp(p1->info.num,tele)==0){
                printf("%-11s     %s\n",p1->info.no,p1->info.num);
                i=1;
            }
            p2=p1;
            p1=p1->next;
        }
        if(i==0){
            printf("没有找到该信息\n");
            return 0;
        }

    }
    return 0;
}
int clearlist(node*head){
    int i=0;
    node *p1,*p2;
    p1=p2=head->next;
    while(p2!=NULL){
        i=1;
        p1=p1->next;
        delete(p2);
        p2=p1;
    }
    if(i) head->next=NULL;
    return 0;

}

int main(){
node* head;
cout<<"正在读取数据，请稍后。。。。"<<endl;
head=load();

while(1) {
    printf("........................\n");
    printf(".......管理通讯系统.......\n");
    printf("欢迎进入通讯录\n");
    printf("请选择\n");
    printf("1.......增加联系人\n");
    printf("2.......查看通讯录\n");
    printf("3.......查找联系人\n");
    printf("4.......删除所有联系人\n");
    printf("5.......退出\n");
    int s=1;
    cin>>s;
    switch(s){
        case 1:add(head);break;
        case 2:view(head);break;
        case 3:search(head);break;
        case 4:{
            if(clearlist(head))
            printf("删除所有联系人成功\n");
            else printf("删除所有联系人失败\n");
        } break;
        case 5:freelist(head);exit(0);break;
        default:printf("erro!请重新输入\n");
    }
}


}
