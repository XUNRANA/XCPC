#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y,kx,ky;
int a[100010],b[100010];
void solve()
{
	cin>>n;
	m=0;
	for(int i=1;i<=n;i++) cin>>a[i],m=max(m,a[i]);
	for(int i=1;i<=m;i++) b[i]=0;
	for(int i=1;i<=m;i++)
	{
		b[i]+=(a[1]+i-1)/i;
		b[i+1]-=(a[1]+i-1)/i;
	}
	
	for(int i=2;i<=n;i++)
	{
		x=a[i];
		y=a[i-1];
		if(x<=y) continue;
		//cout<<i<<"\n";
		for(int r=x,l;r>=1;r=l-1)
		{
			kx=(x+r-1)/r;//???r??x???  
			ky=(y+r-1)/r;//???r??y??? 
			l=max((x+kx-1)/kx,(y+ky-1)/ky);//?????????????????? 
			b[l]+=kx-ky;
			b[r+1]-=kx-ky;
			//cout<<l<<" "<<r<<" "<<kx<<" "<<ky<<"\n";
		}
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++) b[i]+=b[i-1],cout<<b[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
