#include <bits/stdc++.h>
using namespace std;
int n,a[5010],d[5010];
string s;
int ck(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1') a[i]=1;
		else a[i]=0;
		d[i]=0;	
	}	
	for(int i=1;i<=n-x+1;i++)
	{
		d[i]+=d[i-1];
		a[i]+=d[i];
		if(a[i]%2==0)
		{
			d[i]++;
			d[i+x]--;
		}
	}
	for(int i=n-x+2;i<=n;i++) 
	{
		d[i]+=d[i-1];
		a[i]+=d[i];
		if(a[i]%2==0) return 0;
	}
	return 1;
}
void solve()
{
	cin>>n>>s;
	s=" "+s;
	for(int i=n;i>=1;i--)
	{
		if(ck(i))
		{
			cout<<i<<"\n";
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
