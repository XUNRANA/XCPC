#include <bits/stdc++.h>
using namespace std;

struct node
{
	string f,s;
	int g;
}p[100010];
int f[100010];
bool ck(int x,int y)
{
	vector<int>a,b;
	while(f[x]) 
	{
		a.push_back(x);
		x=f[x];
	}
	a.push_back(x);
	
	while(f[y]) 
	{
		b.push_back(y);
		y=f[y];
	}
	b.push_back(y);
	
	for(int i=0;i<min(4,(int)a.size());i++)
	{
		for(int j=0;j<b.size();j++)
		if(b[j]==a[i]) return 1;
	}
	
	for(int j=0;j<min(4,(int)b.size());j++)
	{
		for(int i=0;i<a.size();i++)
		if(b[j]==a[i]) return 1;
	}
	return 0;
}

void solve()
{
	int n;
	cin>>n;
	map<string,int>mp;
	for(int i=1;i<=n;i++)
	{
		string f,s;
		cin>>f>>s;
		mp[f]=i;
		int g;//ÄÐ 
		if((int)s.size()-4>=0&&s.substr(s.size()-4)=="sson")
        {
            g=1;
            s=s.substr(0,s.size()-4);
        }
		else if((int)s.size()-7>=0&&s.substr(s.size()-7)=="sdottir")
		{
			g=0;//Å® 
			s=s.substr(0,s.size()-7);
		}
		else
        {
            if(s.back()=='m') g=1;
            else g=0;
        }
		p[i].f=f;
		p[i].s=s;
		p[i].g=g;
	}
	
	for(int i=1;i<=n;i++)
	if(p[i].g!=2)
	{
		int fid=mp[p[i].s];
		f[i]=fid;
	}
	
	int m;
	cin>>m;
	while(m--)
	{
		string f1,s1,f2,s2;
		cin>>f1>>s1>>f2>>s2;
		if(!mp.count(f1)||!mp.count(f2)) cout<<"NA\n";
		else
		{
			if(p[mp[f1]].g!=p[mp[f2]].g!=0) 
			{
				if(ck(mp[f1],mp[f2])) cout<<"No\n";
				else cout<<"Yes\n";
			}
			else cout<<"Whatever\n";
		}	
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

