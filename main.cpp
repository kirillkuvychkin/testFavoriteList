//
//  main.cpp
//  FavoriteList.cpp
//
//  Created by Kirill Kuvychkin on 19.03.2022.
//
//Создаем вектор+
//добавляем названия игр в вектор+
//отображаем список игр+
//спрашиваем нужно ли изменить список+
//если нужно, то:+
//    - спрашиваем нужно ли добавить название+
//    если да, то:
//        - добавляем название(я) до тех пор, пока не откажемся от добавления+
//    если нет:
//        - спрашиваем нужно ли удалить какое-либо название из списка:+
//        выводим список на отображение+
//            если да, то:
//                - удаляем выбранное название из списка и спрашиваем снова до тех пор, пока не будет получен+ отрицательный ответ,либо размер вектора не будет равен 0+
//отображаем итоговый список+

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    vector<string>gamelist;
    gamelist.push_back("GOD OF WAR");
    gamelist.push_back("LAST OF US");
    gamelist.push_back("RDR2");
    vector<string>::iterator ListSize;
    vector<string>::const_iterator iter;
    string gameName;
    cout << "My favorite games List: \n";
    for (ListSize  = gamelist.begin(); ListSize != gamelist.end(); ++ListSize)
    {
        cout << *ListSize << endl;
    }
    unsigned short int choice;
    do
    {
        cout << "What do You want to do with Game(s) in the List? " << endl;
            cout << "1 - add some Game name" << endl;
            cout << "2 - erase some Game name" << endl;
            cout << "3 - Nothing, just Exit" << endl;
            
            cout << "Select Your choice: ";
            cin >> choice;
            switch (choice)
            {
                case 1:
            cout << "If You want to add some Game to the List," << endl;
            cout << "type Your Game name: ";
                    cin.ignore(1);
            getline(cin, gameName);
            iter = find(gamelist.begin(), gamelist.end(), gameName);
                if (iter == gamelist.end())
                {
                    gamelist.insert(gamelist.begin(), gameName);
                }
                else
                {
                    cout << "\n\t\tThis name is already exist!\n" << endl;
                }
                    
            cout << "\nNow My favorite Games List: \n";
                for (ListSize  = gamelist.begin(); ListSize != gamelist.end(); ++ListSize)
                {
                    cout << *ListSize << endl;
                }
                    cout << "\n" << endl;
                    break;
                case 2:
            cout << "If You want to erase some Game from the List, " << endl;
            cout << "type Your Game name to remove: ";
                    cin.ignore(1);
            getline(cin, gameName);
            iter = find(gamelist.begin(), gamelist.end(), gameName);
            if (iter != gamelist.end())
                {
                    gamelist.erase(iter);
                    cout << "\nNow My favorite Games List: \n";
                            for (ListSize  = gamelist.begin(); ListSize != gamelist.end(); ++ListSize)
                            {
                                cout << *ListSize << endl;
                            }
                            cout << "\n" << endl;
                }
            else
                {
                    cout << "\n\t\tThis name is absent!\n" << endl;
                }
                    break;
                }
        if (gamelist.empty())
        {
            cout << "\n\tList is empty!" << endl;
            choice = 3;
        }
    }
    while (choice != 3) ;

    if (gamelist.empty())
        {
            cout << "\n\t\tBYE!\n" << endl;
        }
        else
        {
            cout << "\nNow My favorite Games List: \n";
            for (ListSize  = gamelist.begin(); ListSize != gamelist.end(); ++ListSize)
            {
                cout << *ListSize << endl;
            }
            cout << "\n\t\tBYE!\n" << endl;
        }
    return 0;
}
