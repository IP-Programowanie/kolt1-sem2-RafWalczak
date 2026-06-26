#include "Wybor.h"
#include "PK1_kolA.h"
#include <bitset>
#include <cstdio>
using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczać pomiędzy #ifdef a #endif. 
*/

#ifdef Kol_1
namespace maskiBitowe {
	enum maski :uint32_t {
		mLiczba = 0xFFFFu << 15,
		mSymbol = 0xFFu<<1,
		mAktywna = 0x01u<<12,
		mWczytana = 0x01u<<9,
		mObliczona = 0x01u<<13,
		mEstymowana = 0x01u<<11
	};
}
uint32_t kompresuj(const Dane& d) {
	uint32_t skompresowane = 0;
	skompresowane |= (static_cast<uint32_t>(d.liczba) << 15) & maskiBitowe::mLiczba;
	skompresowane |= (static_cast<uint32_t>(d.symbol) << 1) & maskiBitowe::mSymbol;
	skompresowane |= (static_cast<uint32_t>(d.aktywna) << 12) & maskiBitowe:: mAktywna;
	skompresowane |= (static_cast<uint32_t>(d.wczytana) << 9) & maskiBitowe::mWczytana;
	skompresowane |= (static_cast<uint32_t>(d.obliczona) << 13) & maskiBitowe::mObliczona;
	skompresowane |= (static_cast<uint32_t>(d.estymowana) << 11) & maskiBitowe::mEstymowana;
	return skompresowane;
}
Dane dekompresuj(uint32_t skompresowane) {
	Dane d;
	d.liczba = (skompresowane & maskiBitowe::mLiczba) >> 15;
	d.symbol = (skompresowane & maskiBitowe::mSymbol) >> 1;
	d.aktywna = (skompresowane & maskiBitowe::mAktywna) >> 12;
	d.wczytana = (skompresowane & maskiBitowe::mWczytana) >> 9;
	d.obliczona = (skompresowane & maskiBitowe::mObliczona) >> 13;
	d.estymowana = (skompresowane & maskiBitowe::mEstymowana) >> 11;
	return d;
}
void ustawLiczba(uint32_t& skompresowane) {
	skompresowane &= ~maskiBitowe::mLiczba;
}

size_t odczytajRozmiar(const uint32_t* wsk) {
	if (wsk == nullptr)return 0;
	return static_cast<size_t>(wsk[-1]);
}

void modyfikuj(uint32_t* wsk, size_t indeks, uint32_t nowa_wartosc) {
	size_t max_rozmiar = odczytajRozmiar(wsk);
	if (indeks >= max_rozmiar) {
		throw out_of_range("");
	}
	wsk[indeks] = nowa_wartosc;
}
void modyfikuj(uint32_t* wsk, size_t indeks, const Dane& nowe_dane) {
	uint32_t skompresowane = kompresuj(nowe_dane);
	modyfikuj(wsk, indeks, skompresowane);
}
FILE* plik = fopen("zapis.txt", "w+b");
fwrite();
int main()
{
	 
}

#endif
