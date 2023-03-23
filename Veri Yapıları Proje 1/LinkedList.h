#pragma once
using namespace std;

struct Node {
	int deger;						//d���m�n say�sal de�eri
	Node* sonraki; 			  		//sonraki d���me i�aret�i
};

struct LinkedList {
	Node* bas;						//listenin ba�lang�� adresini tutar
	void olustur();					//ba�lang�� i�in gereken tan�mlar� i�erir
	void ekle(int, int);			//de�er ve s�ra numaras� alarak ekleme yapar
	void guncelle(int, int);		//de�er ve s�ra numaras� alarak g�nceller
	void sil(int);					//s�ra numaras� alarak silme yapar
	void yazdir();					//liste i�eri�ini ekrana yazar
	void bosalt();					//listenin bellek alanlar�n� iade eder
	int sayac;						//liste ka� eleman oldu�unu tutar
};

void LinkedList::olustur() {
	bas = NULL;
	sayac = 0;
}

void LinkedList::ekle(int eklenecek_deger, int sayi) {


	if (sayi == 0)
	{
		if (bas = NULL)
		{
			bas = new Node();
			bas->deger = eklenecek_deger;
		}

		else
		{
			Node* n = new Node();
			n->deger = eklenecek_deger;
			n->sonraki = bas;
			bas = n;
		}
		sayac++;
	}

	else
	{
		Node* n = new Node();
		n->deger = eklenecek_deger;

		Node* tara;
		tara = bas;
		for (int i = 0; i < sayi - 1; i++)
		{
			tara = tara->sonraki;
		}
		n->sonraki = tara->sonraki;
		tara->sonraki = n;
		sayac++;
	}
}

inline void LinkedList::guncelle(int deger, int sayi)
{
	Node* tara = bas;
	for (int i = 0; i < sayi; i++)
	{
		tara = tara->sonraki;
	}
	tara->deger = deger;
}

inline void LinkedList::sil(int sayi)
{
	if (sayi == 0)
	{
		if (bas = NULL)
		{

		}

		else
		{
			Node* n;
			n = bas;
			bas = bas->sonraki;
			delete[] n;
		}
		sayac--;
	}

	else
	{
		Node* n;

		Node* tara;
		tara = bas;
		for (int i = 0; i < sayi-1; i++)
		{
			tara = tara->sonraki;
		}
		n = tara->sonraki;
		tara->sonraki = tara->sonraki->sonraki;
		delete[] n;
		sayac--;
	}
}


void LinkedList::yazdir() {
	struct Node* tara = bas;

	while (tara != NULL)
	{
		cout << tara->deger << " ";
		tara = tara->sonraki;
	}
	cout << "Listede " << sayac << " tane eleman var." << endl;
	cout << endl;
}

inline void LinkedList::bosalt()
{
	delete[] bas;
}
