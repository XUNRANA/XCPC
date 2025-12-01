#include <bits/stdc++.h>
using namespace std;
int n,x,m,s,t,a[1010][1010];
char op;
void solve()
{
	cin>>n>>m>>x;
	s=0;
	for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) a[i][j]=0;
	a[0][x]=1;
	for(int i=1;i<=m;i++)
	{
		cin>>t>>op;
		for(int j=1;j<=n;j++)
		{
			if(a[i-1][j])
			{
				if(op=='?') 
				{
					if(j+t>n) a[i][j+t-n]=1;
					else a[i][j+t]=1;

					if(j-t<1) a[i][j-t+n]=1;
					else a[i][j-t]=1;	
				}
				else if(op=='0')
				{
					if(j+t>n) a[i][j+t-n]=1;
					else a[i][j+t]=1;
				}
				else if(op=='1')
				{
					if(j-t<1) a[i][j-t+n]=1;
					else a[i][j-t]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) if(a[m][i]) s++;
	cout<<s<<"\n";
	for(int i=1;i<=n;i++) if(a[m][i]) cout<<i<<" ";
	cout<<"\n";

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
