#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
class MaxHeap
{
    long long int *max_heap;
    long int capacity;
    long int heapsize;
public:
    MaxHeap(long int N);
    long int parent(long int i)
    {
        if(i>0)
        {
            return (i-1)/2;
        }
        else
        {
            return 0;
        }
    }
    long int left_child(long int i)
    {
        return 2*i+1;
    }
    long int right_child(long int i)
    {
        return 2*i+2;
    }
    void insert_key(long long int k);
    int extract_max();
    void max_heapify(long int s);
};
MaxHeap::MaxHeap(long int N)
{
    max_heap=new long long int[N];
    capacity=N;
    heapsize=0;
}
void MaxHeap::insert_key(long long int k)
{
    if(heapsize==capacity)
    {
        cout<<"Overflow!!"<<endl;
    }
    else
    {
        heapsize++;
        long int i=heapsize-1;
        max_heap[i]=k;
        while(i!=0 && max_heap[parent(i)]<max_heap[i])
        {
            swap(max_heap[parent(i)],max_heap[i]);
            i=parent(i);
        }
    }
}
void MaxHeap::max_heapify(long int i)
{
    long int l=left_child(i);
    long int r=right_child(i);
    long int biggest=i;
    if(l<heapsize && max_heap[l]>max_heap[i])
    {
        biggest=l;
    }
    if(r<heapsize && max_heap[r]>max_heap[biggest])
    {
        biggest=r;
    }
    if(biggest!=i)
    {
        swap(max_heap[i],max_heap[biggest]);
        max_heapify(biggest);
    }
    return;
}
int MaxHeap::extract_max()
{
    if(heapsize==0)
    {
        cout<<"Underflow!!"<<endl;
        return -1;
    }
    else if(heapsize==1)
    {
        long long int root=max_heap[0];
        heapsize--;
        return root;
    }
    else
    {
        long long int root=max_heap[0];
        max_heap[0]=max_heap[heapsize-1];
        heapsize--;
        max_heapify(0);
        return root;
    }
}
int main()
{
    long int N;
    long long int y;
    long long int val[3];
    cin>>N;
    long long int *result = new long long int[N];
    MaxHeap pqueue(N);
    for(int i=0;i<N;i++)
    {
        cin>>y;
        pqueue.insert_key(y);
        if(i<2)
        {
            result[i]=-1;
        }
        else
        {
            for(int k=0;k<3;k++)
            {
                val[k]=pqueue.extract_max();
            }
            for(int l=0;l<3;l++)
            {
                pqueue.insert_key(val[l]);
            }
            result[i]=val[0]*val[1]*val[2];
        }
    }
    for(int j=0;j<N;j++)
    {
        cout<<result[j]<<" ";
    }
    return 0;
}
