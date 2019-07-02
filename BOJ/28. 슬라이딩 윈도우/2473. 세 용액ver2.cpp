//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector<long long> Acid;
//vector<long long> Basic;
//
//vector<pair<long long, pair<int, int> > > AcidSum;
//vector<pair<long long, pair<int, int> > > BasicSum;
//
//long long Solve[3];
//
//bool cmp(long long a, long long b) {
//	return abs(a) < abs(b);
//}
//
//bool cmp2(pair<long long, pair<int, int> > a, pair<long long, pair<int, int> > b) {
//	return abs(a.first) < abs(b.first);
//}
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int T;
//	long long temp;
//	
//
//	//입력을 받아오자.
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		cin >> temp;
//		if (temp < 0)
//			Basic.push_back(temp);
//		else
//			Acid.push_back(temp);
//	}
//	//가져온 입력을 정렬해준다.
//	sort(Acid.begin(), Acid.end());
//	sort(Basic.begin(), Basic.end(), cmp);
//
//	long long SUM = 3000000000;
//
//	if (Basic.size() >= 3) {
//		SUM = Basic[0] + Basic[1] + Basic[2];
//		SUM = abs(SUM);
//		Solve[2] = Basic[0];
//		Solve[1] = Basic[1];
//		Solve[0] = Basic[2];
//	}
//
//	if (Acid.size() >= 3) {
//		if (SUM > Acid[0] + Acid[1] + Acid[2]) {
//			Solve[0] = Acid[0];
//			Solve[1] = Acid[1];
//			Solve[2] = Acid[2];
//		}
//	}
//
//	//3가지를 모두 더하도록 함수를 만든다면, 5000*5000*5000으로 시간초과를 하게된다.
////따라서 2개를 더한 배열을 만든 이후, 나머지 하나를 더해주는 방식을 택한다면? 5000*5000 + x*5000으로 시간 내 해결 가능!
//	if (Acid.size() >=2) {
//	
//		for (int i = 0; i < Acid.size() - 1; i++)
//			for (int j = i + 1; j < Acid.size(); j++) {
//				AcidSum.push_back({ Acid[i] + Acid[j], {i,j} });
//			}
//		for (int i = 0; i < Basic.size(); i++)
//			AcidSum.push_back({ Basic[i], {i,-1} });
//		sort(AcidSum.begin(), AcidSum.end(), cmp2);
//		for (int i = 0; i < AcidSum.size() - 1; i++) {
//			//인접한 두개의 부호가 다른 경우
//			if (AcidSum[i].first * AcidSum[i + 1].first <= 0) {
//				if (SUM > abs(AcidSum[i].first + AcidSum[i + 1].first)) {
//					SUM = abs(AcidSum[i].first + AcidSum[i + 1].first);
//					if (AcidSum[i].first < 0) {
//						Solve[0] = AcidSum[i].first;
//						Solve[1] = Acid[AcidSum[i + 1].second.first];
//						Solve[2] = Acid[AcidSum[i + 1].second.second];
//					}
//					else {
//						Solve[0] = AcidSum[i + 1].first;
//						Solve[1] = Acid[AcidSum[i].second.first];
//						Solve[2] = Acid[AcidSum[i].second.second];
//					}
//				}
//			}
//		}
//	}
//	
//
//
//
//	
//
//	if (Basic.size() >= 2) {
//		for (int i = 0; i < Basic.size() - 1; i++)
//			for (int j = i + 1; j < Basic.size(); j++) {
//				BasicSum.push_back({ Basic[i] + Basic[j], {j, i} });
//			}
//		for (int i = 0; i < Acid.size(); i++)
//			BasicSum.push_back({ Acid[i], {i,-1} });
//		sort(BasicSum.begin(), BasicSum.end(), cmp2);
//		for (int i = 0; i < BasicSum.size() - 1; i++) {
//			//인접한 두개의 부호가 다른 경우
//			if (BasicSum[i].first * BasicSum[i + 1].first <= 0) {
//				if (SUM > abs(BasicSum[i].first + BasicSum[i + 1].first)) {
//					SUM = abs(BasicSum[i].first + BasicSum[i + 1].first);
//					if (BasicSum[i].first < 0) {
//						Solve[2] = BasicSum[i + 1].first;
//						Solve[0] = Basic[BasicSum[i].second.first];
//						Solve[1] = Basic[BasicSum[i].second.second];
//					}
//					else {
//						Solve[2] = BasicSum[i].first;
//						Solve[0] = Basic[BasicSum[i + 1].second.first];
//						Solve[1] = Basic[BasicSum[i + 1].second.second];
//					}
//				}
//			}
//		}
//	}
//	
//	for (int i = 0; i < 3; i++) {
//		cout << Solve[i] << " ";
//	}
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <climits> //LLONG_MAX

using namespace std;

const int MAX = 5000;
 
int N, idx1, idx2, idx3;
long long minimum;
long long liquid[MAX];

void print3Liquid(void)
{
	for (int i = 0; i < N; i++)
	{
		//양방향에서
		int j = i + 1;
		int k = N - 1;

		while (1)
		{
			if (j >= k)
				break;

			long long sum = liquid[i] + liquid[j] + liquid[k];
			//최소값 갱신 때마다 idx1~idx3 초기화

			if (llabs(sum) < minimum)
			{
				minimum = llabs(sum);
				idx1 = i;
				idx2 = j;
				idx3 = k;
			}
			//오름차순 정렬을 했으므로
			if (sum < 0)
				j++;
			else
				k--;
		}
	}
	cout << liquid[idx1] << " " << liquid[idx2] << " " << liquid[idx3] << endl;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)

		cin >> liquid[i];
	sort(liquid, liquid + N);
	minimum = LLONG_MAX;
	print3Liquid();
	return 0;
}