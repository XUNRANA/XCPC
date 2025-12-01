#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[1010][4];
int y[1010][4];
void solve()
{
	int n,m;
	cin>>n>>m;
	int a1,a2,b1,b2,b3;
	cin>>a1>>a2>>b1>>b2>>b3;
	while(n--)
	{
		int d,op;
		cin>>d>>op;
		if(op==1)
		{
			x[d][op]+=a1;
			y[d][op]-=b1;
		}
		else if(op==2)
		{
			y[d][op]-=b2;
		}
		else 
		{
			y[d][op]-=b3;
			x[d][op]-=a2;
		}
	}
	while(m--)
	{
		int t,op;
		cin>>t>>op;
		if(op==1) y[t][op]/=2;
		else
		{
			y[t][op]/=2;
		}
	}
	
	int ans1=0,ans2=0;
	for(int i=1;i<=1000;i++) 
	{
		ans1+=x[i][1]+x[i][2]+x[i][3];
		ans2+=y[i][1]+y[i][2]+y[i][3];
	}
//	cout<<(-21)/2<<"\n";
	cout<<ans1<<" "<<ans2<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
