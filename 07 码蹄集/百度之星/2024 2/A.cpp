#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	string s,ans="";
	//cin>>n;
	
	for(int i=0;i<8;i++)
	{
		s=st[i];
		ans="";
		char p='1';
		for(auto i:s)
		{
			if(i=='0') ans='A'+ans;
			else if(i=='1')
			{
				if(p=='1') ans='C'+ans;
				else ans='B'+ans;
			}
			p=i;
		}
		cout<<s<<" "<<ans<<"\n";
	}
	
}
