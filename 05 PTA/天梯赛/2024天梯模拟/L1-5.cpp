#include <bits/stdc++.h>
using namespace std;
int a[110],b[110];
void solve()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	while(q--)
	{
		for(int i=1;i<=n;i++) cin>>b[i];
		int c1=0;
		int c2=0;
		for(int i=1;i<=n;i++) 
		if(b[i])
		{
			if(b[i]!=a[i]) c2++;
			else c1++;
		}
		
		if(c1&&!c2) cout<<"Da Jiang!!!\n";
		else cout<<"Ai Ya\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
