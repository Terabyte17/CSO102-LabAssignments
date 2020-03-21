#include<iostream>
#include<string>
using namespace std;

struct node 
{
    int num;
    node *next;
    node *prev;
}*front,*rear,*save;
node* create_new_node(int n)
{
    node *ptr;
    ptr=new node;
    ptr->num=n;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
    
}
int isFull()
{   int x=0;
    node* y=front;
    while(y!=rear)
    {
        y=y->next;
        x++;
    }
    if(front==NULL)
    return 0;
    else if(x==51)
    return 1;
    else 
    return 0;
}
void initialize(int N)
{   node* new_node;
    node* prev_node=create_new_node(1);
    front=prev_node;
    for(int i=2;i<=N;i++)
    {
        new_node=create_new_node(i);
        prev_node->next=new_node;
        new_node->prev=prev_node;
        prev_node=new_node;
    }
    rear=new_node;
}
void insertFront(int num)
{   if(front==NULL)
    {
        front=rear=create_new_node(num);
        return;
    }
    else
    {
        node* new_front;
        new_front=create_new_node(num);
        new_front->next=front;
        front->prev=new_front;
        front=new_front;
    }
}
void insertLast(int num)
{
    if(isFull()==1)
    {
        cout<<"Overflow"<<endl;
        return;
    }
    else if(front==NULL)
    {
        front=rear=create_new_node(num);
    }
    else
    {
        node* new_rear;
        new_rear=create_new_node(num);
        rear->next=new_rear;
        new_rear->prev=rear;
        rear=new_rear;
    }
}
void deleteFront()
{
    int number;
    if(front==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else if(front==rear)
    {   
        number=rear->num;
        front=rear=NULL;
        cout<<"Value deleted from the last: "<<number<<endl;
    }
    else
    {
        number=front->num;
        save=front;
        front=front->next;
        front->prev=NULL;
        delete save;
        cout<<"Value deleted from the front: "<<number<<endl;
    }
}
void deleteLast()
{
    int number;
    if(front==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else if(front==rear)
    {   
        number=rear->num;
        front=rear=NULL;
        cout<<"Value deleted from the last: "<<number<<endl;
    }
    else
    {
        number=rear->num;
        save=rear;
        rear=rear->prev;
        rear->next=NULL;
        delete save;
        cout<<"Value deleted from the last: "<<number<<endl;
    }
}
void getFront()
{
    int number;
    if(front==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else
    {
        number=front->num;
        cout<<"Value at the front: "<<number<<endl;
    }
}
void getRear()
{
    int number;
    if(front==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else
    {
        number=rear->num;
        cout<<"Value at the rear: "<<number<<endl;
    }
}
int isEmpty()
{
    if(front==NULL)
    return 1;
    else 
    return 0;
}


int main()
{
    int N,M,value=0;
    string str;
    cin>>N;
    initialize(N);
    cin>>M;
    int num;
    for(int k=0;k<M;k++)
    {
        cin>>str;
        if(str.compare("addFront")==0)
        {
            cin>>num;
            insertFront(num);
        }
        else if(str.compare("addRear")==0)
        {
            cin>>num;
            insertLast(num);
        }
        else if(str.compare("DrawFront")==0)
        {
            deleteFront();
        }
        else if(str.compare("DrawRear")==0)
        {
            deleteLast();
        }
        else if(str.compare("PeekFront")==0)
        {
            getFront();
        }
        else if(str.compare("PeekRear")==0)
        {
            getRear();
        }
        else if(str.compare("IsEmpty")==0)
        {
            value=isEmpty();
            if(value==1)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        else if(str.compare("IsFull")==0)
        {
            value=isFull();
            if(value==1)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}