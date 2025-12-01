#include <bits/stdc++.h>
using namespace std;

void solve()
{
	vector<int>a;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) 
	{
		int sum=0;
		int mi=100;
		int mx=0;
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			mi=min(mi,x);
			mx=max(mx,x);
			sum+=x;
		}
		a.push_back(sum-mi-mx);
	}
	sort(a.begin(),a.end(),greater<int>());
	int f=0;
	for(int i=k-1;i>=0;i--) 
	{
		if(f) printf(" ");
		printf("%.3f",1.0*a[i]/(m-2));
		f=1;
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

