#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	getline(cin,s);
	string t,t1="";
	getline(cin,t);
	vector<string>v;
	for(int i=0;i<t.size();i++)
	{
		if(t[i]!=' ') t1+=t[i];
		else
		{
			v.push_back(t1);
			t1="";
		}
	}
	v.push_back(t1);
	
	int n=s.size();
	int l=n;
	for(int i=0;i<v.size();i++)
	{
		if(v[i][0]=='L') n=max(n-1,0);
		else if(v[i][0]=='R') n=min(n+1,l);
		else if(v[i][0]=='C')
		{
			if(v[i+1][0]=='S') cout<<s<<"\n";
			else
			{
				int cnt=stoi(v[i+1].substr(1));
				int cntt=cnt;
				string ns="";
				for(int j=0;j<l;j++)
				{
					ns+=s[j];
					if(j==n-1) while(cnt--) ns+=s[j];
				}
				n+=cntt;
				l+=cntt;
				s=ns;
			}
			i++;
		}
	}
	cout<<s<<"\n";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

