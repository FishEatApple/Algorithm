#include<iostream>
using namespace std;
#define NUM 2
int input[NUM];
void sort()
{
    for(int gap=NUM/2;gap>0;gap/=2)
    {
        for(int i=gap;i<NUM;i++)
        {
            int cur=input[i];
            int preIndex=i-gap;
            while(preIndex>=0&&input[preIndex]>cur)
            {
                input[preIndex+gap]=input[preIndex];
                preIndex-=gap;
            }
            input[preIndex+gap]=cur;
        }
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