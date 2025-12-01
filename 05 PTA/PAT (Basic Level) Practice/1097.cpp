#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110][110];
int n,k,x;
void solve()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    int p=1;
    for(int i=1;i<=n;i+=2)
    {
        for(int j=n;j>p;j--) a[i][j]=a[i][j-p];
        for(int j=p;j>=1;j--) a[i][j]=x;
        p++;
        if(p>k) p-=k;
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        int s=0;
        for(int j=1;j<=n;j++) s+=a[j][i];
        if(f) cout<<" ";
        cout<<s;
        f=1;
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
