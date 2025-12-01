#include <bits/stdc++.h>
using namespace std;
int n,k,res1,res2;
string s;
int f(int c0,int c1,int k)
{
	if(k<=c1) return c0+k;
	else 
	{
		int t=k-c1;
		if(t%2==0) return n;
		else 
		{
			if((n+1)%2==1&&t>=(n+1)) return n;
			return n-1;
		}
	}
}
void solve()
{
	cin>>n>>k>>s;
	
	int c0=count(s.begin(),s.end(),'0');
	
	int c1=n-c0;
	
	res1=f(c0,c1,k);
	
	if(k) res2=f(c1,c0,k-1);
	cout<<max(res1,res2)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
