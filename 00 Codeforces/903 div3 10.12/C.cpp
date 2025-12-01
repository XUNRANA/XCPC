#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,i1,j1; 
char a[1010][1010],mx;
string t1,t2,t3,t4;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=n/2;i++)
	{
		i1=j1=i;
		t1=t2=t3=t4=""; 
		while(j1+1<=n-i+1) t1+=a[i1][j1++];
		while(i1+1<=n-i+1) t2+=a[i1++][j1];
		while(j1-1>=i) t3+=a[i1][j1--];
		while(i1-1>=i) t4+=a[i1--][j1];
		for(int i=0;i<t1.size();i++)
		{
			mx=max({t1[i],t2[i],t3[i],t4[i]});
			ans+=mx-t1[i]+mx-t2[i]+mx-t3[i]+mx-t4[i];
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
