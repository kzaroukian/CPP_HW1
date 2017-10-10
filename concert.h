/***********************************************************
* .h file to declare functions and instance variables
* @author Kaylin Zaroukian
* @version 10/5/17
*************************************************************/

#ifndef CIS343CPP_PROJ_CONCERT_H
#define CIS343CPP_PROJ_CONCERT_H

#include <string>
#include <vector>
#include <iostream>

class Concert{

public:
    // name of the concert
    std::string concertName;

    // friends who you are going with
    std::vector<std::string> friends;

    // rating of how much you want to go
    int desire;

    // date of concert
    std::tm date;

    // string of the date in mm/dd/yyyy format
    std::string dateName;

    /********************************************************
     * Constructor for class Concert
     * Assigns arbitrary values to define instance variables
     ********************************************************/
    Concert();

    /**********************************************************************
     * Overloaded Constructor for class Concert used to create objects
     * @param date tm date, the date of concert
     * @param concertName std::string, name of the artist
     * @param desire int desire, numeric value of desire to see show
     * @param friends std::vector vector of friends (strings) to see show
     **********************************************************************/
    Concert(tm date, std::string concertName, int desire, std::vector<std::string> friends);

    /*************************************************************
     * Overloads the "<" to allow a comparison of 2 Concert
     * objects by their dates or desire (if dates are the same)
     * @param other Concert object
     * @return true if < or false if >
     **************************************************************/
    Concert(const std::string &concertName, const std::vector<std::string> &friends, int desire, const tm &date);

    /*************************************************************
     * Overloads the << operator to allow a Concert object be
     * printed out
     * @param output std::ostream to print out a Concert
     * @param other Concert object
     * @return printed Concert
     **************************************************************/
    bool operator<(const Concert& other) const;



};

#endif //CIS343CPP_PROJ_CONCERT_H
