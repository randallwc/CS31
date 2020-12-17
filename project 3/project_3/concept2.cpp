#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

int number(string s, int& startingposition);
bool isValidRowerString(string rowerString);
int totalDistance(string rowerString);
int heartRate(string rowerString);
int strokesPerMinute(string rowerString);
int elapsedMinutes(string rowerString);
int elapsedSeconds(string rowerString);

int main()
{
    string s;
    cout.setf(ios::boolalpha); // prints bool values as "true" or "false"
    
    assert (isValidRowerString(":14    28 s/m     42 m    110")==true);
    assert (isValidRowerString("        :14         28 s/m         42 m      110")==true);
    assert (isValidRowerString("1:14    28 s/m     42 m    110")==true);
    assert (isValidRowerString("59:14     28 s/m     42 m    110")==true);
    assert (isValidRowerString("59:59    28 s/m     42 m    110")==true);
    assert (isValidRowerString("59:59    999 s/m     42 m    110")==true);
    assert (isValidRowerString("59:59    999 s/m     42 m    999")==true);
    assert (isValidRowerString(":14 28 s/m 42 m 110")==true);
    assert (isValidRowerString(":07 28 s/m 42 m 110")==true);
    assert (isValidRowerString("1:14 28 s/m 42 m 110")==true);
    
    assert (isValidRowerString("")==false);
    assert (isValidRowerString("asdf:14    28 s/m     42 m    110")==false);
    assert (isValidRowerString(":14    28 s/m     42 m    110 asdf")==false);
    assert (isValidRowerString(":14     28       s/m    42 m    110")==false);
    assert (isValidRowerString("0:14    28 s/m     42 m    110")==false);
    assert (isValidRowerString("0000:14    00028 s/m     00042 m   000110")==false);
    assert (isValidRowerString(":-14    -28 s/m     -42 m   -110")==false);
    assert (isValidRowerString("555:14    28 s/m    42 m   110")==false);
    assert (isValidRowerString(":555      28 s/m      42 m  110")==false);
    assert (isValidRowerString(":14    99123 s/m    42 m   110")==false);
    assert (isValidRowerString(":14    0 s/m            42 m   110")==false);
    assert (isValidRowerString(":14    28 s/m         42 m   99123")==false);
    assert (isValidRowerString(":14    28 s/m         42 m   0")==false);
    assert (isValidRowerString("00000:14 28 s/m 42 m 110")==false);
    assert (isValidRowerString(":000007 28 s/m 42 m 110")==false);
    assert (isValidRowerString("1:14 28      s/m 42 m 111")==false);
    assert (isValidRowerString("1:14 28 s/m 42      m 111")==false);
    assert (isValidRowerString("1:14 28 s/m 42 m 1111    ")==false);
    assert (isValidRowerString(":7 28 s/m 42 m 111")==false);
    
    for(;;){
//    s = "22:14 10 s/m 10 m 110";
        bool answer;
        cout <<"enter:"<<endl;
        getline(cin, s);
        cout << "isValidRowerString returns \t";
        cout << isValidRowerString(s)<<endl;
        cout << "elapsedMinutes(s) returns \t";
        cout << elapsedMinutes(s)<<endl;
        cout << "elapsedSeconds(s) returns \t";
        cout << elapsedSeconds(s)<<endl;
        cout << "strokesPerMinute(s) returns \t";
        cout << strokesPerMinute(s)<<endl;
        cout << "totalDistance(s) returns \t";
        cout << totalDistance(s)<<endl;
        cout << "heartRate(s) returns \t";
        cout << heartRate(s)<<endl;
        cin>> answer;
        cin.ignore(10000,'\n');
        if(answer==0){
            break;
        }
    }
return 0;
}

int number(string s, int& startingposition){
    int result = 0;
    // ignore leading whitespace
    while (startingposition < s.length() &&  isspace( s.at( startingposition ) ) )
    {
        startingposition = startingposition + 1;
    }
    // no leading zeros
    if (startingposition < s.length())
    {
        if (s.at( startingposition ) >= '1' &&
            s.at( startingposition ) <= '9')
        {
            while (startingposition < s.length() &&
                   s.at( startingposition ) >= '0' &&
                   s.at( startingposition ) <= '9')
            {
                int value = s.at( startingposition ) - '0';
                result = (result * 10) + value;
                /// move on down the road
                startingposition = startingposition + 1;
            }
        }
    }
    else{
        result = -1;
    }
    return(result);
}

