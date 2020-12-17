#include <iostream>
#include <string>
#include <cassert>

#include "Ticket.h"
#include "BoxOffice.h"
#include "Project5Helper.h"

using namespace std;

int main()
{
    // test code
    Project5Helper helper;
    assert( helper.endsWithPM( "sdfasddf PM" ) );
    assert( !helper.endsWithPM( "asdasdfs AM" ) );
    
    assert( !helper.startsWithOrchestra( "sdfasddf PM" ) );
    assert( helper.startsWithOrchestra( "Orchestra AM" ) );
    
    Ticket t( "Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM" );
    BoxOffice b;
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Pavillion Row 13" );
    assert( t.getSeat() == 45 );
    
    t = b.buyTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", "abc" ,Ticket::KIND::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "0.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );
    assert( t.getEvent() == "Episode VII: The Force Awakens");
    assert( t.getVenue() == "abc");
    assert( t.getDayTime() == "September 1, 7:30PM");
    t.setPrice(5);
    assert( std::to_string( t.getPrice() ) == "5.000000");
    
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20 );

    t = b.buyRoyceHallStaffTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::KIND::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "35.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Balcony Row J" );
    assert( t.getSeat() == 120 );
    
    t = b.buyRoyceHallStaffTicket( "Orchestra Row J", 120, "An Evening With David Sedaris", Ticket::KIND::OTHER, "October 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "70.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER );
    assert( t.getRow() == "Orchestra Row J" );
    assert( t.getEvent() == "An Evening With David Sedaris");
    assert( t.getDayTime() == "October 1, 7:30PM");
    assert( t.getSeat() == 120 );

    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM" );
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT );
    assert( t.getRow() == "Orchestra Row A" );
    assert( t.getSeat() == 12 );
    
    t = b.buyTicket( "Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM" );
    t.setPrice( 150.00 );
    assert(t.getPrice() == 150);
    
    t = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM" );
    assert( t.getRow() == "Orchestra Row U" );
    assert( t.getSeat() == 20);
    assert(to_string(t.getPrice()) == "20.000000");
    assert( t.getEvent() == "Episode VII: The Force Awakens" );
    assert( t.getKind() == Ticket::KIND::MOVIE );
    assert( t.getDayTime() == "September 1, 7:30PM" );
    
    t = b.buyRoyceHallStaffTicket( "Balcony Row J", 120, "An Evening With David Sedaris", Ticket::KIND::OTHER, "October 1, 7:30PM" );
        
    t = b.buyRoyceHallTicket( "Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM" );

    t = b.buyRoyceHallStudentTicket( "Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::OTHER , "September 1, 7:30PM" );
    
    assert(to_string(t.getPrice()) == "50.000000");
    
    cout << "all tests passed!" << endl ;
    
    return 0;
    
    }
