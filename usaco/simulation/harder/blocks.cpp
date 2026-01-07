#include <fstream>
#include <string>
#include <vector>

using namespace std;

// void backtrack(int currIdx, int n, vector<string> *stack, vector<pair<string, string>>*p) {
//     if (currIdx >= n) {
//         vector<int> tempfreqmap(26,0);
//         for (int x=0;x<(*stack).size(); x++) {
//             string currWord = (*stack)[x];
//             for (int y = 0; y < currWord.length(); y++) {
//                 tempfreqmap[currWord.at(y) - 'a'] +=1;
//             }
//         }
//         for (int x=0;x<26;x++) {
//             freqmap[x] = max(freqmap[x], tempfreqmap[x]);
//         }
//         return;
//     }
//     string c1 = (*p)[currIdx].first;
//     string c2 = (*p)[currIdx].second;
//     (*stack).push_back(c1);
//     backtrack(currIdx + 1, n, stack, p);
//     (*stack).pop_back();
//     (*stack).push_back(c2);
//     backtrack(currIdx + 1, n, stack, p);
//     (*stack).pop_back();
// }

int main() {

    // brute forced it and had the wrong answer. greedy choice at each step is faster.
	ifstream fin("blocks.in");
	ofstream fout("blocks.out");
    int n;
    fin >> n;
    vector<int> freq(26, 0);
    for (int x=0;x<n;x++) {
        string a,b;
        fin >> a >> b;
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        for (int x=0;x<a.length();x++) m1[a.at(x)-'a'] += 1;
        for (int x=0;x<b.length();x++) m2[b.at(x)-'a'] += 1;
        for (int x=0;x<26;x++) freq[x] += max(m1[x], m2[x]);
    }
    for (int x=0;x<26;x++) fout << freq[x] << endl;
}