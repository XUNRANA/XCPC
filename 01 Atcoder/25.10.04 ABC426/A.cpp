#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a,b;
    cin>>a>>b;
    if(a[0]=='S'&&b[0]=='L') cout<<"No\n";
    else if(a[0]=='O'&&b[0]=='S') cout<<"No\n";
    else if(a[0]=='O'&&b[0]=='L') cout<<"No\n";
    else cout<<"Yes\n";
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
