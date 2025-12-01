#include <bits/stdc++.h>
using namespace std;
void solve()
{
	map<string,int>mp;
    string s;
    while(1)
    {
        cin>>s;

        int f=0;
        for(auto i:s) 
        if(isdigit(i)) 
        {
            f=1;
            break;
        }
        if(f) break;
        
        
        string t;
        for(auto i:s) 
        if(isupper(i)) t+=tolower(i);
        else if(islower(i)) t+=i; 
        
		mp[t]++;
    }

    int t=0;
    for(auto i:s) t=t*10+(i-'0');
    while(t--)
    {
        string s;
        cin>>s;
        if(mp.count(s)) mp.erase(s);
    }
    cout<<mp.size()<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
