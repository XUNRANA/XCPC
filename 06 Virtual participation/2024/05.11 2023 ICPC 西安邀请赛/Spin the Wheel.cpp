#include <bits/stdc++.h>
using namespace std;
int n,mx=0,mi=1e9,a[100010],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	if(mx==mi)
	{
		if(mx==0) ans=0;
		else ans=n+1;
	}
	else
	{
		set<int>s;
		for(int i=2;i<=n;i++)
		{
			if(a[i]>a[i-1]) s.insert(a[i]-a[i-1]);
			else s.insert(a[i]-a[i-1]+n);
		}
		if(s.size()!=1) ans=-1;
		else ans=*s.begin()+(a[1]!=0);
	}
	cout<<ans<<"\n";
}
