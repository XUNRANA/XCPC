#include <bits/stdc++.h>
using namespace std;


vector<int>a[100010];
int d[100010];
void solve()
{
	int n,m,k,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>x;
			a[i].push_back(x);
		}
	}
	int now=1;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		if(!x) now=a[now][y-1];
		else if(x==1)
		{
			cout<<now<<"\n";
			d[y]=now;
		} 
		else now=d[y];
	}
	cout<<now<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

