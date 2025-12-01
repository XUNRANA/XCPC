#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110][110];
int b[110][110];
int c[110][110];
void solve()
{
	int r1,c1,r2,c2;
	cin>>r1>>c1;
	for(int i=1;i<=r1;i++) for(int j=1;j<=c1;j++) cin>>a[i][j];
	
	cin>>r2>>c2;
	for(int i=1;i<=r2;i++) for(int j=1;j<=c2;j++) cin>>b[i][j];

	if(c1==r2)
	{
		cout<<r1<<" "<<c2<<"\n";
		for(int i=1;i<=r1;i++)
		{
			for(int j=1;j<=c2;j++)
			{
				for(int k=1;k<=c1;k++)
				{
					c[i][j]+=a[i][k]*b[k][j];
				}
				if(j!=1) cout<<" "<<c[i][j];
				else cout<<c[i][j];
			}
			cout<<"\n";
		}
		
	}
	else cout<<"Error: "<<c1<<" != "<<r2<<"\n";
	
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

