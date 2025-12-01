#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010];
int tr[1010];
int tr1[1010];
int p[1010];
int s[1010];
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x,int tr[])
{
	while(i<=n) 
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int l,int r,int tr[])
{
	int res=0;
	while(r)
	{
		res+=tr[r];
		r-=lowbit(r);
	}
	l--;
	while(l)
	{
		res-=tr[l];
		l-=lowbit(l);
	}
	return res;
}
int sol()
{

}
int fx(int x)
{
	return x*(x-1)/2;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		add(a[i],1,tr);
		p[i]=query(a[i]+1,n,tr); 
		p[i]+=p[i-1];
	}
	for(int i=1;i<=n;i++) add(a[i],-1,tr);
	
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
		if(i-1>=1) add(a[i-1],1,tr1);
		int res=0,res1=0;
		for(int j=i;j<=n;j++)//1---i-1   i--j  j+1---n
		{
			add(a[j],1,tr);
			res+=query(a[j]+1,n,tr);
			res1+=query(a[j]+1,n,tr1);
			ans.push_back(p[i-1]+p[n]-p[j]+res1+fx(j-i+1)-res);
		}
		for(int j=i;j<=n;j++) add(a[j],-1,tr);
	}
	
	for(int i=0;i<ans.size();i++)
	{
		if(i) cout<<" ";
		cout<<ans[i];
	}
	cout<<"\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
