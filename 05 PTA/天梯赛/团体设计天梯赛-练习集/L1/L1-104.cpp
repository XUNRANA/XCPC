#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a={0,1,2,3,4,5,6,7,8};
void solve()
{
	map<int,vector<int>>h,l,k;
	for(int i=0;i<9;i++) 
	for(int j=0;j<9;j++) 
	{
		int x;
		cin>>x;
		x--;
		h[i].push_back(x);
		l[j].push_back(x);
		k[i/3*3+j/3].push_back(x);
	}
	
	for(auto &i:h)
	{
		sort(i.second.begin(),i.second.end());
		if(i.second!=a) 
		{
			cout<<"0\n";
			return ;
		}
	}
	
	for(auto &i:l)
	{
		sort(i.second.begin(),i.second.end());
		if(i.second!=a) 
		{
			cout<<"0\n";
			return ;
		}
	}
	
	for(auto &i:k)
	{
		sort(i.second.begin(),i.second.end());
		if(i.second!=a) 
		{
			cout<<"0\n";
			return ;
		}
	}
	
	cout<<"1\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

