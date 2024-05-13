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
            cout << "Ofis " << ofisOdaNo << " Bu Ofis Rezerve Edilmiþ." << endl;
        }
    }

    void iptalEt() {
        if (rezervli) {
            rezervli = false;
            cout << "Ofis " << ofisOdaNo << " Rezervasyon Ýptal Edildi." << endl;
        }
        else {
            cout << "Ofis " << ofisOdaNo << " Bu Ofis Rezerve Edilmemiþ." << endl;
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

    // Ofis Odalarýný Gösterdiðimiz Metot
    void odalariListele() {
        cout << "Oteldeki Ofisler : " << endl;
        for (const auto& oda : odalar) {
            cout << "Ofis " << oda.ofisOdaNo << ": " << (oda.rezervli ? "Rezerve Edildi" : "Boþ") << endl;
        }
        cout << endl;
    }

    // Ofis Odalarýný Seçtiðimiz Metot
    void rezervasyonYap() {
        int odaNumarasi;
        cout << "Rezerve Etmek istediginiz Ofis Numarasýný Giriniz : ";
        cin >> odaNumarasi;

        if (odaNumarasi > 0 && odaNumarasi <= odalar.size()) {
            odalar[odaNumarasi - 1].rezervEt();
            ofisEkUcret += 5000;
        }
        else {
            cout << "\nGeçersiz Ofis Numarasý..!" << endl;
        }
    }

    // Rezerve Ettiðimiz Ofis Odalarýný Ýptal Edebildiðimiz Metot
    void rezervasyonIptalEt() {
        int odaNumarasi;
        cout << "Ýptal Etmek Ýstediginiz Ofis Numarasini Giriniz : ";
        cin >> odaNumarasi;

        if (odaNumarasi > 0 && odaNumarasi <= odalar.size()) {
            odalar[odaNumarasi - 1].iptalEt();
            ofisEkUcret -= 5000;
        }
        else {
            cout << "Geçersiz Ofis Numarasý..!" << endl;
        }
    }

    // Ofis Hizmetleri Sekmesinden Seçim Yaptýðýmýz Metot
    void ofisHizmetleri() {
        while (true) {
            cout << "\nOfis Hizmetleri...\n[1] Ofisleri Listele\n[2] Rezervasyon Yap\n[3] Ýptal Et\n[4] Çýkýþ" << endl;
            int secim;
            cout << "\nSeçiminiz : ";
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
                cout << "\nGeçersiz Bir Seçim Yaptýnýz. Tekrar Deneyiniz..." << endl;
            }
        }
    }
};

