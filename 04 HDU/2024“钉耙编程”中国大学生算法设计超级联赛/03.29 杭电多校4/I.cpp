#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000010
int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int nxt[N][26];
int vt[26];
int ans[N];
int p[4];
int n,m;
int fx(int p[])
{
    int x=m+1;
    for(int i=3;i>=0;i--)
    {
        x--;
        if(x<1) return 0;
        x=nxt[x][p[i]];
    }
    return x;
}
void solve()
{
    string s,t;
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<10;i++) vt[i]=0;
    for(int i=1;i<=m;i++)
    {
        char ch=s[i-1];
        if(isdigit(ch)) vt[ch-'0']=i;
        for(int j=0;j<10;j++) nxt[i][j]=vt[j];
    }
    for(int i=0;i<=m+1;i++) ans[i]=0;
    for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=month[i];j++)
        {
            p[0]=i/10;
            p[1]=i%10;
            p[2]=j/10;
            p[3]=j%10;
            int x=fx(p);
            if(x) ans[x]++;
        }
    }
    for(int i=m-1;i>=1;i--) ans[i]+=ans[i+1];
    for(int i=0;i<26;i++) vt[i]=m+1;
    for(int i=m;i>=1;i--)
    {
        char ch=s[i-1];
        if(islower(ch)) vt[ch-'a']=i;
        for(int j=0;j<26;j++) nxt[i][j]=vt[j];
    }
    int sum=0;
    while(n--)
    {
        cin>>t;
        int x=0;
        for(auto i:t)
        {
            x++;
            if(x>m) break;
            x=nxt[x][i-'a'];
        }
        if(x<m) sum+=ans[x+1];
    }
    cout<<sum<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}