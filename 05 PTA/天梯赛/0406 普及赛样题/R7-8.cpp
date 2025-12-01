#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x;
    cin>>n;
    multiset<int>st,st1;
    while(n--) 
    {
        cin>>x;
        if(x>=0) st.insert(x);
        else st1.insert(x);
    }
    vector<int>ans;
    while(st.size())
    {
        int x=(*st.rbegin())/5;
        ans.push_back(x);
        st.erase(st.find(x));
        st.erase(st.find(2*x));
        st.erase(st.find(5*x));
    }
    while(st1.size())
    {
        int x=(*st1.begin())/5;
        ans.push_back(x);
        st1.erase(st1.find(x));
        st1.erase(st1.find(2*x));
        st1.erase(st1.find(5*x));
    }
    sort(ans.begin(),ans.end(),greater<int>());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i==ans.size()-1];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
