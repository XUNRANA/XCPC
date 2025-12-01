#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,ans;
	long long b,d=0;
	cin>>a>>b;
	if(a=="0")
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<a.size();i++)
	{
		ans+=(d*10+a[i]-'0')/b+'0';
		d=(d*10+a[i]-'0')%b;
	}
	int i=0;
	while(ans[i]=='0'&&i<ans.size()) i++;
	while(i<ans.size()) cout<<ans[i++];
}
