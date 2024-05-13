#include <iostream>
#include <string>

using namespace std;

class Otel{

protected:
	string ad, soyad, tc;
	int yas, kisi, id;

public:

	virtual double araUcret() = 0;

};

double Otel::araUcret() {

	return kisi;
}

