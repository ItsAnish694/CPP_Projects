#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

void printMenu(); // Prints The Menu

class calcBinary // Class To Perform Calculations
{
public:
    int binaryDecimal(string Operands) // Convert Binary To Decimal
    {
        int decimal = 0;
        int pwr = Operands.size() - 1;

        for (int i = 0; i < Operands.size(); i++)
        {
            decimal += (Operands[i] - '0') * pow(2, pwr);
            pwr--;
        }

        return decimal;
    }

    string decimalBinary(string Operands) // Convert Decimal To Binary
    {
        if (Operands.length() > 9)
        {
            return "Too Large";
        }

        int decimal = stoi(Operands);
        string valueBinary = "";

        if (decimal == 0)
        {
            return "0";
        }

        while (decimal > 0)
        {
            valueBinary = to_string(decimal % 2) + valueBinary;
            decimal /= 2;
        }

        return valueBinary;
    }

    bool checkError(string str) // Check Error If Input Is Other Than Numbers
    {
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] < '0') || (str[i] > '9'))
            {
                return true;
            }
        }
        return false;
    }

    bool isdecimal(string str) // Checks If The Input Is Decimal
    {
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] != '0') && (str[i] != '1'))
            {
                return true;
            }
        }
        return false;
    }

} Binary;

class TakeInput // Class To Take Inputs
{
public:
    string validInput() // Input How Many Operands To Perform Operations
    {
        string Operands;
        do
        {
            cout << "Enter Number Of Operands:\n";
            cin >> Operands;

            if (Binary.checkError(Operands))
            {
                cout << "No Operations Can Be Performed.\n\n";
            }

        } while (Binary.checkError(Operands)); // Checks Possible Errors
        return Operands;
    }

    void inputOperands(vector<string> &Operands) // Input The Operands
    {
        cout << "\nEnter The Operands:\n";

        for (int i = 0; i < Operands.size(); i++)
        {
            do
            {
                cin >> Operands[i];

                if (Operands[i].length() > 31)
                {
                    cout << "Input Is Too Large.\n";
                }

                else if (Binary.checkError(Operands[i]))
                {
                    cout << "Only Positive Integers Are Allowed(No Space).\n";
                    cout << "\nEnter Corrected Value:\n";
                }

            } while ((Operands[i].length() > 31) || Binary.checkError(Operands[i])); // Checks Possible Errors
        }
    }

    int getChoice() // Takes Valid Input Of Choice
    {
        string ch;
        do
        {
            cin >> ch;
            if (Binary.checkError(ch))
            {
                cout << "Only Positive Integers Are Allowed.\n";
                cout << "\nEnter Your Choice Again:\n";
            }
        } while (Binary.checkError(ch));
        return stoi(ch);
    }

} Input;

int giveOutPut(vector<string> Operands) // Function To Give Output
{
    // calcBinary Binary;
    int ch;
    do
    {
        cout << "\nEnter Your Choice:\n";
        ch = Input.getChoice();

        switch (ch)
        {

        case 1:
        { // Binary To Decimal

            int decimal;
            cout << "_________________________________________\n";
            cout << "__________| Binary -> Decimal |__________\n";

            for (int i = 0; i < Operands.size(); i++)
            {
                if (Binary.isdecimal(Operands[i])) // Checks Error If Converting Value Is Already Decimal
                {
                    cout << Operands[i] << " -> Is Not A Binary Value\n";
                    continue;
                }

                decimal = Binary.binaryDecimal(Operands[i]);
                cout << Operands[i] << " -> " << decimal << endl;
            }

            cout << "_________________________________________\n";
            break;
        }

        case 2:
        { // Decimal To Binary

            string binary;
            cout << "_________________________________________\n";
            cout << "__________| Decimal -> Binary |__________\n";

            for (int i = 0; i < Operands.size(); i++)
            {
                binary = Binary.decimalBinary(Operands[i]);
                cout << Operands[i] << " -> " << binary << endl;
            }

            cout << "_________________________________________\n";
            break;
        }

        case 3:
        { // Addition Of Binary Numbers

            int deciAdd = 0;
            string binaryAdd;

            cout << "_________________________________________\n";
            cout << "___________| Binary Addition |___________\n";

            for (int i = 0; i < Operands.size(); i++)
            {

                if (Binary.isdecimal(Operands[i])) // Check If The Value Is Decimal
                {
                    cout << Operands[i] << " -> Not A Binary Value\n";
                    continue;
                }

                deciAdd += Binary.binaryDecimal(Operands[i]);
                cout << Operands[i] << "\n";
            }

            binaryAdd = Binary.decimalBinary(to_string(deciAdd));

            for (int i = 0; i <= binaryAdd.length(); i++)
            {
                cout << "-";
            }

            cout << "+\n";
            cout << binaryAdd << "\n";
            cout << "_________________________________________\n";
            break;
        }

        case 4:
        { // Binary Multiplication

            int deciMulti = 1;
            string binaryMulti;

            cout << "_________________________________________\n";
            cout << "________| Binary Multiplication |________\n";

            for (int i = 0; i < Operands.size(); i++)
            {
                if (Binary.isdecimal(Operands[i])) // Check If The Value Is Decimal
                {
                    cout << Operands[i] << " -> Not A Binary Value\n";
                    continue;
                }

                deciMulti *= Binary.binaryDecimal(Operands[i]);
                cout << Operands[i] << "\n";
            }

            binaryMulti = Binary.decimalBinary(to_string(deciMulti));

            for (int i = 0; i <= binaryMulti.length(); i++)
            {
                cout << "-";
            }

            cout << "x\n";
            cout << binaryMulti << "\n";
            cout << "_________________________________________\n";
            break;
        }

        case 5:
        { // To Exit First Loop(For New Input)

            cout << "_________________________________________\n";
            cout << "___________| NEXT CALCULATION |__________\n";
            cout << "_________________________________________\n\n";
            break;
        }

        case 6:
        { // To Exit Both Loop(Exit The Program)
            cout << "Exited.";
            break;
        }

        default:
        {
            cout << "Invalid Choice.\n";
            break;
        }
        }

    } while ((ch != 6) && (ch != 5));
    return ch;
}

int main()
{
    string numOperands;
    int ch;

    do
    {
        numOperands = Input.validInput();
        vector<string> Operands(stoi(numOperands));
        Input.inputOperands(Operands);
        printMenu();
        ch = giveOutPut(Operands);
    } while (ch != 6);

    return 0;
}

void printMenu() // Prints Menu
{
    cout << "\n**********************************\n";
    cout << "******** BinaryOperations ********\n";
    cout << "* Convert: Binary To Decimal-> 1 *\n";
    cout << "* Convert: Decimal To Binary-> 2 *\n";
    cout << "* Add Binary Numbers        -> 3 *\n";
    cout << "* Multiply Binary Numbers   -> 4 *\n";
    cout << "* To Input New Values       -> 5 *\n";
    cout << "* Exit                      -> 6 *\n";
    cout << "**********************************\n";
}