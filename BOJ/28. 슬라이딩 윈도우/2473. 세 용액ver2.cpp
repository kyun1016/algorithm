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
//	//�Է��� �޾ƿ���.
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		cin >> temp;
//		if (temp < 0)
//			Basic.push_back(temp);
//		else
//			Acid.push_back(temp);
//	}
//	//������ �Է��� �������ش�.
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
//	//3������ ��� ���ϵ��� �Լ��� ����ٸ�, 5000*5000*5000���� �ð��ʰ��� �ϰԵȴ�.
////���� 2���� ���� �迭�� ���� ����, ������ �ϳ��� �����ִ� ����� ���Ѵٸ�? 5000*5000 + x*5000���� �ð� �� �ذ� ����!
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
//			//������ �ΰ��� ��ȣ�� �ٸ� ���
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
//			//������ �ΰ��� ��ȣ�� �ٸ� ���
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
		//����⿡��
		int j = i + 1;
		int k = N - 1;

		while (1)
		{
			if (j >= k)
				break;

			long long sum = liquid[i] + liquid[j] + liquid[k];
			//�ּҰ� ���� ������ idx1~idx3 �ʱ�ȭ

			if (llabs(sum) < minimum)
			{
				minimum = llabs(sum);
				idx1 = i;
				idx2 = j;
				idx3 = k;
			}
			//�������� ������ �����Ƿ�
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