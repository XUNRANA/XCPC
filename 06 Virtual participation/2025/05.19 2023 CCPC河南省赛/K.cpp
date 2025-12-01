#include <bits/stdc++.h>
using namespace std;

bool is(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
bool ck(vector<int>a)
{
    int f=a[0];
    int l=a.back();
    if(!is(abs(f-l))) return 0;
    for(int i=1;i<a.size();i++)
    {
        if(!is(abs(a[i]-a[i-1]))) return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin>>n;
    if(n<5) cout<<"-1\n";
    else
    {
        if(n<=11)
        {
            vector<int>a;
            for(int i=1;i<=n;i++) a.push_back(i);
            do
            {
                if(ck(a))
                {
                    for(auto i:a) cout<<i<<" ";
                    cout<<"\n";
                    break;
                }
            } while (next_permutation(a.begin(),a.end()));
        }
        else
        {
            if(n&1)
            {
                for(int i=1;i<=n;i+=2)
                {
                    cout<<i<<" ";
                    if(i==5) cout<<"2 ";
                    if(i==n-6) cout<<n-1<<" ";
                }
                for(int i=n-3;i>=4;i-=2) cout<<i<<" ";
                cout<<"\n";
                return ;
            }
            else
            {
                for(int i=1;i<=n-3;i+=2)
                {
                    cout<<i<<" ";
                    if(i==5) cout<<"2 ";
                }
                cout<<n<<" "<<n-2<<" "<<n-4<<" "<<n-1<<" ";
                for(int i=n-6;i>=4;i-=2) cout<<i<<" ";
                cout<<"\n";
                return ;
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}