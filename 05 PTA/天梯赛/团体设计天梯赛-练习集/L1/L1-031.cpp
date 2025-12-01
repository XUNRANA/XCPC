#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,h,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h>>w;
		double w1=(h-100)*0.9*2;
		if(abs(w-w1)<w1*0.1) cout<<"You are wan mei!\n";
		else if(w>w1) cout<<"You are tai pang le!\n";
		else cout<<"You are tai shou le!\n";
	} 

} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

