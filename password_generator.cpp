#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <chrono>
#include <tuple>
#include <math.h>
#include <functional>
#include <vector>

using namespace std::chrono;
using namespace std;

#pragma region Function_Declaration
string randomGenerator(int numberOfCharacters);
string randomLowerGenerator(int numberOfCharacters);
char randomCapitalCharacter();
char randomLowerCharacter();
char randomSpecialCharacter();
char randomInt();
bool validatePassword(string password, bool lower, bool upper, bool number, bool special);

string optamizedDecryption(string crackThisPassword, int &t, int passLength);
string decryption(string crackThisPassword, int &t, int passLength);
string lowerCaseDecryption(string crackThisPassword, int &t, int length);
string timeElapsed(long long seconds);
#pragma endregion Function_Declaration

int main(){
    srand((unsigned int) time(NULL));
    //string password = "xs)";
    //int passwordLength = password.length();
    int passwordLength = 20;
    string password = randomGenerator(passwordLength);
    cout << "Password: " << password << endl;
    int iterations = 0;
    
    auto start = high_resolution_clock::now();
    //string decrpyt = optamizedDecryption(password, iterations, passwordLength);
    //string decrpyt = decryption(password, iterations, passwordLength);
    auto stop = high_resolution_clock::now();

    string timeTaken = timeElapsed(duration_cast<seconds>(stop - start).count());
    //cout << endl << "Password: " << password << " : " << decrpyt << endl << "Time taken to decrpt " << timeTaken << endl << "Decryption attemps: " << iterations << endl;
    

    return 0;
}

