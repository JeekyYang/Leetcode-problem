vector<string> fullJustify(vector<string> &words, int maxWidth) {
	vector<string> ans;
	const int n = words.length();
	int index = 0;
	while(index < n) {
		int wordCount = 0;
		int lineLen = 0;
		int wordLen = 0;
		for(int i = index; i < n; i++) {
			if(lineLen + words[i].length() + i - index <= maxWidth) {
				lineLen += words[i].length() + i- index;
				wordCount++;
				wordLen += words[i].length();
			} else {
				break;
			}
		}

		string line = "";
		int spaceTotal = maxWidth - wordLen;
		int spaceBetweenWords = wordCount == 1? spaceTotal:spaceTotal/(wordCount-1);
		int extra = wordCount == 1? 0:spaceTotal%(wordCount-1);

		for(int i = index; i < index+wordCount; i++) {
			line += words[i] + string(spaceBetweenWords, ' ');
			if(extra > 0) {
				line += " ";
				extra--;
			}
		}
		index += wordCount;
		ans.push_back(line);
	}
	return ans;
}

