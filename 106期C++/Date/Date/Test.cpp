#include "Date.h"

void TestDate1()
{
	Date d1(2022, 10, 19);
	Date d2(2023, 1, 1);
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
}
void TestDate2()
{
	Date d1(2022, 10, 19);
	Date d2(2023, 1, 10);

	d1 += 10;
	d1.print();

	(d2 + 10).print();
	d2.print();

	printf("--------------\n");
	
	d1 -= 10;
	d1.print();

	(d2 - 10).print();
	d2.print();
}
void TestDate3()
{
	Date d1(2022, 10, 19);
	Date d2(2023, 1, 10);

	(d1++).print();

	(++d1).print();

	(--d2).print();

	(d2--).print();
}

void TestDate4()
{
	Date d1(2022, 10, 19);
	Date d2(2023, 1, 10);

	cout << (d2 - d1) << endl;
}

int main()
{
	TestDate4();
	return 0;
}