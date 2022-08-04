#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define MXN 20001*60

int charToIndex(char ch) {

	if (ch == 'A') return 0;
	if (ch == 'G') return 1;
	if (ch == 'C') return 2;
	if (ch == 'T') return 3;

	/*if (ch == 'A') return 1;
	if (ch == 'G') return 2;
	if (ch == 'C') return 3;
	if (ch == 'T') return 4;*/
}

struct TrieNode {
	int id,seqCnt;
	TrieNode* child[4];

};
//struct Node {
//	
//	Node* next[5];
//	int seqCnt;
//	int id;
//
//	void init() {
//		id = 0;
//		seqCnt = 0;
//		for (int i = 0; i < 4; i++) {
//			next[i] = nullptr;
//		}
//	}
//};

int nn;
TrieNode  trieNode[MXN];

TrieNode* getNode() {
	return &trieNode[++nn];
}

TrieNode* rootNode;


unordered_map<int, string> seqDb;



TrieNode  poolNode[20000*61];
int poolIndex;

TrieNode* createNode() {
	//TrieNode* newNode = (TrieNode*) malloc(sizeof(TrieNode));
	TrieNode* newNode = &poolNode[poolIndex++];
	newNode->id = 0;
	newNode->seqCnt = 0;
	for (int i = 0; i < 4; i++) {
		newNode->child[i] = nullptr;
	}
	return newNode;
}
void init()
{
	///////////
	nn = 0;
	poolIndex = 0;
	/*rootNode = getNode();
	rootNode->init();*/
	rootNode = createNode();

	seqDb.clear();
}

int Find(string s) {
	TrieNode* cur = rootNode;

	for (int i = 0; s[i]; i++) {

		int index = charToIndex(s[i]);
		if (cur->child[index] == nullptr) return 0;
		cur = cur->child[index];
	}
	return cur->id;
}

void addTrie(int mId, string s) {

	TrieNode* cur = rootNode;

	for (int i = 0; s[i]; i++) {
		int index = charToIndex(s[i]);
		cur->seqCnt++;
		if (cur->child[index] == nullptr) {
			cur->child[index] = createNode();
			
		}
		cur = cur->child[index];

	}
	cur->seqCnt++;
	cur->id = mId;
}

void deleteTrie(TrieNode * cur) {

	for (int i = 0; i < 4; i++) {
		if (cur->child[i]) {
			deleteTrie(cur->child[i]);
		}
	}
	delete(cur);
}

int addSeq(int mID, int mLen, char mSeq[])
{
	if (seqDb.count(mID) != 0) return 0;
	if (Find(mSeq) != 0) return 0;

	seqDb[mID] = mSeq;

	addTrie(mID, mSeq);
	
	return 1;
}

int searchSeq(int mLen, char mBegin[])
{
	TrieNode* cur = rootNode;
	deleteTrie(cur);
	for (int i = 0; i < mLen; i++) {
		char ch = mBegin[i];
		int index = charToIndex(ch);
		if (cur->child[index] == nullptr) return -1;
		cur = cur->child[index];
	}
	if (cur->seqCnt >= 2) return cur->seqCnt;
	if (cur->seqCnt == 0) return -1;

	while (!cur->id) {
		for (int i = 0; i < 4; i++) {
			if (cur->child[i] != nullptr && cur->child[i]->seqCnt > 0) {
				cur = cur->child[i];
				break;
			}
		}
	}
	return cur->id;
}

void eraseTrie(string s) {

	TrieNode* cur = rootNode;

	for (int i = 0; s[i]; i++) {
		int index = charToIndex(s[i]);
		cur->seqCnt--;
		cur = cur->child[index];
	}
	cur->seqCnt--;
	cur->id = 0;
}

int eraseSeq(int mID)
{
	auto it = seqDb.find(mID);
		if (it == seqDb.end()) return 0;

		string str = it->second;
	
	TrieNode* cur = rootNode;

	eraseTrie(str);

	seqDb.erase(it);
	return 1;
}


int changeBase(int mID, int mPos, char mBase)
{
	if (seqDb.count(mID) == 0) return 0;
	auto it = seqDb.find(mID);


	string str = seqDb[mID];
	if (mPos > (str.size() - 1)) return 0;
	if (mBase == str[mPos]) return 0;

	char c = str[mPos];
	str[mPos] = mBase;

	if (Find(str) != 0) {
		str[mPos] = c;
		return 0;
	}

	str[mPos] = c;
	eraseTrie(str);
	str[mPos] = mBase;
	addTrie(mID, str);
	
	seqDb[mID] = str;
	return 1;
}
