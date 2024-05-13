#include <iostream>
#include <string>

using namespace std;

class OtelBilgilendirme{
public:
	void bilgi();
};

void OtelBilgilendirme::bilgi() {
	cout << "*********** OTELÝMÝZE HOÞGELDÝNÝZ ***********";

	cout << "\nGünlük Kiþi Baþý Ücretimiz : 2000TL\n";

	cout << "\n***** Otelimizde Bulunan Hizmetler *****";
	cout << "\nAçýk Havuz\nKapalý Havuz\nOtopark\nSpor Salonu\nÜcretsiz WiFi"
		<< "\nOda Servisi\nKafe/Bar\nAçýk Büfe\nHayvan Dostu\nSaðlýk Hizmetleri\n";

	cout << "\n***** Otelimizde Bulunan Ekstra Hizmetler *****";
	cout << "\nSPA\nTekne Turu\nOfis Hizmetleri\nOyun Parký\n";
}

