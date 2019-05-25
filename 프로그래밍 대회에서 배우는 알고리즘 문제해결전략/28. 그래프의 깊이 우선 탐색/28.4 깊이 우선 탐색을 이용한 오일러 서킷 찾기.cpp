//#include<iostream>
//#include<vector>
//
//using namespace std;
//
////그래프의 인접 행렬 표현. adj[i][j]=i와 j사이의 간선의 수
//vector<vector<int> > adj;
////무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
////결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다.
//void getEulerCircuit(int here, vector<int>& circuit) {
//	for (int there = 0; there < adj.size(); ++there) {
//		while (adj[here][there] > 0) {
//			adj[here][there]--;	//양쪽 간선을 모두 지운다.
//			adj[there][here]--;
//			getEulerCircuit(there, circuit);
//		}
//	}
//	circuit.push_back(here);
//}