#include <iostream>
#include <string>

class Rezervasyon{

protected:
	int yil, ay, giris, cikis;
	string ayDizi[12] = { "Ocak", "�ubat", "Mart", "Nisan", "May�s", "Haziran",
		"Temmuz", "A�ustos", "Eyl�l", "Ekim", "Kas�m", "Aral�k" };
public:
	int gun;
	void rYil();
	void rGun();
	void rAy();
	void rGiris();

	
};

// Rezervasyon Y�l�n� Girdi�imiz Metot
void Rezervasyon::rYil() {

	while (true) {
		cout << "\nRezervasyon Yapt�rmak �stedi�iniz Y�l� Giriniz : ";
		cin >> yil;
		if (yil >= 2024) {
			// rY�l Metodu ��inde rAy Metodunu Kullan�yoruz
			rAy();
			break;
		}
		else {
			cout << "\nHATALI YIL..!\nTEKRAR DENEY�N�Z...";
		}

	}
}

// Rezervasyon Yapt�rmak istedi�imiz Ay� Se�ti�imiz Metot
void Rezervasyon::rAy() {

	while (true) {
		cout << "\nRezervasyon Yapt�rmak �stedi�iniz Ay� Giriniz (1 - 12) : ";
		cin >> ay;
		if (ay >= 1 && ay <= 12) {
			cout << endl << ayDizi[ay - 1] << " Ay� Se�ildi.\n";
			// Ay Metodu ��inde Giri� Tarihini Se�ti�imiz rGiris Metodunu Kullan�yoruz
			rGiris();
			break;
		}
		else {
			cout << "\nHATALI AY..!\nTEKRAR DENEY�N�Z...";
		}
	}
}

// Kalmak �stedi�imiz G�n Say�s�n� Girdi�imiz Metot
void Rezervasyon::rGun() {

	while (true) {
		cout << "\nKalmak �stedi�iniz G�n Say�s�n� Giriniz (Minimum 2 G�n) : ";
		cin >> gun;
		if (gun >= 2) {
			break;
		}
		else {
			cout << "\nHATALI G�N..!\nTEKRAR DENEY�N�Z...";
		}
	}
}

// Otele Giri� Yapmak �stedi�imiz Tarihi Girdi�imiz Metot
void Rezervasyon::rGiris() {

	while (true) {
		if (ay == 1 || ay == 3 || ay == 5 || ay == 7 || ay == 8 || ay == 10 || ay == 12) {
			cout << "\nOtele Giri� Tarihini Giriniz (1 - 31) : ";
			cin >> giris;
			if (giris <= 31 && giris >= 1) {
				rGun();
				cikis = giris + gun;
				if (cikis > 31 && ay != 12) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 32 << "/" << ay + 1 << "/" << yil;
					break;
				}
				else if (cikis > 31 && ay == 12) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 32 << "/" << ay - 11 << "/" << yil + 1;
					break;
				}
				else if (cikis <= 31) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 1 << "/" << ay << "/" << yil;
					break;
				}
			}
			else if (giris > 31) {
				cout << "\nHATALI G�R�� TAR�H�..!\nTEKRAR DENEY�N�Z...";
			}
		}
		else if (ay == 4 || ay == 6 || ay == 9 || ay == 11) {
			cout << "\nOtele Giri� Tarihini Giriniz (1 - 30) : ";
			cin >> giris;
			if (giris <= 30 && giris >= 1) {
				rGun();
				cikis = giris + gun;
				if (cikis > 30) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 31 << "/" << ay + 1 << yil;
					break;
				}
				else if (cikis <= 30) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 1 << "/" << ay << "/" << yil;
					break;
				}
			}
			else if (giris > 30) {
				cout << "\nHATALI G�R�S TAR�H�..!\nTEKRAR DENEY�N�Z...";
			}
		}
		else if (ay == 2 && yil % 4 == 0) {
			cout << "\nOtele Giri� Tarihini Giriniz (1 - 29) :";
			cin >> giris;
			if (giris <= 29 && giris >= 1) {
				rGun();
				cikis = giris + gun;
				if (cikis > 29) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 30 << "/" << ay + 1 << "/" << yil;
					break;
				}
				else if (cikis <= 29) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 30 << "/" << ay << "/" << yil;
					break;
				}
			}
			else if (giris > 29) {
				cout << "\nHATALI G�R�� TAR�H�..!\nTEKRAR DENEY�N�Z...";
			}
		}
		else if (ay == 2 && yil % 4 != 0) {
			cout << "\nOtele Giri� Tarihini Giriniz : ";
			cin >> giris;
			if (giris <= 28 && giris >= 1) {
				rGun();
				cikis = giris + gun;
				if (cikis > 28) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 29 << "/" << ay + 1 << "/" << yil;
					break;
				}
				else if (cikis <= 28) {
					cout << "\nOtele Giri� Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden ��k�� Tarihi : " << cikis - 1 << "/" << ay << "/" << yil;
					break;
				}
			}
			else if (giris > 28) {
				cout << "\nHATALI G�R�� TAR�H�..!\nTEKRAR DENEY�N�Z...";
			}

		}
	}
}

