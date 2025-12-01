#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		int k=1<<(n-1);
		for(int j=1;j<=n;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='n') ans+=k;
			k/=2;
		}
		cout<<ans+1<<"\n";
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

