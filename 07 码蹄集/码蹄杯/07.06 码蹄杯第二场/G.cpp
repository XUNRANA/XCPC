#include <bits/stdc++.h>
using namespace std;
#define int long long
int L[100010];
int R[100010];

void solve()
{
    vector<int>a;
    
    a.push_back(3);
    a.push_back(1);
    a.push_back(3);

     stack<int>st;
    for(int i=0;i<a.size();i++)
    {
        if(st.empty()) 
        {
            st.push(i);
            L[i]=-1;
        }
        else 
        {
            while(!st.empty()&&a[i]>a[st.top()]) st.pop();

            if(st.empty())
            {
                L[i]=-1;
                st.push(i);
            }
            else
            {
                L[i]=st.top(); 
                st.push(i);
            }
        }
    }
    while(!st.empty()) st.pop();
    
    for(int i=a.size()-1;i>=0;i--)
    {
        if(st.empty()) 
        {
            R[i]=-1;
            st.push(i);
        }
        else 
        {
            while(!st.empty()&&a[i]>a[st.top()]) st.pop();

            if(st.empty())
            {
                R[i]=-1;
                st.push(i);
            }
            else
            {
                R[i]=st.top();
                st.push(i);
            }
        }
    }
    
    for(auto i:a) cout<<i<<" ";
    cout<<"\n";
    for(int i=0;i<a.size();i++) cout<<L[i]<<" ";
    cout<<"\n";
    
    for(int i=0;i<a.size();i++) cout<<R[i]<<" ";
    cout<<"\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}