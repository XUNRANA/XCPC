#include <bits/stdc++.h>
using namespace std;
int n,t;
set<int>s;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>t;
		s.insert(t);
	}
	cout<<s.size()<<"\n";
	for(auto i:s) cout<<i<<" ";
}
