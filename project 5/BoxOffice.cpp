#include "BoxOffice.h"
#include "Ticket.h"
#include "Project5Helper.h"

BoxOffice::BoxOffice(){
    /* do nothing */
}

Ticket BoxOffice::buyTicket( string row, int seat, string event, string venue, Ticket::KIND kind, string daytime ){
    Ticket  t(row, seat, event, venue, 0, kind, daytime);
    return t;
}

Ticket BoxOffice::buyRoyceHallStudentTicket( string row, int seat, string event, Ticket::KIND kind, string daytime ){
    double price;
    Project5Helper b;
    
    if (kind == Ticket::KIND::ATHLETICGAME){
        price = 75;
        if (b.startsWithOrchestra(row)){
            price = price * 2;
        }
        price = price - 30;
    }else if (kind == Ticket::KIND::CONCERT){
        if(!(b.endsWithPM(daytime))){ //if it doesnt end with pm then
            price = 50;
            if (b.startsWithOrchestra(row)){
                price = price * 2;
            }
            price = price - 30;
        }else{// night ticket
            price = 65;
            if (b.startsWithOrchestra(row)){
                price = price * 2;
            }
            price = price - 30;
        }
    }else if (kind == Ticket::KIND::OTHER){
        if(!(b.endsWithPM(daytime))){//day ticket
            price = 40;
            if (b.startsWithOrchestra(row)){
                price = price * 2;
            }
            price = price - 30;
        }else{// night ticket
            price = 55;
            if (b.startsWithOrchestra(row)){
                price = price * 2;
            }
            price = price - 30;
        }
    }else{
        price = 12.50;
        if (b.startsWithOrchestra(row)){
            price = price * 2;
        }
        price = price - (price * .2);
    }
    
    Ticket t(row, seat, event, "Royce Hall", price, kind, daytime);
    return t;
}

Ticket BoxOffice::buyRoyceHallStaffTicket( string row, int seat, string event, Ticket::KIND kind, string daytime ){
    double price;
    Project5Helper b;
    
    if (kind == Ticket::KIND::ATHLETICGAME){
        price = 75;
        if (b.startsWithOrchestra(row)){
            price = price * 2;
        }
        price = price - 20;
    }else if (kind == Ticket::KIND::CONCERT){
        if(!(b.endsWithPM(daytime))){ //if it doesnt end with pm then
            price = 50;
            if (b.startsWithOrchestra(row)){
                price = price * 2;
            }
            price = price - 20;
        }else{// night ticket
            price = 65;
            if (b.startsWithOrchestra(row)){
                price = price * 2;
            }
            price = price - 20;
        }
    }else if (kind == Ticket::KIND::OTHER){
        if(!(b.endsWithPM(daytime))){//day ticket
            price = 40;
            if (b.startsWithOrchestra(row)){
                price = price * 2;
            }
            price = price - 20;
        }else{// night ticket
            price = 55;
            if (b.startsWithOrchestra(row)){
                price = price * 2;
            }
            price = price - 20;
        }
    }else{
        price = 12.50;
        if (b.startsWithOrchestra(row)){
            price = price * 2;
        }
        price = price - (price * .1);
    }
    
    Ticket t(row, seat, event, "Royce Hall", price, kind, daytime);
    return t;
}

Ticket BoxOffice::buyRoyceHallTicket( string row, int seat, string event, Ticket::KIND kind, string daytime ){
    double price;
    Project5Helper b;
    
    if (kind == Ticket::KIND::ATHLETICGAME){
        price = 75;
    }else if (kind == Ticket::KIND::CONCERT){
        if(!(b.endsWithPM(daytime))){ //if it doesnt end with pm then
            price = 50;
        }else{// night ticket
            price = 65;
        }
    }else if (kind == Ticket::KIND::OTHER){
        if(!(b.endsWithPM(daytime))){//day ticket
            price = 40;
        }else{// night ticket
            price = 55;
        }
    }else{
        price = 12.50;
    }
    
    if (b.startsWithOrchestra(row)){
        price = price * 2;
    }
    
    Ticket t(row, seat, event, "Royce Hall", price, kind, daytime);
    return t;
}

