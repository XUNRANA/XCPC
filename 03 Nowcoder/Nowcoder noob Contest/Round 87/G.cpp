#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,tot,a[200010],cnt[200010],t[200010];
vector<int>p[200010];
void upd(int i,int x)
{
	while(i<=200000)
	{
		t[i]+=x;
		i+=(i&(-i));
	}
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res+=t[i];
		i-=(i&(-i));
	}
	return res;
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				p[j].push_back(a[i]);
				if(j*j==a[i]) continue;
				p[a[i]/j].push_back(a[i]);
			}
		}
	}
	for(int i=1;i<=n/2;i++)
	{
		tot=0;
		for(int x:p[i]) 
		{
			cnt[i]+=tot-query(x-1);
			upd(x,1);
            tot++;
		}
		for(int x:p[i]) upd(x,-1);
	}
	for(int i=n/2;i>=1;i--) for(int j=i+i;j<=n;j+=i) cnt[i]-=cnt[j];
	cout<<cnt[1];
} 