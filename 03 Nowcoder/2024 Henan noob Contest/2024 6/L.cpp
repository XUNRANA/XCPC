#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,nn,now,tr[300010];
int lowbit(int x)
{
	return x&-x;
}
int query(int i)
{
	int res=1;
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
    cin>>n>>k;
    for(int i=1;i<=n;i++) add(i,1);
    nn=n;
    now=1;
	while(nn!=1)
    {
    	int l=1,r=n;
    	now=(now+k-1-1)%nn+1;
		while(l<=r)
    	{
    		int m=l+r>>1;
    		if(query(m)>now) r=m-1;
    		else l=m+1;
		}
		nn--;  
		cout<<l<<" ";
		add(l,-1);
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
