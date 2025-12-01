#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	if(s.find("55")!=-1||s.find("3333333333")!=-1) 
	{
		cout<<"invild\n";
		return ;
	}
	vector<int>v;
	v.push_back(-1);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='5'||s[i]=='U')
		v.push_back(i);
	}
	v.push_back(s.size());

		
		for(int i=1;i<v.size();i++)
		{
			if(v[i]-v[i-1]-1>=90)
			{
				cout<<"invalid\n";
				return ;
			}
		}
	cout<<"valid\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
