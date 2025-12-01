#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int main()
{
	string s;
	cin>>s;
	int f=0;
	map<int,int>m;
	for(auto i:s)
	{
		for(auto j:m) 
		if(j.first==i-'a') f=1;
		else ans+=j.second;
		m[i-'a']++;
	}
	if(f==1) ans++;
	cout<<ans<<"\n";
}
