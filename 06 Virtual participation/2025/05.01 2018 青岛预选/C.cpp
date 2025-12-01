#include <bits/stdc++.h>
using namespace std;
#define int long long
string s[10010];
int v[10010];
int k[10010];
int op[10010][256];
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<256;j++) op[i][j]=0;
        cin>>s[i];
        if(s[i][0]=='a') cin>>v[i];
        else cin>>v[i]>>k[i];
    }
    map<int,set<int>>mp;
    int i=1;
    int val=0;
    while(i<=n)
    {
        if(op[i][val]==1)
        {
            cout<<"No\n";
            return ;
        }
        op[i][val]=1;
        if(s[i][0]=='a') 
        {
            val+=v[i];
            val%=256;
            i++;
        }
        else if(s[i][2]=='q')
        {
            if(val==v[i]) 
            {
                i=k[i];
                continue;
            }
            else i++;
        }
        else if(s[i][2]=='e')
        {
            if(val!=v[i]) 
            {
                i=k[i];
                continue;
            }
            else i++;
        }
        else if(s[i][1]=='l')
        {
            if(val<v[i]) 
            {
                i=k[i];
                continue;
            }
            else i++;
        }
        else 
        {
            if(val>v[i]) 
            {
                i=k[i];
                continue;
            }
            else i++;
        }
    }
    cout<<"Yes\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}