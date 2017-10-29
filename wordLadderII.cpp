class Node {
public:
	string word;
	vector<string> path;
	Node(string w, vector<string> p):word(w), path(p){}
};
vector<vector<string>> findLadders(string begin, string end, vector<string> wordList) {
	if(begin.empty()) {
		return vector<vector<string>>();
	}

	vector<vector<string>> ans;

	unordered_set<string> wordSet(wordList.begin(), word.end());
	unordered_set<string> pre;
	unordered_set<string> thisLevel;

	queue<Node> qe;
	qe.push(Node(begin, vector<string>(1, begin)));
	qe.push(Node("", vector<string>()));

	bool found = false;

	while(!qe.empty()) {
		Node cur = qe.front();
		qe.pop();

		if(cur.word == end) {
			ans.push_back(cur.path);
			continue;
		}

		if(cur.word == "") {
			if(found) {
				return ans;
			} else {
				if(!qe.empty()) {
					qe.push(Node("", vector<string>()));
					pre.insert(thisLevel.begin(), thisLevel.end());
					thisLevel.clear();
				}
			}
		} else {
			for(int i = 0; i < begin.size(); i++) {
				for(char j = 'a'; j <= 'z'; j++) {
					string word = cur.word;
					if(word[i] == j) {
						continue;
					}

					if(wordSet.find(word) == wordSet.end() || pre.find(word) != pre.end()) {
						continue;
					}

					string tmp = word;
					tmp[i] = j;
					thisLevel.insert(tmp);

					vector<string> path = cur.path;
					path.push_back(tmp);
					qe.push(Node(tmp, path));
				}
			}
		}
	}
	return ans;
}
