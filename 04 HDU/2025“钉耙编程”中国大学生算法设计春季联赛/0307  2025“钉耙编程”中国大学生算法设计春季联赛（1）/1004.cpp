#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
int n,q,h[100010];
int st[100010][20];
multiset<int>sl,sr;
int query(int l,int r)
{
	int k=__lg(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>h[i];
	sl.clear(),sr.clear();
	st[1][0]=1;
	for(int i=2,j=2;i<=n;i++)
	{
		int l=min(h[i],h[i-1]),r=max(h[i],h[i-1]);
		sl.insert(l);sr.insert(r);
		while(j<=i&&*prev(sl.end())>=*sr.begin())
		{
			int ll=min(h[j],h[j-1]),rr=max(h[j],h[j-1]);
			sl.erase(sl.find(ll)),sr.erase(sr.find(rr));
			j++;
		}
		st[i][0]=i-(j-1)+1;
	}
	for(int i=1;i<=__lg(n);i++)
	for(int j=1;j+(1<<i)-1<=n;j++) st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		int l1=1,r1=r-l+1;
		while(l1<=r1)
		{
			int m=l1+r1>>1;
			if(query(l+m-1,r)>=m) l1=m+1;
			else r1=m-1;
		}
		l1--;
		ans=(ans+1ll*i*l1%P)%P;
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

