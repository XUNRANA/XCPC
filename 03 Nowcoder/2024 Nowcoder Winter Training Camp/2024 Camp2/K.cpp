#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s;
int n,y,num;
void solve()
{
    cin>>n>>s>>y;
    set<int>res;
    for(int a=0;a<10;a++)
    for(int b=0;b<10;b++) if(b!=a)
    for(int c=0;c<10;c++) if(c!=a&&c!=b)
    for(int d=0;d<10;d++) if(d!=a&&d!=b&&d!=c)
    for(int i=0;i<10;i++)
    {
        num=0;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='a') num=num*10+a;
            else if(s[j]=='b') num=num*10+b;
            else if(s[j]=='c') num=num*10+c;
            else if(s[j]=='d') num=num*10+d;
            else if(s[j]=='_') num=num*10+i;
            else num=num*10+s[j]-'0';
            if(num==0&&n>1) 
            {
                num=-1;
                break;
            }
        }
        if(num%8==0&&num<=y) res.insert(num);
    }
    cout<<res.size()<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
    while(T--) solve();
}
