#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> fx(string s)
{
    int a=0;//y的数量
    int b=0;//ye的数量
    int c=0;//n的数量
    int c1=0,c2=0;
    for(auto i:s)
    {
        if(i=='Y') a++;
        else if(i=='E') b+=a;
        else if(i=='S') c1+=b;
        else if(i=='N') c++;
        else if(i=='O') c2+=c;
    }
    return {c1,c2};
}
void solve()
{
    string s;
    cin>>s;
    int c1=fx(s).first;
    int c2=fx(s).second;
    cout<<c1<<" "<<c2<<"\n";
    if(c1>c2)//yes
    {
        for(auto &i:s)
        {
            if(i=='S')
            {
                i='O';
                break;
            }
        }
        int nc1=fx(s).first;
        int nc2=fx(s).second;
        cout<<nc1<<" "<<nc2<<"\n";
        if(nc1<nc2)
        {
            cout<<"O BUDUI BUDUI\n";
        }
        else cout<<"DUI DE\n";
    }
    else if(c1<c2)//no
    {
        for(auto &i:s)
        {
            if(i=='O')
            {
                i='S';
                break;
            }
        }
        int nc1=fx(s).first;
        int nc2=fx(s).second;
        if(nc1>nc2)
        {
            cout<<"O DUI DE\n";
        }
        else cout<<"BUDUI BUDUI\n";
    }
    else cout<<"DUI DUI DUIMA\n";


}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
