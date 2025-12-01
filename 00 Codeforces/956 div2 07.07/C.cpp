#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,a[N],b[N],c[N],s,sum,l1[N],l2[N],l3[N];
int f;
void fx(int *l1,int *l2,int *l3,int c1,int c2,int c3)
{
	map<int,pair<int,int>>mp;
	int l=1,r=l1[l];
	mp[c1]={l,r};
	if(r!=-1&&r<n)
	{
		l=r+1;
		r=l2[l];
		if(r!=-1&&r<n)
		{
			mp[c2]={l,r};
			l=r+1;
			r=l3[l];
			if(r!=-1)
			{	
				mp[c3]={l,r};
				for(auto i:mp) cout<<i.second.first<<" "<<i.second.second<<" ";
				cout<<"\n";
				f=1;
			}
		}	
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	s=0;
	for(int i=1;i<=n;i++) s+=a[i];
	s=(s+2)/3;
	
	for(int i=1;i<=n;i++) l1[i]=-1;
	sum=0;
	for(int i=1,j=1;i<=n;i++)
	{
		sum+=a[i];
		while(sum>=s)
		{
			l1[j]=i;
			sum-=a[j++];
		}
	}
	
	for(int i=1;i<=n;i++) l2[i]=-1;
	sum=0;
	for(int i=1,j=1;i<=n;i++)
	{
		sum+=b[i];
		while(sum>=s)
		{
			l2[j]=i;
			sum-=b[j++];
		}
	}
	
	
	for(int i=1;i<=n;i++) l3[i]=-1;
	sum=0;
	for(int i=1,j=1;i<=n;i++)
	{
		sum+=c[i];
		while(sum>=s)
		{
			l3[j]=i;
			sum-=c[j++];
		}
	}
	
	f=0;
	if(!f)  fx(l1,l2,l3,1,2,3);
	if(!f) 	fx(l1,l3,l2,1,3,2);
	if(!f) 	fx(l2,l1,l3,2,1,3);
	if(!f) 	fx(l2,l3,l1,2,3,1);
	if(!f) 	fx(l3,l1,l2,3,1,2);
	if(!f) 	fx(l3,l2,l1,3,2,1);
	if(!f) cout<<"-1\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
