#include<iostream>
#include<algorithm>
#include<string>
std::string target;
std::string out="";
int n;
void solve(){
    int a=0,b=n-1;
    while(a<=b){//剩余的字符串就是target[a..b]
        bool left=false;
        for(int i=0;a+i<=b;i++){
            if(target[a+i]<target[b-i]){
                left=true;
                break;
            }
            else if(target[a+i]>target[b-i]){
                left=false;
                break;//找出首尾谁的值更小
            }
        }
        if(left) out.push_back(target[a++]);//自增操作，使得已经被操作过的子字符串跳过
        else out.push_back(target[b--]);
    }
    std::cout<<out;
}
int main(){
    std::cin>>target;
    n=target.length();
    solve();
}
