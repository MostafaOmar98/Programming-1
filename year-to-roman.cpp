// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: year-to-roman.cpp
// Last Modification Date: 01/03/2018
// Author1 and ID and Group: Ahmed Wessam Fathy 20170372 G14
// Author2 and ID and Group: Mostafa Omar Mahmoud El-Sayed 20170292 G14
// Author3 and ID and Group: Abdelrahman Hussein Ali 20170163 G14
// Teaching Assistant: Eng. Ibrahim Zidan
// Purpose: Writing years in Roman representation

#include<iostream>
using namespace std;

//returns the index of a letter from the roman - number map
int getLetterIndex(char letter, int (&map)[7][2]){
    for(int i = 0; i < 7; ++i){
        if(map[i][0] == (int)letter){
            return i;
        }
    }
}

//converts from a number to roman
string convert(int n, int (&map)[7][2]){
    string year, minimized;
    //get the roman representation without combination
    for(int i = 0; i < 7; ++i){
        while(n-map[i][1] >= 0){
            n -= map[i][1];
            year += map[i][0];
        }
    }
    //combine mixed roman number to minimize representation
    for(int i = 0; i < (int) year.size(); ++i){
        int index = getLetterIndex(year[i], map);
        //combine two letters (the before notation) i.e DCCCC to CM
        if(year[i+1] == map[index + 1][0] && year[i+2] == map[index + 1][0] && year[i+3] == map[index + 1][0]&& year[i+4] == map[index + 1][0]) {
            minimized += map[index + 1][0];
            minimized += map[index - 1][0];
            i += 4;
        }
            //combine 4 times repeated numbers to two, i.e XXXX to XL
        else if(year[i] == year[i+1] && year[i+1] == year[i+2] && year[i+2] == year[i+3]){
            minimized += map[index][0];
            minimized += map[index - 1][0];
            i += 4;
        }else{
            //else apply the letter as it is
            minimized += year[i];
        }
    }
    return minimized;
}

int main(){
    bool running = true;
    int roman[7][2] = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    int year;
    while(running){
        cout << "Please enter a year between 1000 and 3000 : ";
        cin >> year;
        while(cin.fail() || year < 1000 || year > 3000){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error reading the year" << endl;
            cout << "Please re-enter a year between 1000 and 3000 : ";
            cin >> year;
        }
        cout << convert(year, roman) << endl;
        char input;
        cout << "Do you want to convert another year ? (Y for Yes, N to exit) : ";
        cin >> input;
        while(cin.fail() || (tolower(input) != 'y' && tolower(input) != 'n')){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error reading the input" << endl;
            cout << "Please enter Y to convert another year or N no exit : ";
            cin >> input;
        }
        if(tolower(input) == 'n'){
            running = false;
        }
    }
    return 0;
}