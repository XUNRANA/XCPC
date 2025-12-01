#include <bits/stdc++.h>
using namespace std;
int n,k,h[100010];
bool ck(int x)
{
	int res=1;
	for(int i=2,j=1;i<=n;i++)
	{
		if(h[i]-h[j]>x)
		{
			res++;
			j=i;
		}
	}
	if(res>k) return 0;
	return 1;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>h[i];
	sort(h+1,h+1+n);
	int l=0,r=h[n]-h[0];
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
