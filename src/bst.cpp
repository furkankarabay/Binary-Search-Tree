/**
* @file VeriYapilariOdev3
* @description .txt dosyalarından okunan sayıları bst ağacına yerleştirip, her düğümün soy sayılarını hesaplayarak oynanan oyun.
* @course 2-A
* @assignment 3.Odev
* @date 11.12.2019
* @author Furkan Kemal Karabay furkan.karabay@ogr.sakarya.edu.tr || Emin Utku Mert utku.mert@ogr.sakarya.edu.tr
*/
#include "bst.hpp"

node * BST::makeEmpty(node * altDugum)
{
	{
		if (altDugum == NULL) //durma noktası
			return NULL;
		{
			makeEmpty(altDugum->left);
			makeEmpty(altDugum->right);
			delete altDugum;
		}
		return NULL;
	}
}

node * BST::insert(int eleman, node * altDugum)
{
	//eleman ekleme işlemleri
	if (altDugum == NULL) //durma noktası
	{
		altDugum = new node; //yeni düğüm
		altDugum->data = eleman; 
		altDugum->left = altDugum->right = NULL;
	}
	else if (eleman < altDugum->data) //eleman düğümdeki sayıdan küçük ise
		altDugum->left = insert(eleman, altDugum->left);
	else if (eleman > altDugum->data) //eleman düğümdeki sayıdan büyük ise
		altDugum->right = insert(eleman, altDugum->right);
	else //eşit ise
		altDugum->left = insert(eleman, altDugum->left);
	return altDugum;
}

node * BST::enBuyukDegeriBul(node * altDugum)
{
	if (altDugum == NULL)
		return NULL;
	else if (altDugum->right == NULL) //düğümün sağı boş ise
		return altDugum;
	else //düğümün sağına gitmeye devam eder
		return enBuyukDegeriBul(altDugum->right);
}

node * BST::remove(int eleman, node * altDugum)
{
	//sildirme işlemleri
	node* temp;
	if (altDugum == NULL)
		return NULL;
	else if (eleman < altDugum->data)
		altDugum->left = remove(eleman, altDugum->left);
	else if (eleman > altDugum->data)
		altDugum->right = remove(eleman, altDugum->right);
	else if (altDugum->left && altDugum->right)
	{
		temp = enBuyukDegeriBul(altDugum->left);
		altDugum->data = temp->data;
		altDugum->left = remove(altDugum->data, altDugum->left);
	}
	else
	{
		temp = altDugum;
		if (altDugum->left == NULL)
			altDugum = altDugum->right;
		else if (altDugum->right == NULL)
			altDugum = altDugum->left;
		delete temp;
	}

	return altDugum;
}

int BST::soySayisiBul(node * root)
{
	if (!root)
	{
		return 0;
	}
	return 1 + soySayisiBul(root->left) + soySayisiBul(root->right);
}

void BST::postOrder(node * altDugum)
{
	if (!altDugum)
		return;

	altDugum->soy_sayisi = soySayisiBul(altDugum) - 1;

	toplamSoySayisi = toplamSoySayisi + altDugum->soy_sayisi;
	postOrder(altDugum->left);
	postOrder(altDugum->right);
	cout << "<" << altDugum->data << "," << altDugum->soy_sayisi << "> ";
}

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	root = makeEmpty(root);
}

void BST::insert(int eleman)
{
	root = insert(eleman, root);
}

void BST::remove(int eleman)
{
	root = remove(eleman, root);
}

void BST::ekranaYazdir()
{
	postOrder(root);
	cout << endl;
}

node * BST::maxSayiBul()
{
	if (!root)
	{
		cout << " BST bos!" << endl;
		return NULL;
	}
	node * treeNode = root;
	while (treeNode->right)
		treeNode = treeNode->right;
	return treeNode;
}

int BST::agacKokuGetir()
{
	node *treeNode = root;

	return treeNode->data;
}
