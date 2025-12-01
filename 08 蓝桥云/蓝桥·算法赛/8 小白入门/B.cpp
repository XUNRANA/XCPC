#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
	return a+b<b+a;
}
int main()
{
	int n;
	cin>>n;
	string t;
	vector<string>v;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	string ans;
	for(auto i:v) ans+=i;
	cout<<ans;
} 
