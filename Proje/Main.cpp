#include <iostream>
#include "Musteri.h"
#include "Rezervasyon.h"
#include "Oda.h"
#include "OtelBilgilendirme.h"
#include "OfisHizmetleri.h"
#include "Hastane.h"
#include "TekneTuru.h"
#include "Spa.h"
#include "Camasirhane.h"
#include "Etkinlikler.h"
#include "SpecialYemek.h"

using namespace std;

void run();


int main() {
	setlocale(LC_ALL, "turkish");
	
	run();
}


void run() {
	
	//Baþlangýç Ücreti 
	double toplamFiyat = 0;
	
	// Sýnýflardan Nesne Oluþturduk.
	OtelBilgilendirme bilgi; 
	Musteri musteri;
	Rezervasyon rez;
	Oda oda;
	Ofis ofis;
	Hastane hastane;
	TekneTuru tur;
	Spa spa;
	Camasirhane camasirhane;
	Etkinlikler etkinlik;
	SpecialYemek yemek;
	
	bilgi.bilgi();
	musteri.kisiSayisi();	//Kiþi Sayýsýný Ve Kiþi Bilgilerini Girdiðimiz Metot
	rez.rYil();		//Rezervasyon Tarihi Girdiðimiz Metot

	//Kalacaðýmýz Güne Göre Toplam Konaklama Ücreti
	while (true) {
		cout << endl << endl << rez.gun << " Günlük Toplam Konaklama Ücreti : ";
		cout << musteri.araUcret() * rez.gun << endl;
		toplamFiyat = musteri.araUcret() * rez.gun;
		break;
	}
	oda.odaEkstraOzellik();		//Oda Özelliði Seçtiðimiz Metot

	while (true) {

		cout << "\n[1] Ofis Hizmetleri\n[2] Tekne Turu\n[3] Spa Hizmetleri"
			<< "\n[4] Saðlýk Hizmetleri\n[5] Çamaþýrhane Hizmeti"
			<< "\n[6] Etkinlikler\n[7] Special Yemekler\n[0] Tüm Ýþlemleri Bitir...";
		cout << "\nYapmak Ýstediðiniz Ýþlemi Seçiniz : ";
		int islem;
		cin >> islem;

		if (islem == 1) {
			cout << "\nOfis Hizmetleri Sekmesine Hoþgeldiniz...\n";
			ofis.ofisHizmetleri();		//Ofis Hizmetleri Seçtiðimiz Metot
		}
		else if (islem == 2) {
			cout << "\nTekne Turu Gezi Sekmesine Hoþgeldiniz...\n";
			tur.tekneTuru();	//Tekne Turu Seçeneklerini Seçtiðimiz Metot
		}
		else if (islem == 3) {
			cout << "\nSPA Sekmesine Hoþgeldiniz...\n";
			spa.spa();		//Masaj Seçeneklerini Seçtiðimiz Metot
		}
		else if (islem == 4) {
			cout << "\nSaðlýk Hizmetlerine Sekmesine Hoþgeldiniz...\n";
			hastane.saglikHizmetleri();		//Hastane Randevusu Aldýðýmýz Metot
		}
		else if (islem == 5) {
			cout << "\nÇamaþýrhane Hizmeti Sekmesine Hoþgeldiniz...\n";
			camasirhane.secim();	// Çamaþýr Yýkama Hizmeti Seçtiðimiz Metot
		}
		else if (islem == 6) {
			cout << "\nEtkinlik Sekmesine Hoþgeldiniz...\n";
			etkinlik.etkinlik();	//Etkinlik Seçtiðimiz Metot
		}
		else if (islem == 7) {
			cout << "\nSpecial Yemek Sekmesine Hoþgeldiniz...\n";
			yemek.yemekSecimi();
		}
		else if (islem == 0) {

			// Çýkýþa Basana Kadar Yapýlan Ýþlemlerin Toplam Ücreti	
			try {
				if (toplamFiyat < 0)
					throw 99;
				toplamFiyat += oda.ekOzellikUcret + ofis.ofisEkUcret + tur.turEkUcret + spa.spaEkUcret + camasirhane.camasirUcreti +
					etkinlik.EtkinlikUcret + yemek.ekFiyat;
				cout << endl << "\nToplam Tutar : " << toplamFiyat << endl << endl;
			}
			catch (int hataKodu) {
				cout << "\nUcret 0'dan Düþük Olamaz...\n\n";
			}
			break;
		}
		else{	
			cout << "\nHATALI ÝÞLEM GÝRDÝNÝZ..!\nTEKRAR DENEYÝNÝZ...";
		}
	}
	
}