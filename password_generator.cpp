#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

using namespace std;

string randomGenerator();
char randomCapitalCharacter();
char randomLowerCharacter();
char randomSpecialCharacter();
int randomInt();

/* TODO:
    true and false for if each function allowed to be called in the random.
    random length from 8-12
    each function must be called atleast one time.
    random order of using each function
    */

int main(){
    srand((unsigned int) time(NULL));
    cout << randomGenerator() << endl;
    return 0;
}
int randomInt(){
    //TODO: Make actually random number
    int random_number = std::rand()% 10;
    return random_number;
}
char randomCapitalCharacter(){
    return 65 + rand()%26; //65 = A
}
char randomLowerCharacter(){
    return 97 + rand()%26; //97 = a
}
char randomSpecialCharacter(){
    /** Special characters are split by numbers so we pick a random from one of the 2 groups.*/
    return (rand()%2) ? char(33 + rand()%14) : char(58 + rand()%8); 
}
string randomGenerator(){
    std::string word = "This will turn into a random generator!";
    cout << randomInt() << endl;
    cout << randomCapitalCharacter() << endl;
    cout << randomLowerCharacter() << endl;
    cout << randomSpecialCharacter() << endl;
    return word;
}




