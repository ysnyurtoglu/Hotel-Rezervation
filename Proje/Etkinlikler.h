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
			<< "\n[1] Canlý Müzik (500 TL) "
			<< "\n[2] Tiyatro Gösterisi (300 TL) "
			<< "\n[3] Açýk Hava Sinemasý (200 TL)"
			<< "\n[4] Kokteyl Partisi (500 TL)"
			<< "\n[5] Etkinlik Seçenekleri Sekmesinden Çýkýþ..."
			<< "\nSeçiminiz : ";
		cin >> secim;
		switch (secim) {
		case 1:
			cout << "Canlý Müziði Seçtiniz\n ";
			EtkinlikUcret += 500;
			break;
		case 2:
			cout << "Tiyatro Gösterisini Seçtiniz\n ";
			EtkinlikUcret += 300;
			break;
		case 3:
			cout << "Açýk Hava Sinemasýný Seçtiniz\n ";
			EtkinlikUcret += 200;
			break;
		case 4:
			cout << "Kokteyl Partisini Seçtiniz\n ";
			EtkinlikUcret += 500;
			break;
		case 5:
			cout << "Çýkýþ Yapýlýyor...\n";
			break;
		default:
			cout << "\nHATALI ÝÞLEM SEÇTÝNÝZ..!\nTEKRAR DENEYÝNÝZ...";
		}

	} while (secim != 5);
}