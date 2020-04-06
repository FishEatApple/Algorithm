#include<iostream>
using namespace std;
#define NUM 5
int input[NUM];
void sort()
{
    for(int i=0;i<NUM;i++)
    {
        int minVal=input[i];
        int index=i;
        for(int j=i+1;j<NUM;j++)
        {
            if(input[j]<minVal)
            {
                minVal=input[j];
                index=j;
            }
        }
        int tmp=input[i];
        input[i]=input[index];
        input[index]=tmp;
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