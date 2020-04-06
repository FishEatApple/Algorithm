#include<iostream>
using namespace std;
#define NUM 5
int input[NUM];
void sort(int left,int right)
{
    if(left>=right) return;
    int i=left;
    int j=right;
    int base=input[left];
    int temp;
    while(i<j)
    {
        while(input[j]>=base && i<j) j--;
        while(input[i]<=base && i<j) i++;
        if(i<j)
        {
            temp=input[i];
            input[i]=input[j];
            input[j]=temp;
        }
    }
    input[left]=input[i];
    input[i]=base;
    sort(left,i-1);
    sort(i+1,right);
}
int main()
{
    cout<<"input :";
    for(int i=0;i<NUM;i++) cin>>input[i];
    sort(0,NUM-1);
    cout<<"output:";
    for(int i=0;i<NUM;i++) cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}