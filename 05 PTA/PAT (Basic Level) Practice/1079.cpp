#include <bits/stdc++.h>
using namespace std;
#define int long long



string fx(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size()<b.size()) a+='0';
    while(b.size()<a.size()) b+='0';
    int c=0;
    string ans="";
    for(int i=0;i<a.size();i++)
    {
        int x=a[i]-'0'+b[i]-'0'+c;
        c=x/10;
        ans+=x%10+'0';
    }
    if(c) ans+='1';
    reverse(ans.begin(),ans.end());
    return ans;
}
bool ck(string a)
{
    string b=a;
    reverse(b.begin(),b.end());
    return b==a;
}
void solve()
{
    string s;
    cin>>s;
    int t=10;
    int f=0;
    if(ck(s)) 
    {
        cout<<s<<" is a palindromic number.\n";
        return ;
    }
    while(t--)
    {
        string t=s;
        reverse(t.begin(),t.end());
        string a=fx(t,s);
        cout<<s<<" + "<<t<<" = "<<a<<"\n";
        if(ck(a)) 
        {
            f=1;
            cout<<a<<" is a palindromic number.\n";
            break;
        }
        s=a;
    }
    if(!f) cout<<"Not found in 10 iterations.\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
