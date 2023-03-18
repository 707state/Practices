#include<iostream>
#include<algorithm>
const int MAX = 100000;
std::pair<int,int> itv[MAX];//用于对工作排序的pair数组
int n,s[MAX],t[MAX];
void solve();
int main(){
    printf("输入顺序，给出n个工作，接着给出每个工作的起始时间，再给出结束时间\n");
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>s[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>t[i];
    }
    solve();
}
void solve(){
    for(int i=0;i<n;i++){
        itv[i].first=t[i];
        itv[i].second=s[i];
    }
    std::sort(itv,itv+n);//对pair进行的是字典排序
    int ans=0,t=0;//最后t是工作结束的时间
    for(int i=0;i<n;i++){
        if(t<itv[i].second){
            ans++;
            t=itv[i].first;
        }
    }
    printf("最大工作次数：%d",ans);
}