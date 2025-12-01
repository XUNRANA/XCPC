#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if(n&1) for(int i=1,k=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<k++<<" ";
	else for(int i=1,k=1;i<=n;i++,cout<<"\n")
	{
		if(i&1) for(int j=1;j<=n;j++) cout<<k++<<" ";
		else 
		{
			int t=k++;
			for(int j=1;j<n;j++) cout<<k++<<" ";
			cout<<t;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

