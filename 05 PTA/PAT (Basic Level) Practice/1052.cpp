#include <bits/stdc++.h>
using namespace std;
string ma[20];
string mb[20];
string mc[20];
void solve()
{
    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    int j1=1;
    string p="";
    for(auto i:a)
    {
        if(i=='[') p="";
        else if(i==']') ma[j1++]=p;
        else p+=i;
    }

    int j2=1;
    p="";
    for(auto i:b)
    {
        if(i=='[') p="";
        else if(i==']') mb[j2++]=p;
        else p+=i;
    }

    int j3=1;
    p="";
    for(auto i:c)
    {
        if(i=='[') p="";
        else if(i==']') mc[j3++]=p;
        else p+=i;
    }

    int q,x1,x2,x3,x4,x5;
    cin>>q;
    while(q--)
    {
        cin>>x1>>x2>>x3>>x4>>x5;
        if(x1>=j1||x2>=j2||x3>=j3||x4>=j2||x5>=j1||x1<1||x2<1||x3<1||x4<1||x5<1) 
        {
            cout<<"Are you kidding me? @\\\/@\n";
            continue;
        }
        string ans="";
        ans+=ma[x1];
        ans+='(';
        ans+=mb[x2];
        ans+=mc[x3];
        ans+=mb[x4];
        ans+=')';
        ans+=ma[x5];
        cout<<ans<<"\n";
    }

}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
