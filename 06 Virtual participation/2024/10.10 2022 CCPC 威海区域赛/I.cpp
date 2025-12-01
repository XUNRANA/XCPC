#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[50010],b[30];
int b1[30];
//bool ck(__int128 x)
//{
//	for(__int128 i=0;i<k;i++) b1[i]=b[i];
//	
//	__int128 j=k-1;
//	
//	priority_queue<__int128,vector<__int128>,less<__int128> >q;
//	
//	for(__int128 i=1;i<=n;i++) if(x*a[i]!=0) q.push(x*a[i]);
//
//	while(!q.empty())
//	{
//		__int128 y=q.top();
//		q.pop();
//		if(j==-1) return false;
//		if(y>=(1ll<<j))
//		{	
//			if((1ll<<j)*b1[j]<=y)
//			{
//				y-=(1ll<<j)*b1[j];
//				b1[j]=0;
//				j--;
//				if(y>0) q.push(y);
//			}
//			else
//			{
//				__int128 t=y/(1ll<<j);
//				y-=(1ll<<j)*t;
//				b1[j]-=t;
//				if(b1[j]==0) j--;
//				if(y>0) q.push(y);	
//			}
//		}
//		else
//		{
//			b1[j]--;
//			if(b1[j]==0) j--;
//		}
//	}
//	return true;
//}
bool ck(int x)//sum1、sum2处理的好就不用开__int128 
{
	for(int i=0;i<k;i++) b1[i]=b[i];
	
	int j=k-1;
	
	priority_queue<int,vector<int>,less<int> >q;
	
	for(int i=1;i<=n;i++) if(x*a[i]!=0) q.push(x*a[i]);

	while(!q.empty())
	{
		int y=q.top();
		q.pop();
		if(j==-1) return false;
		if(y>=(1ll<<j))
		{	
			if((1ll<<j)*b1[j]<=y)
			{
				y-=(1ll<<j)*b1[j];
				b1[j]=0;
				j--;
				if(y>0) q.push(y);
			}
			else
			{
				int t=y/(1ll<<j);
				y-=(1ll<<j)*t;
				b1[j]-=t;
				if(b1[j]==0) j--;
				if(y>0) q.push(y);	
			}
		}
		else
		{
			b1[j]--;
			if(b1[j]==0) j--;
		}
	}
	return true;
}
void solve()
{
	
	cin>>n>>k;
	
	int sum1=0,sum2=0;
	
	for(int i=1;i<=n;i++) cin>>a[i],sum1+=a[i];

	for(int i=0;i<k;i++) cin>>b[i],sum2+=(1ll<<i)*b[i];
	
	int l=0,r=sum2/sum1;

	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) l=m+1;
		else r=m-1;
	}
	cout<<l-1<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
