#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    int n;
    cin>>n>>s;
    if(s=="yourname") s="ouyangxinglong";
    cout<<s<<"\n";
    while(n--)
    {
        for(auto &i:s) 
        if(isupper(i))
        {
            if(i=='Z') i='A';
            else i++;
        }
        else if(islower(i))
        {
            if(i=='a') i='z';
            else i--;
        }   
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size()&&i+2<s.size())
            {
                if(islower(s[i])&&islower(s[i+1])&&islower(s[i+2]))
                {
                    while(i<s.size()&&islower(s[i]))
                    {
                        s[i]=toupper(s[i]);
                        i++;
                    }
                    i--;
                }
                else if(isupper(s[i])&&isupper(s[i+1])&&isupper(s[i+2]))
                {
                    while(i<s.size()&&isupper(s[i]))
                    {
                        s[i]=tolower(s[i]);
                        i++;
                    }
                    i--;
                }
            }
        }
    }
    cout<<s<<"\n";

} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
