#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hastane {
public:
    class Hasta {
    public:
        string ad;
        bool muayeneEdildi;

        Hasta(const string& isim) : ad(isim), muayeneEdildi(false) {}
    };

    class Doktor {
    public:
        string ad;
        bool bos;

        Doktor(const string& isim) : ad(isim), bos(true) {}

        void randevuAl(Hasta& hasta) {
            if (bos) {
                cout << ad << " Ýçin " << hasta.ad << " Hastasýna Randevu Aldýnýz." << endl;
                hasta.muayeneEdildi = true;
                bos = false;
            }
            else {
                cout << ad << " Doktoru þu anda dolu." << endl;
            }
        }

        ~Doktor() {};
    };

private:
    vector<Hasta> hastalar;
    vector<Doktor> doktorlar;
    bool doktorlarListelendi;

public:
    Hastane() {
        doktorlar.push_back(Doktor("[1] Dr.Mustafa"));
        doktorlar.push_back(Doktor("[2] Dr.Ahmet"));
        doktorlar.push_back(Doktor("[3] Dr.Ayþe"));
        doktorlarListelendi = false;
    }

    // Hasta Kayýt Ettirdiðimiz Metot
    void hastaEkle(const string& hastaAdi) {
        cout << "Hasta Adýný Giriniz : ";
        hastalar.push_back(Hasta(hastaAdi));
        cout << hastaAdi << " Hastasi Eklendi." << endl;
    }

    // Kaydý Yapýlan Hastalarý Gösterdiðimiz Metot
    void hastalariListele() {
        cout << "Hastanede Bekleyen Hastalar:" << endl;
        if (hastalar.empty()) {
            cout << "Bekleyen Hasta Bulunmamaktadýr." << endl;
        }
        else {
            for (size_t i = 0; i < hastalar.size(); ++i) {
                cout << i + 1 << ". " << hastalar[i].ad << " : " << (hastalar[i].muayeneEdildi ? "Muayene Edildi" : "Beklemede") << endl;
            }
        }
        cout << endl;
    }

    // Doktorlarý Gösterdiðimiz Metot
    void doktorlariListele() {
        cout << "Hastanedeki Doktorlar : " << endl;
        for (size_t i = 0; i < doktorlar.size(); ++i) {
            cout << i + 1 << ". " << doktorlar[i].ad << ": " << (doktorlar[i].bos ? "Boþ" : "Dolu") << endl;
        }
        cout << endl;
    }

    // Randevu Aldýðýmýz Metot
    void randevuAl() {
        hastalariListele();

        int doktorIndex;
        cout << "Randevu Almak Ýstediðiniz Doktorun Numarasýný Giriniz : ";
        cin >> doktorIndex;

        if (doktorIndex >= 1 && static_cast<size_t>(doktorIndex) <= doktorlar.size()) {
            if (!hastalar.empty()) {
                int hastaIndex;
                cout << "Randevu Almak Ýstediðiniz Hastanýn Numarasýný Giriniz : ";
                cin >> hastaIndex;

                if (hastaIndex >= 1 && static_cast<size_t>(hastaIndex) <= hastalar.size()) {
                    Hasta& secilenHasta = hastalar[hastaIndex - 1];
                    if (!secilenHasta.muayeneEdildi) {
                        doktorlar[doktorIndex - 1].randevuAl(secilenHasta);
                        hastalar.erase(hastalar.begin() + (hastaIndex - 1));
                    }
                    else {
                        cout << "Bu Hasta Zaten Muayene Edilmiþ." << endl;
                    }
                }
                else {
                    cout << "Geçersiz Hasta Numarasý..!" << endl;
                }
            }
            else {
                cout << "Randevu Alacak Hasta Bulunmamaktadir." << endl;
            }
        }
        else {
            cout << "Geçersiz Doktor Numarasý..!" << endl;
        }
    }

    void saglikHizmetleri() {
        while (true) {
            cout << "\nSaðlýk Hizmetleri : \n[1] Hasta Ekle\n[2] Hastalarý Listele\n[3] Doktorlarý Listele\n[4] Randevu Al\n[5] Çýkýþ";
            int secim;
            cout << "\nSeçiminiz : ";
            cin >> secim;

            if (secim == 5) {
                cout << "Saðlýk Hizmetleri Sonlandýrýldý." << endl;
                break;
            }
            else if (secim == 1) {
                string hastaAdi;
                cout << "Hasta Adýný Giriniz : ";
                cin >> hastaAdi;
                hastaEkle(hastaAdi);
            }
            else if (secim == 2) {
                hastalariListele();
            }
            else if (secim == 3) {
                if (!doktorlarListelendi) {
                    doktorlariListele();
                    doktorlarListelendi = true;
                }
            }
            else if (secim == 4) {
                randevuAl();
            }
            else {
                cout << "\nGeçersiz Bir Seçim Yaptýnýz. Tekrar deneyiniz." << endl;
            }
        }
    }
};

