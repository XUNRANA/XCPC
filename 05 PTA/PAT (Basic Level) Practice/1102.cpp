#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	cin>>n;
	int mx1=-1;
	int mx2=-1;
	string ans1,ans2;
	for(int i=1;i<=n;i++)
	{
		string s;
		int a,b;
		cin>>s;
		cin>>a>>b;
		if(b>mx1)
		{
			mx1=b;
			ans1=s;
		}
		if(a*b>mx2)
		{
			mx2=a*b;
			ans2=s;
		}
	}
	cout<<ans1<<" "<<mx1<<"\n";
	cout<<ans2<<" "<<mx2<<"\n"; 


}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
