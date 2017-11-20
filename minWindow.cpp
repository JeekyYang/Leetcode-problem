string minWindow(string s, string t) {
	vector<int> used(128, 0);
	for(auto c:t) {
		used[c]++;
	}

	int count = t.size();
	int begin = 0, end = 0, min_len = INT_MAX, min_start = 0;
	while(end < s.size()) {
		if(used[s[end]] > 0) {
			count--;
		}
		used[s[end]]--;
		end++;
		while(count == 0) { // find all the chars
			if(end-begin < min_len) {
				min_start = begin;
				min_len = end-begin;
			}
			used[s[begin]]++;
			if(used[s[begin]] > 0) count++;
			begin++;
		}
	}
	
	return min_len == INT_MAX? "":s.substr(min_start, min_len);
}
