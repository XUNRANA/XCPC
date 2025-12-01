#include <bits/stdc++.h>
using namespace std;
int res,n,k,q,l,r,a[200010],ans[200010];
void solve()
{
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		a[i]+=n-i;
	}
	
	
	res=0;
	vector<int>cnt(2*n+2),freq(n+1);
	for(int i=1;i<k;i++)
	{
		freq[cnt[a[i]]]--;//频数-- 
		res=max(res,++cnt[a[i]]);//最大频数为众数 
		freq[cnt[a[i]]]++;//频数++ 
	}
	
	for(int i=k;i<=n;i++)
	{
		freq[cnt[a[i]]]--;
		res=max(res,++cnt[a[i]]);
	
		freq[cnt[a[i]]]++;
		while(freq[res]==0) res--;//自减 
		
		ans[i-k+1]=k-res;
		
		freq[cnt[a[i-k+1]]]--;
		cnt[a[i-k+1]]--;
		freq[cnt[a[i-k+1]]]++;
	}
	
	while(q--)
	{
		cin>>l>>r;
		cout<<ans[l]<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
