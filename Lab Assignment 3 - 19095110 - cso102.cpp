#include<iostream>
#include<string>
using namespace std;

struct node
{
    string country;
    string penny;
    node *next;
}
*start,*rear;

node *create_new_node(string cn,string pyn)
{
    node *ptr;
    ptr=new node;
    ptr->country=cn;
    ptr->penny=pyn;
    ptr->next=NULL;
    return ptr;
}
void add(node *new_con)
{
    if(start==NULL)
    {
        start=rear=new_con;
    }
    else
    {
        rear->next=new_con;
        rear=rear->next;
    }
}
void display()
{   node *np;
    np=new node;
    np=start;
    if(start==NULL)
    cout<<endl;
    else
    {
        while(np!=NULL)
        {
            cout<<np->country<<'\t';
            np=np->next;
        }
        cout<<endl;
    }
    
}
    void del()
    {   node *np;
        np=new node;
        np=start;
        string p="P";
        if(start!=NULL)
        {   label:
            if(start->penny.compare(p)==0)
            {
                start=start->next;
                np=np->next;
                goto label;
            }
            while(np->next!=NULL)
            {
                if(np->next->penny.compare(p)==0)
                {   
                    np->next=np->next->next;
                }
                else
                {
                    np=np->next;
                }
                
            }
            rear=np;
        }
    }
int main()
{
    int N;
    cin>>N;
    int M;
    cin>>M;
    string op;
    string country_name;
    string penny_y_n;
    node *new_country;
    for(int i=0;i<M;i++)
    {
        cin>>op;
        if(op[0]=='A')
        {
            cin>>country_name;
            cin>>penny_y_n;
            new_country=create_new_node(country_name,penny_y_n);
            add(new_country);
        }
        else if(op[1]=='I')
        {
            display();
        }
        else if(op[1]=='E')
        {
            del();
        }
    }
}