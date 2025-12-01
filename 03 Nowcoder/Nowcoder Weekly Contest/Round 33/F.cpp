#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,a[100010],b[100010],c[100010];
int mi=(1ll<<60);
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=a[i];
		a[i]-=i;
		mi=min(mi,a[i]); 
	}
	stack<pair<int,int>>k;
	//0 1 -1 2 -1 
	//1 2 0 3 0
	//1 1 1 1 2
	for(int i=1;i<=n;i++)
	{
		int sum=a[i]-mi;
		int cnt=1;
		while(!k.empty()&&sum/cnt<k.top().first)
		{
			int s1=k.top().first;
			int c1=k.top().second;
			k.pop();
			sum+=s1*c1;
			cnt+=c1;
		}
		k.push({sum/cnt,cnt-sum%cnt});
		if(sum%cnt) k.push({sum/cnt+1,sum%cnt});
	}
	int j=n;
	while(!k.empty())
	{
		int s1=k.top().first;
		int c1=k.top().second;
		k.pop();
		while(c1--) a[j--]=s1;
	} 
	int ans=0;
	for(int i=1;i<=n;i++) a[i]+=mi+i,c[i]=a[i];
	
	for(int i=1;i<=n;i++) 
	{
		if(a[i]!=b[i])
		{
			ans+=abs(b[i]-a[i]);
			a[i+1]-=b[i]-a[i];
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

