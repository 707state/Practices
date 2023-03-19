#include<iostream>
#include<algorithm>
using namespace std;
int n;
typedef long long ll;
int* fences=new int[n];
void solve(){
    ll ans=0;
    while(n>1){
        int mii1=0,mii2=1;
        if(fences[mii1]>fences[mii2]){
            swap(mii1,mii2);
        }
        for(int i=2;i<n;i++){
            if(fences[i]<fences[mii1]){
                mii2=mii1;
                mii1=i;
            }
            else if(fences[i]<fences[mii2]){
                mii2=i;
            }
        }
        //以上求出最短的版mii1和次短的板mii2
        //将两块板子结合
        int t=fences[mii1]+fences[mii2];
        ans+=t;
        if(mii1==n-1){
            swap(mii1,mii2);
        }
        fences[mii1]=t;//会到树的上一级
        fences[mii2]=fences[n-1];//赋值为树的最右侧叶子
        n--;
    }
    printf("%lld\n",ans);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>fences[i];
    }
    solve();
}