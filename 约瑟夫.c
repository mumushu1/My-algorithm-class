#include<stdio.h>
#include<malloc.h>
struct node{
	int data;//�����򣬴��n���˵�����
	struct node *next;//ָ����  
};
int main(){
	int n,m;//n���ˣ�����m
	int i;
	int answer[100];//����ÿ�εĴ𰸣����һ�����
	int count=0;//���ƴ𰸵��±�
	struct node *head,*tail,*p,*q;//p:��ǰ����ڵ㣬q��ָ����pָ��ָ���ǰһ���ڵ�,head:ͷָ�룬ָ��ͷ��tail��βָ�룬ָ���β
	head=(struct node*)malloc(sizeof(struct node));
	//head->data=-1;
	 head->next =NULL;//����ͷ���
	 
	 while(1){//1��ѭ������һֱ������ȥ
	     printf("������n��m��");
	     scanf("%d%d",&n,&m);
		 if(m==0||n==0)
		{
			free(head);//�ͷŵ������õĽڵ㣬�˳�ѭ�� 
			break;
		 }
		 else{
		 	tail=head;
		 	for(i=0;i<n;i++){
		 		//β�巨����ѭ������
		 		p=(struct node*)malloc(sizeof(struct node));
		 		p->data=i+1;
		 		tail->next=p;//�嵽β��
				p->next=head->next;//���һ���ڵ��ָ����ָ���һ���ڵ㣬�γ�ѭ������
				tail=p;//tail�ƶ������һ���ڵ㣬׼����һ�β��� 
			 }
			p=head->next;//��һ���ڵ�
			q=tail;//��Ϊ��ѭ�������������һ���ڵ��ǵ�һ���ڵ��ǰ���ڵ�
			i=1;//��1��ʼ����
			while(p!=q){//p��q�غ�˵��ֻʣһ���ˣ�ѭ������ 
			
			    if(i==m){//ɾ����ǰ�ڵ� 
			    	q->next=q->next->next;
			    	free(p);
			    	p=q->next;//��p�Ƶ���һ����Ч�ڵ��ϣ����¿�ʼ����
					i=1; 
				}
				else{
				    q=p;
					p=p->next;//p��q��������ƶ�һ����q����p��ǰ��
					i++;
				}
			}
			head->next=q;//ɾ�����һ���ڵ�ʱ����ֹ����Ͽ�
			answer[count]=p->data;//�ѽ���浽����
			count++;
			free(p);
			head->next=NULL;//������գ�ֻʣͷ����� 	 
		 } 
	 	
	 }
	 for(i=0;i<count;i++){
	 	printf("ʤ�����ǣ�%d\n",answer[i]);
	 } 
	 return 0;
}








