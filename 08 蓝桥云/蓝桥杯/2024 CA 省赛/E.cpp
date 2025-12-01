#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,T,a[100010];
bool ck(int x)
{
	vector<int>b;
	for(int i=1;i<=x;i++) b.push_back(a[i]);
	sort(b.begin(),b.end());

	long double s=0,ss=0;
	for(int i=0;i<b.size();i++)
	{
		s+=b[i];
		ss+=b[i]*b[i];
		if(i>=k) 
		{
			s-=b[i-k];
			ss-=b[i-k]*b[i-k];
		}
		if(i>=k-1)
		{
			long double avg=s/k;
			long double d=(ss-2*avg*s)/k+avg*avg;
			if(d<T) return 1;
		}
	}
	
	return 0;
	
}
/*
5 3 0
3 2 5 2 3
*/
void solve()
{
	cin>>n>>k>>T;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(ck(n)==0) 
	{
		cout<<"-1";
		return ;
	}
	
	int l=k,r=n;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;  
	}
	cout<<l<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T1=1;
//	cin>>T;
	while(T1--) solve();
}
