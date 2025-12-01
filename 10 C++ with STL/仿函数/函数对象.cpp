#include <iostream>
using namespace std;

class MyAdd
{
	public:
		int operator()(int a,int b)
		{
			return a+b;
		}
};
void test01()//使用时 像普通函数一样 有参数 有返回值 
{
	MyAdd myAdd;
	cout<<myAdd(10,11)<<endl<<endl; 
}


class MyPrint
{
	public:
		MyPrint()
		{
			this->count=0;
		}
		int operator()(string test)
		{
			cout<<test<<endl;
			this->count++;
		}
		int count;
};
void test02() //函数对象可以有自己的状态 
{
	MyPrint myPrint;
	myPrint("hello world");   
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout<<"Count: "<<myPrint.count<<endl<<endl;
	
} 



void doPrint(MyPrint &mp,string test) 
{
	mp(test);
} 
void test03()  //函数对象可以作为参数传递 
{
	MyPrint myPrint;
	doPrint(myPrint,"Hello c++");  
}

int main()
{
	test01(); 
	test02(); 
	test03(); 
	
}
