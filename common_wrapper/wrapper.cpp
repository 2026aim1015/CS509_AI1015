#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int choice;
    while(true)
    {
        cout << "COMMON WRAPPER"<<endl;
        cout << "Available Assignments"<<endl;
        cout << "1. Assignment 1 - GEMM"<<endl;
        cout << "0. Exit"<<endl<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 0)
        {
            cout << "Exiting..."<<endl;
            break;
        }
        if (choice != 1)
        {
            cout << "Invalid Choice"<<endl;
            continue;
        }
        int option;

        cout << endl<<"Assignment 1 - GEMM"<<endl;
        cout << "1. Compile Assignment"<<endl;
        cout << "2. Run One Test File"<<endl;
        cout << "3. Run All Test Files"<<endl;
        cout << "4. Compile and Run"<<endl;
        cout << "0. Back"<<endl;

        cout <<endl<< "Enter option: ";
        cin >> option;
        switch(option)
        {
            case 1:
                system("cmd /c \"cd assignment_01 && mingw32-make\"");
                break;

            case 2:
                system("cmd /c \"cd assignment_01 && driver.exe\"");
                break;

            case 3:
                for(int i=1;i<=10;i++)
                {
                    cout << "\nRun test_" << (i<10?"0":"") << i << ".txt\n";
                    system("cmd /c \"cd assignment_01 && driver.exe\"");
                }
                break;

            case 4:
                system("cmd /c \"cd assignment_01 && mingw32-make\"");
                system("cmd /c \"cd assignment_01 && driver.exe\"");
                break;

            case 0:
                break;

            default:
                cout << "Invalid Option!\n";
        }
    }

    return 0;
}
