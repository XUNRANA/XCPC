#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[1000010];
bool ck(int x)
{
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum==x)
		{
			cnt++;
			sum=0;
		}
		else if(sum>x)
		{
			cnt++;
			sum=a[i];
		}
	}
    
	if(sum) cnt++;
	return cnt<=k;
}

void solve()
{
	cin>>n>>k;
    int mx=0;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    int l=mx,r=1e15;
    while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;
	}
    cout<<l<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
