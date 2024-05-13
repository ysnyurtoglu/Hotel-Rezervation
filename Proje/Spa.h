#include <iostream>

using namespace std;

class Spa {
private:
	int kisi;
public:
	double spaEkUcret = 0;
	void spa();
};

// Masaj Seçenekleri Ýle Ýlgili Bilgileri Gördüðümüz Ve Seçtiðimiz Metot
void Spa::spa() {
	int secim;
	cout << "\nMasaj Yaptýracak Kiþi Sayýsýný Giriniz : ";
	cin >> kisi;
	cout << "\n[1] Klasik Masaj(1000TL) : Sert vuruþlar eþliðinde dairesel hareketler ve ovma gibi hareketleri barýndýran masaj türüdür.\n"
		<< "\n[2] Thai Masajý(1500TL) : Vücudumuzdaki esnekliðimizi arttýrmak, kas ve eklem gerilimini azaltmak ve vücudun enerji"
		<< "\nsistemlerini dengelemek için pasif germe ve hafif baskýlarýn uygulandýðý masaj türüdür.\n"
		<< "\n[3] Refleseloji Masaji(2250TL) : Ayak refleksoloji masajý, plantar fasiit, ayak bileði yaralanmalarý gibi gün"
		<< "içerisinde \nspor  veya  iþ yaparken kiþileri rahatlatmak için uygulanýr.\n"
		<< "\n[4] Shiatsu Masaji(3000TL) : Vücudumuzun belirli bölgelerine parmak yardýmýyla yapýlan bir masaj yöntemidir.\n"
		<< "\n[5] Masaj Secenekleri Sekmesinden Cikis...";
	for(int i = 1; i <= kisi;i++){
		cout << "\nSeciminiz : ";
		cin >> secim;
		switch (secim) {
		case 1:
			cout << "\nKlasik Masaj Hizmeti Aldýnýz.\n";
			spaEkUcret += 1000;
			break;
		case 2:
			cout << "\nThai Masaj Hizmeti Aldýnýz.\n";
			spaEkUcret += 1500;
			break;
		case 3:
			cout << "\nRefleseloji Masaj Hizmeti Aldýnýz.\n";
			spaEkUcret += 2250;
			break;
		case 4:
			cout << "\nShiatsu Masaj Hizmeti Aldýnýz.\n";
			spaEkUcret += 3000;
			break;
		case 5:
			cout << "\nÇýkýþ Yapýlýyor...\n";
			break;
		}
	}
}
