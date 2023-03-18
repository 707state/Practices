//深度搜索dfs
#include<iostream>
using namespace std;
int n,m;
int arr[100000];
bool dfs(int i,int sum){
    if(i==n) return sum==m;//前n项都计算过了
    if(dfs(i+1,sum)) return true;//不加上arr[i]
    if(dfs(i+1,sum+arr[i])) return true;//加上arr[i]
    return false;
}
void solve(){
    if(dfs(0,0)) printf("yes\n");
    else printf("no");
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
    solve();
}