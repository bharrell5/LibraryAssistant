// File: card.h
// Programmer: Brett Harrell
// Class: COP 2931
// Description: This program simulates the checking out and checking in of books from a library

#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card
{
private:
	char name[20];
	char phone[20];
	int cardID;
	int bookID;

public:
	Card();
	Card(char n[], char p[], int b);
	int getBookID();
	void setBookID(int b);
	int getCardID();
	void print();
};
#endif
