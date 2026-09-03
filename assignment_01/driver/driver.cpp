#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <sys/stat.h> // For checking/creating directories on Linux
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

    // Checking whether the file is opened successfully
    if (!input_file)
    {
        cout << "Error: Unable to open input file (tests/" << test_file << ")." << endl;
        return 1;
    }

    // Take variable for taking dimension of the matrix
    int m, k, n;
    input_file >> m >> k >> n;

    // Checking for valid dimensions of the matrix
    if (m <= 0 || k <= 0 || n <= 0)
    {
        cout << "Error: Invalid matrix dimensions." << endl;
        return 1;
    }

    // Creating two-dimensional vectors for storing matrix values
    vector<vector<int>> matrix_A(m, vector<int>(k));
    vector<vector<int>> matrix_B(k, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            input_file >> matrix_A[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input_file >> matrix_B[i][j];
        }
    }

    input_file.close();

    // Result matrices
    vector<vector<long long>> result_matrix_simple(m, vector<long long>(n, 0));
    vector<vector<long long>> result_matrix_blocking(m, vector<long long>(n, 0));

    // Simple GEMM
    auto start_simple = high_resolution_clock::now();
    simple_GEMM(matrix_A, matrix_B, result_matrix_simple);
    auto end_simple = high_resolution_clock::now();
    auto simple_time = duration_cast<microseconds>(end_simple - start_simple);

    // Blocking GEMM
    auto start_blocking = high_resolution_clock::now();
    blocking_GEMM(matrix_A, matrix_B, result_matrix_blocking, 64);
    auto end_blocking = high_resolution_clock::now();
    auto blocking_time = duration_cast<microseconds>(end_blocking - start_blocking);

    // Ensure 'outputs' directory exists on Linux before creating file
    #if defined(_WIN32)
        system("if not exist outputs mkdir outputs");
    #else
        mkdir("outputs", 0777);
    #endif

    // File name processing
    string base_name = test_file;
    size_t last_slash = base_name.find_last_of("/\\");
    if (last_slash != string::npos)
    {
        base_name = base_name.substr(last_slash + 1);
    }

    size_t ext_pos = base_name.find(".txt");
    string output_file_name = (ext_pos != string::npos) ? base_name.substr(0, ext_pos) + "_output.txt" : base_name + "_output.txt";
    
    ofstream output_file("outputs/" + output_file_name);

    if (!output_file)
    {
        cout << "Error: Unable to create output file." << endl;
        return 1;
    }

    // Output - GEMM Simple
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

    cout << "Execution Time : " << simple_time.count() << " microseconds" << endl << endl;
    output_file << "Execution Time : " << simple_time.count() << " microseconds" << endl << endl;

    // Output - GEMM Blocking
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

    cout << "Execution Time : " << blocking_time.count() << " microseconds" << endl;
    output_file << "Execution Time : " << blocking_time.count() << " microseconds" << endl;

    output_file.close();
    cout << "Output saved in outputs/" << output_file_name << endl;
    return 0;
}