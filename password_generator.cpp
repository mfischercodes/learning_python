#include <iostream>
#include <string>

using namespace std;

string generator();

int main(){
    cout << generator() << endl;
    return 0;
}

string generator(){
    std::string word = "This will turn into a random generator!";
    return word;
}