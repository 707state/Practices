//leetcode322
//k种面值的硬币，面值分别为c1,2...ck，不限制硬币个数
//给定总金额amount，问最少几枚硬币能够凑出来金额
#include<iostream>
#include<vector>
using namespace std;
int k;
vector<int> money[k];
int amount;
void initial(){
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>money[i];
    }
    cin>>amount;
}
vector<int> count;
int dp(vector<int>& coins,int rem){
    if(rem<0) return -1;
    if(rem==0) return 0;
    
    if(count[rem-1]!=0) return count[rem-1];
    int Min=INT_MAX;
    for(int coin:coins){
        int res=dp(coins,rem-coin);
        if(res>=0&&res<Min){
            Min=res+1;
        }
    }
    count[rem-1]=Min==INT_MAX?-1:Min;
    return count[rem-1];
}
int coinChange(vector<int>&coins,int amount){
    if(amount<1) return 0;
    count.resize(amount);
    return dp(coins,amount);
}