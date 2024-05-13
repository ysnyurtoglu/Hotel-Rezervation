#include <iostream>
#include <string>

using namespace std;

class Oda {

protected:
	int odaNo, bosOdaNo, odaSecimi;
	int bosOdaDizi[12];
	int bosOdaSayisi;
	int odaKisi;
	int odaSayisi;
public:
	double ekOzellikUcret = 0;
	void totalOda();
	void odaSec();
	void odaEkstraOzellik();
	void odaKisiSayisi();
};

//void Oda::odaKisiSayisi() {
//
//	while (true) {
//		cout << "\nTek Kiþilik Oda\nÇift Kiþilik Oda\n3 Kiþilik Oda\n4 Kiþilik Oda\n5 Kiþilik Oda";
//		cout << "Kaç Kiþilik Oda Tercih Edersiniz (1 - 5) : ";
//		cin >> odaKisi;
//
//		if (kisi <= odaKisi) {
//			int temp = kisi / odaKisi;
//			cout << temp << " Adet Oda Seçildi.";
//			break;
//		}
//		else if (kisi > odaKisi) {
//
//			int temp = kisi / odaKisi;
//			int temp2 = kisi % odaKisi;
//
//			cout << temp << " Adet " << odaKisi << " Kiþilik Oda Seçildi.";
//			cout << 1 << " Adet " << temp2 << " Kiþilik Oda Seçildi.";
//			break;
//		}
//	}
//}

// Oda Ýçinde Ýstediðimiz Ekstra Özellikleri Seçtiðimiz Metot
void Oda::odaEkstraOzellik() {

	int i = 1;
	cout << "\nOda Özelliklerini Seçiniz...";
	do {
		
		int tercih;
		if (i == 1) {
			cout << "\n[1] Otel Avlu Manzaralý -> Ek Ücret Ýcermez."
				<< "\n[2] Deniz Manzaralý -> + 1000 TL"
				<< "\nOda Manzarasý Tercihi : ";
			cin >> tercih;
			if (tercih == 1) {
				ekOzellikUcret;
				i++;
			}
			else if (tercih == 2) {
				ekOzellikUcret += 1000;
				i++;
			}
			else {
				cout << "\nHATALI ÝSLEM GÝRDÝNÝZ!!!"
					<< "\nTekrar Deneyiniz...";
				i--;
			}
		}
		else if (i == 2) {
			cout << "\n[1] Balkonsuz Oda -> Ek Ücret Ýcermez."
				<< "\n[2] Balkonlu Oda -> +500 Tl"
				<< "\nBalkon Tercihi : ";
			cin >> tercih;
			if (tercih == 1) {
				ekOzellikUcret;
				i++;
			}
			else if (tercih == 2) {
				ekOzellikUcret += 500;
				i++;
			}
			else {
				cout << "\nHATALI ÝSLEM GÝRDÝNÝZ!!!"
					<< "\nTekrar Deneyiniz...";
				i--;
			}
		}
		else if (i == 3) {
			cout << "\n[1] Jakuzisiz Oda -> Ek Ücret Ýcermez."
				<< "\n[2] Jakuzili Oda -> +2000 Tl"
				<< "\nJakuzi Tercihi : ";
			cin >> tercih;
			if (tercih == 1) {
				ekOzellikUcret;
				i++;
			}
			else if (tercih == 2) {
				ekOzellikUcret += 2000;
				i++;
			}
			else {
				cout << "\nHATALI ÝSLEM GÝRDÝNÝZ!!!"
					<< "\nTekrar Deneyiniz...";
				i--;
			}
		}
		else if (i == 4) {
			break;
		}
		else {
			cout << "Hatalý Deðer Girdiniz..!\nTekrar Deneyiniz.";
		}
	} while (i != 4);

	cout << "\nSeçtiðiniz Özelliklere Sahip Boþ Odalarýmýz...";
	odaSec();

}

// Random Bir Þekilde Boþ Olan Odalarý Bulan Metot
void Oda::totalOda() {


	for (int i = 1; i <= 12; i++) {
		// Random Kat Bulma...
		int maksKat = 9, minKat = 1;
		int kat = rand() % 10;

		// Boþ Olan Odalarýn Numaralarý...
		int maksOda = 30, minOda = 1;
		int oda = rand() % 30;
		bosOdaNo = oda + (kat * 100);
		
		if(bosOdaNo > 100){
			bosOdaDizi[i - 1] = bosOdaNo;
			cout << endl << "[" << i << "] : " << bosOdaNo;
		}
		else if (bosOdaNo < 100) {
			i--;
		}

	}
}

// Random Bulduðu Boþ Odalardan Birini Seçtiðimiz Metot
void Oda::odaSec() {

	while (true) {
		totalOda();
		break;
	}
	cout << "\nOda Seçiminizi Yapýnýz : ";
	cin >> odaSecimi;
	switch (odaSecimi) {

	case 1:
		odaNo = bosOdaDizi[0];
		break;
	case 2:
		odaNo = bosOdaDizi[1];
		break;
	case 3:
		odaNo = bosOdaDizi[2];
		break;
	case 4:
		odaNo = bosOdaDizi[3];
		break;
	case 5:
		odaNo = bosOdaDizi[4];
		break;
	case 6:
		odaNo = bosOdaDizi[5];
		break;
	case 7:
		odaNo = bosOdaDizi[6];
		break;
	case 8:
		odaNo = bosOdaDizi[7];
		break;
	case 9:
		odaNo = bosOdaDizi[8];
		break;
	case 10:
		odaNo = bosOdaDizi[9];
		break;
	case 11:
		odaNo = bosOdaDizi[10];
		break;
	case 12:
		odaNo = bosOdaDizi[11];
		break;
	default:
		cout << "\nHATALI ODA SEÇÝMÝ..!\nTEKRAR DENEYÝNÝZ...";
	}
	cout << "\nOda Ek Özellik Ücreti : " << ekOzellikUcret;
	cout << "\nOda Numaranýz : " << odaNo << endl;
	
}

