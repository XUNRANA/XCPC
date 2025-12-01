#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='6')
		{
			int cnt=0;
			
			for(int j=i;j<s.size();j++)
			if(s[j]=='6') cnt++;
			else break;
			
			if(cnt>9) 
			{
				i+=cnt-1;
				cout<<"27";
				
			}
			else if(cnt>3) 
			{
				i+=cnt-1;
				cout<<"9";
			}
			else 
			{
				while(cnt--) cout<<s[i++];
				i--;
			}
		}
		else cout<<s[i];
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
