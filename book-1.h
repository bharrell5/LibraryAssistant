// File: book.h
// Programmer: 
// Class: COP 2931
// Description: This program simulates the checking out and checking in of books from a library

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book 
{
private:
	char title[30];
	char author[10];
	int bookID;
	int cardID;

public:
	Book();
	Book(char t[], char a[], int b, int c);
	int getCardID();
	void setCardID(int c);
	void print();

};
#endif