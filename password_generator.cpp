#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <string>

using namespace std;

string randomGenerator(int numberOfCharacters);
char randomCapitalCharacter();
char randomLowerCharacter();
char randomSpecialCharacter();
char randomInt();

string decryption(string crackThisPassword, int &t);

/* TODO:
    GET RANDOM TO ACTUALLY BE RANDOM
    DEFAULT VALUE FOR FUNCTIONS? NOT WORKING
    true and false for if each function allowed to be called in the random.
    each function must be called atleast one time.
    random order of using each function


    decryption
    DO REAL TIME FOR DECRYPTION
    DO for loops num, alphabetical, etc.. 1a,1b,1c .... 2a,2b,2c
    RANDOMIZE ORDER FOR PASSWORD AS WELL AS FOR DECRYPTION
    */

int main(){
    srand((unsigned int) time(NULL));
    string password = randomGenerator(6);
    int time = 0;
    cout << password << endl << decryption(password, time) << " decrypted in "<< time << " attempts." << endl << endl;
    return 0;
}

char randomInt(){
    //TODO: Make actually random number
    std::string test = to_string(std::rand()% 10);
    char randomNumberChar = test.at(0);
    return randomNumberChar;
}
char randomLowerCharacter(){
    return 97 + rand()%26; //97 = a
}
char randomCapitalCharacter(){
    return 65 + rand()%26; //65 = A
}
char randomSpecialCharacter(){
    /** Special characters are split by numbers so we pick a random from one of the 2 groups.*/
    return (rand()%2) ? char(33 + rand()%14) : char(58 + rand()%8); 
}

string randomGenerator(int numberOfCharacters = 8){
    char randomCharacterTypes[4] = {randomLowerCharacter(),randomInt(), randomCapitalCharacter(), randomSpecialCharacter()};
    std::string password;

    for (int i = 0; i < numberOfCharacters; i++){
        //password += randomCharacterTypes[(rand()%4)%4];
        //above will work once i get random being actually random.
        password += randomCharacterTypes[i%4];
    }
    return password;
}

string decryption(string crackThisPassword, int &t){
    string cracked;
    
    while (cracked != crackThisPassword){
        cracked;
        cracked = randomLowerCharacter();
        cracked += randomInt();
        cracked += randomCapitalCharacter();
        cracked += randomSpecialCharacter();
        cracked += randomLowerCharacter();
        cracked += randomInt();
        cout << cracked << ' ';
        t++;
    }
    
    cout << endl << endl;
    return cracked;
}




