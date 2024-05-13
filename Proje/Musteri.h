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

// Ki�i Bilgilerini Girdi�imiz Metot
void Musteri::setKisiBilgileri(int kisi) {

	for (int i = 1; i <= kisi; i++) {
		cout << "\nAd�n�z : ";
		cin >> ad;
		getline(cin, ad);
		cout << "Soyad�n�z : ";
		cin >> soyad;
		while (true) {
			cout << "TC Kimlik Numaras� : ";
			cin >> tc;
			if (tc.length() == 11) {
				break;
			}
			else {
				cout << "\nHATALI TC K�ML�K NUMARASI..!\nTEKRAR DENEY�N�Z...";
			}
		}
		while (true) {
			cout << "Ya��n�z : ";
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
				cout << "\nHATALI YA�..!\nTEKRAR DENEY�N�Z...";
			}
			
		}
		int maksId = 1000, minId = 1;
		*ptrId = rand() % 1000;
		cout << "M��teri ID Numaran�z : " << id << endl;
	}
}

//Ki�i Say�s�n� Girip Ki�i Say�s�n� Parametre Alan setKisiBilgileri Metodunu Kulland���m�z Metot
void Musteri::kisiSayisi() {
	while (true) {
		cout << "\nRezervasyon Yapt�rmak �stedi�iniz Ki�i Say�s�n� Giriniz : ";
		cin >> kisi;
		if (kisi > 0) {
			setKisiBilgileri(kisi);
			break;
		}
		else {
			cout << "\nHATALI K��� SAYISI..!\nTEKRAR DENEY�N�Z...";
		}
	}

}





	
	

