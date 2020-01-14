vector<int> Solution::findSubstring(string S, const vector<string> &L) {
	int size_word = L[0].size();
	int word_count = L.size();
	int size_L = size_word * word_count;
	vector<int> res;
		return res;
	unordered_map<string, int> hash_map;

	for (int i = 0; i < word_count; i++) 
		hash_map[L[i]]++; 
	for (int i = 0; i <= S.size() - size_L; i++) {
		unordered_map<string, int> temp_hash_map(hash_map);
		int j = i;
		while (j < i + size_L) {
			string word = S.substr(j, size_word);
			if (hash_map.find(word) == hash_map.end())
				break;
			else
				temp_hash_map[word]--;

			j += size_word;
		}

		int count = 0;
		for (auto itr = temp_hash_map.begin();
			itr != temp_hash_map.end(); itr++) 
			if (itr->second > 0)
				count++;	 
		if (count == 0)
			res.push_back(i);
	}

	return res;
}
