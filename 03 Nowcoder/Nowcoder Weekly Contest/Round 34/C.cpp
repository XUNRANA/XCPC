#include <bits/stdc++.h>
using namespace std;


void solve()
{
	string s,t;
	cin>>s;
	vector<string>v[100010];
	for(auto i:s)
	{
        t+=i;
		if((i-'0')%2==0)
        {
			v[t.size()].push_back(t);
			t="";
		}
	}
    for(int i=1;i<=100000;i++)
    {
        sort(v[i].begin(),v[i].end());
        for(auto j:v[i]) cout<<j<<"\n"; 
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

