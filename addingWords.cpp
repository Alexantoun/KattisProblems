#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int initValue = -1000000;
struct words
{
  char varName[31] ;
  int val = initValue;
  words *left = NULL;
  words *right = NULL;
};

void preOrder(words* current)
{
  words *c = current;
  cout<<c->varName<<" "<<c->val<<endl;
  if(c->left!=NULL)
    preOrder(c->left);
  if(c->right != NULL)
    preOrder(c->right);
}

bool findWords(words *root, words *&target, const char word[])
{
  bool found = false;
  target = root;
  while(!found && (target->left!=NULL && target->right!=NULL))
  {
    if (strcmp(word, target->varName)>0)
      target = target->right;
    else if(strcmp(word, target->varName)<0)
      target = target->left;
    else if (strcmp(word, target->varName) == 0)
      found = true;
  }
  return found;
}

void def(words *root)
{
  //cout<<"Entering def function"<<endl;
  if(root->val != initValue)
  {
    char input[31];
    int inVal;
    words *target = root;
    bool placed = false;

    cin>>input>>inVal;

    while(!placed)
    {
      if(strcmp(input, target->varName) < 0)
      {
        if(target->left != NULL)
          target = target->left;
        else
        {
          target->left = new words;
          target = target->left;
          strcpy(target->varName,input);
          target->val = inVal;
          placed=true;
        }
      }
      else if(strcmp(input, target->varName) > 0)
      {
        if(target->right != NULL)
          target = target->right;
        else
        {
          target->right = new words;
          target = target->right;
          strcpy(target->varName, input);
          target->val = inVal;
          placed = true;
        }
      }
    }
  }
  else if(root->val == initValue)
  {
    cin>>root->varName;
    cin>>root->val;
  }
  //cout<<"leaving def function"<<endl;
}

void calc(words *root)
{
  cout<<"Im in calc function"<<endl;
  int sumTotal = 0;
  words *target = NULL;
  char word[31], inst='!', next='!';
  bool known = true;
  char output[1000]="\0";
  cin>>word;
  known = findWords(root, target, word);
  sumTotal = target->val;
  strcat(output, word);
    
  while(inst != '=' && known)
  {
    cin>>inst>>word;
    known = findWords(root, target, word);
    if(known && inst == '-')
    {
      strcat(output," - ");
      strcat(output,word);
      sumTotal -= target->val;
    }
    else if(known && inst == '+')
    {
      strcat(output," + ");
      strcat(output, word);
      sumTotal += target->val;
      cout<<"in the plus, total is: "<<sumTotal<<endl;
    }
    else
      cout<<"I failed, word is: "<<word<<" inst is: "<<inst<<endl;

    cin>>inst;
    if(inst != '=')
      cin.putback(inst);
  }
  strcat(output," = ");
  if(!known)
    cout<<output<<" unkown"<<endl;
  else
    cout<<output<<" "<<sumTotal<<endl;
}

int main()
{
  words *root = new words;
  int pos = 0;
  char instruction[6];

  while(!cin.eof())
  {
    cout<<"enter something"<<endl;
    cin>>instruction;
    if(instruction[0] == 'd')
      def(root);
    else if(instruction[0] == 'c' && instruction[1] == 'a')
      calc(root);
    //else if(instruction[0] == 'c' && instruction[1] == 'l')
      //clear(root, pos);
    else if(instruction[0] == 'p')
      preOrder(root);

    cin.clear();
  }

  return 0;
}
