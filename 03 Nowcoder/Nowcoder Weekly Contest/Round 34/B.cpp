#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,t;
	cin>>n;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++) 
	{
		cin>>b[i];
        t=b[i];
        if(t>=1&&t<=n) a[t]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			cout<<"0\n";
			return ;
		}
	}
	cout<<"1\n"<<1<<" "<<b[1]+1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

