# include <iostream>
# include <stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* tail=NULL;
void push(int num)
	{
		 struct node* temp=(struct node*)malloc(sizeof(struct node));
		if (tail==NULL)
			{
				temp->data=num;
				temp->next=NULL;
				temp->prev=NULL;
				tail=temp;
			}
		else
			{
				temp->data=num;
				temp->next=NULL;
				temp->prev=tail;
				tail->next=temp;
				tail=temp;
			}

	 }
void pop()
	{
		struct node *tmp;
		tmp=tail->prev;
		free(tail);
		tail=tmp;
	}
void dis()
	{
		struct node* temp=tail;
		while(temp!=NULL)
		{
			cout<< temp->data <<endl;
			temp=temp->prev;
		}
	}

int main()
{
	int ch,num;
	while(1)
	{
		cout<<"Enter Your choice\n 1:push\n 2:pop \n 3:display\n";
		cin>> ch;
		if (ch==1)
		{
			cout<< "enter a number:";
			cin>> num;
			push(num);
		}
		else if(ch==2)
		{
			pop();
		}
		else if (ch==3)
		{
			dis();	/* code */
		}
		else
			 exit(1);
	}
	return 0;
}