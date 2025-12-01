#include <bits/stdc++.h>
using namespace std;
int n,q,a[1000010];
void solve()
{
	cin>>n>>q;
	for(int i=0;i<n;i++) a[i]=i+1;
	int now=0;
	while(q--)
	{
		int op,p,x,k;
		cin>>op;
		if(op==1)
		{
			cin>>p>>x;
			p--;
			a[(p+now)%n]=x;
		}
		else if(op==2)
		{
			cin>>p;
			p--;
			cout<<a[(p+now)%n]<<"\n";
		}
		else
		{
			cin>>k;
			now=(now+k)%n;
		}
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
