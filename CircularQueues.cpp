#include<iostream>
using namespace std;

class Queues{
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    Queues(){
        FRONT= -1;
        REAR = -1;
    }

    void insert(){
        int num;
        cout << "Enter a Number: ";
        cin >>num;
        cout << endl;

        //cek antrian penuh
        if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR + 1)){
            cout << "\nQueue overflow\n";
            return;
        }

        //cek apakah antrian kosong
        if (FRONT == -1){
            FRONT = 0;
            REAR = 0;
        }
        else{
            //jika rearberada di posisi terakhir kembali ke awall array
            if(REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove(){
        //cekapakah antrian kosong
        if (FRONT == -1){
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is : " << queue_array[FRONT] << "\n";

        //cek  jika antrian hanya memiliki satu element
        if (FRONT == REAR){
            FRONT = -1;
            REAR = -1;
        }
        else {
            //jika element yg di hapus berada di array tekhir kembali ke awal array
            if(FRONT == max - 1)
                FRONT = 0;
            else    
                FRONT = FRONT + 1;
        }
    }

    void display(){
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        // cek apakah antrian kosong
        if(FRONT == -1){
            cout <<"Queue is Empty\n";
            return;
        }

        cout <<"\nElement is Queue Are. . .\n";

        //jika front position < rear pisiion iterasi front hingga rear
        if(FRONT_position <= REAR_position){
            while (FRONT_position <= REAR_position){
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            //JIKA Front position > rare position iterasi front hingga akhir array
            while (FRONT_position <= max - 1){
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // ITERASI dari awal array hingga rear
            while (FRONT_position <= REAR_position){
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            cout <<endl;
        }
    }   
};

int main(){
    Queues q;
    char ch;

    while(true){
        try{
            cout << "Menu" << endl;
            cout << "1. Implement insert Operation" << endl;
            cout << "2. Implement delete Operation" << endl;
            cout << "3. Display Values" << endl;
            cout << "4. Exit " << endl;
            cout << "Enter Your Choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch){
                case '1':{

                    q.insert();
                    break;
                }
                case '2':{

                    q.remove();
                    break;
                }
                case '3':{
                    q.display();
                    break;
                }
                case '4':{
                    return 0;
                }
                default:{
                    cout << "invalid option!!" << endl;
                    break;
                }
                }
            }
            catch (exception& e){
                cout << "check for the value entered." << endl;
            }

        }
         return 0;
    }
    

