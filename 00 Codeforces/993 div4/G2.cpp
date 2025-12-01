#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
int in[200010],vt[200010];
int a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) in[i]=vt[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=x;
        in[x]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++) 
    if(in[i]==0) q.push(i);
    int ans=0;
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        ans=max(ans,++vt[u]);
        vt[a[u]]+=vt[u];
        in[a[u]]--;
        if(!in[a[u]]) q.push(a[u]);
    }
    cout<<ans+2<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
