#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int Min = x;
	if (y < x)
		Min = y;
	if (w - x < Min)
		Min = w - x;
	if (h - y < Min)
		Min = h - y;

	cout << Min;

	return 0;
}