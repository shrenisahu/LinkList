


//https://ide.geeksforgeeks.org/a6d7af88-79cd-482b-b8a4-61867fc087ee


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
};


class Stack{
    public:
    Node *dummy=new Node(-1);
    Node *iteartor=dummy;
    
    void push(int data)
    {
        Node *nodeToInsert=new Node(data);
        iteartor->next=nodeToInsert;
        nodeToInsert->prev=iteartor;
        iteartor=iteartor->next;
        return;
    }
    
    void print()
    {
        
        Node *temp=iteartor;
        if(temp==NULL)
       {
            cout<<"empty lis";
            return;
       }
          while(temp->prev!=NULL)
          {
              cout<<temp->data<<" ";
              temp=temp->prev;
          }
          return;
    }
    
    void pop()
    
    {
        
        if(iteartor==dummy)
       {
           cout<<"stack is empty";
            return ;
       }
        
        iteartor->prev->next=NULL;
        Node *prevNode=iteartor->prev;
        iteartor->prev=NULL;
        iteartor=prevNode;
        return;
    
    }

};
int main() {
    
    Stack a;
    a.push(1);
    a.push(2);
    a.print();
    a.pop();
    cout<<endl;
    a.print();
     a.pop();
    cout<<endl;
    a.print();
    
    
	
}
