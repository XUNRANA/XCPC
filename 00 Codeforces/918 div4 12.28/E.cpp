#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[200010];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			if(i&1) a[i]*=-1;
		}
		map<long long,int>pos;
		pos[0]=0;
		ll cur=0,f=0;
		for(int i=1;i<=n;i++)
		{
			cur+=a[i];
			if(pos.count(cur)) {f=1;break;}
			pos[cur]=i;
		}
		if(f==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
