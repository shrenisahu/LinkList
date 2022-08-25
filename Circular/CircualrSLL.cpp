//https://ide.geeksforgeeks.org/ca22609b-1309-4cb5-bebd-9676d3767678

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node (int data)
    {
        this->data=data;
        this->next=NULL;
    }
    Node()
    {
        this->next=NULL;
    }
    

};


    
   void insertAtFront(Node *&tail,int element,int data)
    {
        Node *temp=tail;
        Node *newNode=new Node(data);
        if(tail==NULL)
        {
            newNode->next=newNode;
            tail=newNode;
            
            return ;
        }
        
        else 
        {
            while(temp->data!=element)
            {
                temp=temp->next;
                
            }
            newNode->next=temp->next;
            temp->next=newNode;
            
            return;
        }
    }
    
    
    void deleteNode(Node *&tail,int element)
    {
        
        if(tail==NULL)
        {
            cout<<"lis alrady empty cannot be deleted";
            return;
        }
        
      
        else {
            
            Node *prev=tail;
            Node *temp=prev->next;
            while (temp->data!=element)
            {
                prev=temp;
                temp=temp->next;
                
            }
            prev->next=tail->next;
            
            if(prev==temp)
            {
                tail=NULL;
                return;
            }
            else if (tail==temp)
            {
                tail=prev;
            }
            temp->next=NULL;
            
            
        }
    }
    
    
    
    void print(Node *&tail)
    {
        Node *temp=tail;
      do{
    
    cout<<temp->data<<" ";
    temp=temp->next;
    
    }while(temp!=tail);
};

int main() {
Node *tail=NULL;
insertAtFront(tail,5,1);
insertAtFront(tail,1,2);

insertAtFront(tail,2,4);
insertAtFront(tail,2,3);
insertAtFront(tail,4,5);
deleteNode(tail,1);
print(tail);


}
