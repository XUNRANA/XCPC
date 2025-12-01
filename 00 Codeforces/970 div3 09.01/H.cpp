#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,q,a[N],x,ans[N],cnt[N]; 
bool ck(int x,int k)
{
//	   %k<=x
//     [0,x]   [k,k+x]   [2*k,2*k+x] ........
	int res=cnt[x];
	
	for(int i=k;i<=n;i+=k)
	res+=cnt[min(i+x,n)]-cnt[i-1];
	
	return 2*res>n;
}

void solve()
{
	cin>>n>>q;

	for(int i=1;i<=n;i++) cin>>a[i],cnt[i]=0;
	
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	
	for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	

	for(int i=2;i<=n;i++)
	{
		int l=0,r=i-1;
		while(l<=r)
		{
			int m=l+r>>1;
			if(ck(m,i)) r=m-1;
			else l=m+1;
		}
		ans[i]=l;
	}
	while(q--)
	{
		cin>>x;
		cout<<ans[x]<<" ";
	}
	cout<<"\n";
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
