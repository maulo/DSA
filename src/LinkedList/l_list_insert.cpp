# include <iostream>
# include <stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
struct node* tail=NULL;
void insert_begining(int num)
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		if (head==NULL)
		{
			temp->next=NULL;
			head=temp;
			tail=temp;
			
		}
		else
		{
			temp->next=head;
			head=temp;
			
		}

	}

void insert_end(int num)
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=NULL;
		if (head==NULL)
		{
			head=temp;
			tail=temp;
			
		}
	   else
	   {
		/*struct node *temp1;
         temp1=head; 
		while(temp1->next!=NULL)
			{
				temp1=temp1->next;
			}	
			temp1->next=temp;
			temp->next=NULL;*/
			tail->next=temp;
			tail=temp;
			
	    }	
	}

void dis(struct node *t)
	{
		/*if(t==NULL)
			return;
		
		dis(t->next);
		cout<<t->data<<endl;*/
		struct node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}

void insert_after(int num,struct node* temp)
{

	struct node *temp1;
	struct node *temp2=(struct node*)malloc(sizeof(struct node));
	temp2->data=num;
	temp1=temp->next;
	temp->next=temp2;
	temp2->next=temp1;

}

void delete1(int num)
{
		if (head->data==num)
			{
				if(head->next==NULL)
					tail=NULL;
				struct node *temp1;
				temp1=head;
				head=head->next;
				free(temp1);

			}
		else
		{	
			struct node *temp;
			temp=head;
			int i=0;
			while(temp!=NULL)
			{
				if(temp->next->data==num && temp->next->next==NULL)
				{
					 //cout << "b" << i++ <<endl;
					//  struct node *temp1;
					//  free(temp->next->next);
                      temp->next=NULL;
                      tail=temp;
				}
				else if(temp->next->data==num)
				{

					struct node *temp1;
					temp1=temp->next;
					temp->next=temp->next->next;
					free(temp1);
				}
				temp=temp->next;
				// cout << "a" << i++ << endl;
			}

	    }

	}
int main()
{
	int ch,num,num2,num3;
	while(1)
	{
		cout<<"Enter Your choice\n 1:insert node at begining \n 2:insert node at the end \n 3:insert afetr a given node \n 4:display\n 5:delete node of a given value \n";
		cin>> ch;
		if (ch==1)
		{
			cout<< "enter a number:";
			cin>> num;
			insert_begining(num);
		}
		else if(ch==2)
		{
			cout<< "enter a number:";
			cin>> num;
			insert_end(num);
		}
		else if (ch==4)
		{
			dis(head);	

		}
		else if(ch==3)
		{
			if (head!=NULL)
			{
				cout<<"enter data of the node after which you want ro insert a node:";
				cin>>num2;
				struct node *temp=head;
				while(temp!=NULL)
				{	if(temp->data==num2)
					break;
					else
					temp=temp->next;
				}
				if(temp!=NULL)
				{
					cout<<"\n enter new node value:";
				    cin>>num;
					insert_after(num,temp);
				}	
				else
					cout<<"give node doesn't exist\n";
			}
			else
				cout<<"list is empty\n";
		}
		else if (ch==5)
		{
			if(head==NULL)
				cout<<"list is empty\n";
			else
			{
				cout<<"enter value of node to be deleted:";
				cin>>num3;
				delete1(num3);
			}
		}

		else
			 exit(1);
		}
	
	return 0;
}