#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"
#include <chrono>	
using namespace std;

chrono::steady_clock::time_point begin;
chrono::steady_clock::time_point end;
chrono::steady_clock::duration elapsed;


int main()
{
	LinkedList *ll = new LinkedList();
	ll->olustur();
	for (int i = 0; i < 10000; i++)
	{
		ll->ekle(i, i);
	}
	//FOR COMPARİNG PERFORMANCE (MS DIFF)
	/*auto begin = std::chrono::high_resolution_clock::now();
	ll->ekle(22,9999);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	cout << "Bagli Liste 10000 eleman, sonuncu elemani Guncelleme suresi =>  " << elapsed.count()<< "  nano-saniye" << endl;
	*/

	ArrayList* al = new ArrayList();
	al->olustur();
	for (int i = 0; i < 10000; i++)
	{
		al->ekle(i,i);

	}



	return EXIT_SUCCESS;
}

