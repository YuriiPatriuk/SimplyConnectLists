#include <iostream>
#include <forward_list>
#include "FwdList.h"
using namespace std;

//template<typename T>
//void print(const T& container)
//{
//	for (auto& elem : container)
//	{
//		cout << elem <<" ";
//	}
//	cout << endl;
//}
	//ОДНОЗВ'ЯЗНІ ЗВ'ЯЗКИ

int main()
{
	/*forward_list<int> f{ 10,23,150,500 };
	cout <<"Empty: "<<boolalpha<< f.empty() << endl;
	print(f);
	f.front() = 111;
	f.push_front(5);
	print(f);
	f.insert_after(f.begin(), { 7,8,9 });
	print(f);
	int value = 500;
	auto it = find(f.begin(), f.end(), value);
	if (it != f.end())
	{
		f.insert_after(it, 777);
	}
	print(f);
	f.erase_after(it);
	print(f);*/
	FwdList<int> f;
	f.pushFront(10);
	//f.pushFront(5);
	//f.print();
	//f.pushTail(8);
	//f.pushTail(12);
	//f.print();
	///*f.eraseFront();
	//f.print(); */
	//f.pushAfter(5, 100);
	//f.print();
	///*f.eraseAfter(100);
	//f.print();*/
	///*f.pushTail(123);*/
	//f.pushTail(1234);
	//f.print();
	//f.pushAfter(1234,1);
	f.print();
	f.eraseTail();
	f.print();

}
