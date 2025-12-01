#include <bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int c[200010];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
//   1 2 3 4 5
//	1 2 3 4 
	for(int i=1;i<n;i++)
	{
		int p1=b[i],p2=b[i+1];
		if(p1>p2) swap(p1,p2);
		c[p1]++;
		c[p2]--;
	}
	for(int i=1;i<n;i++) c[i]+=c[i-1];
	sort(c+1,c+n,greater<int>());
	int s=0;
	for(int i=1;i<n;i++)
	{
//		cout<<c[i]<<"\n";
		s+=c[i];
		if(s>=k)
		{
			cout<<i<<"\n";
			return ;
		}
	}
	cout<<"-1\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
