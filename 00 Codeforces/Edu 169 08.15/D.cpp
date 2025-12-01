#include <bits/stdc++.h>
using namespace std;
#define N 200010
int a[N],L[16][N],R[16][N],lst[16];
void solve()
{
	int n,q,l,r;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{// B G R Y 
	 //	1 1 1 1 
		string s;
		cin>>s;
		a[i]=0;
		for(auto j:s)
		{
			if(j=='B') a[i]|=1;
			else if(j=='G') a[i]|=2;
			else if(j=='R') a[i]|=4;
			else if(j=='Y') a[i]|=8;
		} 
	}
	for(int i=1;i<=15;i++) lst[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=15;j++) L[j][i]=lst[j];
		lst[a[i]]=i;
	}
	
	for(int i=1;i<=15;i++) lst[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=15;j++) R[j][i]=lst[j];
		lst[a[i]]=i;
	}
	
	
	while(q--)
	{
		cin>>l>>r;
		if(l>r) swap(l,r);
		if(l==r) cout<<"0\n";
		else
		{
			int ans=1e9;
			for(int i=1;i<=15;i++)
			{
				if((i&a[l])&&(i&a[r]))
				{
					if(L[i][l]) ans=min(ans,l+r-2*L[i][l]);
					if(R[i][l]<=r||L[i][r]>=l) ans=min(ans,r-l);
					if(R[i][r]<=n) ans=min(ans,2*R[i][r]-l-r);
				}
			}
			if(ans==1e9) ans=-1;
			cout<<ans<<"\n";
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
