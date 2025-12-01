#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,r,a[100010],dp[100010];
map<int,int>mp;
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],mp[a[i]]);
        mp[a[i-1]]=i-1;
    }
    while(q--)
    {
        cin>>l>>r;
        if(dp[r]>=l) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,r,a[100010],t[100010],ans[200010];
int lowbit(int x)
{
	return x&-x;
}
int query1(int l,int r)
{
	int res=0;
	while(r)
	{
		res+=t[r];
		r-=lowbit(r);
	}
	while(l)
	{
		res-=t[l];
		l-=lowbit(l);
	}
	return res;
}
void add(int i,int x)
{
	while(i<=n)
	{
		t[i]+=x;
		i+=lowbit(i);
	}
}
void solve()
{
    cin>>n>>q;
    map<int,deque<int>>d;
	vector<vector<pair<int,int>> >query(n+1); 
    for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		d[a[i]].push_back(i);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		query[r].push_back({i,l});
	}
	for(int r=1;r<=n;r++)
	{
		while(!d[a[r]].empty()&&r-d[a[r]].front()>1)
		{
			int x=d[a[r]].front();
			d[a[r]].pop_front();
			add(x,1);
		}
		while(!query[r].empty())
		{
			int i=query[r].back().first;
			int l=query[r].back().second;
			query[r].pop_back();
			if(query1(l-1,r)>0) ans[i]=1;
		}
	}
	for(int i=1;i<=q;i++) 
	if(ans[i]) cout<<"YES\n";
	else cout<<"NO\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

*/
