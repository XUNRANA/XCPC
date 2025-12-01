#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int p[2010][2010];
void solve() 
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<=2*n+1;i++) for(int j=0;j<=2*m+1;j++) p[i][j]=0;
    string s;
    cin>>s;
    int x=0,y=0;
    set<pair<int,int>>st;
    st.insert({0,0});
    int U=0,D=0,L=0,R=0;
    for(auto i:s)
    {
        if(i=='U') y++;
        else if(i=='D') y--;
        else if(i=='L') x--;
        else x++; 
        U=max(U,y);
        D=min(D,y);
        R=max(R,x);
        L=min(L,x);
        st.insert({x,y});
    }
    int x1=1+U;
    int x2=n+D;
    int y1=1-L;
    int y2=m-R;
    // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
    if(x1>x2||y1>y2)
    {
        if(k==0) cout<<n*m<<"\n";
        else cout<<"0\n";
    }
    else
    {
        //进洞的袋鼠数量
        int s=(x2-x1+1)*(y2-y1+1)-k;
        for(auto i:st)
        {
            int nx1=x1-i.second;
            int ny1=y1+i.first;

            int nx2=x2-i.second;
            int ny2=y2+i.first;
            // cout<<nx1<<" "<<ny1<<" "<<nx2<<" "<<ny2<<"\n";
            p[nx1][ny1]++;
            p[nx1][ny2+1]--;
            p[nx2+1][ny1]--;
            p[nx2+1][ny2+1]++;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];

        int ans=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans+=(p[i][j]==s);
        cout<<ans<<"\n";
    }
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}