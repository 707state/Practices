#include<iostream>
#include<algorithm>
using namespace std;
//自序列不一定是连续的，子串才是连续的
//leetcode300
#include<string.h>
int n;
int* dp=new int[n];
int *nums=new int[n];
void initial(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        dp[i]=1;
    }
    
}
#define max(a,b) (a>b?a:b);
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int maxDp=*max_element(dp,dp+n);
    printf("最长序列的长度是：%d",maxDp);
}
int main(){
    initial();
    solve();
}