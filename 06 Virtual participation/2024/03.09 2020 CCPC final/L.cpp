#include <bits/stdc++.h>
using namespace std;
int l,r,mid,n,m,a[200010],b[200010],ans;
int ck(int x)
{
	int cnt=0;
	vector<int>d(n+1,0);
	for(int i=1;i<=m;i++)
	{
		if(min(b[i]-a[i],n-(b[i]-a[i]))>x) return 0;
		if(max(b[i]-a[i],n-(b[i]-a[i]))<=x) continue;
		cnt++;
		if(b[i]-a[i]>=n-(b[i]-a[i])) d[a[i]]++,d[b[i]]--;
		else d[1]++,d[a[i]]--,d[b[i]]++;  
	}
	for(int i=1;i<=n;i++)
	{
		d[i]+=d[i-1];
		if(d[i]==cnt) return 1;
	}
	return 0;
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=m;i++) 
		{
			cin>>a[i]>>b[i];
			if(a[i]>b[i]) swap(a[i],b[i]);
		}
		l=0,r=n;
		while(l<=r)
		{
			mid=l+r>>1;
			if(ck(mid)) r=mid-1;
			else l=mid+1;
		}
		cout<<l<<"\n";
	}
}
