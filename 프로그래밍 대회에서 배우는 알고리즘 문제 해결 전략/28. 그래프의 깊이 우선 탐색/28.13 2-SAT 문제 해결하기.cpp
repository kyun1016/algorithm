//#include<iostream>
//#include<vector>
//#include<stack>
//#include<algorithm>
//
//using namespace std;
//
////그래프의 인접 리스트 표현
//vector<vector<int> > adj;
////같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
//vector<int> sccId;
////각 정점의 발견 순서
//vector<int> discovered;
////정점의 번호를 담는 스택
//stack<int> st;
//int sccCounter, vertexCounter;
////here를 루트로 하는 서브트리에서 역방향 간선이나 교차 간선을
////통해 갈 수 있는 정점 중 최소 발견 순서를 반환한다.
////(이미 SCC로 묶인 정점으로 연결된 교차 간선은 무시한다)
//int scc(int here) {
//	int ret = discovered[here] = vertexCounter++;
//	//스택에 here을 넣는다. here의 후손들은 모두 스택에서 here후에 들어간다.
//	st.push(here);
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		//(here, there)가 트리 간선
//		if (discovered[there] == -1)
//			ret = min(ret, scc(there));
//		//there가 무시해야 하는 쿄차간선이 아니라면
//		else if (sccId[there] == -1)
//			ret = min(ret, discovered[there]);
//	}
//	//here에서 부모로 올라가는 간선을 끊어야 할지 확인한다.
//	if (ret == discovered[here]) {
//		//here를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다.
//		while (true) {
//			int t = st.top();
//			st.pop();
//			sccId[t] = sccCounter;
//			if (t == here)
//				break;
//		}
//		++sccCounter;
//	}
//	return ret;
//}
//
////tarjan의 SCC알고리즘
//vector<int> tarjanSCC() {
//	//배열들을 전부 초기화
//	sccId = discovered = vector<int>(adj.size(), -1);
//	//카운터 초기화
//	sccCounter = vertexCounter = 0;
//	//모든 정점에 대해 scc() 호출
//	for (int i = 0; i < adj.size(); i++)
//		if (discovered[i] == -1)
//			scc(i);
//	return sccId;
//}
//
//
////adj에 함의 그래프의 인접 리스트 표현이 주어질 때, 2-SAT 문제의 답을 반환한다.
//vector<int> solve2SAT() {
//	int n = adj.size() / 2;	//변수의 수
//	//함의 그래프의 정점들을 강결합 요소별로 묶는다.
//	vector<int> label = tarjanSCC();
//	//이 SAT 문제를 푸는 것이 불가능한지 화인한다. 한 변수를 나타내는 두 정점이
//	//같은 강결합 요소에 속해 있을 경우 답이 없다.
//	for(int i=0; i<2*n; i+= 2)
//		if(label[i] == label[i+1])
//			return vector<int>();
//	//SAT문제를 푸는 것이 가능하다. 답을 생성하자!
//	vector<int> value(2 * n, -1);
//	//Tarjan 알고리즘에서 SCC번호는 위상 정렬의 역순으로 배정된다.
//	//SCC 번호의 역순으로 각 정점을 정렬하면 위상 정렬 순서가 된다.
//	vector<pair<int, int> > order;
//	for (int i = 0; i < 2 * n; i++)
//		order.push_back(make_pair(-label[i], i));
//	sort(order.begin(), order.end());
//	//각 정점에 값을 배정한다.
//	for (int i = 0; i < 2 * n; i++) {
//		int vertex = order[i].second;
//		int variable = vertex / 2, isTrue = vertex % 2 == 0;
//		if (value[variable] != -1) continue;
//		// not A가 A보다 먼저 나왔다면 A는 참
//		//A가 not A보다 먼저 나왔다면 A는 거짓
//		value[variable] = !isTrue;
//	}
//	return value;
//}