# include <iostream>
# include <stdlib.h>
using namespace std;
struct node
	{
		int data;
		struct node* next;
	};
struct node* head=NULL;
void push(int num)
{
	if(head==NULL)
	{
		struct node* temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;
		temp->data=num;
		head=temp;
	}
	else
	{
		struct node *temp,*temp1;
		temp1=head;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=temp1;
		head=temp;
	}

}
void pop()
{

 struct node * tmp1;
 tmp1=head->next;
 free(head);
 head=tmp1;


}
void dis()
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
		{
			cout<<temp->data<<" ";
            temp=temp->next;   
		}
		cout <<endl;	
} 
int main()
{
	int ch,num;
	while(1)
	{
		cout<<"Enter Your choice\n 1:insert a node\n 2:display \n 3:pop \n";
		cin>> ch;
		if (ch==1)
		{
			cout<< "enter a number:";
			cin>> num;
			push(num);
		}
		else if(ch==2)
		{
			dis();
		}
		else if(ch==3)
		 pop();	
		else
			exit(1);
	}	

}

