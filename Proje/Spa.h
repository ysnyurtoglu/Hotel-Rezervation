#include <iostream>

using namespace std;

class Spa {
private:
	int kisi;
public:
	double spaEkUcret = 0;
	void spa();
};

// Masaj Se�enekleri �le �lgili Bilgileri G�rd���m�z Ve Se�ti�imiz Metot
void Spa::spa() {
	int secim;
	cout << "\nMasaj Yapt�racak Ki�i Say�s�n� Giriniz : ";
	cin >> kisi;
	cout << "\n[1] Klasik Masaj(1000TL) : Sert vuru�lar e�li�inde dairesel hareketler ve ovma gibi hareketleri bar�nd�ran masaj t�r�d�r.\n"
		<< "\n[2] Thai Masaj�(1500TL) : V�cudumuzdaki esnekli�imizi artt�rmak, kas ve eklem gerilimini azaltmak ve v�cudun enerji"
		<< "\nsistemlerini dengelemek i�in pasif germe ve hafif bask�lar�n uyguland��� masaj t�r�d�r.\n"
		<< "\n[3] Refleseloji Masaji(2250TL) : Ayak refleksoloji masaj�, plantar fasiit, ayak bile�i yaralanmalar� gibi g�n"
		<< "i�erisinde \nspor  veya  i� yaparken ki�ileri rahatlatmak i�in uygulan�r.\n"
		<< "\n[4] Shiatsu Masaji(3000TL) : V�cudumuzun belirli b�lgelerine parmak yard�m�yla yap�lan bir masaj y�ntemidir.\n"
		<< "\n[5] Masaj Secenekleri Sekmesinden Cikis...";
	for(int i = 1; i <= kisi;i++){
		cout << "\nSeciminiz : ";
		cin >> secim;
		switch (secim) {
		case 1:
			cout << "\nKlasik Masaj Hizmeti Ald�n�z.\n";
			spaEkUcret += 1000;
			break;
		case 2:
			cout << "\nThai Masaj Hizmeti Ald�n�z.\n";
			spaEkUcret += 1500;
			break;
		case 3:
			cout << "\nRefleseloji Masaj Hizmeti Ald�n�z.\n";
			spaEkUcret += 2250;
			break;
		case 4:
			cout << "\nShiatsu Masaj Hizmeti Ald�n�z.\n";
			spaEkUcret += 3000;
			break;
		case 5:
			cout << "\n��k�� Yap�l�yor...\n";
			break;
		}
	}
}
