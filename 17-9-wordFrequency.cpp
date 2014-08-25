#include <map>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

string toLowerCase(string word) {
	for(int i = 0; i < word.length(); ++i)
		word[i] = tolower(word[i]);
	return word;
}

void setupDict(map<string, int> &dict, string word) {
	word = toLowerCase(word);
	++dict[word];
}

int getFrequency(map<string, int> dict, string word) {
	if(dict.empty() || word == "") return -1;
	word = toLowerCase(word);
	if(dict.find(word) == dict.end()) return 0;
	return dict[word];
}

int main() {
	freopen("17.9.in", "r", stdin);
	string word;
	map<string, int> dict;
	while(cin >> word)
		setupDict(dict, word);
	cout << getFrequency(dict, "hi") << endl;
	cout << getFrequency(dict, "fight") << endl;
	return 0;
}