char randomInt(){
    return '0' + rand()%10;
}
char randomLowerCharacter(){
    return 'a' + rand()%26;
}
char randomCapitalCharacter(){
    return 'A' + rand()%26; 
}
char randomSpecialCharacter(){
    /** Special characters are split by numbers so we pick a random from one of the 2 groups.*/
    char specialCase[] = {'!','"','+','@','#','$','%','^','&','*','(',')','?','~'};
    return specialCase[rand()%(sizeof(specialCase)/sizeof(specialCase[0]))];
    return (rand()%2) ? char(33 + rand()%14) : char(58 + rand()%8); 
}
string timeElapsed(long long seconds){
    string result;
    result += to_string((int)seconds / 3600); // minutes
    result += ':' + to_string(((int)seconds %3600) / 60); // minutes
    result += ':' + to_string((int)seconds % 60); //seconds
    return result;
}
string randomGenerator(int numberOfCharacters){
    char (*randomCharacter[])() = {randomLowerCharacter, randomInt, randomCapitalCharacter, randomSpecialCharacter};
    int baseNumbers = numberOfCharacters;
    std::string password;

    while (true){
        while (numberOfCharacters-- > 0){
            password += randomCharacter[rand()%4]();
        }
        if (validatePassword(password, true, true, true, true) == false){
            //cout << password << endl;
            password.clear();
            numberOfCharacters = baseNumbers;
            continue;
        }
        break;
    }
    return password;
    /* switch statement
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
            */
        
}
bool validatePassword(string password, bool lower, bool upper, bool number, bool special){
    std::string lowerLetter, upperLetter, numberLetter, specialLetter;
    bool validator[4] = {false,false,false,false};
    char specialCase[14] = {'!','"','+','@','#','$','%','^','&','*','(',')','?','~'};

    if (password.length() < 4){
        lower = false; upper = false; number= false; special = false;
        cout << endl << "ERROR: YOU ARE TRYING TO VALIDATE 4 CHARACTER TYPES WITH A PASSWORD LENGTH OF LESS THAN 4!"
        << "\nIn validate Password turn one boolean to false or increase password length." << endl;
    }

    if (lower == true || upper == true){
        for (int i = 0; i < 26; i++){
            lowerLetter = 'a' + i;
            upperLetter = 'A' + i;
            if (lower == true){
                if (password.find(lowerLetter) != std::string::npos){
                validator[0] = true;
                }
            }
            if (upper == true){
                if (password.find(upperLetter) != std::string::npos){
                validator[1] = true;
                }
            }
            
        }
    }

    if (number == true){
        for (int i = 0; i < 10; i++){
            numberLetter = '0'+ i;
            if (password.find(numberLetter) != std::string::npos){
                validator[2] = true;
            }
        }
    }
    else{
        validator[2] = number;
    }

    if (special == true){
        for (int i = 0; i < sizeof(specialCase)/sizeof(specialCase[0]); i++){
            specialLetter = specialCase[i];
            if (password.find(specialLetter) != std::string::npos){
                validator[3] = true;
            }
        }
    }
    else{
        validator[3] = special;
    }

    return ((validator[0] == lower ) && (validator[1] == upper) && (validator[2] == number) && (validator[3] == special)) ? true : false;
    
    
}
string randomLowerGenerator(int numberOfCharacters = 8){
    std::string password;
    for (int i = 0; i < numberOfCharacters; i++){
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
                    cracked += i2;
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
    return "Nothing";
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
string optamizedDecryption(string crackThisPassword, int &t, int passLength){
    string cracked;

    std::vector<char> organizedCharacters = {};
    char lowerCase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char upperCase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char numberCase[10] = {'0','1','2','3','4','5','6','7','8','9'};
    for (int i = 0; i < 26; i++){
        organizedCharacters.push_back(lowerCase[i]);
    }    
    for (int i = 0; i < 26; i++){
        organizedCharacters.push_back(upperCase[i]);
    }   
    for (int i = 0; i < 10; i++){
        organizedCharacters.push_back(numberCase[i]);
    }   

    std::vector<char> organizedCharactersSpecial = organizedCharacters;
    char specialCase[12] = {'!','@','#','$','%','^','&','*','(',')','?','~'};
    for (int i = 0; i < 12; i++){
        organizedCharactersSpecial.push_back(specialCase[i]);
    } 

    int sizeOfArray = sizeof(organizedCharacters) / sizeof(organizedCharacters[0]); // 56 / 1
    
    switch (passLength){
        case 1:
            for (int i = 0; i < 62; i++){
                cracked.clear();
                cracked += organizedCharacters[i];
                cout << cracked << ' ';
                t++;

                if (cracked == crackThisPassword){
                    cout << endl;
                    return cracked;
                }
            }
            break;
        case 2:
            for (int i1 = 0; i1 < 74; i1++){
                for (int i2 = 0; i2 < 74; i2++){
                    cracked.clear();
                    cracked += organizedCharactersSpecial[i1]; cracked += organizedCharactersSpecial[i2];
                    cout << cracked << ' ';
                    t++;

                    if (cracked == crackThisPassword){
                        cout << endl;
                        return cracked;
                    }
                }
            }
            break;
        case 3:
            for (int i1 = 0; i1 < 74; i1++){
                for (int i2 = 0; i2 < 62; i2++){
                    for (int i3 = 0; i3 < 74; i3++){
                        cracked.clear();
                        cracked += organizedCharactersSpecial[i1]; cracked += organizedCharactersSpecial[i2];
                        cracked += organizedCharactersSpecial[i3];
                        cout << cracked << ' ';
                        t++;

                        if (cracked == crackThisPassword){
                            cout << endl;
                            return cracked;
                        }
                    }
                }
            }
            break;
        case 4:
            for (int i1 = 0; i1 < 74; i1++){
                for (int i2 = 0; i2 < 62; i2++){
                    for (int i3 = 0; i3 < 62; i3++){
                        for (int i4 = 0; i4 < 74; i4++){
                            cracked.clear();
                            cracked += organizedCharactersSpecial[i1]; cracked += organizedCharactersSpecial[i2];
                            cracked += organizedCharactersSpecial[i3]; cracked += organizedCharactersSpecial[i4];
                            cout << cracked << ' ';
                            t++;

                            if (cracked == crackThisPassword){
                                cout << endl;
                                return cracked;
                            }
                        }
                    }
                }
            }
            break;
        case 5:
            for (int i1 = 0; i1 < 74; i1++){
                for (int i2 = 0; i2 < 62; i2++){
                    for (int i3 = 0; i3 < 62; i3++){
                        for (int i4 = 0; i4 < 62; i4++){
                            for (int i5 = 0; i5 < 74; i5++){
                                cracked.clear();
                                cracked += organizedCharactersSpecial[i1]; cracked += organizedCharactersSpecial[i2];
                                cracked += organizedCharactersSpecial[i3]; cracked += organizedCharactersSpecial[i4];
                                cracked += organizedCharactersSpecial[i5];
                                cout << cracked << ' ';
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
            break;
        case 6:
            for (int i1 = 0; i1 < 74; i1++){
                for (int i2 = 0; i2 < 62; i2++){
                    for (int i3 = 0; i3 < 62; i3++){
                        for (int i4 = 0; i4 < 62; i4++){
                            for (int i5 = 0; i5 < 62; i5++){
                                for (int i6 = 0; i6 < 74; i6++){
                                    cracked.clear();
                                    cracked += organizedCharactersSpecial[i1]; cracked += organizedCharactersSpecial[i2];
                                    cracked += organizedCharactersSpecial[i3]; cracked += organizedCharactersSpecial[i4];
                                    cracked += organizedCharactersSpecial[i5]; cracked += organizedCharactersSpecial[i6];
                                    cout << cracked << ' ';
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
            break;
        case 7:
            for (int i1 = 0; i1 < 74; i1++){
                for (int i2 = 0; i2 < 62; i2++){
                    for (int i3 = 0; i3 < 62; i3++){
                        for (int i4 = 0; i4 < 62; i4++){
                            for (int i5 = 0; i5 < 62; i5++){
                                for (int i6 = 0; i6 < 62; i6++){
                                    for (int i7 = 0; i7 < 74; i7++){
                                        cracked.clear();
                                        cracked += organizedCharactersSpecial[i1]; cracked += organizedCharactersSpecial[i2];
                                        cracked += organizedCharactersSpecial[i3]; cracked += organizedCharactersSpecial[i4];
                                        cracked += organizedCharactersSpecial[i5]; cracked += organizedCharactersSpecial[i6];
                                        cracked += organizedCharactersSpecial[i7];
                                        cout << cracked << ' ';
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
            break;
        case 8:
            for (int i1 = 0; i1 < 74; i1++){
                for (int i2 = 0; i2 < 62; i2++){
                    for (int i3 = 0; i3 < 62; i3++){
                        for (int i4 = 0; i4 < 62; i4++){
                            for (int i5 = 0; i5 < 62; i5++){
                                for (int i6 = 0; i6 < 62; i6++){
                                    for (int i7 = 0; i7 < 62; i7++){
                                        for (int i8 = 0; i8 < 74; i8++){
                                            cracked.clear();
                                            cracked += organizedCharactersSpecial[i1]; cracked += organizedCharactersSpecial[i2];
                                            cracked += organizedCharactersSpecial[i3]; cracked += organizedCharactersSpecial[i4];
                                            cracked += organizedCharactersSpecial[i5]; cracked += organizedCharactersSpecial[i6];
                                            cracked += organizedCharactersSpecial[i7]; cracked += organizedCharactersSpecial[i8];
                                            cout << cracked << ' ';
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
            break;
    }
    return "Nothing";
}



