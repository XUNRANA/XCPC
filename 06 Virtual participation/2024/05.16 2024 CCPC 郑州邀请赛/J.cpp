#include <bits/stdc++.h>
using namespace std;
string s;
int n,ans;
void solve()
{
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)
	{
		if((s[i]-'0')%2==0)
		{
			swap(s[i],s[s.size()-1]);
			cout<<s<<"\n";
			return ;
		}
	}
	cout<<"13795\n";
}
int main()
{
	int T;
	cin>>T;
	while(T--) solve();
}
