#include <iostream>
#include <cstring>
using namespace std;

//You collect password first, so just iterate through
struct node{
    char data;
    node* next = NULL;
};

class linkedList{
    private:
        node* head;
    public:
        linkedList(){ head = NULL; }
        linkedList(char knew) {
            head = new node;
            head->data = knew;
            head->next = NULL;
        }

        void push(char val){
            node* newNode = new node;
            newNode->data = val;
            if(head == NULL){
                head = newNode;
                return;
            }
            node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            
            temp->next = newNode;

        }

        void printList(){
            node* curr = head;
            cout<<"Inside printList()"<<endl;
            while(curr != NULL){
                cout<<curr->data;
                curr = curr->next;
            }
            cout<<endl;
        }
        
        char pop(){
            char curr = head->data;
            node* temp = head;
            head = head->next;
            delete temp;
            return curr;
        }

        bool emptyList(){
            return (head == NULL);
        }

        bool inList(char value){
            node* curr = head;
            while(curr!=NULL){
                if (curr->data == value)
                    return true;
                curr = curr->next;
            }
            return false;
        }


};


int main()
{
    linkedList password;
    char in;
    cin>>in;
    do{
        password.push(in);
        cin.get(in);
    }while(in != ' ');
    cout<<"OUT OF LOOP"<<endl;
    if(password.emptyList())
        cout<<"emptyList"<<endl;
    password.printList();
    char test;
    cin>>test;
    if(password.inList(test))
        cout<<test<<" is in the list"<<endl;
    else
        cout<<test<<" isn't in the list"<<endl;
    //Uncomment all this after testing class
    // queue<char> remaining;
    // char password[9];
    // cin >> password;
    
    // for(int i =0; i < 9; i++){
    //     if(password[i]!= '\0')
    //         remaining.push(password[i])
    //     else   
    //         break;
    // }

    // char target;
    // do{
    //     cin.get(target);
    //     if(inList(password, target))
    // }
    // return 0;
}
