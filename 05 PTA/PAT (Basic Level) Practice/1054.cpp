#include <bits/stdc++.h>
using namespace std;
bool ck(string s)
{
    if(s[0]=='-') s=s.substr(1);
    int cnt=0;
    for(auto i:s)
    {
        if(!isdigit(i))
        {
            if(i!='.') return 1;
            else cnt++;
        }
    }
    if(cnt>1) return 1;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='.')
        {
            if(!i||(s.size()-i-1)>2) return 1;
        }
    }
    return 0;
}
void solve()
{
    int n;
    cin>>n;
    double ans=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(ck(s)||abs(stod(s))>1000) printf("ERROR: %s is not a legal number\n",s.c_str());
        else ans+=stod(s),cnt++;
    }
    if(cnt==0) printf("The average of 0 numbers is Undefined");
    else if(cnt==1) printf("The average of %d number is %.2f",cnt,ans/cnt);
    else printf("The average of %d numbers is %.2f",cnt,ans/cnt);
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
