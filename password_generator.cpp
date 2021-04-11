#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <chrono>
#include <tuple>
#include <math.h>
#include <functional>

using namespace std::chrono;
using namespace std;

#pragma region Function_Declaration
string randomGenerator(int numberOfCharacters);
string randomLowerGenerator(int numberOfCharacters);
char randomCapitalCharacter();
char randomLowerCharacter();
char randomSpecialCharacter();
char randomInt();

string decryption(string crackThisPassword, int &t, int passLength);
string lowerCaseDecryption(string crackThisPassword, int &t, int length);
string timeElapsed(long long seconds);

#pragma endregion Function_Declaration

/* TODO:
    OPTIMIZE DECRYPTION
    Start at character 65 instead of special characters. and use math 37 + and some module? to check the special characters later.

    *****Iterate for loops according to random Generator number input*****

    How to pass a function as a paramtere to another function so I can clean up the
    START STOP time into a function passing in the function as a parameter.

    GET RANDOM TO ACTUALLY BE RANDOM
    DEFAULT VALUE FOR FUNCTIONS? NOT WORKING
    true and false for if each function allowed to be called in the random.
    each function must be called atleast one time.
    random order of using each function
*/

int main(){
    srand((unsigned int) time(NULL));
    string password = "t!Z";
    int passwordLength = password.length();
    //int passwordLength = 6;
    //string password = randomGenerator(passwordLength);
    int iterations = 0;

    auto start = high_resolution_clock::now();
    string decrpyt = decryption(password, iterations, passwordLength);
    auto stop = high_resolution_clock::now();

    string timeTaken = timeElapsed(duration_cast<seconds>(stop - start).count());
    cout << endl << "Password: " << password << " : " << decrpyt << endl << "Time taken to decrpt " << timeTaken << endl << "Decryption attemps: " << iterations << endl;

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
string timeElapsed(long long seconds){
    string result;
    result += to_string((int)seconds / 60); // minutes
    result += ':' + to_string((int)seconds % 60); //seconds
    return result;
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
string randomLowerGenerator(int numberOfCharacters = 8){
    char randomCharacterTypes[4] = {randomLowerCharacter(),randomInt(), randomCapitalCharacter(), randomSpecialCharacter()};
    std::string password;

    for (int i = 0; i < numberOfCharacters; i++){
        //password += randomCharacterTypes[(rand()%4)%4];
        //above will work once i get random being actually random.
        //password += randomCharacterTypes[i%4];
        password += randomLowerCharacter();
    }
    return password;
}
string lowerCaseDecryption(string crackThisPassword, int &t, int length){
    int i = 97;
    int x = 0;
    int guessingLength = 1;
    int lengthIterator = 0;
    string cracked;

    while (true){
        int nextLetter = pow(123, guessingLength);
        cracked[0] = i% nextLetter;
        cracked[1] = i% nextLetter;

        cout << cracked << ' ';
        t++;
        i++;
        if (i%123 == 0){
                    i += 96;
                    guessingLength++;
                }

        if (cracked == crackThisPassword){
            cout << endl;
            break;
        }
        
    }
    return cracked;

    while (true){
        //cout << cracked << ' ';
        // string length depending on x length

        //cracked = i%123; // iterates through alhpabet
        for (int characterPosition = 0; characterPosition < guessingLength; characterPosition++){
            cracked += i%123;
            cout << cracked << ' ';
        }
        cout << "iterate once" << endl;
        //cracked = i%123 + i%123 etc...
        t++;
        i++;

        if (i%123 == 0){
            i += 96;
            guessingLength++;
        }

        if (cracked == crackThisPassword){
            cout << endl;
            break;
        }
        cracked.clear();

    }
    return cracked;


    /*
    while (true){
        cout << cracked << ' ';
        cracked[length-1] = i%123;
        t++;
        
        if (cracked == crackThisPassword){
            cout << endl;
            break;
        }
        
        if (i % 123 == 0){
            i += 96;
            lengthIterator++;
            cracked[length-2] = i%123 + lengthIterator%26;

            //if iterator mod 26 then -2 should be -3 for 1 turn
        }
        i++;

        // cracked[length-2] = i%123 + lengthIterator%26;

        // check if ran 26 times if so then increment 3rd one once then continue to increment
        //cracked[length - ?]
        
        // iterator % 26 == 0 for step size?
        // 97 - 126 for last char
        // aaa
        // % 123 increment second character once
        // aba
        // incrementor for each loop 26 times length?
        // instead of -2 - 1 we do i / 126
        
    }

    // first character is up to mode 122 * length
    // second is 122 * length
    // will increment aa,ab,ac etc...
        return cracked;
    
    
    // store a loop through all
    // store b loop through all
    */
}
string decryption(string crackThisPassword, int &t, int passLength){
    string cracked;

    switch (passLength){
        case 1:
            for (int i1 = 33; i1 <= 126; i1++){
                cout << cracked << ' ';
                cracked.clear();
                cracked += i1;
                t++;
                if (cracked == crackThisPassword){
                    cout << endl;
                    return cracked;
                }
            }
        case 2:
            for (int i1 = 33; i1 <= 126; i1++){
                for (int i2 = 33; i2 <= 126; i2++){
                    cout << cracked << ' ';
                    cracked.clear();
                    cracked += i1;
                    t++;
                    if (cracked == crackThisPassword){
                        cout << endl;
                        return cracked;
                    }
                }
            }
        case 3:
            for (int i1 = 33; i1 <= 126; i1++){
                for (int i2 = 33; i2 <= 126; i2++){
                    for (int i3 = 33; i3 <= 126; i3++){
                        cout << cracked << ' ';
                        cracked.clear();
                        cracked += i1;
                        cracked += i2;
                        cracked += i3;
                        t++;
                        if (cracked == crackThisPassword){
                            cout << endl;
                            return cracked;
                        }
                    }
                }
            }
        case 4:
            for (int i1 = 33; i1 <= 126; i1++){
                for (int i2 = 33; i2 <= 126; i2++){
                    for (int i3 = 33; i3 <= 126; i3++){
                        for (int i4 = 33; i4 <= 126; i4++){
                            cout << cracked << ' ';
                            cracked.clear();
                            cracked += i1;
                            cracked += i2;
                            cracked += i3;
                            cracked += i4;
                            t++;
                            if (cracked == crackThisPassword){
                                cout << endl;
                                return cracked;
                            }
                        }
                    }
                }
            }
        case 5:
            for (int i1 = 33; i1 <= 126; i1++){
                for (int i2 = 33; i2 <= 126; i2++){
                    for (int i3 = 33; i3 <= 126; i3++){
                        for (int i4 = 33; i4 <= 126; i4++){
                            for (int i5 = 33; i5 <= 126; i5++){
                                cout << cracked << ' ';
                                cracked.clear();
                                cracked += i1;
                                cracked += i2;
                                cracked += i3;
                                cracked += i4;
                                cracked += i5;
                                t++;
                                if (cracked == crackThisPassword){
                                    cout << endl;
                                    return cracked;
                                } 
                            }
                        }
                    }
                }
            }
        case 6:
            for (int i1 = 33; i1 <= 126; i1++){
                for (int i2 = 33; i2 <= 126; i2++){
                    for (int i3 = 33; i3 <= 126; i3++){
                        for (int i4 = 33; i4 <= 126; i4++){
                            for (int i5 = 33; i5 <= 126; i5++){
                                for (int i6 = 33; i6 <= 126; i6++){
                                    cout << cracked << ' ';
                                    cracked.clear();
                                    cracked += i1; cracked += i2; cracked += i3;
                                    cracked += i4; cracked += i5; cracked += i6;
                                    t++;
                                    if (cracked == crackThisPassword){
                                        cout << endl;
                                        return cracked;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        case 7:
            for (int i1 = 33; i1 <= 126; i1++){
                for (int i2 = 33; i2 <= 126; i2++){
                    for (int i3 = 33; i3 <= 126; i3++){
                        for (int i4 = 33; i4 <= 126; i4++){
                            for (int i5 = 33; i5 <= 126; i5++){
                                for (int i6 = 33; i6 <= 126; i6++){
                                    for (int i7 = 33; i7 <= 126; i7++){
                                        cout << cracked << ' ';
                                        cracked.clear();
                                        cracked += i1; cracked += i2; cracked += i3;
                                        cracked += i4; cracked += i5; cracked += i6; cracked += i7;
                                        t++;
                                        if (cracked == crackThisPassword){
                                            cout << endl;
                                            return cracked;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        case 8:
            for (int i1 = 33; i1 <= 126; i1++){
                for (int i2 = 33; i2 <= 126; i2++){
                    for (int i3 = 33; i3 <= 126; i3++){
                        for (int i4 = 33; i4 <= 126; i4++){
                            for (int i5 = 33; i5 <= 126; i5++){
                                for (int i6 = 33; i6 <= 126; i6++){
                                    for (int i7 = 33; i7 <= 126; i7++){
                                        for (int i8 = 33; i8 <= 126; i8++){
                                            cout << cracked << ' ';
                                            cracked.clear();
                                            cracked += i1; cracked += i2; cracked += i3; cracked += i4;
                                            cracked += i5; cracked += i6; cracked += i7; cracked += i8;
                                            t++;
                                            if (cracked == crackThisPassword){
                                                cout << endl;
                                                return cracked;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    }


    /*
    while (cracked != crackThisPassword){
        cracked;
        cracked = randomLowerCharacter();
        cracked += randomInt();
        cracked += randomCapitalCharacter();
        cracked += randomSpecialCharacter();
        cout << cracked << ' ';
        t++;
    }
    
    
    
    cout << endl << endl;
    return cracked;
    */
    
}




