#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1010];
int ans[1010][20][20];
void solve()
{
	int n;
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	int cnt=0,lst=0;
	for(int i=1;i<=mx;i++)
	{
		for(int j=1;j<=10;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i<=a[k])
				{
					if(lst==k) cnt+=2;
					else cnt++;
					lst=k;
					ans[k][i][j]=cnt;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<"#"<<i<<"\n";
		for(int k=1;k<=a[i];k++)
		{
			for(int j=1;j<=10;j++) 
			if(j!=1) cout<<" "<<ans[i][k][j];
			else cout<<ans[i][k][j];
			cout<<"\n";
		}
	}
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

