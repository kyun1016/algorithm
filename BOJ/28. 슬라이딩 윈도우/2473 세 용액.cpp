#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long> acid;
vector<long long> MixAcid;
vector<long long> basic;
vector<long long> MixBasic;

bool cmp(long long a, long long b) {
	return abs(a) < abs(b);
}

bool cmp2(pair<long long, pair<int, int> > a, pair<long long, pair<int, int> > b) {
	return abs(a.first) < abs(b.first);
}


pair<int, int> findRoot(long long a) {
	if (a > 0) {
		for (int i = 0; i < acid.size(); i++)
			for (int j = i + 1; j< acid.size(); j++)
				if (acid[i] + acid[j] == a)
					return { acid[i], acid[j] };

	}
	else {
		for (int i = 0; i < basic.size(); i++)
			for (int j = i + 1; j <basic.size(); j++)
				if (basic[i] + basic[j] == a)
					return { basic[i], basic[j] };
	}

	return { 0,0 };
}


int main() {
	long long N,temp;
	long long ret = 3000000007;
	long long sol[3];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 0)
			acid.push_back(temp);
		else
			basic.push_back(temp);
	}

	sort(acid.begin(), acid.end());
	sort(basic.begin(), basic.end(), cmp);

	if (acid.size() == 0) {
	sol[0] = basic[0];
	sol[1] = basic[1];
	sol[2] = basic[2];
	sort(sol, sol + 3);
	cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;

	return 0;
	}
	else if (basic.size() == 0) {
	sol[0] = acid[0];
	sol[1] = acid[1];
	sol[2] = acid[2];
	sort(sol, sol + 3);
	cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;

	return 0;
	}

	else if (acid.size() == 1) {
		if (abs(acid[0] + basic[0] + basic[1]) < abs(basic[0] + basic[1] + basic[2])) {
			sol[0] = acid[0];
			sol[1] = basic[0];
			sol[2] = basic[1];
			sort(sol, sol + 3);
			cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;

			return 0;
		}
		else {
			sol[0] = basic[0];
			sol[1] = basic[1];
			sol[2] = basic[2];
			sort(sol, sol + 3);
			cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;

			return 0;
		}
	}
	else if (basic.size() == 1) {
		if (abs(acid[0] + basic[0] + acid[1]) < abs(acid[0] + acid[1] + acid[2])) {
			sol[0] = acid[0];
			sol[1] = basic[0];
			sol[2] = acid[1];
			sort(sol, sol + 3);
			cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;

			return 0;
		}
		else {
			sol[0] = acid[0];
			sol[1] = acid[1];
			sol[2] = acid[2];
			sort(sol, sol + 3);
			cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;

			return 0;
		}
	}
	
	for (int i = 0; i < acid.size() - 1; i++)
		for (int j = i + 1; j < acid.size(); j++)
			MixAcid.push_back(acid[i] + acid[j]);

	for (int i = 0; i < basic.size(); i++)
		MixAcid.push_back(basic[i]);

	for (int i = 0; i < basic.size() - 1; i++)
		for (int j = i + 1; j < basic.size(); j++)
			MixBasic.push_back(basic[i] + basic[j]);

	for (int i = 0; i < acid.size(); i++)
		MixBasic.push_back(acid[i]);
	

	sort(MixAcid.begin(), MixAcid.end(), cmp);
	sort(MixBasic.begin(), MixBasic.end(), cmp);


	
	if (acid.size() >= 3) {
		ret = abs(basic[0] + basic[1] + basic[2]);
		sol[0] = acid[0];
		sol[1] = acid[1];
		sol[2] = acid[2];
	}

	if(basic.size() >=3 && ret > abs(basic[0] + basic[1] + basic[2])){
		ret = abs(basic[0] + basic[1] + basic[2]);
		sol[0] = basic[0];
		sol[1] = basic[1];
		sol[2] = basic[2];
	}


	for (int i = 1; i < MixAcid.size(); i++) {
		if (ret > abs(MixAcid[i] + MixAcid[i - 1])) {
			if (MixAcid[i] < 0 && MixAcid[i-1] > 0) {
				sol[0] = MixAcid[i];
				pair<int, int> a = findRoot(MixAcid[i - 1]);
				sol[1] = a.first;
				sol[2] = a.second;
			}
			else if(MixAcid[i] > 0 && MixAcid[i - 1] < 0) {
				sol[0] = MixAcid[i - 1];
				pair<int, int> a = findRoot(MixAcid[i]);
				sol[1] = a.first;
				sol[2] = a.second;
			}
		}
	}
	
	
	for (int i = 1; i < MixBasic.size(); i++) {
		if (ret > abs(MixBasic[i] + MixBasic[i - 1])) {
			if (MixBasic[i] > 0 && MixBasic[i-1] < 0) {
				sol[0] = MixBasic[i];
				pair<int, int> a = findRoot(MixBasic[i - 1]);
				sol[1] = a.first;
				sol[2] = a.second;
			}
			else if(MixBasic[i] < 0 && MixBasic[i - 1] > 0) {
				sol[0] = MixBasic[i - 1];
				pair<int, int> a = findRoot(MixBasic[i]);
				sol[1] = a.first;
				sol[2] = a.second;
			}
		}
	}

	sort(sol, sol + 3);
	cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;

	return 0;
}