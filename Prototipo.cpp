#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <Windows.h>

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
        cout << vet[j] << " ";
    }
    cout << endl;
}
vector<int> HourToMin(vector<string> str)
{
    int hoursDec, hoursUni, minutesDec, minutesUni, hours, minutes;
    vector<int> result;
    for (int i = 0; i < (str.size()); i++)
    {
        hoursDec = int(str[i][0] - 48);
        hoursUni = int(str[i][1] - 48);
        minutesDec = int(str[i][3] - 48);
        minutesUni = int(str[i][4] - 48);

        hours = (hoursDec * 10) + hoursUni;
        minutes = (minutesDec * 10) + minutesUni;
        result.push_back((hours * 60) + minutes);
    }

    return result;
}

vector<string> MinToHour(vector<int> vec)
{
    vector<string> result;
    int hours, minutes;
    string hours_str, minutes_str, x;

    for (int i = 0; i < vec.size(); i++)
    {

        hours = vec[i] / 60;
        minutes = vec[i] % 60;
        hours_str = to_string(hours);
        minutes_str = to_string(minutes);
        if (hours_str.size() == 1)
        {
            if (minutes_str == "0")
            {
                x = "0" + hours_str + ":" + minutes_str + "0";
            }
            else
            {
                x = "0" + hours_str + ":" + minutes_str;
            }
        }
        else
        {
            if (minutes_str == "0")
            {
                x = hours_str + ":" + minutes_str + "0";
            }
            else
            {
                x = hours_str + ":" + minutes_str;
            }
        }

        result.push_back(x);
    }

    return result;
}

vector<int> DepartureOfBus(vector<int> end_int, int TimeOfRout, int gap)
{
    vector<int> departure;
    int TimeOfDeparture = TimeOfRout + gap;
    for (int i = 0; i < end_int.size(); i++)
    {
        departure.push_back(end_int[i] - TimeOfDeparture);
    }
    return departure;
}

vector<int> ArrivalOFBus(vector<int> start_int, int gap)
{
    vector<int> arrival;
    for (int i = 0; i < start_int.size(); i++)
    {
        arrival.push_back(start_int[i] + gap);
    }
    return arrival;
}

vector<int> ArrivalOfDepartureOFBus(vector<int> start_int, int TimeOfRout)
{
    vector<int> arrivalofdeparture;
    for (int i = 0; i < start_int.size(); i++)
    {
        arrivalofdeparture.push_back(start_int[i] + TimeOfRout);
    }
    return arrivalofdeparture;
}

vector<int> quantityofbus(int numberofbus, vector<int> spaceofbus, vector<int> students)
{
    int getstudents = 0;
    vector<int> spaceofbussort;
    vector<int> quantity;
    sort(spaceofbus.begin(), spaceofbus.end());
    for (int i = 0; i < students.size(); i++)
    {
        spaceofbussort = spaceofbus;

        while (getstudents < students[i])
        {

            if (students[i] >= spaceofbussort[spaceofbussort.size() - 1])
            {

                getstudents = getstudents + spaceofbussort[spaceofbussort.size() - 1];
                spaceofbussort.erase(spaceofbussort.begin() + (spaceofbussort.size() - 1));
            }

            else
            {
                int j = spaceofbussort.size() - 1;
                while (students[i] > spaceofbussort[j])
                {
                    j--;
                }
                getstudents = getstudents + spaceofbussort[j];
                spaceofbussort.erase(spaceofbussort.begin() + j);
            }
        }
        getstudents = 0;
        quantity.push_back(10 - spaceofbussort.size());
    }
    return quantity;
}

vector<string> tab(vector<int> vec)
{
    vector<string> str;
    string aux;
    int x;
    for (int i = 0; i < (vec.size()); i++)
    {
        aux = std::to_string(vec[i]);
        x = aux.size();
        for (int j = 0; j < (5 - x); j++)
        {
            aux = ' ' + aux;
        }

        str.push_back(aux);
    }
    return str;
}

