#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define p1 1331
int n,l,r,p[200010],hs[200010];
string s;
bool ck(int x,int k)
{
	//1......x
	int pp=(hs[x]-hs[0]*p[x]%P+P)%P;
	int cnt=1;
	
	for(int i=x+1;i+x-1<=n;i++)
	{
		//1 2 3 4
		// i....i+x-1
		if((hs[i+x-1]-hs[i-1]*p[x]%P+P)%P==pp) 
		{
			cnt++;
			i+=x-1;
		}
	}
	
//	cout<<x<<" "<<cnt<<" "<<l<<"\n";
	return cnt>=k;
}

void solve()
{
	cin>>n>>l>>r>>s;
	s=" "+s;
	p[0]=hs[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*p1%P;
		hs[i]=(hs[i-1]*p1+s[i]-'a')%P;
	}
	for(int k=l;k<=r;k++)
	{
		
		int l1=1,r1=n/k;
		while(l1<=r1)
		{
			int m1=l1+r1>>1;
			if(ck(m1,k)) l1=m1+1;
			else r1=m1-1;
		}
		cout<<l1-1<<" ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
