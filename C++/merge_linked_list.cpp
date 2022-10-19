// Given two sorted singly linked lists, we need to merge both the linked list in such a manner that the resulting linked list is sorted
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    
    Node *finalHead=NULL;
    Node *finalTail=NULL;
  if(head1==NULL && head2==NULL)
  {
      return NULL;
  }
  else if(head1==NULL)
  {
      return head2;
  }
  else if(head2==NULL)
  {
      return head1;
  }
  if(head1->data<head2->data)
  {
      finalHead=head1;
      finalTail=head1;
      head1=head1->next;
  }
  else
  {
      finalHead=head2;
      finalTail=head2;
      head2=head2->next;
  }
  while(head1!=NULL && head2!=NULL)
  {
      if(head1->data<head2->data)
      {
          finalTail->next=head1;
          head1=head1->next;
          finalTail=finalTail->next;
      }
      else
      {
          finalTail->next=head2;
          head2=head2->next;
          finalTail=finalTail->next;
      }
  }
  if(head1!=NULL)  // If the second list is now empty and the first list still contains some integer values
  {
      finalTail->next=head1;
  }
  if(head2!=NULL)  // If the first list is now empty and the second list still contains some integer values
  {
      finalTail->next=head2;
  }
  return finalHead;
}

int main()
{
	int t;
    cout<<"Enter the number of test cases to run : ";
	cin >> t;
	while (t--)
	{
        cout<<"Enter the values for first linked list : ";
		Node *head1 = takeinput();
        cout<<"Enter the values for the second linked list : "; 
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}