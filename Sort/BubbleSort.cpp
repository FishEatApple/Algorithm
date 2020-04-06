#include<iostream>
using namespace std;
#define NUM 5
int input[NUM];
void sort()
{
    for (int i = 0; i < NUM; i++)
    {
        //每循环一次，最大值被移动到最右边
        for (int j = 0; j < NUM-1-i; j++)
        {
            if(input[j]>input[j+1])
            {
                int tmp=input[j+1];
                input[j+1]=input[j];
                input[j]=tmp;
            }
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
