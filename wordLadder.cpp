class Node{
public:
	string word;
	int len;
	Node(string w, int l):word(w), len(l) {}
};
int wordLadder(string begin, string end, vector<int> &wordList) {
	if(begin.empty()) {
		return 0;
	}

	queue<Node> qe;
	qe.push(Node(begin, 1));

	unordered_set<string> wordSet(wordList.begin, wordList.end());
	map<string, bool> used;
	used[begin] = true;

	const int n = begin.size();
	while(!qe.empty()) {
		Node cur = qe.front();
		if(cur.word == end) {
			return cur.len;
		}

		for(int i = 0; i < n; i++) {
			for(char j = 'a'; j <= 'z'; j++) {
				string tmp = cur.word;
				if(tmp[i] == j) {
					continue;
				}

				tmp[i] = j;
				if(wordSet.find(tmp) == wordSet.end() || used[tmp]) {
					continue;
				}

				qe.push(Node(tmp, cur.len+1));
				used[tmp] = true;
			}
		}
	}
	return 0;
}
