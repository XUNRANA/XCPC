#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans,a[61];
void solve()
{	
	cin>>n>>k;
	int l=1;
	a[0]=1;
	while(n)
	{
		a[l]=a[l-1]*(n%10+1);
		l++;
		n/=10;
	}
	k--;
	for(int i=l-1;i>=0;i--)
	{
		if(k>=a[i])
		{
			ans=k/a[i]*(int)pow(10,i)+ans;
			k-=k/a[i]*a[i];
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
