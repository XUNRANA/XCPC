#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m0=0,m1=0,m00,m11;
	cin>>n;
	vector<pair<int,int>>v(n);
	for(int i=0;i<n;i++) 
	{
		cin>>v[i].first>>v[i].second;
		m0=max(m0,v[i].first-v[i].second);
		m1=max(m1,v[i].second);
	}
	m00=m0;
	m11=m1;
	cout<<m0+m1<<"\n";
	while(m11--) cout<<"1";
	while(m00--) cout<<"0";
	cout<<"\n";
	for(int i=0;i<n;i++) cout<<m1-v[i].second<<"\n";
}
