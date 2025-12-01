#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int inv(int x)
{
	return ksm(x,P-2);
}
void solve()
{
	int n,k,p0;
	cin>>n>>k>>p0;
	p0--;
	vector<int>a(k);
	vector<int>ap(k,1);
	for(int i=0;i<k;i++) 
	{
		cin>>a[i];
		a[i]--;
	}
	sort(a.begin(),a.end());
	int res=1;
	int inv2=inv(2);
	while(n>1)
	{
		vector<int>na,nap;
		p0>>=1;
		for(int i=0;i<a.size();i++)
		{
			a[i]>>=1;
			if(a[i]==p0) res=res*((1-ap[i]+P)%P)%P;
			else
			{
				if(i+1<a.size()&&a[i]==(a[i+1]>>1))
				{
					na.push_back(a[i]);
					nap.push_back((ap[i]+ap[i+1])*inv2%P);
					i++;
				}
				else
				{
					na.push_back(a[i]);
					nap.push_back(ap[i]*inv2%P);
				}
			}
		}
		a=na;
		ap=nap;
		n=(n+1)>>1;
	}
	cout<<res<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

