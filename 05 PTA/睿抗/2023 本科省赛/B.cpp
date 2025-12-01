#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n,q;
    cin>>n>>q;
    map<string,char>mp;
    while(n--) 
    {
        string s;
        char ch;
        cin>>s>>ch;
        mp[s]=ch;
    }
    while(q--)
    {
        string s;
        cin>>s;
        if(mp.count(s)) cout<<mp[s]<<"\n";
        else 
        {
            int cnt=0;
            string a,b;
            for(int i=1;i<s.size();i++)
            {
                if(mp.count(s.substr(0,i))&&mp.count(s.substr(i)))
                {
                    cnt++;
                    a=mp[s.substr(0,i)];
                    b=mp[s.substr(i)];
                }
            }
            if(cnt==1) cout<<a+b<<"\n";
            else cout<<"D\n";
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
