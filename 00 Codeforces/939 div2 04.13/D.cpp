#include <bits/stdc++.h>
using namespace std;
int n,a[20],ans,index;
vector<pair<int,int>>ans1;
int f(int x)
{
	int res=0,c=0;
	for(int i=0;i<=n;i++) 
	if(x>>i&1) c++;
	else 
	{
		res+=a[i+1];	
		if(c)
		{
			res+=c*c;
			c=0;
		}
	}
	return res;
}
void op(int l,int r)
{
	map<int,int>mp;
	for(int i=l;i<=r;i++) mp[a[i]]++;
	int cnt=0;
	for(int i=0;i<=r-l;i++)
	{
		if(mp[i]>0) cnt++;
		else break;
	}
	for(int i=l;i<=r;i++) a[i]=cnt;
	ans1.emplace_back(l,r);
	return ;
}
void build(int l,int r)
{
	if(l==r)
	{
		if(a[l]!=0) op(l,r);
		return ;
	}
	build(l,r-1);
	if(a[r]!=r-l)
	{
		op(l,r);
		build(l,r-1);
	}
			
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=0;
	for(int i=0;i<(1<<n);i++) 
	{
		if(f(i)>ans)
		{
			ans=f(i);
			index=i;
		}
	}
	vector<pair<int,int>>res;
	int c=0;
	for(int i=0;i<=n;i++) 
	if(index>>i&1) c++;
	else
	{
		if(c) res.push_back({i-c+1,i});
		c=0;	
	}
	ans1.clear();
	for(auto i:res) 
	{
		//cout<<i.first<<" "<<i.second<<"\n";
		build(i.first,i.second);
		op(i.first,i.second);
	}
	cout<<ans<<" "<<ans1.size()<<" "<<"\n";
	for(auto i:ans1) cout<<i.first<<" "<<i.second<<"\n";
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);	
	int T=1;
//	cin>>T;
	while(T--) solve();
}
