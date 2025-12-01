#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,c1=0,c2=0;
	string s;
	cin>>n>>s;
	for(auto i:s) 
	if(i=='E') c2++;
	else if(i=='W') c2--;
	else if(i=='N') c1++;
	else if(i=='S') c1--;
	
	if(c2%2==0&&c1%2==0)
	{
		if(s.size()==2&&c1==0&&c2==0) cout<<"NO\n";
		else
		{
			string ans="";
			int x=c2/2,y=c1/2;
			if(x==0&&y==0)
			{
				map<char,char>mp;
				mp['S']='N';
				mp['N']='S';
				mp['W']='E';
				mp['E']='W';
				ans+='R';
				int f=0;
				for(int i=1;i<s.size();i++)
				if(mp[s[i]]==s[0]&&f==0) ans+='R',f=1;
				else ans+='H'; 
			}
			else
			{
				int x1=0,y1=0;
				for(auto i:s)
				{
					if(i=='E')
					{
						if(x>0&&x1<x) ans+='R',x1++;
						else ans+='H';
					}
					if(i=='W')
					{
						if(x<0&&x1>x) ans+='R',x1--;
						else ans+='H';
					}
					if(i=='N')
					{
						if(y>0&&y1<y) ans+='R',y1++;
						else ans+='H';
					}
					if(i=='S')
					{
						if(y<0&&y1>y) ans+='R',y1--;
						else ans+='H';
					}
					if(x1==x&&y1==y) break;
				}
				
				while(ans.size()<n) ans+='H';
			}
			cout<<ans<<"\n";
		}
	}
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
