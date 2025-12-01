#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n,a[1000010];
void solve() 
{
    cin>>n;
    int s=1;
    int c=1;
    int t=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        if(x==1)
        {
            s++;
            c++;
        }
        else if(x==-1)
        {
            if(c>1) c--;
            else if(t)
            {
                c++;
                t--;
                s++;
            }
            else
            {
                cout<<"-1\n";
                return ;
            }
        }
        else 
        {
            if(c>1)
            {
                c--;
                t++;
            }
            else 
            {
                c++;
                s++;
            }
        }
    }
    int g=__gcd(s,c);
    s/=g;
    c/=g;
    cout<<s<<" "<<c<<"\n";
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    solve();
    return 0;
}