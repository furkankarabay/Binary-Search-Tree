/**
* @file VeriYapilariOdev3
* @description .txt dosyalarından okunan sayıları bst ağacına yerleştirip, her düğümün soy sayılarını hesaplayarak oynanan oyun.
* @course 2-A
* @assignment 3.Odev
* @date 11.12.2019
* @author Furkan Kemal Karabay furkan.karabay@ogr.sakarya.edu.tr || Emin Utku Mert utku.mert@ogr.sakarya.edu.tr
*/
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include "node.hpp"

using namespace std;

class BST { 

	node* root;

	node* makeEmpty(node* altDugum); //Ağaçtaki düğümleri siler.

	node* insert(int eleman, node* altDugum); //Ağaca eleman ekler

	node* enBuyukDegeriBul(node* altDugum); //Ağaçtaki en büyük değeri bulur.

	node* remove(int eleman, node* altDugum); //Silinmek istenen sayıyı siler.

	int soySayisiBul(node *root); //Düğümün soy sayısını hesaplar.

	void postOrder(node * altDugum); //Postorder dolaşım yapar.

public:

	int toplamSoySayisi = 0;

	BST(); //Düğüm oluşturur.

	~BST(); //MakeEmpty fonksiyonunu çağırıp temizler.

	void insert(int eleman);

	void remove(int eleman);

	void ekranaYazdir(); //Postorder dolaşımla ekrana yazdırır.

	node* maxSayiBul(); 

	int agacKokuGetir();

};


#endif