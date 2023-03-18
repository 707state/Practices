//二分查找的例子,n^3log(n)复杂度
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
#define MAX_N 100000000
int k[MAX_N];
bool binary_search(int x){
    //x的存在范围是k[l:r-1]
    int l=0,r=n;
    while(r-l>0){
        int i=(l+r)/2;//对半分
        if(k[i]==x) return true;//存在这一个元素
        else if(k[i]<x) l=i+1;
        else r=i;
    }
    return false;
}
void solve(){
    sort(k,k+n);
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
                if(binary_search(m-k[i]-k[b]-k[c])){
                    flag=true;
                }
            }
        }
    }
    if(flag){
        printf("yes");
    }
    else printf("no");
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    solve();
}