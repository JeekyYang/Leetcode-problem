class Interval{
	int start;
	int end;
	Interval(int s, int e):start(s), end(e){}
};

vector<Interval> insertInterval(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> ans;
	if(intervals.empty()) {
		ans.push_back(newInterval);
		return ans;
	}

	const int n = intervals.size();
	for(int i = 0; i < n; i++) {
		if(newInterval.start > intervals[i].end) {
			ans.push_back(intervals[i]);
		} else if(newInterval.end > intervals[i].start) {
			ans.push_back(newInterval);
			ans.insert(ans.end(), i+intervals.begin(), intervals.end());
			return ans;
		} else {
			newInterval.start = min(newInterval.start, intervals[i].start);
			newInterval.end = max(newInterval.end, intervals[i].end);
		}
	}
	ans.push_back(newInterval);
	return ans;
}
