/*
 *        File: book_main.cc
 *      Author: Noah Glazier
 *        Date: April 16, 2019
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include "book.h"
using namespace std;

//function prototypes

int main(int argc, char **argv) {
    string books[15000];
	ifstream inStream;
	ofstream outStream;
    string currentBook;
    int size = 0; //size of the array of books
	
	
	//option errors
	if(argc < 2 || argc > 3){ //prints an error if there is an incorrect number of arguments
		cout << "Error: Invalid number of arguments" << endl;
		return -1;
	}
	
	if(argc == 3){  //prints an error if no valid option is entered
		string option = argv[1];
		string search = argv[2];

		if(option != "-a" && option != "-t" && option != "-y" && option != "-n" && option != "-d"){
			cout << "Error: Invalid Option" << endl;
			return -1;
		}
	}
	
    //open file
    inStream.open("bookDB.txt");
    if(inStream.fail()){ //test for failure
        cout << "Error: invalid file name" << endl;
        cout << endl;
        exit(-1);
    }
	//load the array
   getline(inStream, currentBook);
    while(!inStream.eof()){
        
        if(!currentBook.empty()){
            books[size] = currentBook;
            size++;
        }
        getline(inStream, currentBook);
    }

    inStream.close();

	if(argc == 3){
		string option = argv[1];
		string search = argv[2];

		if(option == "-a"){ //searches each book in the array by author
			for(int i = 0; i < size; i++){
				Book x(books[i]);
				if(x.matchAuthor(search) == true){
					cout << x; //prints if match
				}
			}
		}

	
		if(option == "-t"){ //searches each book in the array by title 
			for(int i = 0; i < size; i++){
				Book x(books[i]);
				if(x.matchTitle(search) == true){
					cout << x; //prints if match
				}
			}
		}

	
		if(option == "-y"){ //searches each book in the array by year
			for(int i = 0; i < size; i++){
				Book x(books[i]);
				if(x.matchYear(search) == true){
					cout << x; //prints if match
				}
			}
		}

		if(option == "-n"){ //adds entered book into the array
			books[size] = search;
			size++;
		}

		if(option == "-d"){ //deletes a book by title
			for(int i = 0; i < size; i++){
				Book x(books[i]);
				if(x.matchTitle(search) == true){
					books[i] = "";
				}
			}
			size--;
		}

	}

	if(argc == 2){ //searches each book in the array by title, year, and author
		string search = argv[1];

		for(int i = 0; i < size; i++){
			Book x(books[i]);
			if(x.match(search) == true){
				cout << x;
			}
		}
	}

	

	outStream.open("bookDB.txt");
    if(outStream.fail()){ //test for failure
        cout << "Error: invalid file name" << endl;
        cout << endl;
        exit(-1);
	}
	for(int i = 0; i < size; i++){ //reprints all the books onto the file
		outStream << books[i] << endl;
	}
	inStream.close();
	outStream.close();

	return 0;
}// main


