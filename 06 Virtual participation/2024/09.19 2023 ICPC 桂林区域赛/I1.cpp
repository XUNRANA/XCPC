#include <bits/stdc++.h>
using namespace std;
#define N 500010
int n,m,ans;
int tr[N],a[N],last[N];

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
	cin>>n>>m;
	
	map<int,int>pre,lft;
	
	vector<array<int,3>>q;
	
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		last[a[i]]=0;
		lft[i]=pre[a[i]];
		pre[a[i]]=i;//pre[x]为x最后一次出现的下标 
		if(i-1>=lft[i]+1) q.push_back({lft[i]+1,i-1,a[i]});
	}
	
	for(int i=1;i<=n+1;i++) if(pre[i]<n) q.push_back({pre[i]+1,n,i});
	
	for(int i=1;i<=n+1;i++) tr[i]=0;
	
	ans=-1;

	int j=0;
	for(int i=1;i<=n;i++)
	{
			
		if(last[a[i]]) add(last[a[i]],-1);
		
		last[a[i]]=i;
		
		add(last[a[i]],1);
		
		while(j<q.size()&&i==q[j][1])
		{
			ans=max(ans,query(q[j][1])-query(q[j][0]-1)-q[j][2]);
			j++;
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
