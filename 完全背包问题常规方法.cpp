//有n种重量和价值分别为w v的物品，从这些物品中挑选总质量不超过W的物品，求跳出来的物品价值总和的最大值
//常规方法是三重循环，实现矩阵的
#include<iostream>
#define max(a,b) (a>b?a:b);
using namespace std;
int kind;
pair<int,int>* wv=new pair<int,int>[kind];
int totalW;
int dp[1000][10000]={0};
void solve(){
    for(int i=0;i<kind;i++){
        for(int j=0;j<=totalW;j++){
            for(int k=0;k*wv[i].first<=j;k++){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-k*wv[i].first]+k*wv[i].second);
            }
        }
    }
    printf("%d\n",dp[kind][totalW]);
}
int main(){
    cin>>kind;
    for(int i=0;i<kind;i++){
        cin>>wv[i].first>>wv[i].second;
    }
    cin>>totalW;
    solve();
}