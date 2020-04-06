#include<iostream>
using namespace std;
#define NUM 5
int input[NUM];
void swap(int& v1,int& v2)
{
    int tmp=v1;
    v1=v2;
    v2=tmp;
}
void adjust(int index,int len)
{
    int left=index*2+1;
    int right=index*2+2;
    int maxIndex=index;
    if(left<len&&input[left]>input[maxIndex]) maxIndex=left;
    if(right<len&&input[right]>input[maxIndex]) maxIndex=right;
    if(maxIndex!=index)
    {
        swap(input[maxIndex],input[index]);
        adjust(maxIndex,len);
    }
}
void sort()
{
    for(int i=NUM/2-1;i>=0;i--)
    {
        adjust(i,NUM);
    }
    for(int i=NUM-1;i>0;i--)
    {
        swap(input[0],input[i]);
        adjust(0,i);
    }
}
int main()
{
    cout<<"input :";
    for(int i=0;i<NUM;i++) cin>>input[i];
    sort();
    cout<<"output:";
    for(int i=0;i<NUM;i++) cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}