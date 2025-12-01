#include <bits/stdc++.h>
using namespace std;
int n,a[15][15],p;
char ch[15][15];
void solve()
{
	p=0;
	cin>>n;
	set<int>s;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) 
	{
		cin>>ch[i][j];
		a[i][j]=ch[i][j]-'0';
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]+=a[i][j-1];
	for(int i=1;i<=n;i++)
	{
		if(a[i][n]) s.insert(a[i][n]);
	}
	
	if(s.size()==1) cout<<"SQUARE\n";
	else cout<<"TRIANGLE\n";
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
