#include<iostream>
#include<vector>
using namespace std;
#define NUM 10
vector<int> input;
int maxValue()
{
    int maxVal=input[0];
    for (int i = 1; i < NUM; i++)
    {
        maxVal=maxVal>input[i]?maxVal:input[i];
    }
    return maxVal;
    
}
int minValue()
{
    int minVal=input[0];
    for(int i=1;i<NUM;i++)
    {
        minVal=minVal<input[i]?minVal:input[i];
    }
    return minVal;
}
void insertionSort(vector<int>& vec)
{
    for(int i=1;i<vec.size();i++)
    {
        int cur=vec[i];
        int preIndex=i-1;
        while(preIndex>=0&&cur<vec[preIndex])
        {
            vec[preIndex+1]=vec[preIndex];
            preIndex--;
        }
        vec[preIndex+1]=cur;
    }
}
void sort(int bucketSize)
{
    int minVal=minValue();
    int maxVal=maxValue();
    int bucketCount=(maxVal-minVal)/bucketSize+1;
    vector<vector<int> > vec(bucketCount);
    for(int i=0;i<NUM;i++)
    {
        vec[(input[i]-minVal)/bucketSize].push_back(input[i]);
    }
    int index=0;
    for(int i=0;i<bucketCount;i++)
    {
        if(vec[i].size()!=0)
        {
            insertionSort(vec[i]);
            for(int j=0;j<vec[i].size();j++)
            {
                input[index++]=vec[i][j];
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
    int bucketSize=3;
    sort(bucketSize);
    cout<<"output:";
    for(int i=0;i<NUM;i++) cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}