#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include<fstream>
#include "../src/gemm_simple.h"
#include "../src/gemm_blocking.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    // Take test file name from wrapper or user
    string test_file;

    if (argc >= 2)
    {
        test_file = argv[1];
    }
    else
    {
        cout << "Enter test file name (Example: test_01.txt): ";
        cin >> test_file;
    }

    ifstream input_file("tests/" + test_file);

    //checking whether the file is opened successfully
    if (!input_file)
    {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }
    //take variable for taking dimension of the matrix , mxk dimension for matrix_A and kxn dimension for matrix_B
    int m, k, n;
    input_file >> m >> k >> n;
    //checking for valid dimensions of the matrix
    if (m <= 0 || k <= 0 || n <= 0)
    {
        cout << "Error: Invalid matrix dimensions." << endl;
        return 1;
    }
    //creating two  dimensional vector for storing the matrix values from the file
    vector<vector<int>> matrix_A(m, vector<int>(k));
    vector<vector<int>> matrix_B(k, vector<int>(n));
    //vector matrix_A is used to take entry of first matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            input_file >> matrix_A[i][j];
        }
    }
    //vector matrix_B is used to take entry of second matrix
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input_file >> matrix_B[i][j];
        }
    }
    //closing the file after reading
    input_file.close();

    //creating two dimensional vector for storing result of simple GEMM and blocking GEMM 
    //here long long data type is used beacuse after multiplication we can get larger values
    vector<vector<long long>> result_matrix_simple(m, vector<long long>(n, 0));
    vector<vector<long long>> result_matrix_blocking(m, vector<long long>(n, 0));

    //before calling the algorithm time is noted using given code
    auto start_simple = high_resolution_clock::now();

    //simple GEMM algorithm
    simple_GEMM(matrix_A, matrix_B, result_matrix_simple);

    //after calling the algorithm time is noted using given code
    auto end_simple = high_resolution_clock::now();

    //calculating the running time of simple GEMM
    auto simple_time =duration_cast<microseconds>(end_simple - start_simple);

    //before calling the algorithm time is noted using given code
    auto start_blocking = high_resolution_clock::now();

    //blocking GEMM algorithm
    blocking_GEMM(matrix_A, matrix_B, result_matrix_blocking, 64);

    //after calling the algorithm time is noted using given code
    auto end_blocking = high_resolution_clock::now();

    //calculating the running time of blocking GEMM
    auto blocking_time = duration_cast<microseconds>(end_blocking - start_blocking);

    //for storing the output new file is taken
    string output_file_name = test_file.substr(0, test_file.find(".txt")) + "_output.txt";
    ofstream output_file("outputs/" + output_file_name);

    //checking whether the output file is successfully created or not
    if (!output_file)
    {
        cout << "Error: Unable to create output file." << endl;
        return 1;
    }

    cout << "Algorithm: GEMM Simple" << endl;
    output_file << "Algorithm: GEMM Simple" << endl;
    if (m <= 50)
    {
        cout << "Result Matrix:" << endl;
        output_file << "Result Matrix:" << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << result_matrix_simple[i][j] << " ";
                output_file << result_matrix_simple[i][j] << " ";
            }
            cout << endl;
            output_file << endl;
        }
    }
    else if (m < 250)
    {
        cout << "Result Matrix: Saved in output file." << endl;

        output_file << "Result Matrix:" << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                output_file << result_matrix_simple[i][j] << " ";
            }
            output_file << endl;
        }
    }
    else
    {
        cout << "Result Matrix is too large to display." << endl;
        output_file << "Result Matrix is too large to display." << endl;
    }

    cout << "Execution Time : "<< simple_time.count()<< " microseconds" << endl << endl;

    output_file << "Execution Time : "<< simple_time.count()<< " microseconds" << endl << endl;


    cout << "Algorithm: GEMM Blocking" << endl;
    output_file << "Algorithm: GEMM Blocking" << endl;

    if (m <= 50)
    {
        cout << "Result Matrix:" << endl;
        output_file << "Result Matrix:" << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << result_matrix_blocking[i][j] << " ";
                output_file << result_matrix_blocking[i][j] << " ";
            }
            cout << endl;
            output_file << endl;
        }
    }
    else if (m < 250)
    {
        cout << "Result Matrix: Saved in output file." << endl;

        output_file << "Result Matrix:" << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                output_file << result_matrix_blocking[i][j] << " ";
            }
            output_file << endl;
        }
    }
    else
    {
        cout << "Result Matrix is too large to display." << endl;
        output_file << "Result Matrix is too large to display." << endl;
    }

    cout << "Execution Time : "<< blocking_time.count()<< " microseconds" << endl;

    output_file << "Execution Time : "<< blocking_time.count()<< " microseconds" << endl;
    //output file is closed
    output_file.close();
    cout << "Output saved in outputs/" << output_file_name << endl;
    return 0;
}