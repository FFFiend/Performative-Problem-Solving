#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream fin("traffic.in");
	ofstream fout("traffic.out");
	int n;
	fin >> n;
	vector<pair<string, pair<int, int>>> vec;
	for (int x=0;x<n;x++) {
		string s;
		int l, r;
		fin >> s >> l >> r;
		vec.push_back({s,{l,r}});
	}
	pair<int, int> front = {0,0};
	pair<int, int> back = {0,0};
	int frontIdx, backIdx;
	for (int x=0;x<n;x++) {
		if (vec[x].first == "none") {
			back.first = vec[x].second.first;
			back.second = vec[x].second.second;
			backIdx = x;
		}
	}
	for (int x=n-1;x>=0;x--) {
		if (vec[x].first == "none") {
			front.first = vec[x].second.first;
			front.second = vec[x].second.second;
			frontIdx = x;
		}
	}
	// back, 
	for (int x=frontIdx+1;x<n;x++) {
		if (vec[x].first == "none") {
			front.first = max(front.first, vec[x].second.first);
			front.second = min(front.second, vec[x].second.second);
		} else {
			if (vec[x].first == "on") {
				front.first += vec[x].second.first;
				front.second += vec[x].second.second;
			} else {
				front.first -= vec[x].second.second;
				front.second -= vec[x].second.first;
			}
		}
	}

	for (int x=backIdx-1;x>=0;x--) {
		if (vec[x].first == "none") {
			back.first = max(back.first, vec[x].second.first);
			back.second = min(back.second, vec[x].second.second);
		} else {
			if (vec[x].first == "on") {
				back.first -= vec[x].second.second;
				back.second -= vec[x].second.first;
			} else {
				back.first += vec[x].second.first;
				back.second += vec[x].second.second;
			}
		}
	}
	back.first = max(back.first, 0);
	back.second = max(back.second, 0);
	front.first = max(front.first, 0);
	front.second = max(front.second, 0);
	fout << back.first << " " << back.second << endl;
	fout << front.first << " " << front.second << endl;
	return 0;
}
