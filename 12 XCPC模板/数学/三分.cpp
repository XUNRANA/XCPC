int L=1,R=n;
while(L<R)
{
    int m1=L+(R-L)/3;
    int m2=R-(R-L)/3;
    if(f(m1,m2)) R=m2-1;//f(m1)<f(m2) 极大值时刚好相反 
    else L=m1+1;
}
cout<<L<<"\n";//f（L）即为函数极小值
