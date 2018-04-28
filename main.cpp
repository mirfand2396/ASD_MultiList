#include <iostream>
#include <cstdlib>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main(){
    // BY :
    // Muhammad Novario Ekaputra 1301153620
    // Muhammad Irfan Dhiyaafakhri 1301153618
    //
    int menu;
    int subMenuInsertF;
    int subMenuInsertP;
    int subMenuDeleteP;
    int subMenuDeleteF;
    List_parent LP;
    List_child LC;
    address_child C;
    address_parent P;
    address_parent BefElm;
    address_relasi R;
    flight flighttemp;
    passenger passengertemp;

    createList(LP);
    createList(LC);

    /** insert parent */
    flighttemp.destination = "Dubai";
    flighttemp.flight_id = "EK542";
    flighttemp.flight_name = "Emirates";
    P = alokasi(flighttemp);
    insertFirst(LP, P);

    flighttemp.destination = "Medan";
    flighttemp.flight_id = "JT951";
    flighttemp.flight_name = "Lion Air";
    P = alokasi(flighttemp);
    insertFirst(LP, P);

    flighttemp.destination = "Bengkulu";
    flighttemp.flight_id = "IN226";
    flighttemp.flight_name = "NAM Air";
    P = alokasi(flighttemp);
    insertFirst(LP, P);

    //cout<<"List parent : "<<endl;
    //printInfo(LP);

    /** insert child */
    passengertemp.pass_id = "1301151";
    passengertemp.pass_name = "Budi";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301152";
    passengertemp.pass_name = "Damar";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301153";
    passengertemp.pass_name = "Anton";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301154";
    passengertemp.pass_name = "Zaskia";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301155";
    passengertemp.pass_name = "Rinah";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301156";
    passengertemp.pass_name = "Supri";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301157";
    passengertemp.pass_name = "Annah";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301158";
    passengertemp.pass_name = "Rizka";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301159";
    passengertemp.pass_name = "Rizieq";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    passengertemp.pass_id = "1301160";
    passengertemp.pass_name = "Nabila";
    C = alokasi(passengertemp);
    insertFirst(LC, C);

    while(true){
        cout<<" ==------------ TUBES STD(2018) -------------="<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|       Bentuk IIIB - Contoh Relasi M-N       |"<<endl;
        cout<<"|                                             |"<<endl;
        cout<<" =------------ Flight Information -----------="<<endl;
        cout<<" "<<endl;
        cout<<"     1.  List of Flight"<<endl;
        cout<<"     2.  List of Passenger"<<endl;
        cout<<"     3.  Input new Flight"<<endl;
        cout<<"     4.  Input new Passenger"<<endl;
        cout<<"     5.  Delete Flight"<<endl;
        cout<<"     6.  Delete Passenger"<<endl;
        cout<<"     7.  Delete Connection (Under Maintenis)"<<endl;
        cout<<"     8.  Connect Flight with Passenger"<<endl;

        cout<<" "<<endl;
        cout<<"     0.  Exit"<<endl;
        cout<<" "<<endl;
        cout<<" ---------------------------------------------"<<endl;
        cout<<" "<<endl;

        cout<<endl;
        cout<<"  Choose with NUMBER: ";
        cin>>menu;
        if(cin.fail()){
            cin.clear();
            cout<<"Please input with NUMBER!, press 'enter' to continue...";
            cin.sync();
            cin.get();
        }else{
            switch(menu){
                case 0:
                    return 0;
                break;
                case 1:
                    cout<<endl;
                    cout<<"  -----------  List of Flight  ------------"<<endl;
                    cout<<"     ID          Airline       Destination "<<endl;;
                    printInfo(LP);
                    cout<<"  -----------------------------------------"<<endl;
                    cout<<endl;
                    cout<<"  press 'enter' to continue...";
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 2:
                    cout<<endl;
                    cout<<"  ----------  List of Passenger  ----------"<<endl;
                    cout<<"      ID            Name                   "<<endl;
                    cout<<"  -----------------------------------------"<<endl;
                    printInfo(LC);
                    cout<<"  -----------------------------------------"<<endl;
                    cout<<endl;
                    cout<<"  press 'enter' to continue...";
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 3:
                    cout<<endl;
                    cout<<"  ----------  Input new Flight  -----------"<<endl;
                    cout<<"     1.  Insert First"<<endl;
                    cout<<"     2.  Insert After"<<endl;
                    cout<<"     3.  Insert Last"<<endl;
                    cout<<endl;
                    cout<<"     0.  Main Menu"<<endl;
                    cout<<"  -----------------------------------------"<<endl;
                    cout<<endl;
                    cout<<"  Choose with NUMBER: ";
                    cin>>subMenuInsertF;
                    if(cin.fail()){
                        cin.clear();
                        cout<<"Please input with NUMBER!, press 'enter' to continue...";
                        cin.sync();
                        cin.get();
                    }
                    else{
                        switch(subMenuInsertF){
                        case 1:
                            cout<<endl;
                            cout<<"  ----------  Input First Flight  ---------"<<endl;
                            cout<<"     Flight ID         : ";
                            cin>>flighttemp.flight_id;
                            cout<<"     Airline Name      : ";
                            cin>>flighttemp.flight_name;
                            cout<<"     Destination       : ";
                            cin>>flighttemp.destination;
                            cout<<"  -----------------------------------------"<<endl;
                            cout<<"  press 'enter' to continue...";
                            if(findElm(LP,flighttemp) == NULL){
                                P = alokasi(flighttemp);
                                insertFirst(LP, P);
                            }
                            else{
                                cout<<"  Sorry that ID is already exist, press 'enter' to continue...";
                            }
                            cin.sync();
                            cin.get();
                            system("cls");
                        break;
                        case 2:
                            cout<<endl;
                            cout<<"  ----------  Input After Flight  ---------"<<endl;
                            cout<<"     Flight ID         : ";
                            cin>>flighttemp.flight_id;
                            cout<<"     Airline Name      : ";
                            cin>>flighttemp.flight_name;
                            cout<<"     Destination       : ";
                            cin>>flighttemp.destination;
                            cout<<"  -----------------------------------------"<<endl;
                            cout<<"  press 'enter' to continue...";
                            if(findElm(LP,flighttemp) == NULL){
                                P = alokasi(flighttemp);
                                insertFirst(LP, P);
                            }
                            else{
                                cout<<"  Sorry that ID is already exist, press 'enter' to continue...";
                            }
                            cin.sync();
                            cin.get();
                            system("cls");
                        break;
                        case 3:
                            cout<<endl;
                            cout<<"  ----------  Input Last Flight  ---------"<<endl;
                            cout<<"     Flight ID         : ";
                            cin>>flighttemp.flight_id;
                            cout<<"     Airline Name      : ";
                            cin>>flighttemp.flight_name;
                            cout<<"     Destination       : ";
                            cin>>flighttemp.destination;
                            cout<<"  -----------------------------------------"<<endl;
                            cout<<"  press 'enter' to continue...";
                            if(findElm(LP,flighttemp) == NULL){
                                P = alokasi(flighttemp);
                                insertLast(LP, P);
                            }
                            else{
                                cout<<"  Sorry that ID is already exist, press 'enter' to continue...";
                            }
                            cin.sync();
                            cin.get();
                            system("cls");
                        break;
                        }
                    }
                    system("cls");
                break;
                case 4:
                    cout<<endl;
                    cout<<"  ---------  Input new Passenger  ---------"<<endl;
                    cout<<"     1.  Insert First"<<endl;
                    cout<<"     2.  Insert After (Under Maintenis)"<<endl;
                    cout<<"     3.  Insert Last"<<endl;
                    cout<<endl;
                    cout<<"     0.  Main Menu"<<endl;
                    cout<<"  -----------------------------------------"<<endl;
                    cout<<endl;
                    cout<<"  Choose with NUMBER: ";
                    cin>>subMenuInsertP;
                    if(cin.fail()){
                        cin.clear();
                        cout<<"Please input with NUMBER!, press 'enter' to continue...";
                        cin.sync();
                        cin.get();
                    }
                    else{
                        switch(subMenuInsertP){
                        case 1:
                            cout<<endl;
                            cout<<"  --------  Input First Passenger  --------"<<endl;
                            cout<<"     Passenger ID         : ";
                            cin>>passengertemp.pass_id;
                            cout<<"     Passenger Name       : ";
                            cin>>passengertemp.pass_name;
                            cout<<"  -----------------------------------------"<<endl;
                            cout<<"  press 'enter' to continue...";
                            if(findElm(LC,passengertemp) == NULL){
                                C = alokasi(passengertemp);
                                insertFirst(LC, C);
                            }
                            else{
                                cout<<"  Sorry that ID is already exist, press 'enter' to continue...";
                            }
                            cin.sync();
                            cin.get();
                            system("cls");
                        break;
                        case 2:
                            cout<<endl;
                            cout<<"  --------  Input After Passenger  --------"<<endl;
                            cout<<"     Passenger ID         : ";
                            cin>>passengertemp.pass_id;
                            cout<<"     Passenger Name       : ";
                            cin>>passengertemp.pass_name;
                            cout<<"  -----------------------------------------"<<endl;
                            cout<<"  press 'enter' to continue...";
                            if(findElm(LC,passengertemp) == NULL){
                                C = alokasi(passengertemp);
                                insertFirst(LC, C);
                            }
                            else{
                                cout<<"  Sorry that ID is already exist, press 'enter' to continue...";
                            }
                            cin.sync();
                            cin.get();
                            system("cls");
                        break;
                        case 3:
                            cout<<endl;
                            cout<<"  --------  Input Last Passenger  --------"<<endl;
                            cout<<"     Passenger ID         : ";
                            cin>>passengertemp.pass_id;
                            cout<<"     Passenger Name       : ";
                            cin>>passengertemp.pass_name;
                            cout<<"  -----------------------------------------"<<endl;
                            cout<<"  press 'enter' to continue...";
                            if(findElm(LC,passengertemp) == NULL){
                                C = alokasi(passengertemp);
                                insertLast(LC, C);
                            }
                            else{
                                cout<<"  Sorry that ID is already exist, press 'enter' to continue...";
                            }
                            cin.sync();
                            cin.get();
                            system("cls");
                        break;
                        }
                    }
                    system("cls");
                break;
                case 5:
                    cout<<endl;
                    cout<<"  ----------  Delete Flight  -----------"<<endl;
                    cout<<"     1.  Delete First"<<endl;
                    cout<<"     2.  Delete Last"<<endl;
                    cout<<"     3.  Delete by ID (Under Maintenis)"<<endl;
                    cout<<endl;
                    cout<<"     0.  Main Menu"<<endl;
                    cout<<"  -----------------------------------------"<<endl;
                    cout<<endl;
                    cout<<"  Choose with NUMBER: ";
                    cin>>subMenuDeleteF;
                    if(cin.fail()){
                        cin.clear();
                        cout<<"Please input with NUMBER!, press 'enter' to continue...";
                        cin.sync();
                        cin.get();
                    }
                    else{
                        switch(subMenuDeleteF){
                        case 1:
                            deleteFirst(LP,P);
                            dealokasi(P);
                            system("cls");
                        break;
                        case 2:
                            deleteLast(LP,P);
                            dealokasi(P);
                            system("cls");
                        break;
                        case 3:
                            /*cout<<endl;
                            cout<<"  -----------  List of Flight  ------------"<<endl;
                            cout<<"     ID          Airline       Destination "<<endl;
                            printInfo(LP);
                            cout<<endl;
                            cout<<"  Input Flight ID to Delete :   ";
                            cin>>flighttemp.flight_id;
                            P = findElm(LP,flighttemp);
                            BefElm = findElmBefore(LP,flighttemp);
                            deleteByFlightID(LP,BefElm,P);
                            dealokasi(P);
                            cout<<endl;
                            cout<<"  press 'enter' to continue...";
                            cin.sync();
                            cin.get();
                            system("cls");*/
                        break;
                        }
                    }
                    system("cls");
                  break;
                case 6:
                    cout<<endl;
                    cout<<"  ----------  Delete Passenger  -----------"<<endl;
                    cout<<"     1.  Delete First"<<endl;
                    cout<<"     2.  Delete Last"<<endl;
                    cout<<"     3.  Delete by ID (Under Maintenis)"<<endl;
                    cout<<endl;
                    cout<<"     0.  Main Menu"<<endl;
                    cout<<"  -----------------------------------------"<<endl;
                    cout<<endl;
                    cout<<"  Choose with NUMBER: ";
                    cin>>subMenuDeleteP;
                    if(cin.fail()){
                        cin.clear();
                        cout<<"Please input with NUMBER!, press 'enter' to continue...";
                        cin.sync();
                        cin.get();
                    }
                    else{
                        switch(subMenuDeleteP){
                        case 1:
                            deleteFirst(LC,C);
                            dealokasi(C);
                            system("cls");
                        break;
                        case 2:
                            deleteLast(LC,C);
                            dealokasi(C);
                            system("cls");
                        break;
                        case 3:
                            /*cout<<endl;
                            cout<<"  -----------  List of Flight  ------------"<<endl;
                            cout<<"     ID          Airline       Destination "<<endl;
                            printInfo(LP);
                            cout<<endl;
                            cout<<"  Input Flight ID to Delete :   ";
                            cin>>flighttemp.flight_id;
                            P = findElm(LP,flighttemp);
                            BefElm = findElmBefore(LP,flighttemp);
                            deleteByFlightID(LP,BefElm,P);
                            dealokasi(P);
                            cout<<endl;
                            cout<<"  press 'enter' to continue...";
                            cin.sync();
                            cin.get();
                            system("cls");*/
                        break;
                        }
                    }
                    system("cls");
                  break;
                case 8:
                    cout<<endl;
                    cout<<"  -----------  List of Flight  ------------"<<endl;
                    cout<<"     ID          Airline       Destination "<<endl;
                    cout<<"  -----------------------------------------"<<endl;
                    printInfo(LP);
                    cout<<endl;
                    cout<<"  ----------  List of Passenger  ----------"<<endl;
                    cout<<"      ID            Name                   "<<endl;
                    cout<<"  -----------------------------------------"<<endl;
                    printInfo(LC);
                    cout<<endl;
                    cout<<"  Input Flight ID to Connect Passenger :   ";
                    cin>>flighttemp.flight_id;
                    cout<<"  Input Passenger ID to Connect Flight :   ";
                    cin>>passengertemp.pass_id;
                    P = findElm(LP,flighttemp);
                    C = findElm(LC,passengertemp);
                    R = alokasi(C);
                    insertFirst(child(P),R);
                    cout<<endl;
                    cout<<"  press 'enter' to continue...";
                    system("cls");
                break;
            }
        }

    }

    return 0;
}
