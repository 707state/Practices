//给定两个字符串，求出两个字符串的最长的公共子序列
#include<iostream>
using namespace std;
#define max(a,b) (a>b?a:b);
int len1,len2;
char* str1=new char[len1+1];
char* str2=new char[len2+1];
int dp[1000][1000];
void solve(){
    //书本第56页
    //当str1[i+1]=str2[j+1]时，在序列str1[1..i]和str2[1..j]的公共子列后面\
    追加str1[i+1]或者某一个子列
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(str1[i]==str2[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    printf("%d\n",dp[len1][len2]);//最长的共同自序列
}
int main(){
    cin>>len1>>len2;
    scanf("%s",str1);
    scanf("%s",str2);
    solve();
}