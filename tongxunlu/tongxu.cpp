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
            
           printf("���ڶ�ȡ��%d������\n",i);
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
    printf("�������Ƿ������ϵ�ˣ�<y/n>");
    char h;
    cin>>h;
    if(h=='Y'||h=='y'){
        node* p;
      while(h=='Y'||h=='y'){
        p=new node;
        printf("����������\n");
        fflush(stdin);
        scanf("%s",p->info.no);
        printf("�������ֻ���\n");
        fflush(stdin);
        scanf("%s",p->info.num);

        p->next=head->next;
        head->next=p;
        printf("�����Ƿ�Ҫ�����ϵ�ˣ�<y/n>");
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
        printf("��ʧ��\n");
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
        printf("����ɹ�");
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
        printf("����Ϊ��\n");
        return 0;
    }
    printf(".......................................\n");
    printf("����            �ֻ���\n");
    p1=head->next;
    while(p1!=NULL){
        printf("%-11s   %s\n",p1->info.no,p1->info.num);
       
        p1=p1->next;
    }
    return 0;
}

int search(node *head){
    if(head->next==NULL){
        printf("����Ϊ��\n");
        return 0;
    }
    node *p1,*p2;
    p1=head->next;
    p2=head;
    int i=0;
    printf("��ϣ��ͨ�����������ֻ��Ų��ң�<y=����\n=�ֻ���>\n");
    fflush(stdin);
    char ch=getchar();
    if(ch=='Y'||ch=='y'){
        printf("����������Ҫ���ҵ�����\n");
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
          printf("û���ҵ�����Ϣ\n");
          return 0;
      }

    }else if(ch=='n'||ch=='N'){
        printf("������������ҵ��ֻ���\n");
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
            printf("û���ҵ�����Ϣ\n");
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
cout<<"���ڶ�ȡ���ݣ����Ժ󡣡�����"<<endl;
head=load();

while(1) {
    printf("........................\n");
    printf(".......����ͨѶϵͳ.......\n");
    printf("��ӭ����ͨѶ¼\n");
    printf("��ѡ��\n");
    printf("1.......������ϵ��\n");
    printf("2.......�鿴ͨѶ¼\n");
    printf("3.......������ϵ��\n");
    printf("4.......ɾ��������ϵ��\n");
    printf("5.......�˳�\n");
    int s=1;
    cin>>s;
    switch(s){
        case 1:add(head);break;
        case 2:view(head);break;
        case 3:search(head);break;
        case 4:{
            if(clearlist(head))
            printf("ɾ��������ϵ�˳ɹ�\n");
            else printf("ɾ��������ϵ��ʧ��\n");
        } break;
        case 5:freelist(head);exit(0);break;
        default:printf("erro!����������\n");
    }
}


}
