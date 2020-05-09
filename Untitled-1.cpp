#include<iostream> 
#include<string.h>
#include<conio.h>
#include <fstream> 

using namespace std; 
#define ALPHABET_SIZE (26) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
int test_case = 1;
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 
	bool isWordEnd;
	string meaning; 
}; 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 
	pNode->isWordEnd = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 
void insert(struct TrieNode *root, const string key,const string mean) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int level = 0; level < key.length(); level++) 
	{ 
		int index = CHAR_TO_INDEX(key[level]); 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 
	pCrawl->isWordEnd = true; 
	pCrawl->meaning=mean;
} 
bool search(struct TrieNode *root, const string key) 
{ 
	int length = key.length(); 
	struct TrieNode *pCrawl = root; 
	for (int level = 0; level < length; level++) 
	{ 
		int index = CHAR_TO_INDEX(key[level]); 

		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isWordEnd); 
}  
bool isLastNode(struct TrieNode* root) 
{ 
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		if (root->children[i]) 
			return 0; 
	return 1; 
} 
void suggestionsRec(struct TrieNode* root, string currPrefix , string quer) 
{ 
	if (root->isWordEnd) 
	{ 	if(test_case == 1){
		cout<<quer<<" Not found\n";
		cout<<"Did You Mean?\n";
		test_case =0;
		}

		cout << currPrefix; 
		cout << endl; 
	} 
	if (isLastNode(root)) 
		return; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
	{ 
		if (root->children[i]) 
		{ 
			currPrefix.push_back(97 + i); 
			suggestionsRec(root->children[i], currPrefix , quer); 
			currPrefix.pop_back(); 
		} 
	} 
} 
int printAutoSuggestions(TrieNode* root, const string query) 
{ 
	struct TrieNode* pCrawl = root; 
	int level; 
	int n = query.length(); 
	for (level = 0; level < n; level++) 
	{ 
		int index = CHAR_TO_INDEX(query[level]); 
		if (!pCrawl->children[index]) 
			return 0; 

		pCrawl = pCrawl->children[index]; 
	} 
	bool isWord = (pCrawl->isWordEnd == true); 
	bool isLast = isLastNode(pCrawl); 
	if (isWord && isLast) 
	{ 
		cout << query << endl; 
		cout <<"meaning is "<<pCrawl->meaning;
		return -1; 
	} 
	if (!isLast) 
	{ 
		string prefix = query; 
		suggestionsRec(pCrawl, prefix, query); 
		return 1; 
	} 
} 

int main() 

{ 	
	int qqq =1;
	string check;
	struct TrieNode* root = getNode(); 
	insert(root,"casuarina","a kind of tree with joined leaves");
	insert(root,"cataclysm","deluge");
	insert(root,"catalogue","a list");
	insert(root,"catalogue","prepare a list of");
	insert(root,"catamaran","a raft or float of pieces of wood");
	insert(root,"cataract","a great fall of water; a disease of the eye");
	insert(root,"catch","seize, grasp");
	insert(root,"catch","grasp");
	insert(root,"catchment","source from which rain water flows into");
	insert(root,"catch word","a clue, a slogan");
	insert(root,"catchy","attractive");
	insert(root,"category","group");
	insert(root,"celebrity","a well-known person");
	insert(root,"celestial","heavenly");
	insert(root,"celibacy","the state of being unmarried");
    while(qqq = 1){
        cout<<"\n======================D=I=C=T=I=O=N=A=R=Y==========================="<<endl;
		cout<<"1.Show meaning"<<endl;
		cout<<"2.Exit"<<endl;
		int ch;
		cin>>ch;
		if(ch == 0){
			qqq=0;
			break;
		}
		else{
			cout<<"\nEnter the word\n";
			cin>>check;
			int comp = printAutoSuggestions(root, check); 
			if(comp == 0){
				cout<<"Word Not found";
				cout<<"\nWould you like to add it (y/n)";
				char c;
				cin>>c;
				if(c=='y'){
					cout<<"Enter the meaning ";
					string mean;
					cin>>mean;
					insert(root, check,mean); 
				}
			}
			if(comp == 1){
				cout<<"\nWould you like to add "<<check<<"?";
				char q;
				cin>>q;
				if(q == 'y'){
					cout<<"Enter the meaning";
					string m;
					cin>>m;
					insert(root, check,m); 
				}
			}
		}
    }

	return 0; 
} 
