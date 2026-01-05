#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ifstream fin("cbarn.in");
	ofstream fout("cbarn.out");
	int n;
	fin >> n;
	vector<int> vec;
	for (int x=0;x<n;x++) {
		int f;
		fin >> f;
		vec.push_back(f);
	}
	int ans = INT_MAX;
	for (int x=0;x<n;x++) {
		int ctr = 1;
		int temp = 0;
		int y = (x+1)%n;
		while (y!=x) {
			temp = (temp + ctr*vec[y]);
			ctr += 1;
			y = (y+1)%n;
		}
		ans = min(ans, temp);
	}
	fout << ans << endl;
}
