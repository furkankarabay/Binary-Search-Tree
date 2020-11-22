/**
* @file VeriYapilariOdev3
* @description .txt dosyalarından okunan sayıları bst ağacına yerleştirip, her düğümün soy sayılarını hesaplayarak oynanan oyun.
* @course 2-A
* @assignment 3.Odev
* @date 11.12.2019
* @author Furkan Kemal Karabay furkan.karabay@ogr.sakarya.edu.tr || Emin Utku Mert utku.mert@ogr.sakarya.edu.tr
*/
#ifndef NODE_HPP
#define NODE_HPP

class node
{
public:
	int data;
	node* left;
	node* right;
	int soy_sayisi = 0;
	int temp = 0;
};

#endif