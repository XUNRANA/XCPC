#include <bits/stdc++.h>
using namespace std;
#define N 100010
int t,b[100010],j;
int main()
{
	vector<int>a;
	while(cin>>t) b[++j]=t;
	for(int i=j;i>=1;i--)
	{
		auto it=upper_bound(a.begin(),a.end(),b[i]);//大于等于 
		if(it==a.end()) a.push_back(b[i]);
		else *it=b[i];
	}
	cout<<a.size()<<"\n";
	
	a.clear();
	for(int i=1;i<=j;i++)
	{
		auto it=lower_bound(a.begin(),a.end(),b[i]);//大于 
		if(it==a.end()) a.push_back(b[i]);
		else *it=b[i];
	}
	cout<<a.size()<<"\n";
	
	
}
