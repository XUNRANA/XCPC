#include <bits/stdc++.h>
using namespace std;
vector<int>g[110];
int main()
{
	int n,t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>t;
			if(t==1) g[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++) 
	{
		for(auto j:g[i]) cout<<j<<" ";
		cout<<"\n";
	}
}
