#include<bits/stdc++.h>
using namespace std;
const int NN=3004;
char s[NN],c[NN];
int cnt[NN];
int main()
{
    int n,k,m=0;
    cin>>n>>k>>s+1;
    for(int i=1;i<=n;i++)
    if(s[i]==s[i-1]) cnt[m]++;
    else cnt[++m]=1,c[m]=s[i];
    c[0]=' ',c[m+1]=' ';
    int ans=2e9;
    for(int i=1;i<=m;i++)
    {
        int res=0,len=cnt[i];
        for(int j=2;j<=m;j++)
        {
            if(c[i-j+1]!=c[i+j-1]) break;
            res+=abs(cnt[i-j+1]-cnt[i+j-1]);
            len+=max(cnt[i-j+1],cnt[i+j-1])*2;
            ans=min(ans,res+k-len);
        }
    }
    if(ans<0) cout<<0;
    else cout<<ans;
}