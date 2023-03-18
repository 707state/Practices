#include<iostream>
#include<algorithm>
using namespace std;
int n;
int* head=new int[n];
int search_one(){
    int i=0;
    while(i!=n-1){
        if(head[i++]==0){
            return i-=1;
        }
    }
    return 0;
}
int search_zero(){
    int i=n-1;
    while(i){
        if(head[i--]==1){
            return i+=1;
        }
    }
    return 0;
}
int solve(int num){
    if(num<n){
    int i=0;
    for(int k=num+1;k<n;k++){
        if(head[k]<head[num]) i++;
    }
    return i+solve(num+1);}
    else{
        return 0;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>head[i];
    }
    if(!search_zero()||!search_one()){
        printf("0");
    }
    else{
        if(search_one()<n-search_zero()){
        head[search_one()]=1;}
        else{
        head[search_zero()]=0;}
        //for(int i=0;i<n;i++){
          //  cout<<head[i];
        //}
        printf("%d\n",solve(0));
    }
}