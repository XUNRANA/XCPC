#include <bits/stdc++.h>
using namespace std;

int n,cnt;
char a[3][200010];
void solve()
{
	cnt=0;
	cin>>n;
	for(int i=1;i<=2;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int j=2;j<=n-1;j++) 
	{
		if(a[1][j]=='.'&&a[1][j-1]=='x'&&a[1][j+1]=='x'&&a[2][j]=='.'&&a[2][j-1]=='.'&&a[2][j+1]=='.') cnt++;
		else if(a[2][j]=='.'&&a[2][j-1]=='x'&&a[2][j+1]=='x'&&a[1][j]=='.'&&a[1][j-1]=='.'&&a[1][j+1]=='.') cnt++;
	}
	cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
