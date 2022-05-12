#include<stdio.h>
#include<malloc.h>
struct node{
	int data;//数据域，存放n个人的数据
	struct node *next;//指针域  
};
int main(){
	int n,m;//n个人，报数m
	int i;
	int answer[100];//保存每次的答案，最后一起输出
	int count=0;//控制答案的下标
	struct node *head,*tail,*p,*q;//p:当前处理节点，q：指向在p指针指向的前一个节点,head:头指针，指向开头，tail：尾指针，指向结尾
	head=(struct node*)malloc(sizeof(struct node));
	//head->data=-1;
	 head->next =NULL;//创建头结点
	 
	 while(1){//1：循环可以一直进行下去
	     printf("请输入n和m：");
	     scanf("%d%d",&n,&m);
		 if(m==0||n==0)
		{
			free(head);//释放掉创建好的节点，退出循环 
			break;
		 }
		 else{
		 	tail=head;
		 	for(i=0;i<n;i++){
		 		//尾插法构建循环链表
		 		p=(struct node*)malloc(sizeof(struct node));
		 		p->data=i+1;
		 		tail->next=p;//插到尾部
				p->next=head->next;//最后一个节点的指针域指向第一个节点，形成循环链表
				tail=p;//tail移动到最后一个节点，准备下一次插入 
			 }
			p=head->next;//第一个节点
			q=tail;//因为是循环链表，所以最后一个节点是第一个节点的前驱节点
			i=1;//从1开始报数
			while(p!=q){//p，q重合说明只剩一个人，循环结束 
			
			    if(i==m){//删除当前节点 
			    	q->next=q->next->next;
			    	free(p);
			    	p=q->next;//把p移到下一个有效节点上，重新开始报数
					i=1; 
				}
				else{
				    q=p;
					p=p->next;//p和q各自向后移动一个，q总在p的前面
					i++;
				}
			}
			head->next=q;//删到最后一个节点时，防止链表断开
			answer[count]=p->data;//把结果存到数组
			count++;
			free(p);
			head->next=NULL;//链表清空，只剩头结点了 	 
		 } 
	 	
	 }
	 for(i=0;i<count;i++){
	 	printf("胜利者是：%d\n",answer[i]);
	 } 
	 return 0;
}








