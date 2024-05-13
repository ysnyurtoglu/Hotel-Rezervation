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
	
	//Ba�lang�� �creti 
	double toplamFiyat = 0;
	
	// S�n�flardan Nesne Olu�turduk.
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
	musteri.kisiSayisi();	//Ki�i Say�s�n� Ve Ki�i Bilgilerini Girdi�imiz Metot
	rez.rYil();		//Rezervasyon Tarihi Girdi�imiz Metot

	//Kalaca��m�z G�ne G�re Toplam Konaklama �creti
	while (true) {
		cout << endl << endl << rez.gun << " G�nl�k Toplam Konaklama �creti : ";
		cout << musteri.araUcret() * rez.gun << endl;
		toplamFiyat = musteri.araUcret() * rez.gun;
		break;
	}
	oda.odaEkstraOzellik();		//Oda �zelli�i Se�ti�imiz Metot

	while (true) {

		cout << "\n[1] Ofis Hizmetleri\n[2] Tekne Turu\n[3] Spa Hizmetleri"
			<< "\n[4] Sa�l�k Hizmetleri\n[5] �ama��rhane Hizmeti"
			<< "\n[6] Etkinlikler\n[7] Special Yemekler\n[0] T�m ��lemleri Bitir...";
		cout << "\nYapmak �stedi�iniz ��lemi Se�iniz : ";
		int islem;
		cin >> islem;

		if (islem == 1) {
			cout << "\nOfis Hizmetleri Sekmesine Ho�geldiniz...\n";
			ofis.ofisHizmetleri();		//Ofis Hizmetleri Se�ti�imiz Metot
		}
		else if (islem == 2) {
			cout << "\nTekne Turu Gezi Sekmesine Ho�geldiniz...\n";
			tur.tekneTuru();	//Tekne Turu Se�eneklerini Se�ti�imiz Metot
		}
		else if (islem == 3) {
			cout << "\nSPA Sekmesine Ho�geldiniz...\n";
			spa.spa();		//Masaj Se�eneklerini Se�ti�imiz Metot
		}
		else if (islem == 4) {
			cout << "\nSa�l�k Hizmetlerine Sekmesine Ho�geldiniz...\n";
			hastane.saglikHizmetleri();		//Hastane Randevusu Ald���m�z Metot
		}
		else if (islem == 5) {
			cout << "\n�ama��rhane Hizmeti Sekmesine Ho�geldiniz...\n";
			camasirhane.secim();	// �ama��r Y�kama Hizmeti Se�ti�imiz Metot
		}
		else if (islem == 6) {
			cout << "\nEtkinlik Sekmesine Ho�geldiniz...\n";
			etkinlik.etkinlik();	//Etkinlik Se�ti�imiz Metot
		}
		else if (islem == 7) {
			cout << "\nSpecial Yemek Sekmesine Ho�geldiniz...\n";
			yemek.yemekSecimi();
		}
		else if (islem == 0) {

			// ��k��a Basana Kadar Yap�lan ��lemlerin Toplam �creti	
			try {
				if (toplamFiyat < 0)
					throw 99;
				toplamFiyat += oda.ekOzellikUcret + ofis.ofisEkUcret + tur.turEkUcret + spa.spaEkUcret + camasirhane.camasirUcreti +
					etkinlik.EtkinlikUcret + yemek.ekFiyat;
				cout << endl << "\nToplam Tutar : " << toplamFiyat << endl << endl;
			}
			catch (int hataKodu) {
				cout << "\nUcret 0'dan D���k Olamaz...\n\n";
			}
			break;
		}
		else{	
			cout << "\nHATALI ��LEM G�RD�N�Z..!\nTEKRAR DENEY�N�Z...";
		}
	}
	
}