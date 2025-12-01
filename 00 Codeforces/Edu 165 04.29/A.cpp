#include <bits/stdc++.h>
using namespace std;
int n,a[100];
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=i;
	if(n==2) cout<<2<<"\n";
	else 
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(mp[i]==j&&mp[j]==i)
				{
					cout<<2<<"\n";
					return ;
				}
			}
		}
		cout<<3<<"\n";
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve(); 
}
