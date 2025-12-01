#include <bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1'&&i+1<s.size()&&s[i+1]=='0') ans++;
	}
	cout<<ans<<"\n";
}
