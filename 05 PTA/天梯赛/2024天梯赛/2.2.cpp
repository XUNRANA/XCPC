#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
	for(int i=0;i<min(a.size(),b.size());i++)
	{
		if(a[i]<b[i]) return a<b;
		else if(a[i]>b[i]) return b<a;
	}
	
	if(a.size()>b.size()) return a>b;
	else return b>a;
}
int main()
{
	int n,q;
	string s;
	cin>>n;
	getchar();
	map<string,vector<string> >mp;
	while(n--)
	{
		getline(cin,s);
		string ans;
		ans+=s[0];
		for(int i=0;i<s.size();i++) if(s[i]==' '&&s[i+1]!=' ') ans+=s[i+1];
		cout<<ans<<"\n";
		mp[ans].push_back(s);
	}
	for(auto i:mp)
	{
		if(i.second.size()>1)
		{
			sort(i.second.begin(),i.second.end(),cmp);
		}
	}
	cin>>q;
	getchar();
	while(q--)
	{
		getline(cin,s);
		string ans;
		ans+=s[0];
		for(int i=0;i<s.size();i++) if(s[i]==' '&&s[i+1]!=' ') ans+=s[i+1];
		if(mp.count(ans)) 
		{
			if(mp[ans].size()==1) cout<<mp[ans][0]<<"\n";
			else 
			{
				int f=0;
				for(auto j:mp[ans]) 
				{
					if(f==1) cout<<"|";
					cout<<j;
					f=1;
				}
				cout<<"\n";
			}
		}
		else cout<<s<<"\n";
	}
}
