#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,n,m,a[200010],b[200010],x,y,t,ot,ox,sum,res,ans[200010];
void solve()
{
	cin>>n>>m;
	x=y=t=sum=0;
	N=n+m+1;
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<N;i++) cin>>b[i];
	while(x<n&&y<m)
	{
		if(a[t]>b[t]) sum+=a[t],x++;
		else sum+=b[t],y++;
		t++;
	}
	res=sum;
	for(int i=t;i<N;i++) res+= x==n? b[i]:a[i];
	for(int i=t;i<N;i++) ans[i]=res-(x==n? b[i]:a[i]);
	for(int i=0;i<t;i++) if((x==n)==(a[i]<b[i])) ans[i]=res-max(a[i],b[i]);//²»Ó°Ïì 
	ot=t;
	ox=x;
	if(x==n) x--;
	else y--;
	while(x<n&&y<m)
	{
		if(a[t]>b[t]) sum+=a[t],x++;
		else sum+=b[t],y++;
		t++;
	}
	res=sum;
	for(int i=t;i<N;i++) res+= x==n? b[i]:a[i];
	for(int i=0;i<ot;i++) if((ox==n)==(a[i]>b[i])) ans[i]=res-max(a[i],b[i]); 
	for(int i=0;i<N;i++) cout<<ans[i]<<" \n"[i==N-1];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
