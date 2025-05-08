#include <iostream>
using namespace std;

class node {
    public:
        int noMhs;
        node* next;
};

class list{
    node *START;
    
    public:
    list(){
        START = NULL;
    }

    void addNode(){
        int nim ;

        cout << "\n Masukkan Nomor Mahasiswa :";
        cin >> nim;

        node *nodeBaru = new node;
        nodeBaru -> noMhs;

        if (START == NULL || nim <= START -> noMhs){

            if ((START != NULL)&& (nim == START ->noMhs )){
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return ;
            }
            node *previous = START;
            node *current = START;
            while ((current != NULL) && (nim >= current ->noMhs)){
                if (nim == current ->noMhs){
                    cout << "\nDuplikasi noMhs tidak diijinkan\n";
                    return ;
                }
                previous = current ;
                current = current -> next;
            }
            nodeBaru ->next = current;
            previous ->next = nodeBaru;
        }
    }
    bool listEmpty(){
        return START == NULL;
    }

    bool search (int nim, node ** previous, node ** current){

        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim !=(*current) ->noMhs)){
            *previous = *current ;
            *current = (*current) ->next;
        } return (*current != NULL);
    }

    bool delNode(int nim){
        node *current, *previous ;

        if(!search(nim, &previous, &current))
        return false ;

        if(current == START){
            START = START->next;

        }
        else {
            previous->next = current->next;
        }
        

        delete current;
        return true;
    }

    void transver(){

        if (listEmpty()){
            cout << "\nList Kosong\n";
        }

        else{
            cout << "\nData didalam list adalah : \n";
            node *currentNode = START;
            while (currentNode != NULL){
                cout << currentNode->next;
            }
            cout << endl;
        }
    }

};

int main(){

    list mhs;
    int nim;
    char ch;
    while(1){
        cout << "Menu" << endl;
        cout << endl
             << "1. Menambah data kedalam list"<< endl;
        cout << "2. Menghapus data dari kedalam list"<< endl;
        cout << "3. Menampilkan semua data didalam list"<< endl;
        cout << "4. Mencari data dalam list"<< endl;
        cout << "5. Exit"<< endl;
    }
}