#include <bits/stdc++.h>
using namespace std;

struct node
{
	int l,r,len;
}a[100010];

bool cmp(node a1,node a2)
{
	return a1.len>a2.len;
}

int n,k;
int ans[100010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++) 
	{
		cin>>a[i].l>>a[i].r;
		a[i].len=a[i].r-a[i].l+1;
	} 
	
	sort(a+1,a+1+k,cmp);
	
	if(k==1)
	{
		for(int i=1;i<=n;i++) cout<<i-1<<" ";
		cout<<"\n";
	}
	else if(k==2)
	{
		if(a[1].len==a[2].len) cout<<"IMPOSSIBLE\n";
		else 
		{
			ans[a[1].l]=0;
			for(int i=1;i<=k;i++)
			{
				if(i!=1) ans[a[i].l]=a[1].l;
				for(int j=a[i].l+1;j<=a[i].r;j++)
				{
					ans[j]=j-1;
				} 
			}
			
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			cout<<"\n";
		}
	}
	else 
	{
		if(a[1].len==a[2].len&&a[k].len>a[1].len-2) cout<<"IMPOSSIBLE\n";
		else
		{
			ans[a[1].l]=0;
			for(int i=1;i<=k;i++)
			{
				if(i!=1) ans[a[i].l]=a[1].l;
				for(int j=a[i].l+1;j<=a[i].r;j++)
				{
					ans[j]=j-1;
				} 
			}
			
			if(a[1].len==a[2].len) ans[a[k].l]=a[1].l+1;
	
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			cout<<"\n";
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
