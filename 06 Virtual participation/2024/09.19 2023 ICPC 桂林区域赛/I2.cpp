#include <bits/stdc++.h>
using namespace std;
#define N 500010
int n,m,ans;

int tr[N],a[N],last[N];

vector<int>idx[N];

vector< pair<int,int> >q[N];

int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}


void solve()
{
	cin>>n>>m;//n+1!!!!!!!!!!
	for(int i=1;i<=n+1;i++) idx[i].clear(),q[i].clear(),tr[i]=0;
	for(int i=1;i<=n;i++)
	{ 
		cin>>a[i];
		last[a[i]]=0;
		idx[a[i]].push_back(i);
	}	
	

	
	int l,r,x;
	for(int i=1;i<=n+1;i++)
	{
		x=i;
		if(idx[i].size()==0)
		{
			q[n].push_back({1,x});
			break;
		}
		
		l=0;
		for(auto j:idx[i])
		{
			r=j;
			if(r-1>=l+1) q[r-1].push_back({l+1,x});
			l=r;
		}
		
		if(n>=(l+1)) q[n].push_back({l+1,x});
	}
	
	ans=-1;
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		if(last[t]) add(last[t],-1);
		last[t]=i;
		
		add(last[t],1);
		for(auto j:q[i]) 
		{
			if(i-j.first+1-j.second<=ans) continue;
			ans=max(ans,query(i)-query(j.first-1)-j.second);
		}
	}	
	cout<<ans<<"\n";
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