bool isValidRowerString(string rowerString){
    int i=0; // position
    int k = number(rowerString, i);
    
    //check the minutes value (could be nothing or 01 to 59)
    
    if(k>0 && k<=59){
        //        cout<<"check1"<<endl;
    }else if(k == 0){  //test cases 01:14 28 s/m 42 m 110//00:14//10:14//000:14
        if(rowerString[i] != ':' || (rowerString[i-1]>='1' && rowerString[i-1]>='9') ){// its not a : and
            return false;
        }
    }else{
        return false;
    }
    //check if it is a :
    
    if(rowerString[i] != ':'){  // is it a :
        return false;
    }
    
    if(!isdigit(rowerString[i+1]) || !isdigit(rowerString[i+2])){ // are there 2 numbers after :?
        //        cout << "there are not 2 numbers after **:"<<endl;
        return false;}
    
    i++; // pos 1 after :
    k = number(rowerString,i);
    
    //checks the seconds value
    
    if(k>0 && k<=59){
        //        cout << "check2" << endl;
    }else if(k == 0){
        i++;//move to after 0
        k = number(rowerString, i);
        if(!(k>=0 || k<=9)){//k must be 0-9
            return false;
        }
        //        cout << "check3"<< endl;
    }else{
        return false;
    }
    
    //checks for space between **:** *** s/m
    
    if(rowerString[i] != ' '){
        return false;
    }
    //    cout << "check4"<<endl;
    
    //checks the strokes per minute
    
    k = number(rowerString,i);//new k value
    
    if(!(k>0 && k<1000)){//strokes per minute must be from 1 to 999
        //        cout << "not good s/m";
        return false;
    }
    //    cout << "check5"<<endl;
    
    //check if _s/m_ is there
    
    if(rowerString[i] != ' '){
        return false;
    }
    if(rowerString[i+1] != 's'){
        return false;
    }
    if(rowerString[i+2] != '/'){
        return false;
    }
    if(rowerString[i+3] != 'm'){
        return false;
    }
    if(rowerString[i+4] != ' '){
        return false;
    }
    //    cout << "check6"<<endl;
    i = i + 4;
    
    k = number(rowerString, i);
    
    //checks the distance traveled
    
    if(!(k>0)){//distance must be bigger than 0
        return false;
    }
    //    cout << "check7" << endl;
    
    if(rowerString[i] != ' '){
        return false;
    }
    if(rowerString[i+1] != 'm'){
        return false;
    }
    if(rowerString[i+2] != ' '){
        return false;
    }
    //    cout << "check8"<<endl;
    i=i+2;
    
    k = number(rowerString, i);
    
    //checks the heart rate
    
    if(!(k>0 && k<1000)){//heart rate must be between 1 and 999
        return false;
    }
    //    cout << "check 9" << endl;
    
    //checks if i is the length of the string to make sure that there is notheing after the b/m
    size_t finalI = i; // makes I in terms of size_t so you can compate it to .length()
    if(finalI != rowerString.length()){
        //        cout << "final i value is not equal to st.length()"<<endl;
        return false;
    }
    //    cout << "check10"<<endl;
    
    return true;
}

int totalDistance(string rowerString){
    if(isValidRowerString(rowerString)==false){
        return -1;
    }
    
    int i = 0;
    int k = number(rowerString, i);
    i++;
    k = number(rowerString, i);
    
    if(k==0){
        i++;
        k=number(rowerString,i);
    }
    k=number(rowerString,i);
    i=i+4;
    k=number(rowerString,i);
    
    return k;
}

int heartRate(string rowerString){
    if(isValidRowerString(rowerString)==false){
        return -1;
    }
    
    int i = 0;
    int k = number(rowerString, i);
    i++;
    k = number(rowerString, i);
    
    if(k==0){
        i++;
        k=number(rowerString,i);
    }
    k=number(rowerString,i);
    i=i+4;
    k=number(rowerString,i);
    i=i+2;
    k=number(rowerString,i);
    
    return k;
}

int strokesPerMinute(string rowerString){
    if(isValidRowerString(rowerString)==false){
        return -1;
    }
    int i = 0;
    int k = number(rowerString, i);
    i++;
    k = number(rowerString, i);
    
    if(k==0){
        i++;
        k=number(rowerString,i);
    }
    k=number(rowerString,i);
    
    return k;
}

int elapsedMinutes(string rowerString){
    if(isValidRowerString(rowerString)==false){
        return -1;
    }
    int i = 0;
    int k = number(rowerString,i);
    
    return k;
}

int elapsedSeconds(string rowerString){
    if(isValidRowerString(rowerString)==false){
        return -1;
    }
    int i = 0;
    int k = number(rowerString, i);
    i++;
    k = number(rowerString, i);
    if(k==0){
        i++;
        k=number(rowerString,i);
    }
    
    return k;
}
