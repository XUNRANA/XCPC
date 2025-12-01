#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve()
{
    char ch;
    cin>>ch;
    cin.ignore();
    string s;
    getline(cin,s);

    if(ch=='C')
    {
        vector<char>a;
        vector<int>b;
        for(auto i:s)
        {
            if(!a.size())
            {
                a.push_back(i);
                b.push_back(1);
            }
            else
            {
                if(a.back()==i) b.back()++;
                else
                {
                    a.push_back(i);
                    b.push_back(1);
                }
            }
        }
        for(int i=0;i<a.size();i++)
        {
            if(b[i]!=1) cout<<b[i];
            cout<<char(a[i]);
        }
        cout<<"\n";
    }
    else
    {
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                c=c*10+s[i]-'0';
            }
            else
            {
                if(c)
                {
                    while(c--) cout<<s[i];
                    c=0;
                }
                else cout<<s[i]; 
            }
        }
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
