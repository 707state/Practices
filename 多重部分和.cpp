#include<iostream>
using namespace std;
const int MAX=1000;
//题目描述：n种不同大小的数字ai，每种有mi个，判断是否可以从这些数字中选出若干是他们的和恰好为K
int n,a[MAX],m[MAX],k;
bool dp[MAX][MAX];
void initial(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    cin>>k;
}
void solve(){
    //采用dp方法,dp[i][j]=用前i种数字能否能加和成j
    //可以定义成如下形式
    //dp[i+1][j]=(0<=k<=mi且k*ai<=j时有dp[i][j-k*ai]为1的k)
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            for(int k=0;k<=m[i]&&k*a[i]<=j;k++){
                dp[i+1][j]|=dp[i][j-k*a[i]];//|=运算符表示按位或，例子：a:2=0b0010,b:3=0b0011,那么\
                a|=b的结果是a:3,b:3
            }
        }
    }
    if(dp[n][k]) printf("Yes\n");
    else printf("No\n");
}
int main(){
    initial();
    solve();
}