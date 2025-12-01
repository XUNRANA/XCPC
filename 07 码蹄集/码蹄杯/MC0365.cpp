#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[110][110];
struct matrix
{
    int a[110][110];
    matrix()
    {
        memset(a,0,sizeof(a));
    }
    matrix operator*(const matrix &x)
    {
        matrix ret;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                for(int k=1;k<=m;k++) 
                    ret.a[i][j]=max(ret.a[i][j],a[i][k]+x.a[k][j]);
        return ret;
    }
}s,g,ans,tmp;
matrix pw(matrix x,int k)
{
    matrix tmp=x;//x的k+1次幂
    while(k)
    {
        if(k&1) tmp=tmp*x;
        x=x*x;
        k>>=1;
    }
    return tmp;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>s.a[1][i];

    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            g.a[i][j]=a[i][j]+s.a[1][j];

    ans=s*pw(g,n-2);
    int res=0;

    for(int i=1;i<=m;i++) res=max(res,ans.a[1][i]);
    cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
