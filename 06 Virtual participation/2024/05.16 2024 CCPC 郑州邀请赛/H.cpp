#include <bits/stdc++.h>
using namespace std;
#define int long long
#define p 998244353
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int n,a[400010],ans;
void solve()
{
	cin>>n;
	ans=1;
	vector<int>b;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
		if(a[i]>=0) b.push_back(a[i]);
	}
	sort(b.begin(),b.end());
	map<int,int>cnt;
	for(int i=1,j=0,d=0;i<=2*n;i++)
	{
		if(a[i]>=0) cnt[a[i]]++,d++;
		else
		{
			ans=ans*cnt[b[j]]%p*ksm(d,p-2)%p;
			ans%=p;
			cnt[b[j]]--;
			j++;
			d--;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	int T=1;
	//cin>>T;
	while(T--) solve();
}
