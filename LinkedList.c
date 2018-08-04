#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*List;
//函数的声明
LNode *create_head();//创建一个空表
void create_list(LNode*,int);//创建一个长度为n的线性链表
void insert_list(LNode*,int,int);//插入一个元素
int delete_list(LNode*,int);//删除一个元素
int found_list(LNode*,int);//链表查询
void reverse(LNode*);//倒置整个链表
void delete_whole(LNode*);//删除整个链表
void print_list(LNode *);//打印链表
int main(){
	List head;
	int i;
	int j;
	head=create_head();
	create_list(head,3);
	print_list(head);
	i=found_list(head,2);
	printf("%d\n",i);
	delete_whole(head);
	
	scanf("%d",&j);
	return 0;
}
//创建一个空链表
LNode *create_head(){
	List p;
	p=(LNode*)malloc(sizeof(LNode));
	if(p==NULL){
		printf("内存申请失败！");
	}else{
		p->next=NULL;
		return(p);
	}
}
//创建一个长度为n的线性链表
void create_list(LNode *head,int n){
	LNode *p;//头结点的地址永远是不会变的
	int i;
	p=head;//为了不断移动链表和加入新元素
	for(i=1;i<=n;i++){
		LNode *q=(List)malloc(sizeof(LNode));
		if (q==NULL){
			printf("内存申请失败!");
		}else{
			printf("请输入数据data:");
			scanf("%d",&(q->data));
			q->next=p->next;
			p->next=q;
			p=q;

		}
		
	}
}
void insert_list(LNode *head,int x,int i){
	int j=0;
	List p;
	List q;
	p=head;
	while(p!=NULL&&j<i-1){
		j++;
		p=p->next;
	}//单纯的移动P,让P指向要添加元素的前一个，跳出时指向的必是要添加元素的前一个结点
	if(p==NULL){
		exit(0);
	}else{
		q=(List)malloc(sizeof(List));
		if(q=NULL){
			printf("内存申请失败！");
		}else{
			q->data=x;
			q->next=p->next;
			p->next=q;
		}
	}

}
//删除一个元素
int delete_list(LNode *head,int i)
{
	List p,q;
	int j=0;
	int x;
	p=head;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	if (p==NULL)
	{
		exit(0);
	}else{
		q=p->next;
		p->next=q->next;
		x=p->data;
		free(q);
		q=NULL;
		return(x);
	}
}
//置换链表
void reveser(LNode *head){

}
//删除整个列表,只是删除结构体中的内容
void delete_whole(LNode *head){
	List p;
	List q;
	p=head;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
}
//打印链表
void print_list(LNode *head){
	List p;
	p=head->next;//头结点给p,利用p++来不断指向下一个结点,但不打印头结点，因此p=head->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
//链表查询,查询某一个数据的当前位置.
int found_list(LNode *head,int n){
	List p;
	int i=1;
	for(p=head->next;p!=NULL;p=p->next){
		if(n==p->data){
			return i;
		}
		i++;
	}
}
	

