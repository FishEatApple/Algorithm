#include<iostream>
using namespace std;
#define NUM 5
int input[NUM];
void sort()
{
    for(int i=1;i<NUM;i++)
    {
        int cur=input[i];
        int preIndex=i-1;
        while(preIndex>=0&&cur<input[preIndex])
        {
            input[preIndex+1]=input[preIndex];
            preIndex--;
        }
        input[preIndex+1]=cur;
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