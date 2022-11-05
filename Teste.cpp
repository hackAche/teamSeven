#include <iostream>
#include <string>
#include <conio.h>
//#include <array>
#include <list>
//#include <typeinfo>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

void print_vet_string(vector<string> vet)
{
    for (int j = 0; j < (vet.size()); j++)
    {
        cout << vet[j] << " ";
    }
    cout << endl;
}


void print_vet_int(vector<int> vet)
{
    for (int j = 0; j < (vet.size()); j++)
    {
        cout << vet[j]<< " ";
    }
    cout << endl;
}
vector<int> HourToMin (vector<string> str)
{
    int hoursDec,hoursUni,minutesDec,minutesUni,hours,minutes;
    vector<int> result;
    for(int i = 0; i<(str.size()); i++){
        hoursDec = int (str[i][0]-48);
        hoursUni = int (str[i][1]-48);
        minutesDec = int (str[i][3]-48);
        minutesUni = int (str[i][4]-48);
        
        hours = (hoursDec*10) + hoursUni;
        minutes = (minutesDec*10) + minutesUni;
        result.push_back((hours*60) + minutes);
    }

    return result;
}

vector<string> MinToHour (vector<int> vec)
{
    vector<string> result;
    int hours,minutes;
    string hours_str,minutes_str,x;

    for(int i = 0; i<vec.size(); i++){
        
        hours=vec[i]/60;
        minutes=vec[i]%60;
        hours_str = to_string(hours);
        minutes_str = to_string(minutes);
        if (hours_str.size() == 1){
            if (minutes_str == "0"){
                x="0" + hours_str + ":" + minutes_str + "0";
            }
            else{
                x="0"+hours_str + ":" + minutes_str;
            }
        }
        else{
            if (minutes_str == "0"){
                x=hours_str + ":" + minutes_str + "0";
            }
            else{
                x=hours_str + ":" + minutes_str;
            }
        }
        
        
        result.push_back(x);
        
    }

    return result;
}

vector<int> DepartureOfBus(vector<int>end_int,int TimeOfRout,int gap){
    vector<int> departure;
    int TimeOfDeparture = TimeOfRout + gap;
    for(int i = 0; i<end_int.size(); i++){
        departure.push_back(end_int[i] - TimeOfDeparture);
    }
    return departure;
}

vector<int> ArrivalOFBus(vector<int>start_int,int gap){
    vector<int> arrival;
    for(int i = 0; i<start_int.size(); i++){
        arrival.push_back(start_int[i] + gap);
    }
    return arrival;
}

vector<int> ArrivalOfDepartureOFBus(vector<int>start_int,int TimeOfRout){
    vector<int> arrivalofdeparture;
    for(int i = 0; i<start_int.size(); i++){
        arrivalofdeparture.push_back(start_int[i] + TimeOfRout);
    }
    return arrivalofdeparture;
}

vector<int> quantityofbus (int numberofbus,vector<int> spaceofbus,vector<int> students){
    int getstudents = 0;
    vector<int> spaceofbussort;
    vector<int> quantity;
    sort (spaceofbus.begin(),spaceofbus.end());
    //print_vet_int(spaceofbus);
    for(int i = 0; i<students.size(); i++){
        spaceofbussort = spaceofbus;
        while (getstudents<students[i]){
            if (students[i]>=spaceofbussort[spaceofbussort.size()-1]){
            getstudents = getstudents + spaceofbussort[spaceofbussort.size()-1];
            spaceofbussort.erase(spaceofbussort.begin()+(spaceofbussort.size()));
            }
            else{
                int j=spaceofbussort.size()-1;
                while(students[i]>spaceofbussort[j]){
                    j--;
                }
                getstudents = getstudents + spaceofbussort[j];
                spaceofbussort.erase(spaceofbussort.begin()+j);
            }
        }
        quantity.push_back(spaceofbussort.size());
    }
    return quantity;
}


int main(){
    int TimeOfRout = 30;
    int numberofbus = 10;
    vector<int> spaceofbus{50,50,50,50,50,50,60,25,25,25};
    vector<int> studentsIn {623,324,412,415,120};
    vector<int> studentsOut {55,540,310,315,402};
    vector<int> quantifyofbusin;
    vector<int> quantifyofbusout;
    int gap = 10;
    vector<int> start_int;
    vector<int> end_int;
    vector<int> departure;
    vector<int> arrivalofdeparture;
    vector<int> arrival;
    vector<string> start {"08:00","10:00","12:00","13:30","15:10"};
    vector<string> end {"09:40","11:40","14:00","15:10","16:50"};
    vector<string> printdeparture;
    vector<string> printarrivalofdeparture;
    vector<string> printarrival;

    start_int = HourToMin(start);
    end_int = HourToMin(end);
    departure = DepartureOfBus(start_int,TimeOfRout,gap);
    arrivalofdeparture = ArrivalOfDepartureOFBus(departure,TimeOfRout);
    arrival = ArrivalOFBus(end_int,gap);
    
    printdeparture = MinToHour(departure);
    printarrivalofdeparture=MinToHour(arrivalofdeparture);
    printarrival=MinToHour(arrival);

    quantifyofbusin = quantityofbus (numberofbus,spaceofbus,studentsIn);
    quantifyofbusout = quantityofbus (numberofbus,spaceofbus,studentsOut);

    //print_vet_int(start_int);
    //print_vet_int(end_int);

    /*cout << endl << endl << endl;

    cout << "Saida do campus pre-aula: ";
    print_vet_string(printdeparture);

    cout << "Chegada no campus: ";
    print_vet_string(printarrivalofdeparture);

    cout << "Horario da aula: ";
    print_vet_string(start);

    cout << "Horario de saida aula: ";
    print_vet_string(end);

    cout << "Saida do campus pos aulas: ";
    print_vet_string(printarrival);

    cout << endl << endl << endl;*/


    cout << "pessoas por horario indo: ";
    print_vet_int(studentsIn);
    cout << "numero de onibus utilizados:";
    print_vet_int(quantifyofbusin);

    cout << "pessoas por horario voltando: ";
    print_vet_int(studentsOut);
    cout << "numero de onibus utilizados:";
    print_vet_int(quantifyofbusout);
    //DepartureOfBus



    return 0;
}