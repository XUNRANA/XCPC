#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int ans[200010];
void solve() 
{
    int n;
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        ans[i]=0;
        m=max(m,a[i]);
    }
    int l=1,r=n;
    for(int i=1;i<=m;i++)
    {
        vector<int>b[2];
        int x=0;
        for(int j=1;j<=n;j++) 
        {
            x|=(a[j]==-1);
            if(a[j]==i) b[x].push_back(j);
        }

        reverse(b[1].begin(),b[1].end());
        for(auto &j:b[0]) 
        if(i&1) ans[j]=r--;
        else ans[j]=l++;

        for(auto &j:b[1]) 
        if(i&1) ans[j]=r--;
        else ans[j]=l++;
    }
    for(int i=1;i<=n;i++) if(!ans[i]) ans[i]=l;

    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];

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