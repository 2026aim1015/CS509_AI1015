#include<iostream>
#include<cstdlib>
#include <string>
using namespace std;
int main()
{
    int choice;
    while(true)
    {
        cout<<"COMMON WRAPPER"<<endl;
        cout<<"Available Assignments"<<endl;
        cout<<"1. Assignment 1 - GEMM"<<endl;
        cout<<"2. Assignment 2 - Graph Algorithms"<<endl;
        cout <<"3. Assignment 3 - MST"<<endl;
        cout<<"0. Exit"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == 0)
        {
            cout<<"Exiting..."<<endl;
            break;
        }
        if(choice != 1 && choice != 2 && choice != 3)
        {
            cout<<"Invalid Choice"<<endl;
            continue;
        }
        int option;
        if(choice==1)
        {
            cout<<endl<<"Assignment 1 - GEMM"<<endl;
            cout<<"1. Compile Assignment"<<endl;
            cout<<"2. Run One Test File"<<endl;
            cout<<"3. Run All Test Files"<<endl;
            cout<<"4. Compile and Run"<<endl;
            cout<<"0. Back"<<endl;

            cout<<endl<<"Enter option: ";
            cin>>option;
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
                        cout<<"\nRun test_" << (i<10?"0":"") <<i<<".txt\n";
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
                    cout<<"Invalid Option!\n";
            }
        }
        else if(choice==2)
        {
            int algorithm;

            cout<<endl<<"Assignment 2 - Graph Algorithms"<<endl;
            cout<<"1. Bellman-Ford"<<endl;
            cout<<"2. Floyd-Warshall"<<endl;
            cout<<"0. Back"<<endl;

            cout<<endl<<"Enter algorithm: ";
            cin>>algorithm;

            if (algorithm == 1)
            {
                int option;
                cout<<endl<<"Bellman-Ford"<<endl;
                cout<<"1. Compile"<<endl;
                cout<<"2. Run One Test File"<<endl;
                cout<<"3. Run All Test Files"<<endl;
                cout<<"4. Compile and Run All"<<endl;
                cout<<"0. Back"<<endl;
                cout<<endl<<"Enter option: ";
                cin>>option;

                switch(option)
                {
                    case 1:
                        system("cmd /c \"cd assignment_02 && g++ -std=c++17 src/csr.cpp src/bellman_ford.cpp driver/driver_bellman_ford.cpp -o bellman_test\"");
                        break;
                    case 2:
                    {
                        int test;
                        cout<<endl;
                        cout<<"1. bf_10.txt"<<endl;
                        cout<<"2. bf_100.txt"<<endl;
                        cout<<"3. bf_10000.txt"<<endl;
                        cout<<"4. bf_50000.txt"<<endl;
                        cout<<"5. bf_100000.txt"<<endl;
                        cout<<"6. bf_20.txt"<<endl;

                        cout<<"Enter test number: ";
                        cin>>test;
                        string file;

                        if(test == 1) file = "bf_10.txt";
                        else if(test == 2) file = "bf_100.txt";
                        else if(test == 3) file = "bf_10000.txt";
                        else if(test == 4) file = "bf_50000.txt";
                        else if(test == 5) file = "bf_100000.txt";
                        else if(test == 6) file = "bf_20.txt";
                        else
                        {
                            cout<<"Invalid test number!"<<endl;
                            break;
                        }

                        string command ="cmd /c \"cd assignment_02 && bellman_test tests/bellman_ford/" +file + "\"";
                        system(command.c_str());
                        break;
                    }

                    case 3:
                    {
                        string tests[] =
                        {
                            "bf_10.txt",
                            "bf_100.txt",
                            "bf_10000.txt",
                            "bf_50000.txt",
                            "bf_100000.txt",
                            "bf_20.txt"
                        };

                        for (int i = 0; i < 6; i++)
                        {
                            cout<<"\nRunning "<<tests[i]<<endl;
                            string command ="cmd /c \"cd assignment_02 && bellman_test tests/bellman_ford/" +tests[i] + "\"";
                            system(command.c_str());
                        }
                        break;
                    }

                    case 4:
                        system("cmd /c \"cd assignment_02 && g++ -std=c++17 src/csr.cpp src/bellman_ford.cpp driver/driver_bellman_ford.cpp -o bellman_test\"");
                        system("cmd /c \"cd assignment_02 && bellman_test tests/bellman_ford/bf_10.txt\"");
                        system("cmd /c \"cd assignment_02 && bellman_test tests/bellman_ford/bf_100.txt\"");
                        system("cmd /c \"cd assignment_02 && bellman_test tests/bellman_ford/bf_10000.txt\"");
                        system("cmd /c \"cd assignment_02 && bellman_test tests/bellman_ford/bf_50000.txt\"");
                        system("cmd /c \"cd assignment_02 && bellman_test tests/bellman_ford/bf_100000.txt\"");
                        system("cmd /c \"cd assignment_02 && bellman_test tests/bellman_ford/bf_20.txt\"");
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Invalid Option!" << endl;
                }
            }
            else if (algorithm == 2)
            {
                int option;

                cout<<endl<<"Floyd-Warshall"<<endl;
                cout<<"1. Compile"<<endl;
                cout<<"2. Run One Test File"<<endl;
                cout<<"3. Run All Test Files"<<endl;
                cout<<"4. Compile and Run All"<<endl;
                cout<<"0. Back"<<endl;

                cout<<endl<<"Enter option: ";
                cin>>option;
                switch(option)
                {
                    case 1:
                        system("cmd /c \"cd assignment_02 && g++ -std=c++17 src/csr.cpp src/floyd_warshall.cpp driver/driver_floyd_warshall.cpp -o floyd_test\"");
                        break;

                    case 2:
                    {
                        int test;

                        cout<<endl;
                        cout<<"1. fw_10.txt"<<endl;
                        cout<<"2. fw_100.txt"<<endl;
                        cout<<"3. fw_500.txt"<<endl;
                        cout<<"4. fw_1000.txt"<<endl;
                        cout<<"5. fw_2000.txt"<<endl;
                        cout<<"6. fw_20.txt"<<endl;

                        cout<<"Enter test number: ";
                        cin>>test;

                        string file;

                        if(test == 1) file = "fw_10.txt";
                        else if(test == 2) file = "fw_100.txt";
                        else if(test == 3) file = "fw_500.txt";
                        else if(test == 4) file = "fw_1000.txt";
                        else if(test == 5) file = "fw_2000.txt";
                        else if(test == 6) file = "fw_20.txt";
                        else
                        {
                            cout<<"Invalid test number!"<<endl;
                            break;
                        }

                        string command ="cmd /c \"cd assignment_02 && floyd_test tests/floyd_warshall/" +file + "\"";
                        system(command.c_str());
                        break;
                    }
                    case 3:
                    {
                        string tests[] =
                        {
                            "fw_10.txt",
                            "fw_100.txt",
                            "fw_500.txt",
                            "fw_1000.txt",
                            "fw_2000.txt",
                            "fw_20.txt"
                        };

                        for(int i = 0; i < 6; i++)
                        {
                            cout<<"\nRunning " << tests[i] << endl;
                            string command ="cmd /c \"cd assignment_02 && floyd_test tests/floyd_warshall/" +tests[i] + "\"";
                            system(command.c_str());
                        }
                        break;
                    }

                    case 4:
                        system("cmd /c \"cd assignment_02 && g++ -std=c++17 src/csr.cpp src/floyd_warshall.cpp driver/driver_floyd_warshall.cpp -o floyd_test\"");
                        system("cmd /c \"cd assignment_02 && floyd_test tests/floyd_warshall/fw_10.txt\"");
                        system("cmd /c \"cd assignment_02 && floyd_test tests/floyd_warshall/fw_100.txt\"");
                        system("cmd /c \"cd assignment_02 && floyd_test tests/floyd_warshall/fw_500.txt\"");
                        system("cmd /c \"cd assignment_02 && floyd_test tests/floyd_warshall/fw_1000.txt\"");
                        system("cmd /c \"cd assignment_02 && floyd_test tests/floyd_warshall/fw_2000.txt\"");
                        system("cmd /c \"cd assignment_02 && floyd_test tests/floyd_warshall/fw_20.txt\"");
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Invalid Option!" << endl;
                }
            }
        }        
        else if(choice == 3)
        {
            int option;

            cout << endl << "Assignment 3 - MST" << endl;
            cout << "1. Compile Assignment" << endl;
            cout << "2. Run One Test File" << endl;
            cout << "3. Run All Test Files" << endl;
            cout << "4. Compile and Run All" << endl;
            cout << "0. Back" << endl;

            cout << endl << "Enter option: ";
            cin >> option;

            switch(option)
            {
                case 1:
                    system("cmd /c \"cd assignment_03 && g++ -std=c++17 -O2 src/csr.cpp src/kruskal.cpp src/prim.cpp driver/main.cpp -o mst.exe\"");
                    cout << "Assignment 3 compiled successfully." << endl;
                    break;

                case 2:
                {
                    int test;
                    cout << endl;
                    cout << "1. mst_10.txt" << endl;
                    cout << "2. mst_100.txt" << endl;
                    cout << "3. mst_1000.txt" << endl;
                    cout << "4. mst_10000.txt" << endl;
                    cout << "5. mst_50000.txt" << endl;
                    cout << "6. mst_100000.txt" << endl;
                    cout << "Enter test number: ";
                    cin >> test;
                    string file;
                    if(test == 1)
                        file = "mst_10.txt";

                    else if(test == 2)
                        file = "mst_100.txt";

                    else if(test == 3)
                        file = "mst_1000.txt";

                    else if(test == 4)
                        file = "mst_10000.txt";

                    else if(test == 5)
                        file = "mst_50000.txt";

                    else if(test == 6)
                        file = "mst_100000.txt";
                    else
                    {
                        cout << "Invalid test number!" << endl;
                        break;
                    }
                    string command = "cmd /c \"cd assignment_03 && mst.exe tests/"+ file + "\"";
                    system(command.c_str());
                    break;
                }

                case 3:
                {
                    string tests[] =
                    {
                        "mst_10.txt",
                        "mst_100.txt",
                        "mst_1000.txt",
                        "mst_10000.txt",
                        "mst_50000.txt",
                        "mst_100000.txt"
                    };
                    for(int i = 0; i < 6; i++)
                    {
                        cout << endl;
                        cout << "Running " << tests[i] << endl;
                        string command ="cmd /c \"cd assignment_03 && mst.exe tests/"+ tests[i] + "\"";
                        system(command.c_str());
                    }
                   break;
                }
                case 4:
                    system("cmd /c \"cd assignment_03 && g++ -std=c++17 -O2 src/csr.cpp src/kruskal.cpp src/prim.cpp driver/main.cpp -o mst.exe\"");
                    system("cmd /c \"cd assignment_03 && mst.exe tests/mst_10.txt\"");
                    system("cmd /c \"cd assignment_03 && mst.exe tests/mst_100.txt\"");
                    system("cmd /c \"cd assignment_03 && mst.exe tests/mst_1000.txt\"");
                    system("cmd /c \"cd assignment_03 && mst.exe tests/mst_10000.txt\"");
                    system("cmd /c \"cd assignment_03 && mst.exe tests/mst_50000.txt\"");
                    system("cmd /c \"cd assignment_03 && mst.exe tests/mst_100000.txt\"");
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid Option!" << endl;
            }
        }
    }

    return 0;
}
