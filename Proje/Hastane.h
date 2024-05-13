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
                cout << ad << " ��in " << hasta.ad << " Hastas�na Randevu Ald�n�z." << endl;
                hasta.muayeneEdildi = true;
                bos = false;
            }
            else {
                cout << ad << " Doktoru �u anda dolu." << endl;
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
        doktorlar.push_back(Doktor("[3] Dr.Ay�e"));
        doktorlarListelendi = false;
    }

    // Hasta Kay�t Ettirdi�imiz Metot
    void hastaEkle(const string& hastaAdi) {
        cout << "Hasta Ad�n� Giriniz : ";
        hastalar.push_back(Hasta(hastaAdi));
        cout << hastaAdi << " Hastasi Eklendi." << endl;
    }

    // Kayd� Yap�lan Hastalar� G�sterdi�imiz Metot
    void hastalariListele() {
        cout << "Hastanede Bekleyen Hastalar:" << endl;
        if (hastalar.empty()) {
            cout << "Bekleyen Hasta Bulunmamaktad�r." << endl;
        }
        else {
            for (size_t i = 0; i < hastalar.size(); ++i) {
                cout << i + 1 << ". " << hastalar[i].ad << " : " << (hastalar[i].muayeneEdildi ? "Muayene Edildi" : "Beklemede") << endl;
            }
        }
        cout << endl;
    }

    // Doktorlar� G�sterdi�imiz Metot
    void doktorlariListele() {
        cout << "Hastanedeki Doktorlar : " << endl;
        for (size_t i = 0; i < doktorlar.size(); ++i) {
            cout << i + 1 << ". " << doktorlar[i].ad << ": " << (doktorlar[i].bos ? "Bo�" : "Dolu") << endl;
        }
        cout << endl;
    }

    // Randevu Ald���m�z Metot
    void randevuAl() {
        hastalariListele();

        int doktorIndex;
        cout << "Randevu Almak �stedi�iniz Doktorun Numaras�n� Giriniz : ";
        cin >> doktorIndex;

        if (doktorIndex >= 1 && static_cast<size_t>(doktorIndex) <= doktorlar.size()) {
            if (!hastalar.empty()) {
                int hastaIndex;
                cout << "Randevu Almak �stedi�iniz Hastan�n Numaras�n� Giriniz : ";
                cin >> hastaIndex;

                if (hastaIndex >= 1 && static_cast<size_t>(hastaIndex) <= hastalar.size()) {
                    Hasta& secilenHasta = hastalar[hastaIndex - 1];
                    if (!secilenHasta.muayeneEdildi) {
                        doktorlar[doktorIndex - 1].randevuAl(secilenHasta);
                        hastalar.erase(hastalar.begin() + (hastaIndex - 1));
                    }
                    else {
                        cout << "Bu Hasta Zaten Muayene Edilmi�." << endl;
                    }
                }
                else {
                    cout << "Ge�ersiz Hasta Numaras�..!" << endl;
                }
            }
            else {
                cout << "Randevu Alacak Hasta Bulunmamaktadir." << endl;
            }
        }
        else {
            cout << "Ge�ersiz Doktor Numaras�..!" << endl;
        }
    }

    void saglikHizmetleri() {
        while (true) {
            cout << "\nSa�l�k Hizmetleri : \n[1] Hasta Ekle\n[2] Hastalar� Listele\n[3] Doktorlar� Listele\n[4] Randevu Al\n[5] ��k��";
            int secim;
            cout << "\nSe�iminiz : ";
            cin >> secim;

            if (secim == 5) {
                cout << "Sa�l�k Hizmetleri Sonland�r�ld�." << endl;
                break;
            }
            else if (secim == 1) {
                string hastaAdi;
                cout << "Hasta Ad�n� Giriniz : ";
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
                cout << "\nGe�ersiz Bir Se�im Yapt�n�z. Tekrar deneyiniz." << endl;
            }
        }
    }
};

