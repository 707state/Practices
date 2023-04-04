//给定一个字符串，每次只能移动最前或者最后的字符，求其最小字典序
//解决思路：矩阵方法，见书本57
#include<iostream>
#include<string.h>
using namespace std;
int n;
char* inputLine=new char[n+1];
void solve(){
    //每一次操作时，剩余的字符串是原有字符串减去一个
    int a=0,b=n-1;
    while(a<=b){
        bool left=false;
        //将从左起和从右起的字符串进行比较
        for(int i=0;a+i<=b;i++){
            if(inputLine[i+a]<inputLine[b-i]){
                left=true;
                break;
            }
            else if(inputLine[a+i]>inputLine[b-i]){
                left=false;
                break;
            }
        }
        if(left) putchar(inputLine[a++]);
        else putchar(inputLine[b--]);
        printf("\n");//putchar将一个字符输出到终端
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inputLine[i];
    }
    solve();
}