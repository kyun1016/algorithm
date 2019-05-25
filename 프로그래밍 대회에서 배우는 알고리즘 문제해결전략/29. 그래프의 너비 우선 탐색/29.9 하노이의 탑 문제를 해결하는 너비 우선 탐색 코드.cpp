//#include<queue>
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAX_DISCS = 12;
//int get(int state, int index) {
//	return (state >> (index * 2)) & 3;
//}
//int set(int state, int index, int value) {
//	return (state & ~(3 << (index * 2))) | (value << (index * 2));
//}
//int c[1 << (MAX_DISCS * 2)];