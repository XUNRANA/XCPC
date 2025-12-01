#include <bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	int z=0,f=0;
	int ra=0,rb=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&b[i]==0) continue;
		
		if(a[i]==1&&b[i]==1)
		{
			z++;
			continue;
		}
		
		if(a[i]==-1&&b[i]==-1)
		{
			f++;
			continue;
		}
		
		if(a[i]>b[i]) ra+=a[i];
		else rb+=b[i];
	}
	int t=abs(ra-rb);
	if(z+f>=t) 
	{
		if(ra+rb+z-f>0) cout<<(ra+rb+z-f)/2<<"\n";
		else cout<<(ra+rb+z-f-1)/2<<"\n";
	}
	else cout<<min(max(ra,rb)-f,min(ra,rb)+z)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
