#include <iostream>
#include <string>

using namespace std;

class OtelBilgilendirme{
public:
	void bilgi();
};

void OtelBilgilendirme::bilgi() {
	cout << "*********** OTEL�M�ZE HO�GELD�N�Z ***********";

	cout << "\nG�nl�k Ki�i Ba�� �cretimiz : 2000TL\n";

	cout << "\n***** Otelimizde Bulunan Hizmetler *****";
	cout << "\nA��k Havuz\nKapal� Havuz\nOtopark\nSpor Salonu\n�cretsiz WiFi"
		<< "\nOda Servisi\nKafe/Bar\nA��k B�fe\nHayvan Dostu\nSa�l�k Hizmetleri\n";

	cout << "\n***** Otelimizde Bulunan Ekstra Hizmetler *****";
	cout << "\nSPA\nTekne Turu\nOfis Hizmetleri\nOyun Park�\n";
}

