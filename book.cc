#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include "book.h"
using namespace std;

Book::Book(){ //default constructor
	title = "***";
	year = 0;
	author = "***";
}

Book::Book(string newTitle, int newYear, string newAuthor){ //sets the title, year, and author to their respective places
	title = newTitle;
	if(newYear > 0){
		year = newYear;
	}else{
		year = 0;
	}
	author = newAuthor;
}

Book::Book(string allData){ //splits the line into the title, year, and author
	int pos = 0;
	int barIndex;
	string stringYear;
	int bar2Index;
	barIndex = allData.find("|", pos);
	title = allData.substr(0, barIndex);
	pos = barIndex + 1;
	bar2Index = allData.find("|", pos);
	int length = bar2Index - barIndex;
	stringYear = allData.substr(barIndex + 1, length);
	if(stoi(stringYear) > 0){
		year = stoi(stringYear);
	}else{
		year = 0;
	}
	author = allData.substr(bar2Index + 1);
}

string Book::getTitle(){ //returns the title
	return title;
}

int Book::getYear(){ // returns the year
	return year;
}

string Book::getAuthor(){ // returns the author
	return author;
}

void Book::setTitle(string newTitle){ //sets the new title
	title = newTitle;
}

void Book::setYear(int newYear){ // sets the new year
	if(newYear > 0){
		year = newYear;
	}
}

void Book::setAuthor(string newAuthor){ //sets the new author
	author = newAuthor;
}

bool Book::matchTitle(string targetTitle){ //searches the title for the entry
	string tempTitle;
	string tempTarget;

	for(size_t i = 0; i < targetTitle.size(); i++){
       tempTarget += toupper(targetTitle[i]);
	}

	for(size_t i = 0; i < title.size(); i++){
       tempTitle += toupper(title[i]);
   }

   if(tempTitle.find(tempTarget) == string::npos){
	   return false;
   }else{
	   return true;
   }

}

bool Book::matchYear(string targetYear){ //searches the year for the entry
	string tempYear;
	tempYear = to_string(year);

	if(tempYear.find(targetYear) == string::npos){
		return false;
	}else{
		return true;
	}
}



bool Book::matchAuthor(string targetAuthor){ //searches the author for the entry
	string tempAuthor;
	string tempTarget;

	for(size_t i = 0; i < targetAuthor.size(); i++){
       tempTarget += toupper(targetAuthor[i]);
	}

	for(size_t i = 0; i < author.size(); i++){
       tempAuthor += toupper(author[i]);
   }

   if(tempAuthor.find(tempTarget) == string::npos){
	   return false;
   }else{
	   return true;
   }

}

bool Book::match(string target){ //searches every field for the entry
	if(matchAuthor(target) == true || matchYear(target) == true || matchTitle(target) == true){
		return true;
	}else{
		return false;
	}
}

void operator << (ostream &outs, Book x){  //when called outputs "The value is" and then outputs the private value
  outs  << x.title << "|" << x.year << "|" << x.author << endl; 
}