#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

//void readArray(const string array[], int size){
//    for (int i = 0; i < size; i++){
//        cout << array[i] << ", ";
//    }
//    cout << endl;
//}
//
//void remakeArray(string array[], int size){
//    if (size == 5){
//    array[0] = "qa";
//    array[1] = "ws";
//    array[2] = "ed";
//    array[3] = "rf";
//    array[4] = "t";
//    }
//}

bool hasDuplicates( const string array[ ],  int size );
int  countAllDigits( const string array[ ] , int size );
bool isInDecreasingOrder( const string array[ ], int size );
int  shiftRight( string array[ ], int size, int amount, string placeholder );
int  find( const string array[ ], int size, string match );
int  replaceAllCharacters( string array[ ], int size, char findLetter, char replaceLetter );

int main()
{
    string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
    string a2[6] = { "gamma", "gamma", "delta", "beta", "beta", "alpha" };
    string folks[8] = {"samwell", "jon", "margaery", "daenerys","tyrion", "sansa", "howard123", "jon"};
    string b[3] = {"","a","cc"};
    string c[5] = {"5","4","3","2","1"};
    string c2[5] = {"5","4","3","2","3"};
    string p[5] = {"qa","ws","ed","rf","t"};
    
    assert(hasDuplicates(a, 6 ) == true);
    assert(hasDuplicates(a, 3 ) == false);
    assert(hasDuplicates(a, 0) == false);
    assert(hasDuplicates(a, -1) == false);
    assert(hasDuplicates(a, 1) == false);
    
    assert(countAllDigits(folks, -100) == -1);
    assert(countAllDigits(folks, 3) == 0);
    assert(countAllDigits(folks, 8) == 3);
    
    assert(isInDecreasingOrder(b, 0)== true);
    assert(isInDecreasingOrder(b, 1)== true);
    assert(isInDecreasingOrder(a2, 6) == true);
    assert(isInDecreasingOrder(c, 5) == true);
    assert(isInDecreasingOrder(c2, 5) == false);
    assert(isInDecreasingOrder(a, 2)== false);
    assert(isInDecreasingOrder(a, 4)== false);
    assert(isInDecreasingOrder(folks, 8)== false);
    
    //all dont change the array
    assert(shiftRight(folks, -100, 100, "hi") == -1);
    assert(shiftRight(folks, 8, -100, "hi") == -1);
    assert(shiftRight(folks, 8, 0, "hi") == 0);
    assert(shiftRight(folks, 0, 10, "hi") == 0);
    
    //change the array
//    readArray(p, 5);
//    assert(shiftRight(p, 5, 5, "foo")==5);
//    readArray(p, 5);
//    remakeArray(p, 5);
//    cout << endl;
    //
//    readArray(p, 5);
//    assert(shiftRight(p, 5, 10, "foo")==5);
//    readArray(p, 5);
//    remakeArray(p, 5);
//    cout << endl;
    //
//    readArray(p, 5);
    assert(shiftRight(p, 5, 3, "asdf asdf")==3);
//    readArray(p, 5);
//    remakeArray(p, 5);
//    cout << endl;
    //
    string foo[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    assert(shiftRight(foo, 10, 3, "foo")==3);
//    readArray(foo, 10);
//    cout << endl;
    //
//    readArray(p, 5);
//    assert(shiftRight(p, 5, 2, "hi")==2);
//    readArray(p, 5);
//    remakeArray(p, 5);
//    cout << endl;
    
    assert(find(folks, 0, "hi")== -1);
    assert(find(folks, -100, "hi")== -1);
    assert(find(folks, 8, "margaery")==2);
    assert(find(folks, 4, "jon")==1);
    assert(find(folks, 8, "howard123")==6);
    assert(find(folks, 8, "bob")== -1);
    assert(find(a,6,"gamma")==2);
    
    assert(replaceAllCharacters(a, 0, 'a', '_')== -1);
    assert(replaceAllCharacters(a, -190, 'a', '_')== -1);
    assert(replaceAllCharacters(folks, 8, 'a', '+')== 7);
//    readArray(folks, 8);
    
    cout << "All tests succeeded" << endl;
    return( 0 );
}

bool hasDuplicates( const string array[ ],  int size ){
    if (size <= 0){
        return false;
    }
    
    for (int i = 0; i < size ;i++){
        for (int k = i + 1; k < size; k++){
            if (array [i] == array [k]){
                return true;
            }
        }
    }
    return false;
}

int  countAllDigits( const string array[ ] , int size ){
    if (size <= 0){
        return -1;
    }
    int count = 0;
    for(int i = 0; i < size ; i++){
        string s = array[i];
        for(size_t k = 0; k < s.length();k++){
            if(isdigit(s[k])){
                count++;
            }
        }
    }
    
    return count;
}

bool isInDecreasingOrder( const string array[ ], int size ){
    if (size == 0 || size == 1){
        return true;
    }
    
    for(int i = 0; i < size - 1; i++){
        if (array[i] < array[i+1]) {//if they are the same it skips and if the second string is not less than the string before it it returns false
            return false;
        }
    }
    
    return true;
}

int  shiftRight( string array[ ], int size, int amount, string placeholder ){
    if (size < 0 || amount < 0){
        return -1;}
    if (size == 0){
        return 0;}
    if(amount >= size){
        for (int i = 0; i < size; i++){
            array[i] = placeholder;
        }
        return size;
    }
    
    int k = 1;
    for(int i = size-1; i >= amount; i--){
        array[i] = array [size - amount - k];
        k++;
    }
    
    for(int i = 0; i < amount; i++){
        array[i]=placeholder;
    }
    
    return amount;
}

int  find( const string array[ ], int size, string match ){
    if(size <= 0){
        return -1;
    }
    int count = 0;
    for(int i = 0; i < size; i++){
        if (array[i]==match){
            return count;
        }
        count++;
    }
    return -1;
}

int  replaceAllCharacters( string array[ ], int size, char findLetter, char replaceLetter ){
    if(size <= 0){
        return -1;
    }
    int count = 0;
    for(int i=0; i < size; i++){
        string s = array[i];
        for(int k=0; k < s.length(); k++){
            if(s[k]==findLetter){
                s[k]=replaceLetter;
                array[i]=s;
                count++;
            }
        }
    }
    
    return count;
}
