#include <bits/stdc++.h>
using namespace std;
int n,d,k,l,r;
int L[100010],R[100010],res[100010];
void solve()
{
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++) L[i]=R[i]=0;
	for(int i=1;i<=k;i++)
	{
		cin>>l>>r;
		L[l]++;
		R[r]++;
	}
	int ans=0;
	for(int i=1,j=1;j<=n;j++)
	{
		ans+=L[j];
		if(j-i+1==d)
		{
			res[i]=ans;
			ans-=R[i];
			i++;
		}
	}
	int ans1=0,res1=0;
	int ans2=1e9,res2=0;
	for(int i=1;i+d-1<=n;i++) 
	{
		if(res[i]>ans1)
		{
			ans1=res[i];
			res1=i;
		}
		
		if(res[i]<ans2)
		{
			ans2=res[i];
			res2=i;
		}
	}
	cout<<res1<<" "<<res2<<"\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
