#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;
void printList(vector<int> &list) {
	if(list.empty()) cout<<"empty";
	else {
		cout<<list[0];
		for(int i = 1;i < list.size(); i++) {
			cout<<" "<<list[i];
		}
		cout<<endl;
	}
}
class Solution {
public:
	vector<int> preference(vector<vector<int>> &preList) {
		unordered_map<int, unordered_set<int>> mp;
		unordered_map<int, int> degree;

		for(auto list:preList) {
			for(int i = 0; i < list.size()-1; i++) {
				mp[list[i]].insert(list[i+1]);
			}
		}

		for(auto m:mp) {
			for(auto po:m.second) {
				if(degree.find(po) == degree.end()) degree[po] = 1;
				else degree[po]++;
			}
		}

		vector<int> ans;
		queue<int> qe;
		for(auto list:preList) {
			for(auto po:list) {
				if(degree.find(po) == degree.end()) qe.push(po);
			}
		}

		while(!qe.empty()) {
			int cur = qe.front();
			qe.pop();
			ans.push_back(cur);
			for(auto next:mp[cur]) {
				if(!(--degree[next])) qe.push(next);
			}
		}
		return ans;
	}
};
int main() {
	vector<vector<int>> preList = {
		{3,5,7,9},
		{2,3,8},
		{5,8}
	};

	Solution s;
	vector<int> ans = s.preference(preList);
	printList(ans);
}
