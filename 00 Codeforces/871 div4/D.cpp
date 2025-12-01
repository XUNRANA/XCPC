#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
void fx(int x)
{
    mp[x]=1;
    if(x%3) return ;
    fx(x/3);
    fx(x/3*2);
}
void solve()
{
    int a,b;
    cin>>a>>b;
    mp.clear();
    fx(a);
    if(mp.count(b)) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
