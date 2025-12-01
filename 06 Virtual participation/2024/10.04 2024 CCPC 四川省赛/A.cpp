#include <bits/stdc++.h>
using namespace std;
int n,a[300010];
int b[30][30];
void solve()
{
/*
9
5 9 1 8 2 6 4 7 3
*/
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				b[i][a[j]]=1;
				cout<<i<<" "<<a[j]<<"\n";
			}
		}
	}
	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<b[i][j]<<" "; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
