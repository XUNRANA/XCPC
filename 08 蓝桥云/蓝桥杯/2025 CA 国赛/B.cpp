#include <bits/stdc++.h>
using namespace std;

int a[]={0,0,2,2,5,5,1,6};
set<int> fx(int x)
{
    vector<int>c;
    set<int>res;
    for(int j=0;j<8;j++)
    if(x>>j&1) c.push_back(j);
    
    do
    {
        int num=0;
        if(a[c[0]])
        {
            for(auto i:c) num=num*10+a[i];
            if(num) res.insert(num);
        }
        /* code */
    }while(next_permutation(c.begin(),c.end()));

    return res;
}
void solve()
{
    int n=8;
    int ans=0;
    set<array<int,3>>st;
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=1;j<(1<<n);j++)
        {
            if(i&j) continue;
            for(int k=1;k<(1<<n);k++)
            {
                if((i&k)||(j&k)) continue;
                set<int>a,b,c;
                // cout<<i<<"\n";
                // cout<<j<<"\n";
                // cout<<k<<"\n";
                a=fx(i);
                b=fx(j);
                c=fx(k);

                // cout<<i<<"?\n";
                // for(auto i1:a) cout<<i1<<" ";
                // cout<<"\n";

                // cout<<j<<"?\n";
                // for(auto i1:b) cout<<i1<<" ";
                // cout<<"\n";

                // cout<<k<<"?\n";
                // for(auto i1:c) cout<<i1<<" ";
                // cout<<"\n";
                if(a.size()&&b.size()&&c.size())
                for(auto i1:a)
                {
                    for(auto j1:b)
                    {
                        for(auto k1:c)
                        {
                            if(i1+j1>k1&&j1+k1>i1&&i1+k1>j1)
                            {
                                if(i1>j1) swap(i1,j1);
                                if(j1>k1) swap(j1,k1);
                                if(i1>j1) swap(i1,j1);
                                // cout<<i1<<" "<<j1<<" "<<k1<<"\n";
                                st.insert({i1,j1,k1});
                                // ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    // for(auto i:st) cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
    cout<<st.size()<<"\n";
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
