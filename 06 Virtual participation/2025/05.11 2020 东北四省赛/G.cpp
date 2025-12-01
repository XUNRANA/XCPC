#include <bits/stdc++.h>
using namespace std;
#define int long long

int c[110][26];
void solve() 
{
    int n,k1;
    cin>>n>>k1;
    int ans=0;
    for(int i=0;i<k1;i++) for(int j=0;j<26;j++) c[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        char ch;
        int x;
        cin>>ch>>x;
        for(int k=0;k<26;k++) c[i%k1][k]=0;
        c[i%k1][ch-'A']=x;
        for(int k=0;k<26;k++)
        {
            int s=0;
            for(int j=0;j<k1;j++) s+=c[j][k];
            ans+=(s==5);
        }
    }
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}