void data()
{
    int TimeOfRout = 30;
    int numberofbus = 10;
    int gap = 10;
    vector<int> spaceofbus{50, 50, 50, 50, 50, 50, 60, 25, 25, 25};
    vector<int> studentsIn{435, 324, 412, 415, 120};
    vector<int> studentsOut{55, 380, 310, 315, 402};
    vector<int> quantifyofbusin;
    vector<int> quantifyofbusout;
    vector<string> strstudentsIn;
    vector<string> strstudentsOut;
    vector<string> strquantifyofbusin;
    vector<string> strquantifyofbusout;
    vector<int> start_int;
    vector<int> end_int;
    vector<int> departure;
    vector<int> arrivalofdeparture;
    vector<int> arrival;
    vector<string> start{"08:00", "10:00", "12:00", "13:30", "15:10"};
    vector<string> end{"09:40", "11:40", "14:00", "15:10", "16:50"};
    vector<string> printdeparture;
    vector<string> printarrivalofdeparture;
    vector<string> printarrival;
    start_int = HourToMin(start);
    end_int = HourToMin(end);
    departure = DepartureOfBus(start_int, TimeOfRout, gap);
    arrivalofdeparture = ArrivalOfDepartureOFBus(departure, TimeOfRout);
    arrival = ArrivalOFBus(end_int, gap);

    printdeparture = MinToHour(departure);
    printarrivalofdeparture = MinToHour(arrivalofdeparture);
    printarrival = MinToHour(arrival);

    quantifyofbusin = quantityofbus(numberofbus, spaceofbus, studentsIn);
    quantifyofbusout = quantityofbus(numberofbus, spaceofbus, studentsOut);

    strstudentsIn = tab(studentsIn);
    strstudentsOut = tab(studentsOut);
    strquantifyofbusin = tab(quantifyofbusin);
    strquantifyofbusout = tab(quantifyofbusout);

    cout << endl
         << endl
         << endl;

    cout << "    Relatorio do controle de dados de lotacao dos onibus:" << endl;

    cout << endl;

    cout << "Tempo de rota:                " << TimeOfRout << endl;
    cout << "Folga:                        " << gap << endl;
    cout << "Numero de onibus:             " << numberofbus << endl;

    cout << "capacidade dos onibus:        ";
    print_vet_int(spaceofbus);

    cout << endl;

    cout << "Saida do campus pre-aula:     ";
    print_vet_string(printdeparture);

    cout << "Chegada no campus:            ";
    print_vet_string(printarrivalofdeparture);

    cout << "Horario da aula:              ";
    print_vet_string(start);

    cout << "pessoas por horario indo:     ";
    print_vet_string(strstudentsIn);

    cout << "numero de onibus utilizados:  ";
    print_vet_string(strquantifyofbusin);

    cout << endl;

    cout << "Horario de saida aula:        ";
    print_vet_string(end);

    cout << "Saida do campus pos aulas:    ";
    print_vet_string(printarrival);

    cout << "pessoas por horario voltando: ";
    print_vet_string(strstudentsOut);

    cout << "numero de onibus utilizados:  ";
    print_vet_string(strquantifyofbusout);

    cout << endl
         << endl
         << endl;
}

void map()
{
    char matriz[32][32];
    char f;

    char trajeto_A[56][2] = {{1, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {6, 8}, {6, 9}, {6, 10}, {6, 11}, {7, 12}, {8, 13}, {9, 14}, {10, 13}, {11, 13}, {12, 13}, {13, 14}, {13, 15}, {14, 16}, {14, 15}, {15, 14}, {16, 13}, {17, 12}, {18, 13}, {19, 14}, {18, 15}, {17, 16}, {16, 17}, {15, 18}, {14, 19}, {13, 20}, {12, 21}, {11, 22}, {10, 21}, {9, 20}, {10, 19}, {11, 18}, {12, 17}, {11, 16}, {10, 15}, {9, 14}, {9, 13}, {9, 12}, {9, 11}, {9, 10}, {9, 9}, {9, 8}, {8, 7}, {7, 6}, {6, 5}, {5, 4}, {4, 3}, {3, 2}, {2, 1}, {1, 1}};
    char paradas_A[4][2] = {{1, 1}, {11, 22}, {19, 14}, {9, 13}};
    // char trajeto_C[24][2] = {{15,15},{14,14},{13,13},{12,12},{11,11},{10,10},{9,9},{8,8},{7,7},{6,6},{5,5},{4,4},{3,3},{2,2},{1,1},{0,0},{1,1},{2,2},{3,3},{2,4},{3,5},{4,6},{5,7},{6,8}};

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {

            if (i == 0 || i == 31)
            {
                matriz[i][j] = '#';
            }
            else
            {
                if (j == 0 || j == 31)
                {
                    matriz[i][j] = '#';
                }
                else
                {
                    matriz[i][j] = ' ';
                }
            }
        }
    }

    for (int m = 0; m < 56; m++)
    {
        system("cls");
        matriz[trajeto_A[m][0]][trajeto_A[m][1]] = 'O';
        if (m > 0)
        {
            matriz[trajeto_A[m - 1][0]][trajeto_A[m - 1][1]] = '.';
        }
        matriz[paradas_A[0][0]][paradas_A[0][1]] = 'A';
        matriz[paradas_A[1][0]][paradas_A[1][1]] = 'X';
        matriz[paradas_A[2][0]][paradas_A[2][1]] = 'X';
        matriz[paradas_A[3][0]][paradas_A[3][1]] = 'X';

        for (int i = 0; i < 32; i++)
        {
            //printf("\t");
            for (int j = 0; j < 32; j++)
            {
                printf(" %c", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\t\tcoordenadas: (%d,%d)",trajeto_A[m][0],trajeto_A[m][1] );
        Sleep(200);
    }
    printf("\n\n\t\tROTA FINALIZADA\n\n");
}

int main()
{

    int value;

    do
    {
        cout << ":::::::::::::::::::::Menu:::::::::::::::::::::" << endl;
        cout << ":  0 Exit                                    :" << endl;
        cout << ":  1 Controle de dados de lotacao de onibus  :" << endl;
        cout << ":  2 Localizacao em tempo real dos onibus    :" << endl;
        cout << "::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cin >> value;

        switch (value)
        {
        case 1:
            data();
            break;

        case 2:
            map();
            break;

        case 0:
            exit(1);
        default:
            cout << endl
                 << "Comando Invalido" << endl << "Digite novamente:" << endl;
            break;
        }

    } while (value != 0);
    return 0;
}