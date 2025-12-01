#include <bits/stdc++.h>
using namespace std;
int ch[]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
void solve()
{
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string c="";
    while(a.size()<b.size()) a+='0';
    while(b.size()<a.size()) b+='0';
    for(int i=0;i<a.size();i++)
    {
        if(i&1) c+=(b[i]-a[i])<0? ch[b[i]-a[i]+10]:ch[b[i]-a[i]];
        else c+=ch[(b[i]-'0'+a[i]-'0')%13]; 
    }
    reverse(c.begin(),c.end());
    cout<<c<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
