#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,l,r,y,ans,tr[100010];
int lowbit(int x)
{
	return x&-x;
}
int query(int i)
{
    if(i<=0) return 0;
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
void solve()
{
	ans=0;
	cin>>n>>x;
	vector<pair<int,int> >v;
	vector<int>a;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r>>y;
		v.push_back({l,y});//start
		v.push_back({r,-y});//end
		a.push_back(y);
    }
    sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	sort(v.begin(),v.end());
	for(auto i:v)
	{
        int l=i.first;
		int op=i.second;
		int j=upper_bound(a.begin(),a.end(),abs(op))-a.begin();
		add(j,op);
		if(op>0)
		{
			int j1=upper_bound(a.begin(),a.end(),x)-a.begin();
			int add=query(j1),p=0;
			while(add!=p)
			{
				p=add;
				j1=upper_bound(a.begin(),a.end(),x+add)-a.begin();
				add=query(j1);
			}
			ans=max(ans,x+add);
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
}
