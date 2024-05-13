#include <iostream>
#include <string>

using namespace std;

class SpecialYemek{

private:
	string menu[6][3] = { {"Spring Rolls","Sweet and Sour Chicken", "Fortune Cookies"},
		{"Edaname","Sushi Assortment", "Mochi Ice Cream"},
		{"Caprese Salad", "Risotto", "Tiramisu"},
		{"French Onion Soup", "Coq au Vin", "Cr�me Br�l�e"},
		{"Gazpacho", "Paella", "Churros"},
		{"Hummus", "Kebab Platter", "Baklava"}};
	double menuFiyat[6] = {1500, 1800, 1900, 1200, 1400, 1000};
public:
	double ekFiyat = 0;
	void yemekSecimi();
};

void SpecialYemek::yemekSecimi() {

	cout << "\n�lkelere �zel Yemek Men�lerimiz...\n[1] �in\n[2] Japonya\n[3] Fransa\n[4] �talya\n[5] �spanya\n[6] T�rkiye";
	while (true) {
		int choise;
		cout << "\nSe�iminiz : ";
		cin >> choise;
		switch (choise) {
		case 1:
			cout << "\n�in Yeme�i Se�ildi\n";
			
			cout << "Ba�lang�� : " << menu[0][0] << endl;
			cout << "Ana Yemek : " << menu[0][1] << endl;
			cout << "Tatl� : " << menu[0][2] << endl;
			ekFiyat += menuFiyat[0];
			break;
		case 2:
			cout << "\nJaponya Yeme�i Se�ildi\n";
			cout << "Ba�lang�� : " << menu[1][0] << endl;
			cout << "Ana Yemek : " << menu[1][1] << endl;
			cout << "Tatl� : " << menu[1][2] << endl;
			ekFiyat += menuFiyat[1];
			break;
		case 3:
			cout << "\nFransa Yeme�i Se�ildi\n";
			cout << "Ba�lang�� : " << menu[2][0] << endl;
			cout << "Ana Yemek : " << menu[2][1] << endl;
			cout << "Tatl� : " << menu[2][2] << endl;
			ekFiyat += menuFiyat[2];
			break;
		case 4:
			cout << "\n�talya Yeme�i Se�ildi\n";
			cout << "Ba�lang�� : " << menu[3][0] << endl;
			cout << "Ana Yemek : " << menu[3][1] << endl;
			cout << "Tatl� : " << menu[3][2] << endl;
			ekFiyat += menuFiyat[3];
			break;
		case 5:
			cout << "\n�spanya Yeme�i Se�ildi\n";
			cout << "Ba�lang�� : " << menu[4][0] << endl;
			cout << "Ana Yemek : " << menu[4][1] << endl;
			cout << "Tatl� : " << menu[4][2] << endl;
			ekFiyat += menuFiyat[4];
			break;
		case 6:
			cout << "\nT�rkiye Yeme�i Se�ildi\n";
			cout << "Ba�lang�� : " << menu[5][0] << endl;
			cout << "Ana Yemek : " << menu[5][1] << endl;
			cout << "Tatl� : " << menu[5][2] << endl;
			ekFiyat += menuFiyat[5];
			break;
		default:
			cout << "\nHATALI SE��M..!\nTEKRAR DENEY�N�z...";
		}
		break;
	}

}

