#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
	cin>>n>>m;
	if(m>=2*n) cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<(i-j+2*n)%(2*n)/2+1<<" \n"[j==m-1];
			}
		}
	}
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

