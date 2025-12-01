#include <bits/stdc++.h>
using namespace std;

int px[50010];
int py[50010];
int a[80010];
int idx[100000];
int is[100000];
int ans[80010];
int n,m,x;
//1
//77777 88888
//10
//11111 33333 88888 22222 23333 55555 66666 10000 44444 12345
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>px[i]>>py[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		a[i]=x;
		idx[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int i1=idx[px[i]];
		int i2=idx[py[i]];
		if(i1==0||i2==0) continue;
		
		is[px[i]]=1;
		is[py[i]]=1;
		if(i1>i2) swap(i1,i2);
		if(i1+1==i2)
		{
			ans[i1-1]++;
			ans[i1]--;
			ans[i2+1]++;
			ans[i2+2]--;
		}
		else 
		{
			ans[i1+1]++;
			ans[i2]--;
		}
	}
	int mx=0;
	for(int i=1;i<=m;i++) 
	{
		ans[i]+=ans[i-1];
		if(!is[a[i]]) mx=max(mx,ans[i]);
	}
	
	vector<int>res;
	for(int i=1;i<=m;i++) 
	{
		if(!is[a[i]]&&mx==ans[i]) res.push_back(a[i]);
	}
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++)
	{
		if(i) putchar(' ');
		printf("%05d",res[i]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
