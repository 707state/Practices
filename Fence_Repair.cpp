//给定长度的木板，每一次切开的开销都等于自身长度，并且给定目标长度，求最小开销
#include<iostream>
using namespace std;
int n;//木板数目
int *wood=new int[n];
void solve(){
    //本题仍然可以使用贪心算法
    long long ans=0;
    //求出最短板miil和次短板mii2
    while(n>1){
        int miil=0,mii2=1;
        if(wood[miil]>wood[mii2]){
            swap(miil,mii2);//
        }
        for(int i=2;i<n;i++){
            if(wood[i]<wood[miil]){
                mii2=miil;
                miil=i;
            }
            else if(wood[i]<wood[mii2]){
                mii2=i;
            }
        }
        //将两块板子拼合
        int t=wood[miil]+wood[mii2];
        ans+=t;
        if(miil==n-1){
            swap(miil,mii2);
        }
        wood[miil]=t;
        wood[mii2]=wood[n-1];
    }
    printf("%lld",ans);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>wood[i];
    }
    solve();
}