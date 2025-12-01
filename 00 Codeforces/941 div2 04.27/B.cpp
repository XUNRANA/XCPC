#include <bits/stdc++.h>
using namespace std;
int n,m,a[510][510];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++)
	{
		char ch;
		cin>>ch;
		if(ch=='B') a[i][j]=1;
		else a[i][j]=0;
	}
	int s1=0,sn=0,s11=0,smm=0;
	for(int i=1;i<=m;i++) s1+=a[1][i];
	for(int i=1;i<=m;i++) sn+=a[n][i];
	
	for(int i=1;i<=n;i++) s11+=a[i][1];
	for(int i=1;i<=n;i++) smm+=a[i][m];
	if((s1==m&&sn==0)||(s1==0&&sn==m)||(s11==n&&smm==0)||(s11==0&&smm==n)) cout<<"NO\n";
	else cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
