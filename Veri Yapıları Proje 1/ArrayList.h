
#include <stdio.h>
#include <iostream>
using namespace std;

struct ArrayList {
    int* bas;                   //dizinin baþlangýç adresini tutar
    void olustur();             //baþlangýç için gereken tanýmlarý içerir
    void ekle(int, int);        //deðer ve sýra numarasý alarak ekleme yapar
    void guncelle(int, int);    //deðer ve sýra numarasý alarak günceller
    void sil(int);              //sýra numarasý alarak silme yapar
    void yazdir();              //liste içeriðini ekrana yazar
    void bosalt();              //listenin bellek alanlarýný iade eder
    int sayac;                  //liste kaç eleman olduðunu tutar
};



void ArrayList::olustur() {
	bas = NULL;
	sayac = 0;


}

void ArrayList::ekle(int deger, int sira) {
	int* dizi;
	dizi = new int[++sayac];
	
	if (bas==NULL)
	{
		dizi[0] = deger;
	}
	else
	{
		for (int i = 0; i < sayac; i++)
		{
			if (i >= sira)
			{
				dizi[i] = *(bas + i - 1);
			}
			else if (sira - 1 == i)
			{
				dizi[i] = deger;
			}
			else
			{
				dizi[i] = *(bas + i);
			}
		}
	}
	bosalt();
	bas = dizi;

}

void ArrayList::guncelle(int deger, int siraNo) {
	*(bas + siraNo - 1) = deger;
}

void ArrayList::sil(int siraNo) {

	for (int i = 0; i < sayac; i++)
	{
		if (i >= siraNo - 1) {
			*(bas + i) = *(bas + i + 1);
		}

	}
	sayac--;
}

void ArrayList::yazdir() {
	for (int i = 0; i < sayac; i++)
	{
		cout  << *(bas + i) << " ";
	}
	cout << endl << "Eleman Sayisi : " << sayac << endl;
}

void ArrayList::bosalt() {
	delete[] bas;
}