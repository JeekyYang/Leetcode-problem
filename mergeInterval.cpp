class Interval{
	int start;
	int end;
	Interval(int s, int e):start(s),end(e){}
};

vector<Interval> mergeInterval(vector<Interval> &intervals) {
	vector<Interval> ans;
	for(int i = 0; i < intervals.size(); i++) {
		ans = insert(ans, intervals[i]);
	}
	return ans;
}
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> ans;
	if(intervals.empty()) {
		ans.push_back(newInterval);
		return ans;
	}

	const int n = intervals.size();
	for(int i = 0; i < n; i++) {
		if(newInterval.end < intervals[i].start) {
			ans.push_back(newInterval);
			ans.insert(ans.end(), i+intervals.begin(), intervals.end());
			return;
		} else if(newInterval.start > intervals[i].end) {
			ans.push_back(intervals[i]);
		} else {
			newInterval.start = min(newInterval.start, intervals[i].start);
			newInterval.end = max(newInterval.end, intervals[i].end);
		}
	}
	ans.push_back(newInterval);
	return ans;
}
