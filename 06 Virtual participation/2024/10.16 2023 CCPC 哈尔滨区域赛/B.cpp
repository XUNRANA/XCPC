#include <bits/stdc++.h>
using namespace std;
long long n,a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]>0) cout<<"+";
	else if(a[1]==0) cout<<"0";
	else cout<<"-";
	
	int f=0;
	for(int i=2;i<=n;i++)
	{
		a[i]+=a[i-1]/2;
		if(a[i-1]&1)
		{
			if(a[i-1]>0) f=1;
			else f=-1;
		}
		if(a[i]>0) cout<<"+";
		else if(a[i]<0) cout<<"-";
		else if(a[i]==0)
		{
			if(f==0) cout<<"0";
			else if(f==1) cout<<"+";
			else cout<<"-";
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
