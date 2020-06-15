#include<iostream>
#include "Date.h"


using namespace std;


int main() {

	Date d1(31, 12, 2020);
	d1.Print();
	//d1.PlusOneDay();
	d1.Print();	

	//++d1;
	//d1.Print();
	d1++;
	d1.Print();

	Date d2(5, 2, 2020);
	
	if (d1 > d2) {
		cout << "d1 > d2" << endl;
	}
	else {
		cout << "d1 < d2" << endl;
	}

	if (d1 == d2) {
		cout << "d1 = d2" << endl;
	}
	else {
		cout << "d1 != d2" << endl;
	}

	Date d3(28, 6, 2020);	
	d3 += 3;	
	d3.Print();

	Date d4(4, 3, 2020);
	d4 -= 5;
	d4.Print();
	--d4;
	d4.Print();


	ofstream out(fileName);
	out << d4;
	Date d5;
	ifstream in(fileName);
	in >> d5;
	d5.Print();

	d5(3);
	d5.Print();
	d5(3, 15);
	d5.Print();

	system("pause");
	return 0;
}