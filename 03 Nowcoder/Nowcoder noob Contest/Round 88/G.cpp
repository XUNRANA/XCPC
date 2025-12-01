#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    double x1,x2,y1,y2,a;
    double x0;
    while(t--){
        cin>>x1>>y1>>x2>>y2>>a;
        a = a / 2;
        a = a / 180 * acos(-1);
        double yc = -0.5 * (x1 - x2) / tan(a) + (y1 + y2) / 2;
        double xc = 0.5 * (y1 - y2) / tan(a) + (x1 + x2) / 2;
        cout.precision(9);
        cout.setf(ios::fixed);
        cout << xc << " " << yc << "\n";
    }
    return 0;
}