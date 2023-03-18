#include<iostream>
#include<algorithm>
int n,r;
const int MAX=10000;
int x[MAX];
void solve(){
    std::sort(x,x+n);
    int i=0,ans=0;
    while(i<n){
        int s=x[i++];
        while(i<n&&x[i]<=s+r) i++;
        int p=x[i-1];
        while(i<n&&x[i]<=p+r) i++;
        ans++;
    }
    printf("%d\n",ans);
}
int main(){
    std::cin>>n>>r;
    for(int i=0;i<n;i++){
        std::cin>>x[i];
    }
    solve();
}
