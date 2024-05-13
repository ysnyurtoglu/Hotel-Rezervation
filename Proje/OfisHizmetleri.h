#include <iostream>
#include <vector>
#include <string>

using namespace std;

class OfisHizmetleri {
public:
    int ofisOdaNo;
    bool rezervli;

    OfisHizmetleri(int numara) : ofisOdaNo(numara), rezervli(false) {}

    void rezervEt() {
        if (!rezervli) {
            rezervli = true;
            cout << "Ofis " << ofisOdaNo << " Rezerve Edildi." << endl;
        }
        else {
            cout << "Ofis " << ofisOdaNo << " Bu Ofis Rezerve Edilmi�." << endl;
        }
    }

    void iptalEt() {
        if (rezervli) {
            rezervli = false;
            cout << "Ofis " << ofisOdaNo << " Rezervasyon �ptal Edildi." << endl;
        }
        else {
            cout << "Ofis " << ofisOdaNo << " Bu Ofis Rezerve Edilmemi�." << endl;
        }
    }
};

class Ofis {
private:
    vector<OfisHizmetleri> odalar;

public:
    double ofisEkUcret = 0;
    static const int Sabit_Oda_Sayisi = 5;

    Ofis() {
        for (int i = 1; i <= Sabit_Oda_Sayisi; ++i) {
            odalar.push_back(OfisHizmetleri(i));
        }
    }

    // Ofis Odalar�n� G�sterdi�imiz Metot
    void odalariListele() {
        cout << "Oteldeki Ofisler : " << endl;
        for (const auto& oda : odalar) {
            cout << "Ofis " << oda.ofisOdaNo << ": " << (oda.rezervli ? "Rezerve Edildi" : "Bo�") << endl;
        }
        cout << endl;
    }

    // Ofis Odalar�n� Se�ti�imiz Metot
    void rezervasyonYap() {
        int odaNumarasi;
        cout << "Rezerve Etmek istediginiz Ofis Numaras�n� Giriniz : ";
        cin >> odaNumarasi;

        if (odaNumarasi > 0 && odaNumarasi <= odalar.size()) {
            odalar[odaNumarasi - 1].rezervEt();
            ofisEkUcret += 5000;
        }
        else {
            cout << "\nGe�ersiz Ofis Numaras�..!" << endl;
        }
    }

    // Rezerve Etti�imiz Ofis Odalar�n� �ptal Edebildi�imiz Metot
    void rezervasyonIptalEt() {
        int odaNumarasi;
        cout << "�ptal Etmek �stediginiz Ofis Numarasini Giriniz : ";
        cin >> odaNumarasi;

        if (odaNumarasi > 0 && odaNumarasi <= odalar.size()) {
            odalar[odaNumarasi - 1].iptalEt();
            ofisEkUcret -= 5000;
        }
        else {
            cout << "Ge�ersiz Ofis Numaras�..!" << endl;
        }
    }

    // Ofis Hizmetleri Sekmesinden Se�im Yapt���m�z Metot
    void ofisHizmetleri() {
        while (true) {
            cout << "\nOfis Hizmetleri...\n[1] Ofisleri Listele\n[2] Rezervasyon Yap\n[3] �ptal Et\n[4] ��k��" << endl;
            int secim;
            cout << "\nSe�iminiz : ";
            cin >> secim;

            if (secim == 4) {
                cout << "\nOfis hizmetleri sonlandirildi." << endl;
                break;
            }
            else if (secim == 1) {
                odalariListele();
            }
            else if (secim == 2) {
                rezervasyonYap();
            }
            else if (secim == 3) {
                rezervasyonIptalEt();
            }
            else {
                cout << "\nGe�ersiz Bir Se�im Yapt�n�z. Tekrar Deneyiniz..." << endl;
            }
        }
    }
};

