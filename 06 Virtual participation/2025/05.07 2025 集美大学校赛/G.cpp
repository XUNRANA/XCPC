#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[10];
int y[10];
int dis(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
void solve() 
{
    int k=1;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            x[k]=i;
            y[k]=j;
            k++;
        }
    }
    x[0]=4;
    y[0]=2;

    string s;
    cin>>s;
    int ans=0;
    for(int i=1;i<s.size();i++) ans+=dis(s[i]-'0',s[i-1]-'0');
    cout<<ans<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}