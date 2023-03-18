#include<iostream>
#include<algorithm>
using namespace std;
int max(int a,int b){
    return (a>b)?a:b;
}
void solve(int* head,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                int len=head[i]+head[j]+head[k];
                int ma=max(head[i],max(head[j],head[k]));
                int rest=len-ma;//两边之差小于第三边
                if(ma<rest){
                    ans=max(ans,len);
                }
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    int n;
    cin>>n;
    int* line=new int[n];
    for(int i=0;i<n;i++){
        cin>>line[i];
    }
    solve(line,n);
}