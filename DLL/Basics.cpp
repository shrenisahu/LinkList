

//https://ide.geeksforgeeks.org/b820b3c8-9939-4146-a218-5c96055415e6
#include <iostream>
using namespace std;

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

class LinkList{
    
    public:

    void insertAtHead(Node *&head, int d)
    {

        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
    
    void insertEnd(Node *&head,int data)
    {
        Node *newNode =new Node(data);
        
        if(head==NULL)
        {
            insertAtHead(head,data);
            return;
        }
        
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
    void insertAtPos(Node *&head,int pos,int data)
    {
        Node *temp=head;
        if(pos==1)
        {
            insertAtHead(head,data);
            return;
        }
        int count=1;
        while(count <pos-1)
        {
            temp=temp->next;
            count++;
        }
        
        if(temp==NULL)
{
            insertEnd(head,data);
return;
}
        Node *nodeToInsert=new Node(data);
        
        nodeToInsert->next=temp->next;
        temp->next=nodeToInsert;
    }
    
     void deleteATFront(Node *&head)
     {
         head=head->next;
         return;
     }
     
     
     void deleteATEnd(Node *&head)
     {
         Node *temp=head;

         
         while(temp->next!=NULL && temp->next->next!=NULL)
         {
            
             temp=temp->next;
             
         }
          temp->next=NULL;
         return;
     }
     
     
     void deletATPos(Node *&head,int pos)
     {
         if(pos==1)
         deleteATFront(head);
         
         Node *temp=head;
         
         int count=1;
         while(count <pos-1)
         {
             count++;
             temp=temp->next;
         }
         if(temp==NULL)
         {
             deleteATEnd(head);
             return;
         }
         temp->next=temp->next->next;
         
     }
    void printList(Node *head)
    {

        Node *temp = head;
        if (head == NULL)
        {
            "list is empty";
        }

        else
        {
            while (temp != NULL)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
        }
    }
    
};


int main()
{
    LinkList a;
   
    Node *head = new Node(84);
    a.insertAtHead(head, 83);
    a.insertAtHead(head, 82);
    a.insertAtHead(head, 81);
    a.insertEnd(head,85);
    a.insertAtPos(head,7,99);
//     a.deleteATFront(head);
//     a.deleteATEnd(head);
    a.deletATPos(head,3);
    a.printList(head);

    return 0;
}
