#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[110],b[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	while(q--)
	{
		int cnt1=0,cnt0=0;
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i++) 
		if(b[i])
		{
			if(b[i]==a[i]) cnt1++;  
			else cnt0++;
		}
		if(cnt1&&!cnt0) cout<<"Da Jiang!!!\n";
		else cout<<"Ai Ya\n";
	}
	
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

