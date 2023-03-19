#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> train;
    int n;
    cin>>n;
    while(n--){
        int d;
        cin>>d;
        if(train.size()==0||train[train.size()-1]<d){
            train.push_back(d);
        }
        else{
            vector<int>::iterator it=upper_bound(train.begin(),train.end(),d);//二分搜索第一个比d大的位置并返回迭代
            if(*it!=-1) *it=d;
        }
    }
    cout<<train.size();
}