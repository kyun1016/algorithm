#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

//first = x좌표, second = y좌표
vector<pair<ll, ll> > V;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}


//생각해보니까 x축을 기준으로 비교를 하는 것 자체가 불가능한 x소리이다.
//비교를 해야되는 기준점은 각 점들을 비교해주자.
//h는 x축을 밑변으로 가지는 직사각형을 생성 할 것인데, 이 중 변이 가장 긴 것을 찾아보자.
//추가적으로 y축은 2배를 해서 평가하자.
//void cmpDot(const ll& left, const ll& right) {
//	ll xl, xr, h, MAX;
//	xl = V[0].first;
//	xr = V[1].first;
//	h = V[1].second;
//	MAX = min(h*2, xr - xl);
//	for (int i = 0; i < V.size() - 1; i++) {
//		xl = V[i].first;
//		h = V[i + 1].second;
//		xr = V[i + 1].first;
//		ll temp = min(h * 2, xr - xl);
//
//		MAX = max(temp, MAX);
//		for (int j = i + 2; j < V.size(); j++) {
//			xr = V[j].second;
//			ll length = xr - xl;
//			if (h > V[j - 1].second) {
//				if (length > V[j - 1].second * 2) {
//					cout << 2 << endl;
//					h = V[j - 1].second;
//					temp = min(h * 2, length);
//					MAX = max(temp, MAX);
//					break;
//				}
//				else
//					h = V[j - 1].second;
//			}
//			
//				
//			temp = min(h * 2, length);
//			MAX = max(temp, MAX);
//			if (length > h * 2) {
//				cout << 1 << endl;
//				temp = h * 2;
//				MAX = max(temp, MAX);
//				break;		
//			}
//				
//			
//		}
//		cout << "MAX : "<<MAX << endl;
//	}
//	if (MAX % 2 == 1)
//		MAX--;
//	cout << MAX << endl;
//}


ll compareLength(const ll& start, const ll& end) {
	ll xl, xr, h, MAXLength, tempLength;

	MAXLength = 0;


	//원래 좌 우 탐색인데, 이 연산은 입력에서 처리를 바로 해주자.
	////왼쪽을 탐색하자.
	//int i = 0;
	
	//h = V[0].second;
	//while (1) {
	//	//우선 끝까지 하기는 하자.
	//	if (i >= V.size() - 1)
	//		break;
	//	//오른쪽은 i번째 x좌표
	//	xr = V[i].first;
	//	//h는 높이로
	//	if (h > V[0].second)
	//		h = V[0].second;

	//	//x*2와 h*2중 더 작은걸로 값을 가지자.
	//	tempLength = min((xr - start + 1) * 2, h * 2);
	//	//만일 이번의 크기가 최대 크기보다 작아지는 경우에 패스하자.
	//	if (tempLength < MAXLength)
	//		break;
	//	//xr이 start보다 큰 경우에만 시행하자.
	//	if (start < xr) {
	//		MAXLength = max(MAXLength, tempLength);
	//	}
	//	//아니면 탈출
	//	else
	//		break;
	//	i++;
	//}

	////
	//i = V.size() - 1;
	//h = V[i].second;
	//ll temp2 = 0;
	//while (1) {
	//	if (i <= 0)
	//		break;
	//	if (h > V[i].second)
	//		h = V[i].second;
	//	xl = V[i].first;
	//	tempLength = min((end - xl + 1) * 2, h * 2);
	//	if (temp2 > tempLength)
	//		break;
	//	if (end > xl) {
	//		temp2 = max(temp2, tempLength);
	//	}
	//	else
	//		break;
	//	i--;
	//}

	//MAXLength = max(MAXLength, temp2);

	for (int i = 0; i < V.size() - 1; i++) {
		xl = V[i].first;
		h = V[i + 1].second;
		if (xl > end)
			break;
		for (int j = i + 1; j < V.size(); j++) {
			xr = V[j].first;
			if (xr < start)
				break;
			tempLength = min(h * 2, xr - xl);
			if (h > V[j].second) {
				h = V[j].second;
			}
			MAXLength = max(tempLength, MAXLength);
			if (h * 2 < xr - xl)
				break;
		}
	}
	if (MAXLength % 2 == 1)
		MAXLength--;
	return MAXLength;
}



ll countSize(const ll&l, const ll& r) {
	//크기를 키우는 연산
	ll MAXSize = 0;
	ll left, right, height, tempSize;
	for (int i = 0; i < V.size() - 1; i++) {
		left = V[i].first;
		if (left < l)
			continue;
		height = V[i + 1].second;
		for (int j = i + 1; j < V.size(); j++) {
			if (height > V[j-1].second)
				height = V[j-1].second;
			//이 경우에서 높이가 최대 사이즈에 미치지 못한다면 패스.
			if (height * 2 < MAXSize)
				break;
			right = V[j].first;
			tempSize = min(height * 2, left + right);
			MAXSize = max(tempSize, MAXSize);
			if (right > r)
				break;
		}
	}
	return MAXSize;
}


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, test_case, N;
	ll r, l, x, y;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> l >> r >> N;
		ll leftSize, rightSize;
		//크기를 줄이는 연산
		leftSize = 4000000000001; rightSize = 4000000000001;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			y = abs(y);
			V.push_back({ x, y });
			leftSize = max(abs(l - x) * 2, leftSize);
			rightSize = max(abs(r - x) * 2, rightSize);
			if (x >= l - leftSize && x <= l + leftSize) {
				leftSize = min(leftSize, y * 2);
			}
			if (x >= r - rightSize && x <= r + rightSize) {
				rightSize = min(rightSize, y * 2);
			}
		}
		sort(V.begin(), V.end(), cmp);
		/*ll allSize = compareLength(l, r);
		allSize = max(allSize, leftSize);
		allSize = max(allSize, rightSize);*/
		ll MAXSize = countSize(l, r);
		MAXSize = max(MAXSize, rightSize);
		MAXSize = max(MAXSize, leftSize);
		
		cout << "Case #" << test_case + 1 << "\n";
		//cout << allSize << "\n";
		cout << MAXSize << "\n";
		V.clear();
	}

	return 0;//Your program should return 0 on normal termination.
}