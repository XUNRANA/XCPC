#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,a[100010],s,ans;
void solve()
{
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++) cin>>a[i];
	s=ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		s+=a[i];
		if(s<l) continue;
		if(s>=l&&s<=r)
		{
			ans++;
			s=0;
			j=i+1;
		}
		else if(s>r)
		{
			while(s>r) s-=a[j++];
			if(s>=l&&s<=r)
			{
				ans++;
				s=0;
				j=i+1;
			}
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
