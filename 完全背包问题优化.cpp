#include<iostream>
using namespace std;
#define max(a,b) (a>b?a:b);
typedef struct 
{
    /* data */
    int kind;
    pair<int,int>* packs=new pair<int,int>;
    int totalW;
}Package;
Package myPack;
void init(){
    cin>>myPack.kind;
    for(int i=0;i<myPack.kind;i++){
        cin>>myPack.packs[i].first>>myPack.packs[i].second;
    }
    cin>>myPack.totalW;
}
void solve(){
    //优化掉第三层循环
    int dp[1000][1000]={0};
    for(int i=0;i<myPack.kind;i++){
        for(int j=0;j<=myPack.totalW;j++){
            if(j<myPack.packs[i].first){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=max(dp[i][j],dp[i+1][j-myPack.packs[i].first]+myPack.packs[i].second);
            }
        }
    }
    printf("%d\n",dp[myPack.kind][myPack.totalW]);
}
int main(){
    init();
    solve();
}