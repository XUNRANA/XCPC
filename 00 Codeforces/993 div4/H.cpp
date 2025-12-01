#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[2010][2010];
int pi[2010][2010];
int pj[2010][2010];
int get(int x1,int y1,int x2,int y2)
{
    return p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1];
}
int geti(int x1,int y1,int x2,int y2)
{
    return pi[x2][y2]-pi[x1-1][y2]-pi[x2][y1-1]+pi[x1-1][y1-1];
}
int getj(int x1,int y1,int x2,int y2)
{
    return pj[x2][y2]-pj[x1-1][y2]-pj[x2][y1-1]+pj[x1-1][y1-1];
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+x;
            pi[i][j]=pi[i-1][j]+pi[i][j-1]-pi[i-1][j-1]+x*i;
            pj[i][j]=pj[i-1][j]+pj[i][j-1]-pj[i-1][j-1]+x*j;
        }
    }
    while(q--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int s=get(x1,y1,x2,y2);
        int si=geti(x1,y1,x2,y2);
        int sj=getj(x1,y1,x2,y2);
        int ans=(-x1*(y2-y1+1)-y1+1)*s+(y2-y1+1)*si+sj;
        cout<<ans<<" ";
    }
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
