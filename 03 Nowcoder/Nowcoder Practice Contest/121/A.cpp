#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    string s;
    cin>>n>>s;
    map<int,int>m;
    for(int i=0;i<s.size();i++) m[s[i]-'A']++;
    for(auto i:m) sum+=i.second+1;
    cout<<sum;
}s