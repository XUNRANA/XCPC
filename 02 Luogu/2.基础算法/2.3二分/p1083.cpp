#include <bits/stdc++.h>
using namespace std;
#define N 1000010
long long n,m,a[N],d[N],s[N],t[N],b[N],f,l,r,mid;
int check(int mid)
{
	int f1=0;
	vector<long long>v(N);
	for(int i=1;i<=mid;i++)
	{
		v[s[i]]+=d[i];
		v[t[i]+1]-=d[i];
	}
	for(int i=1;i<=n;i++) 
	{
		v[i]+=v[i-1];
		if(v[i]>a[i]) return 1;
	}
	return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>d[i]>>s[i]>>t[i];
		b[s[i]]+=d[i];
		b[t[i]+1]-=d[i];
	}
	for(int i=1;i<=n;i++) 
	{
		b[i]+=b[i-1];
		if(b[i]>a[i]) f=1;
	}
	if(f==0) cout<<0;
	else 
	{
		cout<<-1<<"\n";
		l=1,r=m;
		while(l<r)
		{
			//cout<<l<<" "<<r<<"\n";
			mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l;
	}
} 
