#include <bits/stdc++.h>
using namespace std;
string fx(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string res;
    int carry=0;
    for(int i=0;i<max(a.size(),b.size());i++)
    {
        int x=carry;
        if(i<a.size()) x+=a[i]-'0';
        if(i<b.size()) x+=b[i]-'0';
        res+=to_string(x%2);
        carry=x/2;
    }
    if(carry) res+='1';
    reverse(res.begin(),res.end());
    return res;
}
void solve()
{
    string s;
    cin>>s;
    string ans1=s+"0000";//16
    string ans2=s+"00";//4
    string ans3=s;//1
    cout<<fx(fx(ans1,ans2),ans3)<<"\n";
} 

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

