#include <iostream>
#include <string>

class Rezervasyon{

protected:
	int yil, ay, giris, cikis;
	string ayDizi[12] = { "Ocak", "Þubat", "Mart", "Nisan", "Mayýs", "Haziran",
		"Temmuz", "Aðustos", "Eylül", "Ekim", "Kasým", "Aralýk" };
public:
	int gun;
	void rYil();
	void rGun();
	void rAy();
	void rGiris();

	
};

// Rezervasyon Yýlýný Girdiðimiz Metot
void Rezervasyon::rYil() {

	while (true) {
		cout << "\nRezervasyon Yaptýrmak Ýstediðiniz Yýlý Giriniz : ";
		cin >> yil;
		if (yil >= 2024) {
			// rYýl Metodu Ýçinde rAy Metodunu Kullanýyoruz
			rAy();
			break;
		}
		else {
			cout << "\nHATALI YIL..!\nTEKRAR DENEYÝNÝZ...";
		}

	}
}

// Rezervasyon Yaptýrmak istediðimiz Ayý Seçtiðimiz Metot
void Rezervasyon::rAy() {

	while (true) {
		cout << "\nRezervasyon Yaptýrmak Ýstediðiniz Ayý Giriniz (1 - 12) : ";
		cin >> ay;
		if (ay >= 1 && ay <= 12) {
			cout << endl << ayDizi[ay - 1] << " Ayý Seçildi.\n";
			// Ay Metodu Ýçinde Giriþ Tarihini Seçtiðimiz rGiris Metodunu Kullanýyoruz
			rGiris();
			break;
		}
		else {
			cout << "\nHATALI AY..!\nTEKRAR DENEYÝNÝZ...";
		}
	}
}

// Kalmak Ýstediðimiz Gün Sayýsýný Girdiðimiz Metot
void Rezervasyon::rGun() {

	while (true) {
		cout << "\nKalmak Ýstediðiniz Gün Sayýsýný Giriniz (Minimum 2 Gün) : ";
		cin >> gun;
		if (gun >= 2) {
			break;
		}
		else {
			cout << "\nHATALI GÜN..!\nTEKRAR DENEYÝNÝZ...";
		}
	}
}

// Otele Giriþ Yapmak Ýstediðimiz Tarihi Girdiðimiz Metot
void Rezervasyon::rGiris() {

	while (true) {
		if (ay == 1 || ay == 3 || ay == 5 || ay == 7 || ay == 8 || ay == 10 || ay == 12) {
			cout << "\nOtele Giriþ Tarihini Giriniz (1 - 31) : ";
			cin >> giris;
			if (giris <= 31 && giris >= 1) {
				rGun();
				cikis = giris + gun;
				if (cikis > 31 && ay != 12) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 32 << "/" << ay + 1 << "/" << yil;
					break;
				}
				else if (cikis > 31 && ay == 12) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 32 << "/" << ay - 11 << "/" << yil + 1;
					break;
				}
				else if (cikis <= 31) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 1 << "/" << ay << "/" << yil;
					break;
				}
			}
			else if (giris > 31) {
				cout << "\nHATALI GÝRÝÞ TARÝHÝ..!\nTEKRAR DENEYÝNÝZ...";
			}
		}
		else if (ay == 4 || ay == 6 || ay == 9 || ay == 11) {
			cout << "\nOtele Giriþ Tarihini Giriniz (1 - 30) : ";
			cin >> giris;
			if (giris <= 30 && giris >= 1) {
				rGun();
				cikis = giris + gun;
				if (cikis > 30) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 31 << "/" << ay + 1 << yil;
					break;
				}
				else if (cikis <= 30) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 1 << "/" << ay << "/" << yil;
					break;
				}
			}
			else if (giris > 30) {
				cout << "\nHATALI GÝRÝS TARÝHÝ..!\nTEKRAR DENEYÝNÝZ...";
			}
		}
		else if (ay == 2 && yil % 4 == 0) {
			cout << "\nOtele Giriþ Tarihini Giriniz (1 - 29) :";
			cin >> giris;
			if (giris <= 29 && giris >= 1) {
				rGun();
				cikis = giris + gun;
				if (cikis > 29) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 30 << "/" << ay + 1 << "/" << yil;
					break;
				}
				else if (cikis <= 29) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 30 << "/" << ay << "/" << yil;
					break;
				}
			}
			else if (giris > 29) {
				cout << "\nHATALI GÝRÝÞ TARÝHÝ..!\nTEKRAR DENEYÝNÝZ...";
			}
		}
		else if (ay == 2 && yil % 4 != 0) {
			cout << "\nOtele Giriþ Tarihini Giriniz : ";
			cin >> giris;
			if (giris <= 28 && giris >= 1) {
				rGun();
				cikis = giris + gun;
				if (cikis > 28) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 29 << "/" << ay + 1 << "/" << yil;
					break;
				}
				else if (cikis <= 28) {
					cout << "\nOtele Giriþ Tarihi : " << giris << "/" << ay << "/" << yil;
					cout << "\nOtelden Çýkýþ Tarihi : " << cikis - 1 << "/" << ay << "/" << yil;
					break;
				}
			}
			else if (giris > 28) {
				cout << "\nHATALI GÝRÝÞ TARÝHÝ..!\nTEKRAR DENEYÝNÝZ...";
			}

		}
	}
}

