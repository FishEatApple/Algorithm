#include<iostream>
using namespace std;
#define NUM 5
int input[NUM];
int maxValue()
{
    int maxVal=0;
    for(int i=0;i<NUM;i++)
    {
        maxVal=input[i]>maxVal?input[i]:maxVal;
    }
    return maxVal;
}
void sort()
{
    int maxVal=maxValue();
    int array[maxVal+1]={};
    for(int i=0;i<NUM;i++)
    {
        array[input[i]]++;
    }
    int index=0;
    for(int i=0;i<maxVal+1;i++) while (array[i]--) input[index++]=i;
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