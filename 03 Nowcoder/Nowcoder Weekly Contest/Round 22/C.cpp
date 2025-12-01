#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x,a[100010];
void solve()
{
	cin>>n>>k>>x;
	if(n>k||(n+1)*n/2>x) cout<<"-1\n";
	else
	{
		x-=(n+1)*n/2;
		for(int i=1;i<=n;i++) a[i]=i+x/n;
		x%=n;
		for(int i=n;i>=n-x+1;i--) a[i]++;
		for(int i=1;i<=n;i++)
        {
            if(a[i]>k) 
            {
                cout<<"-1\n";
                return ;
            }
        }
        
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

