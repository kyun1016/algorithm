#include<iostream>
#include<algorithm>

int arr[10001];

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int N;
	std::cin >> N;
	int this_Num = 666;
	int count = 1;
	while (1) {
		if (N == count)
			break;
		this_Num++;
		int copy_Num = this_Num;
		int flag = 0;
		while (copy_Num) {
			int temp = copy_Num % 10;
			if (temp == 6)
				flag++;
			else if (flag < 3)
				flag = 0;
			copy_Num /= 10;
		}
		if (flag >= 3)
			count++;
	}

	std::cout << this_Num;

	return 0;
}