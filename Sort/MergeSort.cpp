#include<iostream>
#include<memory.h>
using namespace std;
#define NUM 5
int input[NUM];
typedef bool(*CompareFunc)(int,int);
bool compare(int left,int right)
{
    return left<right;
}
void mergeSort(int input[],int left,int mid,int right,CompareFunc comp)
{
    if(left>=mid||mid>=right) return;
    int* tmp=new int(right-left);
    int index=0;
    int leftP=left;
    int midP=mid;
    while(leftP<mid&&midP<right)
    {
        if(comp(input[leftP],input[midP])) 
        {
            tmp[index]=input[leftP];
            leftP++;
        }
        else 
        {
            tmp[index]=input[midP];
            midP++;
        }
        index++;
    }
    if(midP<right)
    {
        memcpy(tmp+index,input+midP,sizeof(int)*(right-midP));
    }
    else if(leftP<mid)
    {
        memcpy(tmp+index,input+leftP,sizeof(int)*(mid-leftP));
    }
    memcpy(input+left,tmp,sizeof(int)*(right-left));
    delete[] tmp;
    tmp=NULL;
}
void sort(int input[],int left,int right,CompareFunc comp)
{
    if(input==NULL||right-left<=1) return;
    int mid=(left+right)/2;
    sort(input,left,mid,comp);
    sort(input,mid,right,comp);
    mergeSort(input,left,mid,right,comp);
}
int main()
{
    cout<<"input :";
    for(int i=0;i<NUM;i++) cin>>input[i];
    sort(input,0,NUM,compare);
    cout<<"output:";
    for(int i=0;i<NUM;i++) cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}