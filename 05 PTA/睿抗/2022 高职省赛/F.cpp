#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1010
int n,m;
char a[N][N];
int vt[N][N];
bool ck(int i,int j,int l)
{
    if(i+l>n||j+l>m) return 0;
    int ni=i+l;
    int nj=j+l;
    for(int j1=nj;j1>=j;j1--) if(a[ni][j1]!=a[i][j]||vt[ni][j1]) return 0;
    for(int i1=ni;i1>=i;i1--) if(a[i1][nj]!=a[i][j]||vt[i1][nj]) return 0;
    for(int j1=nj;j1>=j;j1--) vt[ni][j1]=1;
    for(int i1=ni;i1>=i;i1--) vt[i1][nj]=1;
    return 1;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    map<char,map<int,int>>mp;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vt[i][j]) continue;
            int l=1;
            while(ck(i,j,l)) l++;
            mp[a[i][j]][l]++;       
        }
    }
    int s=0;
    for(auto i:mp) for(auto j:i.second) s++;
    cout<<s<<"\n";
    for(auto i:mp)
    {
        for(auto j:i.second)
        cout<<"color = "<<i.first<<"; size = "<<j.first<<"; amount = "<<j.second<<"\n";
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
