#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	for(int i=k;i<=n;i++)
	{
		if(a[i]-a[i-k]>=1024*k)
		{
			printf("%.6f MiBps\n",double(a[i]-a[i-k])/(1024*k));
		}
		else 
		{
			printf("%.6f KiBps\n",double(a[i]-a[i-k])/k);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve(); 
}
