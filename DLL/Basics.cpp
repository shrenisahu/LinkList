

// https://ide.geeksforgeeks.org/9ca06a66-6c4e-4823-956e-ac1dcbe63f56


#include <iostream>
using namespace std;



class Node{
    public:
    
    int data;
    Node *prev;
    Node *next;
    
    Node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
        
    }
}
;


class DoubllyLinkList{
    
    public:
    
    void insertATHead(Node *&head,int data)
    {
        Node *newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        
    }
    void insertAtEnd(Node *&head,int data)
    {
        Node *newNode =new Node(data);
        Node *temp=head;
         while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        
       
        
    }

    void insertAtEndWithTail(Node *&tail,int data)
    {
         Node *newNode =new Node(data);
         tail->next = newNode;
         newNode->prev = tail;
    }
    void insertATPos(Node *&head,int data,int pos)
    {
        
        if(pos==1)
        {
            insertATHead(head,data);
            return;
            
        }
        Node *temp=head;
        Node *newNode =new Node (data);
        int count=1;
        
        
        while(count <pos-1)
        {
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL  || temp==NULL)
        {
            insertAtEnd(head,data);
            return;
        }
      
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
        newNode->prev=temp;
        // rough->prev=newNode;
        
        
        
    }
    
    void deleteAtFront(Node *&head)
    {
        head->next->prev=NULL;
        head=head->next;
    }
    
    void deleteAtEnd(Node *&head)
    {
        Node *temp=head;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
            
        }
        temp->prev->next=NULL;
        temp->prev=NULL;
        
    }
    
    void deletATPos(Node *&head,int pos)
    {
        if(pos==1)
        {
            deleteAtFront(head);
            return;
        }
        int count=1;
        Node *temp=head;
        while(count <pos)
        {
            temp=temp->next;
            count++;
        }
        if(temp==NULL || temp->next==NULL)
        {
            deleteAtEnd(head);
            return;
        }
       temp->prev->next=temp->next;
       temp->next->prev=temp->prev;
        
        
        
    }
    
    void print(Node *&head)
    {
        Node *temp=head;
        if(head==NULL)
        {
            cout<<"empty";
            return ;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            
            temp=temp->next;
        }
    }
};
int main() {
Node *head=new Node(70);
DoubllyLinkList a;
a.insertATHead(head,10);
a.insertAtEnd(head,90);
a.insertATPos(head,60,2);
a.deleteAtFront(head);
a.deleteAtEnd(head);
a.deletATPos(head,4);
a.print(head);

}
