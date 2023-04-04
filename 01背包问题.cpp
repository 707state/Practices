//与完全背包不同，这里是有n个背包，完全背包是n种
#include<iostream>
#include<algorithm>
//i书本第51页
//思路：初等方法采用每一个物品进行搜索
using namespace std;
#define max(a,b) (a>b?a:b);
int n;
pair<int,int>* wv=new pair<int,int>[n];
int W;
void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>wv[i].first>>wv[i].second;
    }
    cin>>W;
}
int rec(int i,int j){
    int res;
    if(i==n){
        res=0;
    }else if(j<wv[i].first){
        //此时无法选择该物品
        res=rec(i+1,j);
    }else{
        res=max(rec(i+1,j),rec(i+1,j-wv[i].first)+wv[i].second);
    }
    return res;
}
void solve(){
    printf("%d\n",rec(0,W));
}
int main(){
    init();
    solve();
}