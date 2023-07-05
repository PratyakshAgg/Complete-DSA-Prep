#include <bits/stdc++.h>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	// Write your code here.
	vector<int> ans;
	queue<int> q;
	int i = 0;

	for(int j = 0; j < n; j++){
		if(arr[j] < 0) q.push(arr[j]);

		if(j - i + 1 == k){
			if(q.size()>0) ans.push_back(q.front());
			else ans.push_back(0);
			
			if(arr[i] < 0) q.pop();
			i++;
		}
	}
	return ans;
}