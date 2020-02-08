#include<bits/stdc++.h>
using namespace std;
struct flags
{
    int* arr;
    int top1=-1;
    int top2=-1;
    
};

int N;
void push1(int &top1,int &top2,int n, int *arr)
{
        for(int j=top2;j>top1;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[top1+1]=n;
        top1=top1+1;
        top2=top2+1;
    
}
void push2(int &top1,int &top2,int n, int *arr)
{
  if(top2<=top1)
  {
    top2=top1;
  }
  arr[top2+1]=n;
  top2=top2+1;
    
}
int pop1(int &top1,int &top2,int *arr)
{   int num=0;
    num=arr[top1];
    for(int j=top1+1;j<=top2;j++)
    {
        arr[j-1]=arr[j];
    }
    top1--;
    top2--;
    return num;
}
int pop2(int &top1,int &top2,int *arr)
{   
    int num;
    num=arr[top2];
    top2--;
    return num;
}
int main()
{   flags flag_array;
    cin>>N;
    int num;
    flag_array.arr=(int*)malloc(N*sizeof(int));
    int* original=(int*)malloc(N*sizeof(int));
    int final[10];
    int M;
    cin>>M;
    int a=0;
    float sum=0;
    int op,sn,index;
    for(int i=0;i<M;i++)
    {
        cin>>op>>sn>>index;
        if(op==1)
        {
            if(sn==1)
            {
                push1(flag_array.top1,flag_array.top2,index,flag_array.arr);
            }
            else if(sn==2)
            {
                push2(flag_array.top1,flag_array.top2,index,flag_array.arr);
            }
        }
        else
        {
            if(sn==1)
            {
                num=pop1(flag_array.top1,flag_array.top2,flag_array.arr);
                final[a]=num;
                a++;
            }
            else
            {
                num=pop2(flag_array.top1,flag_array.top2,flag_array.arr);
                final[a]=num;
                a++;
            }
        }
        
        
    }
    int k=0;
    for(k=0;k<=flag_array.top2;k++)
        {
            original[k]=flag_array.arr[k];
        }
        for(int q=0;q<a;q++)
        {
            original[k]=final[q];
            k++;
        }
    int small;
    int temp;
    int pos;
    for(int r=0;r<flag_array.top2+a;r++)
    {
        small=original[r];
        pos=r;
        for(int s=r+1;s<flag_array.top2+a+1;s++)
        {
            if(small>original[s])
            {
                pos=s;
                small=original[s];
            }
        }
        temp=original[r];
        original[r]=original[pos];
        original[pos]=temp;
    }
    int median;
    for(int x=0;x<flag_array.top2+a+1;x++)
    {
        sum+=original[x];
    }
    
    sum=sum/(flag_array.top2+a+1);
    if((flag_array.top2+a+1)%2==1)
    {
        median=original[(flag_array.top2+a+1)/2];
    }
    else
    {
        median=original[(flag_array.top2+a+1)/2] + original[(flag_array.top2+a-1)/2];
        median=median/2;
    }
    int mode;
    int count=0;
    int max_count=0;
    for(int y=0;y<flag_array.top2+a-1;y++)
    {
        if(original[y]==original[y+1])
        {
            count++;
        }
        else
        {   if(count>max_count)
            {
                max_count=count;
                mode=original[y];
            }
            count=0;
        }
    }
    float std=0;
    for(int o=0;o<flag_array.top2+a+1;o++)
    {
        std+=pow(original[o]-sum,2);
    }
    std/=flag_array.top2+a+1;
    std=sqrt(std);
    cout<<sum<<'\t'<<median<<'\t'<<mode<<'\t';
    printf("%0.2f",std);
    cout<<'\n';
    for(int d=flag_array.top1;d>=0;d--)
    {
        cout<<flag_array.arr[d]<<'\t';
    }
    cout<<'\n';
    for(int e=flag_array.top2;e>flag_array.top1;e--)
    {
        cout<<flag_array.arr[e]<<'\t';
    }
    
}