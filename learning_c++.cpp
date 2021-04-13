#include <string>
#include <iostream>
#include <time.h>

using namespace std;

string randomGenerator(int numberOfCharacters);
char randomCapitalCharacter();
char randomLowerCharacter();
char randomSpecialCharacter();
char randomInt();

int main(){
    srand((unsigned int) time(NULL));
    int passwordLength = 12;
    string password = randomGenerator(passwordLength);
    cout << password << endl;
    return 0;
}

string randomGenerator(int numberOfCharacters){
    char randomCharacterTypes[4] = {randomLowerCharacter(),randomInt(), randomCapitalCharacter(), randomSpecialCharacter()};
    std::string password;

    while (numberOfCharacters > 0){
        int random = rand()%4;
        switch(random){
            case 0:
                password += randomLowerCharacter();
                break;
            case 1:
                password += randomInt();
                break;
            case 2:
                password += randomCapitalCharacter();
                break;
            case 3:
                password += randomSpecialCharacter();
                break;
        }
        numberOfCharacters--;
    }
    return password;
}
char randomInt(){
    std::string numberAsString = to_string(std::rand()% 10);
    char randomNumberChar = numberAsString.at(0);
    return randomNumberChar;
}
char randomLowerCharacter(){
    return 'a' + rand()%26;
}
char randomCapitalCharacter(){
    return 'A' + rand()%26;
}
char randomSpecialCharacter(){
    /** Special characters are split by numbers so we pick a random from one of the 2 groups.*/
    return (rand()%2) ? char(33 + rand()%14) : char(58 + rand()%8); 
}