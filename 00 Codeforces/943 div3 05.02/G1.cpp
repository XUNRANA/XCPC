#include <bits/stdc++.h>
using namespace std;
#define N 200010
string s;
int n,l,r;
vector<int>z;
bool ck(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++) if(z[i]>=x) i+=x-1,cnt++;
	return cnt>=l;
}
vector<int> zfun(string s)//z算法，z[i]表示s[i...n]与s[1..n]的lcp 
{
	vector<int>z(s.size(),0);
	z[1]=n;
	for(int i=2,l=1,r=1;i<=n;i++)
	{
		z[i]=i<=r? min(z[i-l+1],r-i+1):0;
		while(i+z[i]<=n&&s[i+z[i]]==s[1+z[i]]) z[i]++;
		if(i+z[i]-1>r) r=i+z[i]-1,l=i;
	}
	return z;
}
void solve()
{
	cin>>n>>l>>r>>s;
	s="$"+s;
	z=zfun(s);
	int l1=1,r1=n/l;
	while(l1<=r1)
	{
		int m=l1+r1>>1;
		if(ck(m)) l1=m+1;
		else r1=m-1;
	}
	cout<<l1-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
