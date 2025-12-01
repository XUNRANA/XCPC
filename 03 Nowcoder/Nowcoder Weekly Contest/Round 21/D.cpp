#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	stack<int>st;
	long long a,ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(') st.push(i);
		else 
		{
			if(st.size()!=0)
			{
				a=st.top();
				st.pop();
				ans+=(s.size()-i)*(a+1);
			}
		}
	}
	cout<<2*ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
