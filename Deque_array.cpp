#include<iostream>
#include<string>
using namespace std;

struct deque 
{
    int arr[100];
    int front;
    int rear;
};
deque deck;
void initialize(int N)
{
    deck.front=0;
    deck.rear=0;
    for(int i=1;i<=N;i++)
    {
        deck.arr[deck.rear]=i;
        deck.rear++;
    }
}
void insertFront(int num)
{   if(deck.rear==deck.front)
    {
        deck.arr[deck.rear]=num;
        deck.rear++;
        return;
    }
    else
    {
        for(int i=deck.rear;i>deck.front;i--)
        {
            deck.arr[i]=deck.arr[i-1];
        }
        deck.arr[deck.front]=num;
        deck.rear++;
    }
}
void insertLast(int num)
{
    if(deck.rear==52)
    {
        cout<<"Overflow"<<endl;
        return;
    }
    else
    {
        deck.arr[deck.rear]=num;
        deck.rear++;
    }
}
void deleteFront()
{
    int num;
    if(deck.front==deck.rear)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else
    {
        num=deck.arr[deck.front];
        for(int i=deck.front;i<deck.rear-1;i++)
        {
            deck.arr[i]=deck.arr[i+1];
        }
        cout<<"Value deleted from the front: "<<num<<endl;
        deck.rear--;
    }
}
void deleteLast()
{
    int num;
    if(deck.front==deck.rear)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else
    {
        num=deck.arr[deck.rear-1];
        deck.rear--;
        cout<<"Value deleted from the last: "<<num<<endl;
    }
}
void getFront()
{
    int num;
    if(deck.front==deck.rear)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else
    {
        num=deck.arr[deck.front];
        cout<<"Value at the front: "<<num<<endl;
    }
}
void getRear()
{
    int num;
    if(deck.front==deck.rear)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else
    {
        num=deck.arr[deck.rear-1];
        cout<<"Value at the rear: "<<num<<endl;
    }
}
int isEmpty()
{
    if(deck.front==deck.rear)
    return 1;
    else 
    return 0;
}
int isFull()
{
    if(deck.rear==52)
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
