//采用记忆化搜索,注意区别
#include<iostream>
#include<string.h>
using namespace std;
const int MAX=1000;
int n;
int W;
int weal[MAX],val[MAX];
int dp[MAX][MAX];
#define max(a,b) (a>b?a:b);
void initial(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>weal[i]>>val[i];
    }
    cin>>W;
}
int rec(int i,int j){
    if(dp[i][j]>=0){
        return dp[i][j];
    }
    int res;
    if(i==n){
        res=0;//这时候已经循环到头
    }else if(j<weal[i]){
        res=rec(i+1,j);
    }
    else{
        res=max(rec(i+1,j),rec(i+1,j-weal[i])+val[i]);
    }
    return dp[i][j]=res;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    printf("%d\n",rec(0,W));
}
int main(){
    initial();
    solve();
}