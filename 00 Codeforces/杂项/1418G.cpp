#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define u64 unsigned long long
#define i64 long long
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
u64 a[N],h1[N],h2[N],hs[N],sum[N];
void init()
{
	for(int i=1;i<=500000;i++) h1[i]=rng();
	for(int i=1;i<=500000;i++) h2[i]=rng();
}
void solve()
{
	int n;
	cin>>n;
	map<u64,int>mp;
	map<u64,i64>cnt;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(cnt[a[i]]%3==0) hs[i]=h1[a[i]];
		if(cnt[a[i]]%3==1) hs[i]=h2[a[i]];
		if(cnt[a[i]]%3==2) hs[i]=h1[a[i]]^h2[a[i]];
		cnt[a[i]]++;
	}
	cnt.clear();
	
	mp[0]=1;
	i64 ans=0;
	for(int l=0,r=1;r<=n;r++)
	{	
		sum[r]=sum[r-1]^hs[r];
		cnt[a[r]]++;
		while(cnt[a[r]]>3)//3次以上左指针移动，消除影响 
		{
			cnt[a[l]]--;
			if(l) mp[sum[l-1]]--;
			l++;
		}
//		cout<<l<<" "<<r<<" "<<sum[r]<<" "<<mp[sum[r]]<<"\n";
		ans+=mp[sum[r]];
		mp[sum[r]]++;
	}
	cout<<ans<<"\n";
}

int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}


