#include<bits/stdc++.h>
using namespace std;


void solve()
{
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		if(islower(s[i-1]))
		{
			if(s[i]==toupper(s[i-1])) continue;
			if(s[i]==s[i-1]-1) continue;
			cout<<"N\n";
			return ;
		}
		else
		{
			if(s[i]==tolower(s[i-1])) continue;
			if(s[i]==s[i-1]+1) continue;
			cout<<"N\n";
			return ;
		}
	}
	cout<<"Y\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}


