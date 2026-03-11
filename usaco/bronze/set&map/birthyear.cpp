#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n; 
    map<string, int> original = {
        {"Ox", 0},
        {"Tiger", 1},
        {"Rabbit", 2},
        {"Dragon", 3},
        {"Snake", 4},
        {"Horse", 5},
        {"Goat", 6},
        {"Monkey", 7},
        {"Rooster", 8},
        {"Dog", 9},
        {"Pig", 10},
        {"Rat", 11}
    };
    map<string, string> months;
    map<string, int> ages;
    ages["Bessie"] = 0;
    months["Bessie"] = "Ox";
    cin.ignore();
    for (int x=0;x<n;x++) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        string startCow = words[0];
        string dir = words[3];
        string finalMonth = words[4];
        string endCow = words[7];

        int startMonth = original[months[endCow]];
        int ctr = 1;
        int endCowAge = ages[endCow];

        if (dir == "next") { 
            int start = (startMonth+1)%12;
            while (start != original[finalMonth]) {
                start = (start+1)%12;
                ctr += 1;
            }
            ages[startCow] = endCowAge + ctr;
        } else {
            int start = (startMonth-1+12)%12;
            while (start != original[finalMonth]) {
                start = (start-1+12)%12;
                ctr += 1;
            }
            ages[startCow] = endCowAge - ctr;
        }
        months[startCow] = finalMonth;
    }
    cout << abs(ages["Elsie"]-ages["Bessie"]);
}