#include <iostream>
#include <cstdlib> // Rastgele sayý üretmek için
#include <ctime> // Zamaný rastgele sayý üretmek için kullanmak için

using namespace std;

class Camasirhane {
private:
    int bosMakineSayisi;
    int birMakineFiyati;
    int kullanilacakMakineSayisi;
public:
    int camasirUcreti = 0;
    // Constructor
    Camasirhane() {
        srand(time(NULL)); // Rastgele sayý üretmek için zamaný kullandýk
        bosMakineSayisi = rand() % 16 + 5; // 5 ile 20 arasýnda rastgele bir sayý oluþturduk
        birMakineFiyati = 100; // Her bir makine için belirlenen sabit fiyat
    }

    void bosMakineSayisiniYazdir() {   // Bu fonksiyonu boþ makine sayýsýný ekrana yazdýrmak için kullandýk
        cout << "Boþ çamaþýr makinesi sayýsý : " << bosMakineSayisi << endl;
    }

    void fiyatHesaplaVeYazdir() {      // Çamaþýrhane hizmeti için toplam fiyatý hesaplayýp ekrana yazdýrmak için kullandýk
        cout << "Kaç makine kullanmak istersiniz? ";  // Müþteriden kullanmak istediði makine sayýsýný aldýk
        cin >> kullanilacakMakineSayisi;
        camasirUcreti = kullanilacakMakineSayisi * birMakineFiyati;   // Kullanýcýnýn girdiði makine sayýsýna göre toplam fiyatý hesapladýk
        cout << "Çamaþýrhane hizmeti icin toplam fiyat : " << camasirUcreti << " TL" << endl;
    }

    void cikis() {
        cout << "Çamaþýrhane Sekmesinden Çýkýþ Yapýlýyor...";
    }

    void secim() {
        bosMakineSayisiniYazdir();
        cout << "\n[1] Çamaþýr Yýkama Hizmetini Kullanma"
            << "\n[2] Çamaþýr Yýkama Sekmesinden Çýkýþ...";
        cout << "\nSeçiminiz : ";
        int secim;
        cin >> secim;
        if (secim == 1) {
            fiyatHesaplaVeYazdir();
        }else if(secim == 2){
            cikis();
        }
        else {
            cout << "\nHATALI ÝÞLEM..!\nTEKRAR DENEYÝNÝZ...";
        }

    }
};