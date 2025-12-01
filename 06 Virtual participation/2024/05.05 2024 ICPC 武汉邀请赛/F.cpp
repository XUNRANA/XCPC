#include <bits/stdc++.h>
using namespace std;
int n,k,l,r,m;
int q(int i,int j,int x)
{
	cout<<"? "<<i<<" "<<j<<" "<<x<<"\n\n";
	int res; 
	cin>>res;
	return res;
}
int ck(int x)
{
	int ans=0;
	for(int i=n,j=1;i>=1;i--)
	{
		while(j<=n&&q(i,j,x-1)) j++;
		ans+=n-j+1;
	}
	return ans>=k;
}
int main()
{
	cin>>n>>k;
	l=1,r=n*n;
	while(l<r)
	{
		m=(l+r+1)>>1;
		if(ck(m)) l=m;
		else r=m-1;
	}
	cout<<"! "<<l<<"\n";
}
