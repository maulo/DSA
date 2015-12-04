import java.util.Scanner;


public class LinkedList 
{
	class Node
	{
		int data;
		Node next;
		
		Node (int d)
		{
			data=d;
			next=null;
			
		}
		
	}
	Node head=null;
	public void insert(int d)
	{
		Node temp=new Node(d);
		temp.data=d;
		temp.next=head;
		head=temp;
	}
	public void len()
	{
		if (head==null)
		{
			System.out.println("List is empty\n");
			return;
		}
		int cnt=0;
		Node temp2=head;
		while(temp2!=null)
		{
			cnt++;
			temp2=temp2.next;
		}
		
		System.out.println(cnt + " ");
	}
	public void del(int d)
	{
		Node temp=head;
		if(head==null)
		{
			System.out.println("List is empty\n");
			return;
		}
		
			if (head.data==d)
				head=head.next;
			else
			{
				while(temp!=null)
					{
					if(temp.next==null)
						return;
					if (temp.next.data==d && temp.next.next==null)
					{
						temp.next=null;
						System.out.println(d + "is deleted\n");
						break;
					}
					else if(temp.next.data==d)
					{
						temp.next=temp.next.next;
						System.out.println(d + "is deleted\n");

						break;
					}
					
					temp=temp.next;
					
				}
			
			}
	}	
	
	public void dis()
	{
		Node temp=head;
		if (head==null)
		{
			System.out.println("List is empty\n");
			return ;
		}
		System.out.println( "List...\n");

		while(temp!=null)
		{
			System.out.println( temp.data);
			temp=temp.next;
		}
	}
	public static void main(String[] args)
	{
		LinkedList l1=new LinkedList();
		Scanner scc =new Scanner(System.in);
		int ch,num,num_d;
		while(2>1)
		{
			System.out.println("Press 1: For insert a node\nPress 2: For displaying length of the list\nPress 3 for deleteing a node with a give value\nPress 4 for Displaying linked List ");
			ch=scc.nextInt();
			if (ch==1)
			{
				System.out.println("Enter node value:");
				num=scc.nextInt();
				l1.insert(num);
				System.out.println(num + "is succesfully inserted\n");
			}
			else if (ch==2)
				l1.len();
			else if (ch==3)
			{
				System.out.println("Enter a node value to be deleted:");
				num_d=scc.nextInt();
				l1.del(num_d);
			}
			else if (ch==4)
			{
				l1.dis();
			}
			else
				break;
			
		}
		
	}
	
	
	

}
