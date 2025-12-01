#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
  	vector<int>a,b;
  	cin>>n;
  	while(n--)
  	{
    	cin>>t;
    	if(t&1) a.push_back(t);
    	else b.push_back(t);
  	}
  	sort(a.begin(),a.end());
  	sort(b.begin(),b.end());
  	for(auto i:a) cout<<i<<" ";
  	for(auto i:b) cout<<i<<" ";
}
