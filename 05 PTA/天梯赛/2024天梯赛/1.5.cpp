#include <bits/stdc++.h>
using namespace std;
string s[101];
int cnt,n,k;
string p;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    cin>>k;
    getchar();
    getline(cin,p);

	for(int j=1;j<=n;j++)
	{
		for(int i=0;i<p.size();i++)
		{
    		if(p.substr(i,s[j].size())==s[j])
    		{
    			p.erase(i,s[j].size());
    			p.insert(i,"<censored>");
				cnt++;
			}
		}
	}
	if(cnt<k) cout<<p<<"\n";
	else 
	{
		cout<<cnt<<"\n";
		cout<<"He Xie Ni Quan Jia!\n";
	}
}
