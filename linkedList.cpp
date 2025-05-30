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
        nodeBaru -> noMhs = nim;

        if (START == NULL || nim <= START -> noMhs){

            if ((START != NULL) && (nim == START ->noMhs)){
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return ;
            }
            nodeBaru -> next = START ;
            START = nodeBaru ;
            return;

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
        }   nodeBaru->next = current;
            previous->next = nodeBaru ;

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

    void transverver(){

        if (listEmpty()){
            cout << "\nList Kosong\n";
        }

        else{
            cout << "\nData didalam list adalah : \n";
            node *currentNode = START;
            while (currentNode != NULL){
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }

};

int main(){

    list mhs;
    int nim;
    char ch;
     do{
        cout << "Menu" << endl;
        cout << endl
             << "1. Menambah data kedalam list"<< endl;
        cout << "2. Menghapus data dari kedalam list"<< endl;
        cout << "3. Menampilkan semua data didalam list"<< endl;
        cout << "4. Mencari data dalam list"<< endl;
        cout << "5. Exit"<< endl;

        cout << endl <<"Masukkan pilihan (1-5)"<< endl;
        cin >> ch;

        switch(ch){
            case '1':{
                mhs.addNode();
                break;
            }
            
            case '2':{
                if (mhs.listEmpty()){
                    cout << endl << "List Kosong" << endl;
                    break;
                }
                cout << endl << "\nMasukkan no Mahasiswa yang akan di hapus";
                cin >> nim;
                
                if(mhs.delNode(nim) == false)
                    cout << endl << "Data tidak ditemukan" << endl;
                
                else
                cout << endl << "Data dengan nomor Mahasiswa" << nim << " berhasil dihapus" << endl;

            }break;

            case '3':{
                mhs.transverver();
            }
            break;

            case '4':{

                if (mhs.listEmpty() == true){
                    cout <<"\nList Kosong\n";
                    break;
                }
                node *previous, *current;
                cout<< endl <<"Masukkan no Mahasiswa yang dicari :"<< endl;
                cin >> nim;
                if (mhs.search(nim, &previous, &current) == false)
                {
                    cout << endl <<"Data tidak ditemukkan"<< endl;
                }
                
                else{
                    cout <<endl << "Data ditemukan" << endl;
                    cout << "\nNo Mahasiswa :" << current->noMhs << endl;
                    cout << "\n";
                }
               
            } break;
            case '5':{}
            break;
            default:{
                cout << "Pilihan salah !." << endl;
            }break;
        }  

    }while (ch != '5');
}