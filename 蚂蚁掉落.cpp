#include<iostream>
using namespace std;
int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
void solve(int* head,int l,int n){
    int minT=0,maxT=0;
    for(int i=0;i<n;i++){
        minT=max(minT,min(head[i],l-head[i]));
    }
    for(int i=0;i<n;i++){
        maxT=max(maxT,max(head[i],l-head[i]));
    }
    printf("最短时间：%d, 最大时间: %d",minT,maxT);
}
int main(){
    int n;
    cin>>n;
    int l;
    cin>>l;
    int* ants=new int[n];
    for(int i=0;i<n;i++){
        cin>>ants[i];
    }
    solve(ants,l,n);
}