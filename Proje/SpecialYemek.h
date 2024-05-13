#include <iostream>
#include <string>

using namespace std;

class SpecialYemek{

private:
	string menu[6][3] = { {"Spring Rolls","Sweet and Sour Chicken", "Fortune Cookies"},
		{"Edaname","Sushi Assortment", "Mochi Ice Cream"},
		{"Caprese Salad", "Risotto", "Tiramisu"},
		{"French Onion Soup", "Coq au Vin", "Crème Brûlée"},
		{"Gazpacho", "Paella", "Churros"},
		{"Hummus", "Kebab Platter", "Baklava"}};
	double menuFiyat[6] = {1500, 1800, 1900, 1200, 1400, 1000};
public:
	double ekFiyat = 0;
	void yemekSecimi();
};

void SpecialYemek::yemekSecimi() {

	cout << "\nÜlkelere Özel Yemek Menülerimiz...\n[1] Çin\n[2] Japonya\n[3] Fransa\n[4] Ýtalya\n[5] Ýspanya\n[6] Türkiye";
	while (true) {
		int choise;
		cout << "\nSeçiminiz : ";
		cin >> choise;
		switch (choise) {
		case 1:
			cout << "\nÇin Yemeði Seçildi\n";
			
			cout << "Baþlangýç : " << menu[0][0] << endl;
			cout << "Ana Yemek : " << menu[0][1] << endl;
			cout << "Tatlý : " << menu[0][2] << endl;
			ekFiyat += menuFiyat[0];
			break;
		case 2:
			cout << "\nJaponya Yemeði Seçildi\n";
			cout << "Baþlangýç : " << menu[1][0] << endl;
			cout << "Ana Yemek : " << menu[1][1] << endl;
			cout << "Tatlý : " << menu[1][2] << endl;
			ekFiyat += menuFiyat[1];
			break;
		case 3:
			cout << "\nFransa Yemeði Seçildi\n";
			cout << "Baþlangýç : " << menu[2][0] << endl;
			cout << "Ana Yemek : " << menu[2][1] << endl;
			cout << "Tatlý : " << menu[2][2] << endl;
			ekFiyat += menuFiyat[2];
			break;
		case 4:
			cout << "\nÝtalya Yemeði Seçildi\n";
			cout << "Baþlangýç : " << menu[3][0] << endl;
			cout << "Ana Yemek : " << menu[3][1] << endl;
			cout << "Tatlý : " << menu[3][2] << endl;
			ekFiyat += menuFiyat[3];
			break;
		case 5:
			cout << "\nÝspanya Yemeði Seçildi\n";
			cout << "Baþlangýç : " << menu[4][0] << endl;
			cout << "Ana Yemek : " << menu[4][1] << endl;
			cout << "Tatlý : " << menu[4][2] << endl;
			ekFiyat += menuFiyat[4];
			break;
		case 6:
			cout << "\nTürkiye Yemeði Seçildi\n";
			cout << "Baþlangýç : " << menu[5][0] << endl;
			cout << "Ana Yemek : " << menu[5][1] << endl;
			cout << "Tatlý : " << menu[5][2] << endl;
			ekFiyat += menuFiyat[5];
			break;
		default:
			cout << "\nHATALI SEÇÝM..!\nTEKRAR DENEYÝNÝz...";
		}
		break;
	}

}

