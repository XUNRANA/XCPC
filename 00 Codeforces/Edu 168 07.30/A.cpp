#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	if(s.size()==1)
	{
		s+=char((s[0]-'a'+1)%26+'a');
		cout<<s<<"\n";
		return ;
	}
	int n=s.size();
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==s[i-1])
		{
			s=s.substr(0,i)+char((s[i]-'a'+1)%26+'a')+s.substr(i);
			break;
		}
	}
	if(s.size()==n)
	{
		s=char((s[0]-'a'+1)%26+'a')+s;
	}
	cout<<s<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
