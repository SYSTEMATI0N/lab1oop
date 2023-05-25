#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <filesystem>

#include "Module1.h"

using namespace std;

void print_sequence(const double* sequence, const int length);
double* parse_sequence_from_file(ifstream& file, int& sequence_length);
double* parse_sequence_from_argv(const int argc, char** argv, int& sequence_length);
void save_sequence(const string& filename, const double* sequence, const int length, const Results& results);
ifstream get_input_file();

int main(int argc, char** argv)
{
    double* input = nullptr;
    int input_length;

    // Check if command-line parameters are provided
    if (argc == 1)
    {
        // If not, ask for the filename from the user
        ifstream file = get_input_file();
        input = parse_sequence_from_file(file, input_length);
        file.close();
    }
    else
    {
        // Parse the sequence from command-line parameters
        input = parse_sequence_from_argv(argc, argv, input_length);
    }

    cout << "Before sorting by decimal part:\n";
    print_sequence(input, input_length);

    // Sort the sequence using the provided sorting criterion
    sort(compare_decimal_ascending, input, input_length);

    cout << "After sorting by decimal part:\n";
    print_sequence(input, input_length);

    // Calculate the results (maximum, minimum, and their indices)
    Results results = calculate_results(input, input_length);
    cout << "Maximum: " << results.maximum << "\n";
    cout << "Minimum: " << results.minimum << "\n";
    cout << "Maximum Index: " << results.maximumIndex << "\n";
    cout << "Minimum Index: " << results.minimumIndex << "\n";

    string filename;
    cout << "Enter filename to save sequence and results to: ";
    cin >> filename;
    save_sequence(filename, input, input_length, results);
    cout << "Saved sequence and results to " << filename << "\n";
    cout << "Press enter to exit";

    delete[] input;
    cin.get();
    cin.get();
    return 0;
}

void print_sequence(const double* sequence, const int length)
{
    for (int i = 0; i < length; i++)
        cout << "[" << i << "] = " << sequence[i] << "\n";
}

void save_sequence(const string& filename, const double* sequence, const int length, const Results& results)
{
    ofstream file(filename);
    for (int i = 0; i < length; i++)
        file << sequence[i] << " ";
    file << "\nMaximum: " << results.maximum;
    file << "\nMinimum: " << results.minimum;
    file << "\nMaximum Index: " << results.maximumIndex;
    file << "\nMinimum Index: " << results.minimumIndex;
    file.close();
}

double* parse_sequence_from_file(ifstream& file, int& sequence_length)
{
    double number;
    sequence_length = 0;
    while (file >> number)
        sequence_length++;

    file.clear();
    file.seekg(0, std::ios::beg);

    double* sequence = new double[sequence_length];
    for (int i = 0; file >> number; i++)
        sequence[i] = number;

    return sequence;
}

double* parse_sequence_from_argv(const int argc, char** argv, int& sequence_length)
{
    sequence_length = argc - 1;
    double* sequence = new double[sequence_length];
    for (int i = 0; i < sequence_length; i++)
        sequence[i] = atof(argv[i + 1]);
    return sequence;
}

ifstream get_input_file()
{
    string filename;
    ifstream file;
    while (true)
    {
        cout << "Enter file name to read numbers from: ";
        cin >> filename;

        // Check if the file name has an extension
        if (filename.find('.') == string::npos)
        {
            // Append ".txt" to the file name if no extension is provided
            filename += ".txt";
        }

        file.open(filename);
        if (file.is_open())
            break;

        cout << "Could not find the file" << std::endl;
    }
    return file;
}