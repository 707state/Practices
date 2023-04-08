//应用剪枝法
#include<iostream>
#include<vector>
using namespace std;
struct solution1{
    int (*fib)(int N);
    int (*helper)(vector<int>&memo,int n);
};//1采用从顶向下
struct solution2{
    int (*dptable)(int n);
    int (*superSimple)(int n);
};//采用从底向上
int superSimple(int n){
    if(n==1||n==2){
        return 1;
    }
    int prev=1,curr=1;
    for(int i=3;i<n;i++){
        int sum=prev+curr;
        prev=curr;
        curr=sum;
    }
    return curr;
}
int dptable(int n){
    vector<int> dp(n+1,n);
    dp[1]=dp[2]=1;
    for(int i=3;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fib(int N){
    if(N<0) return 0;
    vector<int> memo(N+1,N);
    //进行备忘录的递归
    return helper(memo,N);
}
int helper(vector<int>& memo,int n){
    if(n==1||n==2){
        return 1;
    }
    if(memo[n]!=0) return memo[n];
    memo[n]=helper(memo,n-1)+helper(memo,n-2);
    return memo[n];
}
int main(){
    int n;
    cin>>n;
    printf("%d\n",fib(n));
    printf("%d\n",dptable(n));
    printf("%d\n",superSimple(n));
}