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

            
        }
    }

};