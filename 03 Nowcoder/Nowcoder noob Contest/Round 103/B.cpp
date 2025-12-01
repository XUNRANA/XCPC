#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	int f=0;
	string l,d;
	for(auto i:s)
	{
        if(i=='@'&&f==1)
        {
            cout<<"No\n";
            return ;
        }
		if(i=='@') 
		{
			f=1;
			continue;
		}
        
		if(!f) l+=i;
		else d+=i;
	}
	if(l.size()==0||l.size()>64||d.size()==0||d.size()>255)
	{
		cout<<"No\n";
		return ;
	}
	if(l[0]=='.'||l[0]==','||l.back()=='.'||l.back()==',')
	{
		cout<<"No\n";
		return ;
	}
	if(d[0]=='.'||d[0]==','||d.back()=='.'||d.back()==','||d[0]=='-'||d.back()=='-')
	{
		cout<<"No\n";
		return ;
	}
	for(auto i:l)
	{
		if(!islower(i)&&!isupper(i)&&!isdigit(i)&&i!=','&&i!='.')
		{
			cout<<"No\n";
			return ;
		}
	}
	
	for(auto i:d)
	{
		if(!islower(i)&&!isupper(i)&&!isdigit(i)&&i!=','&&i!='.'&&i!='-')
		{
			cout<<"No\n";
			return ;
		}
	}
	cout<<"Yes\n";
//	cout<<l<<" "<<d<<"\n";
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
