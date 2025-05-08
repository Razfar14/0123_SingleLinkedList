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
        
    }

};