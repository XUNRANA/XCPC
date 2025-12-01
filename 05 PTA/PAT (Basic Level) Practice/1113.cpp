#include <bits/stdc++.h>
using namespace std;


string fx(string a,string b)
{
    string ans="";
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int c=0;
    for(int i=0;i<a.size();i++)
    {
        int sa=0,sb=0;
        if(isdigit(a[i])) sa=a[i]-'0';
        else sa=a[i]-'a'+10;

        if(isdigit(b[i])) sb=b[i]-'0';
        else sb=b[i]-'a'+10;
        
        int n=(sa+sb+c)%30;
        if(n<10) ans=char(n+'0')+ans;
        else ans=char(n-10+'a')+ans;

        c=(sa+sb+c)/30;
    }
    if(c) ans="1"+ans;
    return ans;
}
void solve()
{
    string a,b;
    cin>>a>>b;
    string ans=fx(a,b);
    while(ans.size()>1&&ans[0]=='0')
    {
        ans=ans.substr(1,ans.size()-1);
    }
    cout<<ans<<"\n";
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
