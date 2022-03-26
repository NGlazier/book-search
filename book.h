#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#ifndef BOOK_H
#define BOOK_H
using namespace std;

class Book{
public:
    Book(); //default constructor
    Book(string newTitle, int newYear, string newAuthor); //sets the title, year, and author respectively
	Book(string allData); //splits the data into title, year, and author
    
	string getTitle(); //returns title
	int getYear();     //returns year
	string getAuthor();//returns author

	void setTitle(string newTitle);   //sets new title
	void setYear(int newYear);        //sets new year
	void setAuthor(string newAuthor); //sets new author

	bool matchTitle(string targetTitle);   //searches the titles for the target
	bool matchYear(string targetYear);     //searches the years for the target
	bool matchAuthor(string targetAuthor); //seachers the authors for the target
	bool match(string target);             //searches the titles, years, and authors for the target
 
	friend void operator << (ostream &outs, Book x); //prints the book in allData form

private:
    string allData;
	string title;
	int year;
	string author;

};

#endif