#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
	cin>>a>>b;
	if(a>b) cout<<"kou";
	else if(a<b) cout<<"yukari";
	else cout<<"draw";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

