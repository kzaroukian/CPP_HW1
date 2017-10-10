/***********************************************************
* Defintions of functions from concert.h to create concerts
* @author Kaylin Zaroukian
* @version 10/5/17
*************************************************************/

#include <string>
#include <vector>
#include "concert.h"
#include <iostream>

/********************************************************
 * Constructor for class Concert
 * Assigns arbitrary values to define instance variables
 ********************************************************/
Concert::Concert() {
    // arbitrary values to define instance variables
    date.tm_year = 1999;
    date.tm_mday = 1;
    date.tm_mon = 1;
    concertName = "";
    desire = 0;
    friends.push_back("Friend 1");

}

/**********************************************************************
 * Overloaded Constructor for class Concert used to create objects
 * @param date tm date, the date of concert
 * @param concertName std::string, name of the artist
 * @param desire int desire, numeric value of desire to see show
 * @param friends std::vector vector of friends (strings) to see show
 **********************************************************************/
Concert::Concert(tm date, std::string concertName, int desire, std::vector<std::string> friends){
        this->date = date;
        this->concertName = concertName;
        this->desire = desire;
        for(std::string buddy : friends){
            this->friends.push_back(buddy);
        }
        // defines dateName as a string to hold the dates
        dateName = std::to_string(date.tm_mon);
        dateName += "/";
        dateName += std::to_string(date.tm_mday);
        dateName += "/";
        dateName += std::to_string(date.tm_year);
    }




    /*************************************************************
     * Overloads the "<" to allow a comparison of 2 Concert
     * objects by their dates or desire (if dates are the same)
     * @param other Concert object
     * @return true if < or false if >
     **************************************************************/
    // referenced Sams Teach yourself C++ book pg. 355
    bool Concert::operator<(const Concert& other) const{
        // finds earlier year
        if(date.tm_year < other.date.tm_year){
            return true;
        }

        // finds earlier month
        if(date.tm_year == other.date.tm_year){
            if(date.tm_mon < other.date.tm_mon){
                return true;
            }
        }

        // finds earlier day
        if(date.tm_year == other.date.tm_year){
            if(date.tm_mon == other.date.tm_mon){
                if(date.tm_mday < other.date.tm_mday){
                    return true;
                }
            }
        }
        // finds lower desire
        if(date.tm_year == other.date.tm_year){
            if(date.tm_mon == other.date.tm_mon){
                if(date.tm_mday == other.date.tm_mday){
                    if(desire < other.desire ){
                        return true;
                    }
                }
            }
        }

        // if this > other
        return false;



    }

/*************************************************************
 * Overloads the << operator to allow a Concert object be
 * printed out
 * @param output std::ostream to print out a Concert
 * @param other Concert object
 * @return printed Concert
 **************************************************************/
// C++ for dummies pg. 314
std::ostream& operator<<(std::ostream &out, const Concert& other) {
    return out<<"The "<<other.concertName<<" concert on "<<other.dateName<< " Desire: "<<other.desire;
}


/************************************************
 * main function to create 10 concert objects
 * @param args number of arguments
 * @param argv array of characters
 * @return 0
 ************************************************/
int main(int args, char** argv){
    std::vector<Concert> concerts;

    // function variables for overloaded constructor
    std::vector<std::string> list;
    std::tm date;
    int desire;
    std::string name;

    date.tm_mon = 8;
    date.tm_year=2018;
    date.tm_mday = 18;
    name = "Drake";
    desire = 7;
    Concert A(date, name, desire, list);
    concerts.push_back(A);

    // second item in the vector
    date.tm_mon = 8;
    date.tm_year=2018;
    date.tm_mday = 18;
    name = "Britney Spears";
    desire = 4;
    Concert B(date, name, desire, list);
    concerts.push_back(B);

    // third item in the vector
    date.tm_mon = 10;
    date.tm_year=2017;
    date.tm_mday = 19;
    name = "Elton John";
    desire = 8;
    Concert C(date, name, desire, list);
    concerts.push_back(C);

    // fourth item in the vector
    date.tm_mon = 6;
    date.tm_year=2019;
    date.tm_mday = 9;
    name = "Miley Cyrus";
    desire = 1;
    Concert D(date, name, desire, list);
    concerts.push_back(D);

    // fifth item in the vector
    date.tm_mon = 1;
    date.tm_year=2020;
    date.tm_mday = 21;
    name = "Lana Del Rey";
    desire = 5;
    Concert E(date, name, desire, list);
    concerts.push_back(E);

    // sixth item in the vector
    date.tm_mon = 4;
    date.tm_year=2018;
    date.tm_mday = 7;
    name = "Ed Sheeran";
    desire = 3;
    Concert F(date, name, desire, list);
    concerts.push_back(F);

    // seventh item in the vector
    date.tm_mon = 7;
    date.tm_year=2019;
    date.tm_mday = 11;
    name = "Beyonce";
    desire = 10;
    Concert G(date, name, desire, list);
    concerts.push_back(G);

    // eighth item in the vector
    date.tm_mon = 3;
    date.tm_year=2018;
    date.tm_mday = 12;
    name = "Kanye West";
    desire = 6;
    Concert H(date, name, desire, list);
    concerts.push_back(H);

    // ninth item in the vector
    date.tm_mon = 3;
    date.tm_year=2018;
    date.tm_mday = 12;
    name = "Justin Bieber";
    desire = 4;
    Concert I(date, name, desire, list);
    concerts.push_back(I);

    // tenth item in the vector
    date.tm_mon = 10;
    date.tm_year=2017;
    date.tm_mday = 10;
    name = "Blake Shelton";
    desire = 8;
    Concert J(date, name, desire, list);
    concerts.push_back(J);


    // sorts the vector in ascending order
    std::sort(concerts.begin(), concerts.end());

    // prints out each concert in the vector concerts
    for (Concert h : concerts){
        std::cout<<h<<std::endl;
    }

    return 0;

}

