#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin>>s;
    int now=0,s1=1,s2=3e5;
    //前s1个数为递增，s1为满足条件的最大值
    //前s2个数不递增，s2为满足条件的最小值
    for(auto i:s)
    {
        if(i=='+') now++;
        else if(i=='-') 
        {
            now--;
            if(s1>now&&now>0) s1=now;
            if(s2>now) s2=3e5;//无穷
        }
        else if(i=='0')
        {
            if(s1>=now) 
            {
                cout<<"NO\n";
                return ;
            }
            s2=min(s2,now);
        }
        else 
        {
            if(s2<=now)
            {
                cout<<"NO\n";
                return ;
            }
            s1=max(s1,now);
        }
    }
    cout<<"YES\n";
    
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
