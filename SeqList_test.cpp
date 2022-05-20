#include"SeqList_test.h"
#include<string>

class PHONEBOOK                          //“类”一定要“封装”好，别丢了大小括号......
{
private:
	int m_ID;
	string m_name;
	string m_phone;
	string m_group;
public:
	PHONEBOOK(){}                        //缺少这行会显示“没有合适的默认构造函数使用”
	PHONEBOOK(const int id, const char* name, const char* phone, const char* group) { //有参构造函数
		m_ID = id;
		m_name = name;
		m_phone = phone;
		m_group = group;
	}

	void print() {                      //显示函数
		cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
	}

	bool operator == (PHONEBOOK& p) {  //重载“==”运算符，从而使locate()函数可用
		if (p.m_ID == m_ID)
			return true;
		else
			return false;
	}
};


	void main()
	{

		PHONEBOOK pbook[4] = { {2020522033,"Yang","13695568789","classmates"},
							  {2020522034,"Tu","15601357298","myself"},
							  {2020522035,"Xiao","17982365545","classmates"},
							  {2020522036,"Li","13641552003","classmates"}
		};
		PHONEBOOK record(2020522055, "Zhao", "13320056966", "classmates");
		SeqList<PHONEBOOK, 100>list(pbook, 4);
		cout << "通信录内容列表：" << endl;
		list.PrintList();
		list.Insert(1, record);
		cout << "通信录内容列表：" << endl;
		list.PrintList();
		PHONEBOOK x = list.Delete(3);
		cout << "删除元素：" << endl;
		x.print();
		cout << "通信录内容列表：" << endl;
		list.PrintList();
		int p = list.Locate(record);
		cout << "phoneix的位置是：" <<p<< endl;
	}