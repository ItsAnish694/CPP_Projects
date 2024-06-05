#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

void clear();
void menu();

string to_lower(string name)
{
    string temp = "";
    for (char a : name)
    {
        a = tolower(a);
        temp = temp + a;
    }
    return temp;
}

bool alreadyExist(string name)
{
    string data;
    ifstream file;
    file.open("Data/File.txt");
    if (!file.is_open())
    {
        ofstream Open;
        Open.open("Data/File.txt", ios::app);
        Open.close();
        file.open("Data/File.txt");
    }
    while (getline(file, data))
    {
        data = to_lower(data);
        name = to_lower(name);
        if (data == name)
        {
            file.close();
            clear();
            return true;
        }
    }
    file.close();
    clear();
    return false;
}

int getCho()
{
    string choice;
    do
    {
        clear();
        menu();
        cout << "\nEnter Your Choice:";
        cin >> choice;
        cin.ignore();
        if ((choice < "1") || (choice > "4") || choice.length() > 1)
        {
            clear();
            cout << "Invalid Choice!! Try Again";
            getch();
        }
    } while (choice < "1" || (choice > "4") || choice.length() > 1);
    return stoi(choice);
}

void writeFile(string name)
{
    if (alreadyExist(name))
    {
        cout << "That Name Already Available!\nPress Any Key";
        getch();
        return;
    }
    ofstream file;
    file.open("Data/File.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error Opening The File.";
        getch();
        return;
    }
    file << name << endl;
    if (!file.good())
    {
        cout << "Error Writing The File.";
        getch();
        return;
    }
    clear();
    cout << "File Updated\nPress Any Key";
    getch();
    file.close();
}

void display()
{
    clear();
    ifstream file;
    string str;
    file.open("Data/File.txt");
    if (!file.is_open())
    {
        cout << "Error Cannot Open The File.\n";
        getch();
        return;
    }
    cout << "Data:\n";
    while (getline(file, str))
    {
        cout << str << endl;
    }
    cout << "Press Any Key.";
    file.close();
    getch();
}

void deleteData(string delData, bool isTrue = false)
{
    ifstream File;
    ofstream tempFile;
    string str;
    string strLow;
    if (!isTrue)
    {
        if (!alreadyExist(delData))
        {
            cout << "The Data Doesn't Exist!";
            getch();
            return;
        }
    }

    File.open("Data/File.txt");
    tempFile.open("Data/temp.txt");
    if (!tempFile.is_open() || !File.is_open())
    {
        cout << "Cannot Delete The Data,Try Again !";
        getch();
        return;
    }

    while (getline(File, str))
    {
        strLow = to_lower(str);
        delData = to_lower(delData);
        if (strLow != delData)
        {
            tempFile << str << endl;
        }
    }

    tempFile.close();
    File.close();
    remove("Data/File.txt");
    rename("Data/temp.txt", "Data/File.txt");

    if (isTrue)
    {
        cout << "Data Deleted!";
        getch();
        return;
    }
    deleteData("", true);
}

int main()
{
    int ch;
    string name;
    string delData;
    do
    {
        ch = getCho();
        switch (ch)
        {
        case 1:
            clear();
            cout << "Enter The Name: ";
            getline(cin, name);
            writeFile(name);
            break;

        case 2:
            display();
            break;

        case 3:
            clear();
            cout << "Data To Delete:";
            getline(cin, delData);
            deleteData(delData);
            break;

        case 4:
            cout << "Exit";
            break;

        default:
            break;
        }
    } while (ch != 4);
}

void clear()
{
    cout << "\033[2J\033[1;1H";
}

void menu()
{
    cout << "    Options    \n";
    cout << "Insert Data:  1\n";
    cout << "View Data:    2\n";
    cout << "Delete Data:  3\n";
    cout << "Exit:         4\n";
}