#include <iostream>					   //模板类在头文件里写
using namespace std;

template <class T, int N>

class SeqList
{
public:
	SeqList() { length = 0; }          //无参构造函数                缺少这行会显示“没有合适的默认构造函数使用”
	SeqList(T a[], int n);			   //有参构造函数
	void PrintList();				   //遍历元素函数
	T Delete(int n);				   //删除函数
	int Locate(T x);				   //查找顺序表中值为x的元素
	T Get(int i);					   //获取顺序表第i个位置上的元素
	void Insert(int i, T x);		   //在第i个位置上插入元素x
private:
	T data[N];						   //存储顺序表数据元素的数组
	int length;						   //顺序表的长度
};


template<class T, int N>
SeqList<T, N>::SeqList(T a[], int n)
{
	if (n > N) throw"数组长度超过顺序表最大长度";
		for (int i = 0; i < n; i++)
			data[i] = a[i];
	length = n;
}

/*                                  初始遍历函数                     
template<class T, int N>
void SeqList <T, N>::PrintList()
{
	cout << "按序号依次遍历线性表中的各个数据元素" << endl;
	for (int i = 0; i < length; i++)
		cout << "data[i]" << endl;
	cout << endl;
}
*/

template<class T, int N>                     //本例中所使用的遍历函数  
void SeqList<T, N>::PrintList() {			 //按序号依次遍历顺序表中的各个数据元素
	for (int i = 0; i < length; i++)
		data[i].print();
	cout << endl;
}


template<class T, int N>
void SeqList <T, N>::Insert(int i, T x)
{
	if (length >= N) throw"上溢异常";
	if (i<1 || i>length + 1) throw"位置异常";
		for (int j = length; j >= i; j--)
			data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}


template<class T, int N>
T SeqList<T, N>::Delete(int i)
{
	if (0 == length) throw"下溢异常";
	if (i<1 || i>length) throw"位置异常";
	T x = data[i - 1];
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return x;
}

template<class T, int N>
T SeqList<T, N>::Get(int i)
{
	if (i<1 || i>length) throw"查找位置非法";
		return data[i-1];
}

template<class T, int N>
int SeqList<T, N>::Locate(T x)
{
	for (int i = 0; i < length; i++)
		if (data[i] == x)return i + 1;
	return 0;
}
