#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2010][2010];
int n;
int b[4000010];
void init()
{
    int cnt=1;
    for(int i=1;i<=2000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==1) a[i][j]=1;
            else a[i][j]=cnt*cnt+a[i-1][j-1]+a[i-1][j]-a[i-2][j-1];
            b[cnt]=a[i][j];
            cnt++;
        }
    }
}
void solve()
{
    cin>>n;
    cout<<b[n]<<"\n";
}
signed main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
