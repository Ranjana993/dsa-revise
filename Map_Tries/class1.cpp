#include <iostream>
using namespace std;

class TrieNode{
  public:
    char data;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char data){
      this->data = data;
      for(int i = 0 ; i < 26 ; i++)children[i] = NULL;
      this->isTerminal = false;
    }
};


void insertWord(TrieNode* &root , string str){
  cout <<"inserting .." << str <<endl;
  if(str.length() == 0){
    root->isTerminal = true;
    return;
  }

  char ch = toupper(str[0]);
  // char ch = str[0];
  int index = ch - 'A';

  TrieNode*child;
  if(root->children[index] != NULL){
    child = root->children[index];
  }
  else{
    child = new TrieNode(ch);
    root -> children[index] = child;
  }
  insertWord(child,str.substr(1));
}


bool searchWord(TrieNode*root , string word ){
  if(word.length() == 0 ){
    return root -> isTerminal;
  }
  char ch = toupper(word[0]);
  int index = ch - 'A';

  TrieNode*child;
  if(root->children[index] != NULL){
    child = root->children[index];
  }
  else{
    return false;
  }
  return searchWord(child,word.substr(1));

}

int main() {
  TrieNode* root = new TrieNode('\0'); 
  insertWord(root, "Dad");
  cout<<endl<<endl;
  insertWord(root, "Daddy");
  insertWord(root, "Ram");
  insertWord(root, "ramu");
  insertWord(root, "Daddu");
  if(searchWord(root , "Daddo")){
    cout <<"Found"<<endl;
  }
  else{
    cout<<"Not found"<<endl;
  }
  
  return 0;
}