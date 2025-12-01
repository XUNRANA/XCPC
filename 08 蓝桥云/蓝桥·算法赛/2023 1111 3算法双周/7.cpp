#include <bits/stdc++.h>
using namespace std;
int n,a[100010],s[100010][30];
int f[30];
void init()
{
	f[0]=f[1]=1;
	for(int i=2;i<30;i++) f[i]=f[i-1]+f[i-2];
}
int sg(int x,int l)
{
	if(s[x][l]!=-1) return s[x][l];
	vector<int>vis(2,0);
	for(int i=l+1;i<30;i++)
	{
		if(x+f[i]<=n&&a[x+f[i]]>a[x]) vis[sg(x+f[i],i)]=1; 
		if(x-f[i]>=1&&a[x-f[i]]>a[x]) vis[sg(x-f[i],i)]=1;  
	}
	if(vis[0]) return s[x][l]=1;
	else return s[x][l]=0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(s,-1,sizeof(s));
	for(int i=1;i<=n;i++) 
	if(sg(i,0)) cout<<"Little Lan\n";
	else cout<<"Little Qiao\n";
}
int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
