#include <iostream>
#include <functional>  //头文件 
using namespace std;

 
void test01()
{
	negate<int>n;       //negate 一元仿函数 取反仿函数
	cout<<n(100)<<endl<<endl;
	
	plus<int>p;         //加法仿函数 
	cout<<p(100,10)<<endl<<endl;
	
	minus<int>mi;       //减法仿函数 
	cout<<mi(100,10)<<endl<<endl;
	
	multiplies<int>ml;  //乘法仿函数 
	cout<<ml(100,10)<<endl<<endl;
	
	divides<int>d;      //除法仿函数 
	cout<<d(100,10)<<endl<<endl;
	
	modulus<int>mo;      //除法仿函数 
	cout<<mo(100,10)<<endl<<endl;
}

int main()
{
	test01(); 
} 
