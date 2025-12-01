#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
	cin>>s;
	int res=0,mx=0,c1=0;
	for(auto i:s)
	{
		if(i=='1') res++;
		else res--;
	}
	mx=max(mx,res);
	for(auto i:s)
	{
		if(i=='1') c1++,res--;
		else res++;
        mx=max(mx,min(c1,1)+res);
	}
	cout<<mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

