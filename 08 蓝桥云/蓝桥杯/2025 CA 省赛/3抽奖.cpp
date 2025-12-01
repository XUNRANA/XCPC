#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010];
int b[1010];
int c[1010];
void solve()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]; 
	for(int i=0;i<n;i++) cin>>b[i]; 
	for(int i=0;i<n;i++) cin>>c[i];
	int i=0,j=0,k=0;
	int m;
	cin>>m;
	int ans=0;
	while(m--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		i=(i+x)%n;
		j=(j+y)%n;
		k=(k+z)%n;
		vector<int>v;
		v.push_back(a[i]);
		v.push_back(b[j]);
		v.push_back(c[k]);
		sort(v.begin(),v.end());
		if(v[0]==v[2]) ans+=200;
		else if(a[i]+1==b[j]&&b[j]+1==c[k]) ans+=200;
		else if(v[0]==v[1]||v[1]==v[2]) ans+=100;
		else if(v[0]+1==v[1]&&v[1]+1==v[2]) ans+=100;
	} 
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
