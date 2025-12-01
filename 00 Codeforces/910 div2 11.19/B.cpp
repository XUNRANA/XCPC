#include <bits/stdc++.h>
using namespace std;
long long cnt,n,d,l,lst,a[200010];
void solve1()
{
	cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	lst=a[n];
	for(int i=n;i>=1;i--)
	{
		if(a[i]<=lst)
		{
			lst=a[i];
			continue;
		}
		else
		{
			d=(a[i]+lst-1)/lst;
			cnt+=d-1;
			lst=a[i]/d;
		}
	}
	cout<<cnt<<"\n";
}

void solve()
{
	cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=n-1;i>=1;i--)
	{
		//cout<<cnt<<"\n";
		if(a[i]<=a[i+1]) continue;
		l=(a[i]+a[i+1]-1)/a[i+1];
		a[i]=a[i]/l;
		cnt+=l-1;
	}
	cout<<cnt<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
