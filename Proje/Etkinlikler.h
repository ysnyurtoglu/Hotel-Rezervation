#include<iostream>

using namespace std;

class Etkinlikler {

public:
	double EtkinlikUcret = 0;
	void etkinlik();
};

void Etkinlikler::etkinlik() {

	int secim;
	do {
		cout << "\nOtelimizde Bulunan Etkinlikler: "
			<< "\n[1] Canl� M�zik (500 TL) "
			<< "\n[2] Tiyatro G�sterisi (300 TL) "
			<< "\n[3] A��k Hava Sinemas� (200 TL)"
			<< "\n[4] Kokteyl Partisi (500 TL)"
			<< "\n[5] Etkinlik Se�enekleri Sekmesinden ��k��..."
			<< "\nSe�iminiz : ";
		cin >> secim;
		switch (secim) {
		case 1:
			cout << "Canl� M�zi�i Se�tiniz\n ";
			EtkinlikUcret += 500;
			break;
		case 2:
			cout << "Tiyatro G�sterisini Se�tiniz\n ";
			EtkinlikUcret += 300;
			break;
		case 3:
			cout << "A��k Hava Sinemas�n� Se�tiniz\n ";
			EtkinlikUcret += 200;
			break;
		case 4:
			cout << "Kokteyl Partisini Se�tiniz\n ";
			EtkinlikUcret += 500;
			break;
		case 5:
			cout << "��k�� Yap�l�yor...\n";
			break;
		default:
			cout << "\nHATALI ��LEM SE�T�N�Z..!\nTEKRAR DENEY�N�Z...";
		}

	} while (secim != 5);
}