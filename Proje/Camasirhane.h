#include <iostream>
#include <cstdlib> // Rastgele say� �retmek i�in
#include <ctime> // Zaman� rastgele say� �retmek i�in kullanmak i�in

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
        srand(time(NULL)); // Rastgele say� �retmek i�in zaman� kulland�k
        bosMakineSayisi = rand() % 16 + 5; // 5 ile 20 aras�nda rastgele bir say� olu�turduk
        birMakineFiyati = 100; // Her bir makine i�in belirlenen sabit fiyat
    }

    void bosMakineSayisiniYazdir() {   // Bu fonksiyonu bo� makine say�s�n� ekrana yazd�rmak i�in kulland�k
        cout << "Bo� �ama��r makinesi say�s� : " << bosMakineSayisi << endl;
    }

    void fiyatHesaplaVeYazdir() {      // �ama��rhane hizmeti i�in toplam fiyat� hesaplay�p ekrana yazd�rmak i�in kulland�k
        cout << "Ka� makine kullanmak istersiniz? ";  // M��teriden kullanmak istedi�i makine say�s�n� ald�k
        cin >> kullanilacakMakineSayisi;
        camasirUcreti = kullanilacakMakineSayisi * birMakineFiyati;   // Kullan�c�n�n girdi�i makine say�s�na g�re toplam fiyat� hesaplad�k
        cout << "�ama��rhane hizmeti icin toplam fiyat : " << camasirUcreti << " TL" << endl;
    }

    void cikis() {
        cout << "�ama��rhane Sekmesinden ��k�� Yap�l�yor...";
    }

    void secim() {
        bosMakineSayisiniYazdir();
        cout << "\n[1] �ama��r Y�kama Hizmetini Kullanma"
            << "\n[2] �ama��r Y�kama Sekmesinden ��k��...";
        cout << "\nSe�iminiz : ";
        int secim;
        cin >> secim;
        if (secim == 1) {
            fiyatHesaplaVeYazdir();
        }else if(secim == 2){
            cikis();
        }
        else {
            cout << "\nHATALI ��LEM..!\nTEKRAR DENEY�N�Z...";
        }

    }
};