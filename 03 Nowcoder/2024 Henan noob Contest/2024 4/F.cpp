#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int x=0;
	vector<int>v;
	for(auto i:s)
	if(isdigit(i)) x=x*10+i-'0';
	else
	{
		v.push_back(x);
		x=0;
	}
	if(x) v.push_back(x);
	
	sort(v.begin(),v.end(),greater<int>());
	cout<<v[0];
	int sum=v[0];
	for(int i=1;i<v.size();i++) cout<<"+"<<v[i],sum+=v[i];
	cout<<"\n";
	cout<<sum<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
