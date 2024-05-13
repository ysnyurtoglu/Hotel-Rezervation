#include <iostream>

using namespace std;

class TekneTuru {

private:
	int kisi, yas, yCount = 0, cCount = 0, secim;
public:
	double turEkUcret = 0;
	void tekneTuru();
};

// Tekne Turu Ýle Ýlgili Bilgileri Gördüðümüz Ve Seçim Yaptýðýmýz Metot
void TekneTuru::tekneTuru() {

	cout << "\nPhaselis Koyu -> Cennet Koyu -> Kiriþ Koyu";

	cout << "\nYetiþkin(12+) + Yemek (+Meþrubat) -> 500TL - 700Tl"
		<< "\nÇocuk(7-12) + Yemek (+Meþrubat) -> 200TL - 350TL"
		<< "\nBebek(0-6) -> Ek Ücret Ýçermez.";

	cout << "\nTura Katýlacak Kiþi Sayýsýný Giriniz : ";
	cin >> kisi;
	cout << "\nTura Katýlan Kiþilerin Yaþlarýný Giriniz...\n";
	for (int i = 1; i <= kisi; i++) {
		cout << i << ". Kiþinin Yaþý : ";
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
		<< "\n[2] Yemek + Meþrubatlý Tur : " << (yCount * 700) + (cCount * 350)
		<< "\n[3] Tekne Turu Sekmesinden Çýkýþ"
		<< "\nSeçiminiz : ";
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
			cout << "\nHATALI TERCÝH!!!\nTekrar Deneyiniz...";
		}
	} while (secim != 1 && secim != 2);

}



