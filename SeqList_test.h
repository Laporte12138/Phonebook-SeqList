#include <iostream>					   //ģ������ͷ�ļ���д
using namespace std;

template <class T, int N>

class SeqList
{
public:
	SeqList() { length = 0; }          //�޲ι��캯��                ȱ�����л���ʾ��û�к��ʵ�Ĭ�Ϲ��캯��ʹ�á�
	SeqList(T a[], int n);			   //�вι��캯��
	void PrintList();				   //����Ԫ�غ���
	T Delete(int n);				   //ɾ������
	int Locate(T x);				   //����˳�����ֵΪx��Ԫ��
	T Get(int i);					   //��ȡ˳����i��λ���ϵ�Ԫ��
	void Insert(int i, T x);		   //�ڵ�i��λ���ϲ���Ԫ��x
private:
	T data[N];						   //�洢˳�������Ԫ�ص�����
	int length;						   //˳���ĳ���
};


template<class T, int N>
SeqList<T, N>::SeqList(T a[], int n)
{
	if (n > N) throw"���鳤�ȳ���˳�����󳤶�";
		for (int i = 0; i < n; i++)
			data[i] = a[i];
	length = n;
}

/*                                  ��ʼ��������                     
template<class T, int N>
void SeqList <T, N>::PrintList()
{
	cout << "��������α������Ա��еĸ�������Ԫ��" << endl;
	for (int i = 0; i < length; i++)
		cout << "data[i]" << endl;
	cout << endl;
}
*/

template<class T, int N>                     //��������ʹ�õı�������  
void SeqList<T, N>::PrintList() {			 //��������α���˳����еĸ�������Ԫ��
	for (int i = 0; i < length; i++)
		data[i].print();
	cout << endl;
}


template<class T, int N>
void SeqList <T, N>::Insert(int i, T x)
{
	if (length >= N) throw"�����쳣";
	if (i<1 || i>length + 1) throw"λ���쳣";
		for (int j = length; j >= i; j--)
			data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}


template<class T, int N>
T SeqList<T, N>::Delete(int i)
{
	if (0 == length) throw"�����쳣";
	if (i<1 || i>length) throw"λ���쳣";
	T x = data[i - 1];
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return x;
}

template<class T, int N>
T SeqList<T, N>::Get(int i)
{
	if (i<1 || i>length) throw"����λ�÷Ƿ�";
		return data[i-1];
}

template<class T, int N>
int SeqList<T, N>::Locate(T x)
{
	for (int i = 0; i < length; i++)
		if (data[i] == x)return i + 1;
	return 0;
}
