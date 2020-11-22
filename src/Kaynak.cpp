/**
* @file VeriYapilariOdev3
* @description .txt dosyalarından okunan sayıları bst ağacına yerleştirip, her düğümün soy sayılarını hesaplayarak oynanan oyun.
* @course 2-A
* @assignment 3.Odev
* @date 11.12.2019
* @author Furkan Kemal Karabay furkan.karabay@ogr.sakarya.edu.tr || Emin Utku Mert utku.mert@ogr.sakarya.edu.tr
*/
#include <fstream>
#include <conio.h>
#include "bst.hpp"

using namespace std;

int main()
{
	BST *benim = new BST;
	BST *rakip = new BST;
	ifstream benimInfile("benim.txt");
	ifstream rakipInfile("rakip.txt");

	int benimSayilar[10000];
	int rakipSayilar[10000];

	int benimSkor = 0;
	int rakipSkor = 0;
	
	int i = 0;
	while (benimInfile >> benimSayilar[i]) //dosyadan okuma işlemleri.
	{
		benim->insert(benimSayilar[i]);
		i++;
	}
	
	int j = 0;
	while (rakipInfile >> rakipSayilar[j])//dosyadan okuma işlemleri.
	{
		rakip->insert(rakipSayilar[j]);
		j++;
	}
	

	
	cout << "Benim Agac Postorder :" << endl;
	benim->ekranaYazdir();

	cout << "Benim agac toplam soy sayisi : " << benim->toplamSoySayisi << endl;
	cout << "-----------------------" << endl << endl;


	cout << "Rakip Agac Postorder :" << endl;
	rakip->ekranaYazdir();

	
	cout << "Rakip agac toplam soy sayisi : " << rakip->toplamSoySayisi << endl << endl;

	int kontrol;

	int turSayisi = 0;
	while (true) //klavyeden tuşa basıldıkça devam eder.
	{	

		node *benimMax = benim->maxSayiBul();
		node *rakipMax = rakip->maxSayiBul();

		if (benim->toplamSoySayisi > rakip->toplamSoySayisi)
		{
			cout << "-- TURU KAYBETTINIZ --" << endl;

			rakipSkor = rakipSkor + 1;

			rakip->insert(benimMax->data);
			benim->remove(benimMax->data);

			benim->insert(rakip->agacKokuGetir());
			rakip->remove(rakip->agacKokuGetir());

			benim->toplamSoySayisi = 0;
			rakip->toplamSoySayisi = 0;
		}
		else if (benim->toplamSoySayisi < rakip->toplamSoySayisi)
		{
			cout << "-- TEBRIKLER TURU KAZANDINIZ --" << endl;

			benimSkor = benimSkor + 1;

			benim->insert(rakipMax->data);
			rakip->remove(rakipMax->data);

			rakip->insert(benim->agacKokuGetir());
			benim->remove(benim->agacKokuGetir());
			benim->toplamSoySayisi = 0;
			rakip->toplamSoySayisi = 0;
		}
		else
		{
			benim->insert(rakip->agacKokuGetir());
			rakip->insert(benim->agacKokuGetir());
			benim->remove(benim->agacKokuGetir());
			rakip->remove(rakip->agacKokuGetir());

			cout << "BERABERE" << endl;

			benim->toplamSoySayisi = 0;
			rakip->toplamSoySayisi = 0;
		}
		
		if (rakipSkor == 5)
		{
			cout << "---SON SKOR---" << endl;
			cout << "Benim : " << benimSkor << endl;
			cout << "Rakip : " << rakipSkor << endl << endl;
			cout << "---RAKIP KAZANDI--- " << endl;
			break;
		}
		else if (benimSkor == 5)
		{
			cout << "---SON SKOR---" << endl;
			cout << "Benim : " << benimSkor << endl;
			cout << "Rakip : " << rakipSkor << endl << endl;
			cout << "---TEBRIKLER KAZANDINIZ--- " << endl;
			break;
		}

		cout << "Benim : " << benimSkor << endl;
		cout << "Rakip : " << rakipSkor << endl << endl;
		kontrol = _getch();

		cout << "Benim Agac Postorder :" << endl;
		benim->ekranaYazdir();

		cout << "Benim agac toplam soy sayisi : " << benim->toplamSoySayisi << endl;
		cout << "-----------------------" << endl << endl;


		cout << "Rakip Agac Postorder :" << endl;
		rakip->ekranaYazdir();

		cout << "Rakip agac toplam soy sayisi : " << rakip->toplamSoySayisi << endl << endl;


		turSayisi++;

		if (turSayisi == 21)
		{
			if (rakipSkor > benimSkor)
			{
				cout << "---SON SKOR---" << endl;
				cout << "Benim : " << benimSkor << endl;
				cout << "Rakip : " << rakipSkor << endl << endl;
				cout << "---RAKIP KAZANDI--- " << endl;
			}
			else if (rakipSkor < benimSkor)
			{
				cout << "---SON SKOR---" << endl;
				cout << "Benim : " << benimSkor << endl;
				cout << "Rakip : " << rakipSkor << endl << endl;
				cout << "---TEBRIKLER KAZANDINIZ--- " << endl;
			}
			else
			{
				cout << "---SON SKOR---" << endl;
				cout << "Benim : " << benimSkor << endl;
				cout << "Rakip : " << rakipSkor << endl << endl;
				cout << "---BERABERE BITTI---" << endl;
			}
			delete rakipMax, benimMax;
			break;
		}

	}
	
	delete benim,rakip;

	system("pause");
	return 0;
}