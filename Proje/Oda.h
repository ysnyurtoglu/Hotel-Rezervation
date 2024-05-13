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
//		cout << "\nTek Ki�ilik Oda\n�ift Ki�ilik Oda\n3 Ki�ilik Oda\n4 Ki�ilik Oda\n5 Ki�ilik Oda";
//		cout << "Ka� Ki�ilik Oda Tercih Edersiniz (1 - 5) : ";
//		cin >> odaKisi;
//
//		if (kisi <= odaKisi) {
//			int temp = kisi / odaKisi;
//			cout << temp << " Adet Oda Se�ildi.";
//			break;
//		}
//		else if (kisi > odaKisi) {
//
//			int temp = kisi / odaKisi;
//			int temp2 = kisi % odaKisi;
//
//			cout << temp << " Adet " << odaKisi << " Ki�ilik Oda Se�ildi.";
//			cout << 1 << " Adet " << temp2 << " Ki�ilik Oda Se�ildi.";
//			break;
//		}
//	}
//}

// Oda ��inde �stedi�imiz Ekstra �zellikleri Se�ti�imiz Metot
void Oda::odaEkstraOzellik() {

	int i = 1;
	cout << "\nOda �zelliklerini Se�iniz...";
	do {
		
		int tercih;
		if (i == 1) {
			cout << "\n[1] Otel Avlu Manzaral� -> Ek �cret �cermez."
				<< "\n[2] Deniz Manzaral� -> + 1000 TL"
				<< "\nOda Manzaras� Tercihi : ";
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
				cout << "\nHATALI �SLEM G�RD�N�Z!!!"
					<< "\nTekrar Deneyiniz...";
				i--;
			}
		}
		else if (i == 2) {
			cout << "\n[1] Balkonsuz Oda -> Ek �cret �cermez."
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
				cout << "\nHATALI �SLEM G�RD�N�Z!!!"
					<< "\nTekrar Deneyiniz...";
				i--;
			}
		}
		else if (i == 3) {
			cout << "\n[1] Jakuzisiz Oda -> Ek �cret �cermez."
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
				cout << "\nHATALI �SLEM G�RD�N�Z!!!"
					<< "\nTekrar Deneyiniz...";
				i--;
			}
		}
		else if (i == 4) {
			break;
		}
		else {
			cout << "Hatal� De�er Girdiniz..!\nTekrar Deneyiniz.";
		}
	} while (i != 4);

	cout << "\nSe�ti�iniz �zelliklere Sahip Bo� Odalar�m�z...";
	odaSec();

}

// Random Bir �ekilde Bo� Olan Odalar� Bulan Metot
void Oda::totalOda() {


	for (int i = 1; i <= 12; i++) {
		// Random Kat Bulma...
		int maksKat = 9, minKat = 1;
		int kat = rand() % 10;

		// Bo� Olan Odalar�n Numaralar�...
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

// Random Buldu�u Bo� Odalardan Birini Se�ti�imiz Metot
void Oda::odaSec() {

	while (true) {
		totalOda();
		break;
	}
	cout << "\nOda Se�iminizi Yap�n�z : ";
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
		cout << "\nHATALI ODA SE��M�..!\nTEKRAR DENEY�N�Z...";
	}
	cout << "\nOda Ek �zellik �creti : " << ekOzellikUcret;
	cout << "\nOda Numaran�z : " << odaNo << endl;
	
}

