#include <bits/stdc++.h>
using namespace std;
string s;
int n,ans;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(s.size()==5&&s[2]==s[4])
		{
			set<char>st;
			for(int i=0;i<4;i++) st.insert(s[i]);
			if(st.size()==4) ans++;
		}
	}
	cout<<ans<<'\n';
}
