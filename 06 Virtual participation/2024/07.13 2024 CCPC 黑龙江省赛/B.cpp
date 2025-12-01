#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	vector<char>vt;
	for(auto i:s)
	{
		if(vt.size()>=2)
		{
			if(vt[vt.size()-1]==vt[vt.size()-2]&&vt[vt.size()-1]==i)
			{
				vt.pop_back();
				vt.pop_back();
				continue;
			}
		}
		
		vt.push_back(i);
	}
	if(vt.size()==0) cout<<"NAN\n";
	else for(auto i:vt) cout<<i;
} 
