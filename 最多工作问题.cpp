//贪心算法实例
#include<stdio.h>
#include<iostream>
using namespace std;
#include<algorithm>
//正确算法：每一次都选择结束时间最早的工作
int workNums;
int* startTime=new int[workNums];
int* endTime=new int[workNums];
pair<int,int>* itv=new pair<int,int>[workNums];//对工作排序
void solve(){
    for(int i=0;i<workNums;i++){
        itv[i].first=endTime[i];
        itv[i].second=startTime[i];//结束时间早的工作旁在前面，endTIme放入第一位，startTime放入第二位
    }
    //排序
    sort(itv,itv+workNums);
    //按照字典序排序
    int ans=0,t=0;
    //t表示最后所选工作的结束时间
    for(int i=0;i<workNums;i++){
        if(t<itv[i].second){
            ans++;//工作数
            t=itv[i].first;
        }
    }
    printf("%d\n",ans);//输出工作数
}
int main(){
    scanf("%d",&workNums);
    for(int i=0;i<workNums;i++){
        cin>>startTime[i];
    }
    for(int i=0;i<workNums;i++){
        cin>>endTime[i];
    }
    solve();
}