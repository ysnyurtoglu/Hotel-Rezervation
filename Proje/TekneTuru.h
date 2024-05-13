#include <iostream>

using namespace std;

class TekneTuru {

private:
	int kisi, yas, yCount = 0, cCount = 0, secim;
public:
	double turEkUcret = 0;
	void tekneTuru();
};

// Tekne Turu �le �lgili Bilgileri G�rd���m�z Ve Se�im Yapt���m�z Metot
void TekneTuru::tekneTuru() {

	cout << "\nPhaselis Koyu -> Cennet Koyu -> Kiri� Koyu";

	cout << "\nYeti�kin(12+) + Yemek (+Me�rubat) -> 500TL - 700Tl"
		<< "\n�ocuk(7-12) + Yemek (+Me�rubat) -> 200TL - 350TL"
		<< "\nBebek(0-6) -> Ek �cret ��ermez.";

	cout << "\nTura Kat�lacak Ki�i Say�s�n� Giriniz : ";
	cin >> kisi;
	cout << "\nTura Kat�lan Ki�ilerin Ya�lar�n� Giriniz...\n";
	for (int i = 1; i <= kisi; i++) {
		cout << i << ". Ki�inin Ya�� : ";
		cin >> yas;
		if (yas > 12) {
			yCount++;
		}
		else if (yas >= 7 && yas <= 12) {
			cCount++;
		}
		else {

		}
	}
	cout << "[1] Yemekli Tur : " << (yCount * 500) + (cCount * 200)
		<< "\n[2] Yemek + Me�rubatl� Tur : " << (yCount * 700) + (cCount * 350)
		<< "\n[3] Tekne Turu Sekmesinden ��k��"
		<< "\nSe�iminiz : ";
	do {
		cin >> secim;
		if (secim == 1) {
			turEkUcret += (yCount * 500) + (cCount * 200);
		}
		else if (secim == 2) {
			turEkUcret += (yCount * 700) + (cCount * 350);
		}
		else if (secim == 3) {
			break;
		}
		else {
			cout << "\nHATALI TERC�H!!!\nTekrar Deneyiniz...";
		}
	} while (secim != 1 && secim != 2);

}



