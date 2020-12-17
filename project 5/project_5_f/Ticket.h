#ifndef Ticket_h
#define Ticket_h
#include <iostream>
#include <string>
using namespace std;

class Ticket
{
public:
    enum KIND {ATHLETICGAME, CONCERT, MOVIE, OTHER};

    Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime);

    string getRow();
    int getSeat();
    string getEvent();
    string getVenue();
    double getPrice();
    KIND getKind();
    string getDayTime();
    
    void setPrice( double price);
    
private:
    string mRow;
    int mSeat;
    string mEvent;
    string mVenue;
    double mPrice;
    KIND mKind;
    string mDayTime;
};

#endif
