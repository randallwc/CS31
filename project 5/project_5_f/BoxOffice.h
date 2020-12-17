#ifndef BoxOffice_h
#define BoxOffice_h
#include "Ticket.h"
#include <iostream>
#include <string>
using namespace std;

class BoxOffice
{
public:
    BoxOffice();
    
    Ticket buyTicket( string row, int seat, string event, string venue, Ticket::KIND kind, string daytime );
    Ticket buyRoyceHallStudentTicket( string row, int seat, string event, Ticket::KIND kind, string daytime );
    Ticket buyRoyceHallStaffTicket( string row, int seat, string event, Ticket::KIND kind, string daytime );
    Ticket buyRoyceHallTicket( string row, int seat, string event, Ticket::KIND kind, string daytime );
};

#endif
