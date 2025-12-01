#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int x;
	cin>>x;
	if((x&(x+1))==0||(x&(x-1))==0) cout<<"-1\n";
	else cout<<(1<<(int)log2(x))-1<<"\n"; 
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

