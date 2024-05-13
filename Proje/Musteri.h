#include <iostream>
#include <string>
#include "Otel.h"

using namespace std;

class Musteri :public Otel{

protected:
	double kbgu = 2000;
	double konaklamaUcret = 0;
public:
	int id;
	int *ptrId = &id;
	void setKisiBilgileri(int kisi);
	void kisiSayisi();
	
	double araUcret() override {
		
		return konaklamaUcret;
	}
};

// Kiþi Bilgilerini Girdiðimiz Metot
void Musteri::setKisiBilgileri(int kisi) {

	for (int i = 1; i <= kisi; i++) {
		cout << "\nAdýnýz : ";
		cin >> ad;
		getline(cin, ad);
		cout << "Soyadýnýz : ";
		cin >> soyad;
		while (true) {
			cout << "TC Kimlik Numarasý : ";
			cin >> tc;
			if (tc.length() == 11) {
				break;
			}
			else {
				cout << "\nHATALI TC KÝMLÝK NUMARASI..!\nTEKRAR DENEYÝNÝZ...";
			}
		}
		while (true) {
			cout << "Yaþýnýz : ";
			cin >> yas;
			if (yas >= 0) {
				if (yas > 12) {
					konaklamaUcret += kbgu;
				}
				else if (yas <= 12 && yas >= 7) {
					konaklamaUcret += kbgu * (0.7);
				}
				else if (yas < 7 && yas > 0) {
					konaklamaUcret += 0;
				}
				break;
			}
			else {
				cout << "\nHATALI YAÞ..!\nTEKRAR DENEYÝNÝZ...";
			}
			
		}
		int maksId = 1000, minId = 1;
		*ptrId = rand() % 1000;
		cout << "Müþteri ID Numaranýz : " << id << endl;
	}
}

//Kiþi Sayýsýný Girip Kiþi Sayýsýný Parametre Alan setKisiBilgileri Metodunu Kullandýðýmýz Metot
void Musteri::kisiSayisi() {
	while (true) {
		cout << "\nRezervasyon Yaptýrmak Ýstediðiniz Kiþi Sayýsýný Giriniz : ";
		cin >> kisi;
		if (kisi > 0) {
			setKisiBilgileri(kisi);
			break;
		}
		else {
			cout << "\nHATALI KÝÞÝ SAYISI..!\nTEKRAR DENEYÝNÝZ...";
		}
	}

}





	
	

