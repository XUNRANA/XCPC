#include <bits/stdc++.h>
using namespace std;

int is(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	int n,ans;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<v.size();i++) v[i]=i+1;
	do
	{
		int f=0;
		for(int i=1;i<v.size();i++) 
		if(is(v[i]+v[i-1])) 
		{
			f=1;
			break;
		}
		if(f==0) ans++;
	}while(next_permutation(v.begin(),v.end()));
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

