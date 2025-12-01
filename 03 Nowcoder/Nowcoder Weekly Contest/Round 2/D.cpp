#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[100010];
void solve()
{
	int n,h,k;
	cin>>n>>h>>k;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		c[i]=a/4*3;
		if(a%4==2||a%4==1) c[i]++;
		else if(a%4==3) c[i]+=2;
		c[i]=max((c[i]-1)*b,0ll);
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++) c[i]+=c[i-1];
    int q,x;
	cin>>q;
	while(q--)
	{
		cin>>x;
        cout<<lower_bound(c+1,c+1+n,k*x+h)-c-1<<" ";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
