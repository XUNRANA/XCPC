#include  <bits/stdc++.h>
using namespace std;
#define N 5010
int n,m,ans,s[N][N];
char a[N][N];
int get(int x,int y,int nx,int ny)
{
    return s[nx][ny]-s[x-1][ny]-s[nx][y-1]+s[x-1][y-1];
}
void solve()
{
	cin>>n>>m;
	for(int i=n;i>=1;i--) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) s[i][j]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=='1');
    ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
            if(a[i][j]=='1')
            {
                ans=max(ans,1);
                for(int k=1;k<=min(n,m);k++)
                {
                    if(i+k>n||j+k>m) break;
                    if(a[i+k][j+k]=='1'&&a[i][j+k]=='1'&&a[i+k][j]=='1'&&get(i,j,i+k,j+k)==3*k+1)
                    {
                        ans=max(ans,k+1);
                    }
                    else break;
                }
            }
		}
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

