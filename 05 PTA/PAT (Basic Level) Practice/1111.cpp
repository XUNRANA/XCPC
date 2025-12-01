#include <bits/stdc++.h>
using namespace std;
int n;
string m[]={"","Jan","Feb", "Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
void solve()
{
    string a,b,c;
    cin>>a>>b>>c;
    b=b.substr(0,b.size()-1);
    
    while(c.size()<4) c="0"+c;

    if(b.size()==1) b="0"+b;
    for(int i=1;i<=12;i++)
    {
        if(a==m[i])
        {
            if(i<10) c=c+"0"+to_string(i)+b;
            else c=c+to_string(i)+b;
        }
    }
    string c1=c;
    reverse(c1.begin(),c1.end());
    if(c==c1) cout<<"Y ";
    else cout<<"N ";
    cout<<c<<"\n";
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
