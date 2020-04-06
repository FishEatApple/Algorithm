#include<iostream>
#include<vector>
using namespace std;
#define NUM 10
vector<int> input;
int maxBit()
{
    int res=1;
    for(int i=0;i<NUM;i++)
    {
        int num=input[i];
        int bit=0;
        while(num)
        {
            bit++;
            num/=10;
        }
        res=bit>res?bit:res;
    }
    return res;
}
void sort(int max_bit)
{
    vector<vector<int> > vec(10);
    int dev=1;
    int mod=10;
    for(int i=0;i<max_bit;i++,dev*=10,mod*=10)
    {
        for(int j=0;j<NUM;j++)
        {
            int index=input[j]%mod/dev;
            vec[index].push_back(input[j]);
        }
        int index=0;
        for(int j=0;j<10;j++)
        {
            if(vec[j].size()!=0)
            {
                for(int k=0;k<vec[j].size();k++)
                {
                    input[index++]=vec[j][k];
                }
                vec[j].clear();//要清空，不然出错
            }
        }
    }
}
int main()
{
    cout<<"input :";
    for(int i=0;i<NUM;i++)
    {
        int val;
        cin>>val;
        input.push_back(val);
    } 
    sort(maxBit());
    cout<<"output:";
    for(int i=0;i<NUM;i++) cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}