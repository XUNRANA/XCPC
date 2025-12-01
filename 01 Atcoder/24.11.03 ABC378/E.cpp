#include <bits/stdc++.h>
using namespace std;

int n,m,a[200010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1],a[i]%=m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cout<<i<<" "<<j<<" "<<a[j]-a[i-1]<<"\n";
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
