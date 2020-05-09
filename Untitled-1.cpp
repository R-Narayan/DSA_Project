#include<iostream> 
#include<string.h>
#include<conio.h>
using namespace std; 
#define size (26) 
#define findIndex(c) ((int)c - (int)'a') 
int test_case = 1;
struct node{ 
	struct node *child[size]; 
	bool isEnd;
	string meaning; 
}; 
struct node *newNode(void){ 
	struct node *pNode = new node; 
	pNode->isEnd = false; 
	for (int i = 0; i < size; i++) 
		pNode->child[i] = NULL; 
	return pNode; 
} 
void add(struct node *root, const string key,const string mean){ 
	struct node *finder = root; 
	for (int level = 0; level < key.length(); level++){ 
		int index = findIndex(key[level]); 
		if (!finder->child[index]) 
			finder->child[index] = newNode(); 
		finder = finder->child[index]; 
	} 
	finder->isEnd = true; 
	finder->meaning=mean;
} 
bool find(struct node *root, const string key){ 
	int length = key.length(); 
	struct node *finder = root; 
	for (int level = 0; level < length; level++){ 
		int index = findIndex(key[level]); 
		if (!finder->child[index]) 
			return false; 
		finder = finder->child[index]; 
	} 

	return (finder != NULL && finder->isEnd); 
}  
bool checkLast(struct node* root){ 
	for (int i = 0; i < size; i++) 
		if (root->child[i]) 
			return 0; 
	return 1; 
} 
void recommend(struct node* root, string currPrefix , string quer, int dddd){ 
	if (root->isEnd){ 	
		if(test_case == 1 && dddd == 0){
		cout<<quer<<" Not found\n";
		cout<<"Did You Mean?\n";
		test_case =0;
		}
		cout << currPrefix; 
		cout << endl; 
	} 
	if (checkLast(root)) 
		return; 
	for (int i = 0; i < size; i++){ 
		if (root->child[i]){ 
			currPrefix.push_back(97 + i); 
			recommend(root->child[i], currPrefix , quer , dddd); 
			currPrefix.pop_back(); 
		} 
	} 
} 
int mainFinder(node* root, const string query, int def =0){ 
	struct node* finder = root; 
	int level; 
	int n = query.length(); 
	for (level = 0; level < n; level++) { 
		int index = findIndex(query[level]); 
		if (!finder->child[index]) 
			return 0; 
		finder = finder->child[index]; 
	} 
	bool isWord = (finder->isEnd == true); 
	bool isLast = checkLast(finder); 
	if (isWord && isLast) { 
		if(def == 0){
			cout << query << endl; 
			cout <<"meaning is "<<finder->meaning;
			return -1; 
		}
	} 
	if (!isLast){ 
		string prefix = query; 
		recommend(finder, prefix, query, def); 
		return 1; 
	} 
} 


int main() { 	
	int qqq =1;
	string check;
	struct node* root = newNode(); 
	add(root,"casuarina","a kind of tree with joined leaves");
	add(root,"cataclysm","deluge");
	add(root,"catalogue","a list");
	add(root,"catalogue","prepare a list of");
	add(root,"catamaran","a raft or float of pieces of wood");
	add(root,"cataract","a great fall of water; a disease of the eye");
	add(root,"catchment","source from which rain water flows into");
	add(root,"catchword","a clue, a slogan");
	add(root,"category","group");
	add(root,"caterer","one who undertakes to supply provisions, food, etc.,");
	add(root,"cathedral","the principal church");
	add(root,"cats-eye","a chief variety of quartz");
	add(root,"cats-paw","a scapegoat, a dupe pr tool");
	add(root,"cattle","cows, sheep, etc., live stock");
	add(root,"caught","past tense and past participle");
	add(root,"cauldron","a big hollow vessel for boiling etc.,");
	add(root,"caulk","repair leakages, (in ship, cask, etc)");
	add(root,"cause","reason");
	add(root,"caution","care");
	add(root,"cautious","careful, watchful");
	add(root,"cavalcade","procession of person on horseback"); 
	add(root,"cavalier","horseman");
	add(root,"cavalier","haughty");
	add(root,"cave","a (large) den");
	add(root,"cavil","a trivial objection");
	add(root,"cavity","a hollow");
	add(root,"caw","the cry of a crow");
	add(root,"cease","stop, put an end to");
	add(root,"ceaseless","continual, never ending");
	add(root,"cedar","a kind of big tree");
	add(root,"cede","grant, give way, yield");
	add(root,"ceiling","the inner roof of a house");
	add(root,"celebrate","perform with proper rites and ceremonies");
	add(root,"celebrated","famous");
	add(root,"celebration","observance or performance with due rites");
	add(root,"celebrity","a well-known person");
	add(root,"celestial","heavenly");
	add(root,"celibacy","the state of being unmarried");
    while(qqq = 1){
        cout<<"\n======================D=I=C=T=I=O=N=A=R=Y==========================="<<endl;
		cout<<"1.Show meaning"<<endl;
		cout<<"2.Exit"<<endl;
		int ch;
		cin>>ch;
		if(ch == 2){
			qqq=0;
			break;
		}
		else{
			cout<<"\nEnter the word\n";
			cin>>check;
			int comp = mainFinder(root, check); 
			if(comp == 0){

				cout<<"Word Not found";
				string f = check;
				f.pop_back();  
				int comp = mainFinder(root, f,0); 
				cout<<"\nWould you like to add it (y/n)";
				char c;
				cin>>c;
				if(c=='y'){
					cout<<"Enter the meaning ";
					string mean;
					cin>>mean;
					add(root, check,mean); 
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
					add(root, check,m); 
				}
			}
		}
    }

	return 0; 
} 
