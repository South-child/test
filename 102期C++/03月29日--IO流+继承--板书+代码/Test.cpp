#include <iostream>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Date
{
	friend ofstream& operator<<(ofstream& ofs, Date& d);
	friend ostringstream& operator<<(ostringstream& oss, Date& d);

public:
	Date(int year = 2022, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

//ostream& operator<<(ostream& os, const Date& d)

ofstream& operator<<(ofstream& ofs, Date& d)
{
	ofs << d._year << " " << d._month << " " << d._day << endl;
	return ofs;
}

ostringstream& operator<<(ostringstream& oss, Date& d)
{
	oss << d._year << " " << d._month << " " << d._day << endl;
	return oss;
}

// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
struct ServerInfo
{
	char _ip[32];	// ip
	int _port;		// �˿�

	Date _d;
};

void TestC_W_Bin()
{
	ServerInfo info = { "127.0.0.1", 80 };
	// fopen/fclose
	// �����ƶ�д  fwrite/fread  д��ȥ�Ķ������ļ��п�����
	// �ı���д    fprintf/fscanf
	FILE* fout = fopen("test.bin", "wb");
	assert(fout);

	fwrite(&info, sizeof(info), 1, fout);
	fclose(fout);
}

void TestC_R_Bin()
{
	FILE* fin = fopen("test.bin", "rb");
	assert(fin);

	ServerInfo info;
	fread(&info, sizeof(info), 1, fin);
	fclose(fin);

	printf("%s:%d\n", info._ip, info._port);
}

void TestC_W_Text()
{
	FILE* fout = fopen("test.txt", "w");
	assert(fout);

	ServerInfo info = { "127.0.0.1", 80 };
	fprintf(fout, "%s\n%d", info._ip, info._port);
	fclose(fout);
}

void TestC_R_Text()
{
	FILE* fin = fopen("test.txt", "r");
	assert(fin);

	ServerInfo info;
	fscanf(fin, "%s%d", info._ip, &info._port);
	fclose(fin);

	printf("%s:%d\n", info._ip, info._port);
}

class ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}

	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename.c_str(), ios_base::out | ios_base::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename.c_str(), ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
	}

	void WriteText(ServerInfo& info)
	{
		ofstream ofs(_filename.c_str());
		//ofs << info._ip <<" "<< info._port<<" "<< info._d;
		ofs << info._d;
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename.c_str());
		ifs >> info._ip >> info._port;
		//ifs >> info._d;
	}

private:
	string _filename;
};

//int main()
//{
//	//TestC_W_Bin();
//	//TestC_R_Bin();
//
//	//TestC_W_Text();
//	//TestC_R_Text();
//
//	ServerInfo winfo = { "127.0.0.1", 80 };
//
//	//ConfigManager cm("config.bin");
//	////cm.WriteBin(info);
//	//cm.ReadBin(info);
//	//cout << info._ip << ":" << info._port << endl;
//
//	ConfigManager cm("config.txt");
//	cm.WriteText(winfo);
//
//	/*ServerInfo rinfo;
//	cm.ReadText(rinfo);
//
//	cout << rinfo._ip << rinfo._port << endl;*/
//
//	return 0;
//}

struct PersonInfo
{
	string _name;
	int _age;
	// ....

	Date _d;
};

//int main()
//{
//	// ���л�
//	PersonInfo info = {"����", 18};
//	ostringstream oss;
//	oss << info._name <<" "<< info._age <<" ";
//	oss << info._d;
//	string str = oss.str();
//
//	// �����л�
//	istringstream iss(str);
//	string name;
//	int age;
//	iss >> name >> age;
//
//	return 0;
//}


//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//
//private:
//	int _aa;
//};
//
//// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�����Print���Կ�����Ա�����ĸ��á�
//struct Student : public Person
//{
//public:
//	void f()
//	{
//		//_aa = 1; // ���ɼ�
//		Print();
//	}
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//
//int main()
//{
//	Student s;
//	//s._aa = 1; // ���ɼ�
//
//	Teacher t;
//	//s.Print();
//	t.Print();
//
//	return 0;
//}

class Person
{
protected:
	string _name; // ����
	string _sex;  // �Ա�
public:
	void f()
	{
		_age = 1;
	}
private:
	int	_age;	 // ����
};

class Student : public Person
{
public:
	/*void f()
	{
	_age = 1;
	}*/
public:
	int _No; // ѧ��
};

int main()
{
	Person p;
	Student s;

	// ����=���ำֵ���� -�� �и�  ��Ƭ
	// ���ﲻ��������ת�������﷨��Ȼ֧����Ϊ
	p = s;
	Person* ptr = &s;
	ptr->f();
	//ptr->_age = 1;
	Person& ref = s;

	// ���� = ����
	//s = (Student)p; // ����������
	Student* pptr = (Student*)&p;
	Student& rref = (Student&)p;
	// ��Σ�յģ�����Խ����ʵķ���
	//pptr->_No = 1;


	// ����ת�����м�������ʱ����
	int i = 1;
	double d = 2.2;
	i = d;
	const int& ri = d;

	return 0;
}