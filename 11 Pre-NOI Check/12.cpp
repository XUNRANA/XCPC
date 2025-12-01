#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int m,l;
	cin>>m>>l;
	string s;
	map<string,int>mp;
	while(m--)
	{
		string op;
		cin>>op;
		if(op=="Add")
		{
			char c;
			cin>>c;
			s+=c;
			if(s.size()>=l) mp[s.substr(s.size()-l,l)]++;
		}
		else
		{
			if(s.size()>=l)
			{
				mp[s.substr(s.size()-l,l)]--;
				if(mp[s.substr(s.size()-l,l)]==0) mp.erase(s.substr(s.size()-l,l));
			}
			s=s.substr(0,s.size()-1);
		}
		cout<<mp.size()<<"\n";
		
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
