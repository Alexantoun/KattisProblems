#include <iostream>
#include <cstring>
using namespace std;

//You collect password first, so just iterate through
bool inList(char pwd[], const char& target){ //Returns the first occurance of the target char in password, else -1 if not in
    
    for(int i =0; i <9; i++)
        if(target == pwd[i])
            return true;
    return false;
}

int main()
{
    char password[9];
    int curr = 0;
    bool inPass;
    char target;
    cin>>password;

    while(cin.peek() != '\n' && curr<8){
        cin.get(target);
        cout<<"The target is: "<<target<<endl;
        inPass = inList(password, target);
        if( inPass && target == password[curr])
            curr++;
        else if(inPass){
            cout<<"FAIL"<<endl;
            return 0;
        }
        if(password[curr] == '\0'){
            cout<<"PASS"<<endl;
            return 0;
        }
        cout<<"The curr is at: "<<curr<<endl;
    }
    cout<<"FAIL"<<endl;
    return 0;
}
