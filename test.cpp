#include <iostream>
#include "ReadCSV.hpp"
//#include "matrix.hpp"

using namespace std;

int main()
{
    /**
     * @mainpage
     * A sample run for 'ReadCSV' header.
     * Reading a csv file, with only numeric values.
     */
    uint64_t Nrows, Ncols;
    vector<double> Row_number;
    string headers;

    try
    {
        csv<double> my_dataset("all_number.csv");
        Nrows = my_dataset.get_NRows();
        Ncols = my_dataset.get_NCols();
        headers = my_dataset.get_header();
    }
    catch (const exception &e)
    {
        cout << e.what();
        return -1;
    }
    // Saving our data set into a matrix
    matrix<double> MatrixData(Nrows, (Ncols + 1));
    matrix<double> MatrixData2(Nrows, Ncols);
    try
    {
        csv<double> my_dataset("all_number.csv");
        MatrixData = my_dataset.read_data(false);
        MatrixData2 = my_dataset.read_data(true);
    }
    catch (const exception &e)
    {
        cout << e.what();
        return -1;
    }
    cout << "\nHeaders: " << headers << "\n\n";
    cout << "\nWithout row numbers:" << MatrixData;
    cout << "\nWith row numbers:" << MatrixData2 << "\n\n";

    try
    {
        csv<double> my_dataset("anything.csv");
    }
    catch (const exception &e)
    {
        cout << e.what();
        return -1;
    }

    cout << "This line will NOT be printed!\n";
}
