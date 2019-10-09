#include <iostream>
#include <string>
using namespace std;

int main() {
    string pay;// Ticket or BruinCard
    string meal;// Breakfast, Lunch, or Dinner
    string role;// Staff or Student
    string live;// resident or not yes or no
    
    cout << "Ticket or BruinCard? ";
    getline(cin,pay);
    
    if(pay == "Ticket" || pay == "BruinCard"){//checks if pay is typed correctly
    }else{
        cout << "The kind value must either be Ticket or BruinCard."<<endl;
        return (1);
    }
    
    cout << "Breakfast, Lunch or Dinner? ";
    getline(cin,meal);
    
    if(pay == "Ticket" && meal == "Breakfast"){
        cout << "Thank you for eating at UCLA today.  Your meal cost is $12.50." << endl;//ticket breakfast
        return (0);
    }else if(pay == "Ticket" && meal == "Lunch"){
        cout << "Thank you for eating at UCLA today.  Your meal cost is $14.50." << endl;//ticket lunch
        return (0);
    }else if(pay == "Ticket" && meal == "Dinner"){
        cout << "Thank you for eating at UCLA today.  Your meal cost is $17.00." << endl;//ticket dinner
        return (0);
    }else if(!(meal == "Breakfast") && !(meal == "Lunch") && !(meal == "Dinner")){//checks if meal is typed correctly
        cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
        return (1);
    }
    
    // must be BruinCard at this point
    
    cout << "Student or Staff? ";
    getline(cin,role);
    
    if(role == "Staff" && meal == "Breakfast"){
        cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25." << endl;//bcard staff breakfast
        return (0);
    }else if(role == "Staff" && meal == "Lunch"){
        cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << endl;//bcard staff lunch
        return (0);
    }else if(role == "Staff" && meal == "Dinner"){
        cout << "Thank you for eating at UCLA today.  Your meal cost is $14.75." << endl;//bcard staff dinner
        return (0);
    }else if(!(role == "Staff") && !(role == "Student")){
        cout << "The type value must either be Student or Staff." << endl;//checks if role is typed correctly
        return (1);
    }
    
    //must be BruinCard and Student
    
    cout << "Resident? ";
    getline(cin,live);
    
    if(live == "Yes"){ //checks if resident
        if(meal == "Breakfast"){
            cout << "Thank you for eating at UCLA today.  Your meal cost is $9.75." << endl;//bcard stud res bfast
            return (0);
        }else if(meal == "Lunch"){
            cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25." << endl;//bcard stud res lunch
            return (0);
        }else if (meal == "Dinner"){
            cout << "Thank you for eating at UCLA today.  Your meal cost is $12.25." << endl;//bcard stud res dinner
            return (0);
        }
    }else if(live == "No"){//checks if nonresident
        if(meal == "Breakfast"){
            cout << "Thank you for eating at UCLA today.  Your meal cost is $10.00." << endl;//bcard student nres bfast
            return (0);
        }else if(meal == "Lunch"){
            cout << "Thank you for eating at UCLA today.  Your meal cost is $11.75." << endl;//bcard student nres lunch
            return (0);
        }else if (meal == "Dinner"){
            cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << endl;//bcard student nres dinner
            return (0);
        }
    }else if(!(live == "Yes") && !(live == "No")){
        cout << "The resident value must either be Yes or No." << endl;
        return (1);//checks if role is typed correctly
    }
    return 0;
}
