#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,s,l,t,a,b;
int get(int x,int y)
{
	return (x+y)*(y-x+1)/2;
}
int fa[200010],p[200010];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b)
{
	int f1=find(a);
	int f2=find(b);
	if(f1>f2) fa[f2]=f1;
	else fa[f1]=f2;
}
void solve()
{
	ans=s=0;
	cin>>n>>m;
	vector<pair<int,int>>v;
	for(int i=1;i<=n;i++)
	{
		cin>>l;
		s+=l;
		map<int,int>mp;
		for(int i=1;i<=l;i++)
		{
			cin>>t;
			mp[t]=1;
		}

		int c1=0;
		for(int i=0;i<=l+2;i++)
		{
			if(!mp.count(i)) 
			{
				if(c1==1) 
				{
					b=i;
					ans=max(ans,i);
					break;
				}
				a=i;
				c1++;
			}
		}
		v.push_back({a,b});
	}
	for(int i=0;i<=l+2;i++) fa[i]=i;
	for(auto i:v) merge(i.first,i.second);
	

	for(int i=0;i<=l+2;i++) p[i]=find(i);
//	for(int i=0;i<=l+2;i++) cout<<p[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<=l+2;i++) p[i]+=p[i-1];
	if(m<=l+2) cout<<p[m]<<"\n";
	else cout<<p[l+2]+get(l+3,m)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
