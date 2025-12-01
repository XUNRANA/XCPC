#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x,y;
    cin>>x>>y;
    if(x>=y) cout<<"-1 -1\n";
    else cout<<"1 "<<y-x<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

