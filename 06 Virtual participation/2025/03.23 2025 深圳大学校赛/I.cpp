#include<bits/stdc++.h>

using namespace std;
pair<string,string>p[100010];
int main(){
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].first>>p[i].second;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)cout<<p[i].first<<" "<<p[i].second<<endl;
}