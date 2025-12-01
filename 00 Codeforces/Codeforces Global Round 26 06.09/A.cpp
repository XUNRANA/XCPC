#include <bits/stdc++.h>
using namespace std;
int n,a[100];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]==a[n]) cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		if(a[2]!=a[n])
		{
			cout<<"B";
			for(int i=2;i<=n;i++) cout<<"R";
			cout<<"\n";
			return ;
		}
		cout<<"BB";
		for(int i=3;i<=n;i++) cout<<"R";
		cout<<"\n";
		return ;
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
