#include <bits/stdc++.h>
using namespace std;
char w;
int n,cnt,c;
string s;
void solve()
{
	cnt=c=0;
	map<char,vector<string>>m;
	cin>>n>>w;
	for(int i=1;i<=2*n;i++)
	{
		cin>>s;
		if(s[1]==w) cnt++;
		m[s[1]].push_back(s);
	}
	sort(m[w].begin(),m[w].end());
	string p="CDHS";
	for(int i=0;i<4;i++)
	{
		if(p[i]==w) continue;
		if(m[p[i]].size()%2==1) c++;
	}


	if(c<=cnt) 
	{
		int k=0;
		for(int i=0;i<4;i++)
		{
			int j;
			if(p[i]==w) continue;
			sort(m[p[i]].begin(),m[p[i]].end());
			for(j=0;j<m[p[i]].size();j+=2)
			{
				if(j+1<m[p[i]].size()) cout<<m[p[i]][j]<<" "<<m[p[i]][j+1]<<"\n";
				else break;
			}
			
			if(j==m[p[i]].size()-1) cout<<m[p[i]][j]<<" "<<m[w][k++]<<"\n";
		}
		
		while(k<m[w].size())
		{
			if(k+1<m[w].size()) cout<<m[w][k]<<" "<<m[w][k+1]<<"\n";
			k+=2;
		}
	}
	else cout<<"IMPOSSIBLE\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
