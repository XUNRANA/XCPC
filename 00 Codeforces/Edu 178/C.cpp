#include <bits/stdc++.h>
using namespace std;
vector<int>a,b;
int n;
bool beat(int x,int y)
{
    if(x==1) return y==n;
    else if(x==n) return y!=1;
    else return x>y;
}
bool ck(int x)
{
    for(auto i:b)
    if(!beat(x,i)) return 0;
    return 1;
}
void solve() 
{
    string s;
    cin>>n>>s;
    a.clear();
    b.clear();
    s=" "+s;
    for(int i=1;i<=n;i++)
    if(s[i]=='A') a.push_back(i);
    else b.push_back(i);


    for(auto i:a)
    if(ck(i))
    {
        cout<<"Alice\n";
        return ;
    }
    cout<<"Bob\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}