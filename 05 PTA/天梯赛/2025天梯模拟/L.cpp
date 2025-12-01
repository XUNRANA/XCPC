#include <bits/stdc++.h>
using namespace std;
#define int long long
int fx(int x)
{
	int c=0;
	for(int i=23;i>=0;i--) if(x>>i&1) c++;
	return c;
}
void solve()
{
	int n;
	cin>>n;
	vector<int>a;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	vector<int>b;
	int sum=0;
	do
	{
		int s=0;
		for(auto i:a) s=s*10+i;
		b.push_back(s);
		sum+=s*s;
//		cout<<s<<"\n";
	}while(next_permutation(a.begin(),a.end()));
	
	for(int i=0;i<(1<<b.size());i++)
	{
		if(fx(i)!=b.size()/2) continue;
		int s1=0;
		for(int j=0;j<b.size();j++) if(i>>j&1) s1+=b[j]*b[j];
		if(2*s1==sum)
		{
			for(int j=0;j<b.size();j++) if(i>>j&1) cout<<b[j]<<"\n";
			return ;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
