// File: Library.cpp

// Programmer: Brett Harrell

// Class: COP 2931

// Description: This program simulates the checking out and checking in of books from a library


#include <iostream>
#include <fstream>
#include <iomanip>
#include "Book.h"
#include "Card.h"
using namespace std;

Card CreateCard(char name[], char phone[], int CardID);
Book CreateBook(char title[], char author[], int BookID);
void CheckOutBooks(Book books[], Card cards[], int numBooks, int numCards);
void CheckInBook(Book books[], Card cards[], int numBooks, int numCards);

void ShowMenu()
{
	cout << "====[ M A I N  M E N U ]====" << endl;
	cout << "1. Show all library cards   " << endl;
	cout << "2. Show all books           " << endl;
	cout << "3. Check out a book         " << endl;
	cout << "4. Check in a book          " << endl;
	cout << "5. Create a new library card" << endl;
	cout << "0. Exit the system          " << endl;

}

int main()
{
	ShowMenu();
	int command = 0;

	// declare an array of 20 cards
	Card cards[20];
	int numCards = 0;

	// declare an array of 20 books--------------------------------------------
	Book books[20];
	int numBooks = 0;

	// declare a file pointer and open the cards file 
	cout << "Opening file cards.txt..." << endl;
	ifstream cardInput("cards.txt");
	if (!cardInput)
	{
		cout << "System ERROR: Cards.txt file not found." << endl;
		system("pause");
		exit(1);
	}
	cout << "Reading file cards.txt..." << endl;

	// read the next line from the file
	char name[20];
	char phone[20];
	int cardID = 0;
	char junk[10];

	cardInput.getline(name, 19, ',');
	while (cardInput)
	{
		cardInput.getline(junk, 5, ' ');
		cardInput.getline(phone, 15, ',');
		cardInput.getline(junk, 5, ' ');
		cardInput >> cardID;
		cardInput.getline(junk, 5, '\n');

		//Create new card
		cards[numCards] = CreateCard(name, phone, cardID);
		numCards++;

		cardInput.getline(name, 19, ',');
	}

	
	// declare a file pointer and open the books file ----------------------------------------
	cout << "Opening file books.txt..." << endl;
	ifstream bookInput("books.txt");
	if (!bookInput)
	{
		cout << "System ERROR: book.txt not found." << endl;
		system("pause");
		exit(1);
	}
	cout << "Reading file books.txt..." << endl;

	// read the next line from the file--------------------------------------------------
	char title[30];
	char author[30];
	int bookID = 0;

	bookInput.getline(title, 29, ',');
	while (bookInput)
	{
		bookInput.getline(junk, 9, ' ');
		bookInput.getline(author, 29, ',');
		bookInput.getline(junk, 9, ' ');
		bookInput >> bookID;
		bookInput.getline(junk, 9, '\n');

		//create a new book
		books[numBooks] = CreateBook(title, author, bookID);
		numBooks++;

		bookInput.getline(title, 29, ',');
	}

	

	// display main menu
	void ShowMenu();
	cout << "Enter a command or 0 to quit." << endl;
	cin >> command;

	while (command != 0)
	{
		switch (command)
		{
		case 1:
			for (int i = 0; i < numCards; i++)
			{
				cards[i].print();
			}
			break;
		case 2:
			for (int i = 0; i < numBooks; i++)
			{
				books[i].print();
			}
			break;
		case 3:
			CheckOutBooks(books, cards, numBooks, numCards);
			break;
		case 4:
			CheckInBook(books, cards, numBooks, numCards);
			break;
		case 5:
			CreateCard(name, phone, cardID);
			break;
		}

		ShowMenu();
		cout << "Enter a command or 0 to quit." << endl;
		cin >> command;
	}

}


// create a card and store it in the array of cards

Card CreateCard(char name[], char phone[], int CardID)
{
	Card temp(name, phone, CardID);
	return temp;
}

//create a book and store it in the array of books

Book CreateBook(char title[], char author[], int BookID)
{
	Book temp(title, author, BookID);
	return temp;
}

void CheckOutBooks(Book books[], Card cards[], int numBooks, int numCards)
{
	int bookID = 0, cardID = 0;
	int card = 0, book = 0;

	//Get cardid
	cout << "Enter the card ID: " << endl;
	cin >> cardID;

	//search for cardid
	while (card < numCards && cardID != cards[card].getCardID())
	{
		card++;
	}

	//if not found, return
	if (card == numCards)
	{
		cout << "ERROR: Card not found." << endl;
		return;
	}

	//if found, do they have a book
	if (cards[card].getBookID() != 0)
	{
		cout << "ERROR: You must check in your book first." << endl;
		return;
	}


	//Get bookid
	cout << "Enter the book ID: " << endl;
	cin >> bookID;

	//search for bookid
	while (book < numBooks && bookID != books[book].getBookID())
	{
		book++;
	}

	//if not found, return
	if (book == numBooks)
	{
		cout << "ERROR: Book not found." << endl;
		return;
	}

	//if found, is it checked out
	if (books[book].getCardID() != 0)
	{
		cout << "ERROR: Book is already checked out." << endl;
		return;
	}

	cards[card].setBookID(bookID);
	books[book].setCardID(cardID);
}

void CheckInBook(Book books[], Card cards[], int numBooks, int numCards)
{
	int bookID = 0, cardID = 0;
	int card = 0, book = 0;

	//Get cardid
	cout << "Enter the card ID: " << endl;
	cin >> cardID;

	//search for cardid
	while (card < numCards && cardID != cards[card].getCardID())
	{
		card++;
	}

	//if not found, return
	if (card == numCards)
	{
		cout << "ERROR: Card not found." << endl;
		return;
	}


	//Get bookid
	cout << "Enter the book ID: " << endl;
	cin >> bookID;

	//search for bookid
	while (book < numBooks && bookID != books[book].getBookID())
	{
		book++;
	}

	//if not found, return
	if (book == numBooks)
	{
		cout << "ERROR: Book not found." << endl;
		return;
	}

	cards[card].setBookID(0);
	books[book].setCardID(0);
}