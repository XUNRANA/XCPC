#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,ans=1e18,a[100010],c;
void solve()
{
    cin>>n>>k;
    priority_queue<int,vector<int>,less<int>>q;
    for(int i=1;i<=n;i++) cin>>a[i],q.push(a[i]);
    if(k==1) 
    {
        cout<<q.top();
        return ;
    }
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        ans=min(ans,c+t);
        c++;
        t/=k;
        if(t) q.push(t);
    }
    ans=min(ans,c);
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}