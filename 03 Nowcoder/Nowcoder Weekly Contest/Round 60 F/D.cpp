#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],s;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	s=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>s+1)
		{
			cout<<s+1<<"\n";
			return ;
		}
		s+=a[i];
        if(s>=n) break;
	}
	cout<<"Cool!\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
