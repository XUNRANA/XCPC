#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        string s,tt;
		cin>>s>>tt;
		map<char,int>ma;
		for(int i=0;i<s.size();i++)
		ma[s[i]]++; 
        map<char,int>mt;
		for(int i=0;i<tt.size();i++)
		mt[tt[i]]++;
        long long ans=ma[tt[0]]/mt[tt[0]];
        for(auto i:mt)
        {
            if(ma[i.first]/i.second<ans) ans=ma[i.first]/i.second;
        }
        cout<<ans<<endl;
	}
}