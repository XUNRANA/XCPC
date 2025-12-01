#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,mi,p,a[200010];
void solve()
{
	cin>>n;
	mi=1e9;
	for(int i=1;i<=n;i++) cin>>a[i],mi=min(a[i],mi);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==mi)
		{
			p=i;
			break;
		}
	}
	
	for(int i=n-1;i>=1;i--) 
	if(a[i]>a[i+1]) 
	{
		if(a[i+1]!=mi)
		{
			cout<<"-1\n";
			return ;
		}
		if(i==p-1) cout<<i<<"\n";
		else cout<<"-1\n";
		return ;
	}
	cout<<"0\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}

