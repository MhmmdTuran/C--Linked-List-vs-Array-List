#pragma once
using namespace std;

struct Node {
	int deger;						//düðümün sayýsal deðeri
	Node* sonraki; 			  		//sonraki düðüme iþaretçi
};

struct LinkedList {
	Node* bas;						//listenin baþlangýç adresini tutar
	void olustur();					//baþlangýç için gereken tanýmlarý içerir
	void ekle(int, int);			//deðer ve sýra numarasý alarak ekleme yapar
	void guncelle(int, int);		//deðer ve sýra numarasý alarak günceller
	void sil(int);					//sýra numarasý alarak silme yapar
	void yazdir();					//liste içeriðini ekrana yazar
	void bosalt();					//listenin bellek alanlarýný iade eder
	int sayac;						//liste kaç eleman olduðunu tutar
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
