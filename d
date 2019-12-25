#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, i, j;

	vector<int> answer;
	queue<int> q1;
	queue<int> q2;
	
	cin >> n;

	int temp;
	for(i = 0; i < n; i++) {
		cin >> temp;

		if(temp > 0) {
			q1.push(temp);
		} else {
			q2.push(temp);
		}
		
		cout << q1.size() << ' ' << q2.size() << '\n';
		cout << temp << '\n';
	}
	
	while(!q1.empty()) {
		temp = q1.front();
		answer[i] = temp;
		i++;
		q1.pop();
	}
	
	while(!q2.empty()) {
		temp = q2.front();
		answer[i] = temp;
		i++;
		q2.pop();
	}

	for(i = 0; i < n; i++) {
		cout << answer[i] << ' ';
	}
	
	return 0;
}

