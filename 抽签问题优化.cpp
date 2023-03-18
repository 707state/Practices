#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 10000
int n,m,k[max_n];
int kk[max_n*max_n];
bool binary_search(int x){
    int l=0,r=n*n;
    while(r-l>0){
        int i=(r+l)/2;
        if(kk[i]==x) return true;
        else if(kk[i]<x) l=i+1;
        else r=i;
    }
    return false;
}
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            kk[i*n+j]=k[i]+k[j];
        }
    }
    //排序后方便查找
    sort(kk,kk+n*n);
    bool f=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(binary_search(m-k[i]-k[j])){
                f=true;
            }
        }
    }
    if(f) printf("yes");
    else printf("no");
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    solve();
}