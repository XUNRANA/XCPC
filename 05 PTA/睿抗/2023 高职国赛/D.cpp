#include <bits/stdc++.h>
using namespace std;
#define int long long
int mi;
int x;
__int128 fx(string s)
{
    __int128 x=0;
    for(auto i:s) x=x*10+(i-'0');
    return x;
}
string rfx(__int128 x)
{
    string s="";
    while(x)
    {
        s=char(x%10+'0')+s;
        x/=10;
    }
    return s;
}
void dfs(string s,int c)
{
    if(c>mi) return ;
    if(s.size()==1) 
    {
        if(c<mi)
        {
            mi=c;
            x=s[0]-'0';
        }
        else if(c==mi) 
        {
            int x1=s[0]-'0';
            x=min(x,x1);
        }
        return ;
    }
    for(int i=1;i<s.size();i++)
    {
        __int128 x=fx(s.substr(0,i));
        __int128 y=fx(s.substr(i));
        x+=y;
        dfs(rfx(x),c+1);
    } 
}
void solve()
{
    string s;
    cin>>s;
    mi=1e9;
    dfs(s,0);
    cout<<mi<<" "<<x<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
