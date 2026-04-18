#include <bits/stdc++.h>
using namespace std;
#define int long long
string str[100010];
int vt[100010];
void solve()
{
    string s;
    int a=0;// /*  */
    int b=0;// " "
    while(cin>>s) 
    {
        int c=0;// //
        for(int i=0;i<s.size();i++)
        {
            if(a)
            {
                if(i+1<s.size()&&s.substr(i,2)=="*/")
                {
                    s[i]=s[i+1]='#';
                    i++;
                    a=0;
                }
                else s[i]='#';
            }else if(b) 
            {
                if(s[i]=='"') b=0;
            }
            else 
            {
                if(c) s[i]='#';
                else if(i+1<s.size()&&s.substr(i,2)=="//") 
                {
                    s[i]=s[i+1]='#';
                    c=1;
                    i++;
                }
                else if(i+1<s.size()&&s.substr(i,2)=="/*") 
                {
                    s[i]=s[i+1]='#';
                    a=1;
                    i++;
                }
                else if(s[i]=='"') b=1;
            }
        }
        cout<<s<<"\n";
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