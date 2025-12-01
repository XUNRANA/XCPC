#include <bits/stdc++.h>
using namespace std;
#define int long long
string s[110];
void solve() 
{
    int n;
    cin>>n;
    vector<string>vt;
    while(n--)
    {
    	string s;
    	cin>>s;
    	vt.push_back(s);
	}
	int k;
    cin>>k;
    string p;
    cin.ignore();
    getline(cin,p);
    int cnt=0;
    for(auto i:vt)
    {
    	string np;
    	for(int j=0;j<p.size();j++)
    	{
    		if(j+i.size()-1<p.size()&&p.substr(j,i.size())==i)
    		{
    			cnt++;
    			np+="-_-";
    			j+=i.size()-1;
			}
			else np+=p[j];
		}
		p=np;
	}
	if(cnt<k)
	{
		for(int j=0;j<p.size();j++)
		{
			if(j+2<p.size()&&p.substr(j,3)=="-_-")
			{
				cout<<"<censored>";
				j+=2;
			}
			else cout<<p[j];
		}
	}
	else
	{
		cout<<cnt<<"\n";
		cout<<"He Xie Ni Quan Jia!\n";
	}
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
