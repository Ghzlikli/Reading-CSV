# A C++20 Class Template for Reading CSV Files

<!-- TOC depthFrom:2 -->

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Constructor](#constructor)
- [Member Functions](#member-functions)
- [Performance Test](#performance-test)
- [Version history](#version-history)
- [Acknowledgment](#acknowledgment)
- [Feedback](#feedback)
- [Author and copyright](#author-and-copyright)

<!-- /TOC -->

## Introduction

Comma-separated values (CSV) files are text files in which the values are separated by commas. Each line of the file represents a row of values, and each value belongs to a column. CSV files are helpful to store datasets, and they are usually used to import data into programs.

The header file `ReadCSV.hpp` contains a class template for reading CSV files. The implementation requires `matrix.hpp` header file, which contains a class template to store and access data in a matrix format.  

## Features

- **Compatibility:** It is compatible with any C++20-compliant compiler.
- **Documented using Doxygen:** The comments are generated using Doxygen, making the code easy to understand and modify.
- **Access to preliminary information:** There are four public member functions helpful to access the basic information of the dataset, namely the number of columns, number of rows, headers, and row numbers.

## Usage

To use the csv class, include the header file:

```cpp
#include "ReadCSV.hpp"
```

Please note that the implementation is dependent on `matrix.hpp` header file. So, we need to have `matrix.hpp` header file in the same folder, but we do not need to include it in the code, as it has already been included in the `ReadCSV.hpp` header file.

To define a new csv object, simply write:

```cpp
csv<double> my_dataset("all_number.csv");
```

The template has one parameter, T, which is the value type of the dataset. For example:

- csv<uint64_t>: a dataset with unsigned integer values with 64 bits of precision.
- csv<double>: a dataset of real values (double-precision floating point format).

`my_dataset` is the name of the csv object, and the parentheses contain the name of the CSV file, `"all_number.csv"`.

## Constructor

A csv object can be constructed only by giving the name of the CSV file. The CSV file must be in the format of `value_1, value_2, ..., value_n`. The constructor reads the CSV file and stores the basic information: the header, number of columns, and number of rows. If it encounters an empty line, it will report the line number and throw an exception. In total, it might throw three exceptions:

- `csv::file_notfound`: Exception to be thrown if the file cannot be opened.
- `csv::input_failed`: Exception to be thrown if getting the file encounters an error.
- `csv::empty_line`: Exception to be thrown if the file contains empty lines.

## Member Functions

There are five public member functions available:

- `read_data(row_num)`: Reads the data set line by line and returns the dataset in matrix format. If the parameter `row_num` is true, row numbers are added to the data set.
- `get_NCols()`: Returns the number of columns of the dataset.
- `get_NRows()`: Returns the number of rows of the dataset.
- `get_header()`: Returns the headers of the dataset.
- `get_row_numbers()`: Returns the row numbers of the dataset.

There are two private member functions:

- `csv::is_valid_number(value_st)`: To check the validity of a number, the string is broken down into characters. It checks all the characters one by one, and if everything is fine, it will return `true`; otherwise, it will return `false`.
- `csv::read_rows(line)`: Reads a row of the dataset in CSV format. It might throw two exceptions:
  - `csv::less_column`: Exception to be thrown if the number of columns is less than expected.
  - `csv::more_column`: Exception to be thrown if the number of columns is more than expected.
  - `csv::number_invalid`: Exception to be thrown if a number value is not valid.

## Performance Test

The `test.cpp` file shows how to use the csv class template. First, it defines a csv object named `my_dataset`, and reads the preliminary information of `all_numbers.csv` file. Then, it defines two null matrixes with the known dimensions; then, it reopens the file and reads it twice, with and without row numbers. Finally, it prints them and the headers. It also tries to open a non-existing file, which throws an exception, and terminates the program; so, the next line will not be printed.

This library was tested on a system with Intel(R) Core(TM) i3-7100U CPU @ 2.40GHz 2.40 GHz processor and 8.00 GB (7.89 GB usable) of RAM, using GCC compiler v11.2.0 on Windows 10 build 19044.1415. To satisfy the C++20 requirement, the compiler must have the `-std=c++20` flag. The output is as follows:

```none
Data file is successfully received        

Data file is successfully received        
Started reading the data: ****
Reached end of the file.
 + All the rows are received successfully.

Started reading the data: ****
Reached end of the file.
 + All the rows are received successfully.


Headers: ID,age,height,weight


Without row numbers:
( 324   14      140     40      )
( 244   22      180     80      )
( 214   18      170     77      )
( 245   32      165     64      )

With row numbers:
( 1     324     14      140     40      )
( 2     244     22      180     80      )
( 3     214     18      170     77      )
( 4     245     32      165     64      )

File "anything.csv":
Cannot open a file with the given name!

```

## Version history

- Version 1.1 (2021-12-31)
  - Some cosmetic changes.
  - `read_data(row_num)` is modified, and now the user can decide whether to include row numbers in the output matrix or not.
  - A `README.md` documentation file is added.
  - `test.cpp` and `all_number.csv` files are added, which are helpful for testing.
  - Released in a separate [GitHub repository](https://github.com/Ghzlikli/Reading-CSV).
- Version 1.0 (2021-12-23)
  - Initial release, as a part of [TSP-Hybrid_Optimization repository](https://github.com/Ghzlikli/TSP-Hybrid_Optimization).

## Acknowledgment

The `matrix.hpp` is retrieved from Shoshany, Barak [Lecture Notes for CSE 701: Foundations of Modern Scientific Programming](https://baraksh.com/CSE701/notes.php) section 7.1.3 ('Class template example: the matrix class again').

## Feedback

Any feedback or request is highly appreciated through [open a new issue](https://github.com/Ghzlikli/Reading-CSV/issues) or [email](mailto:khalili.ghazal.97@gmail.com).

## Author and copyright

Copyright (c) 2021 [Ghazal Khalili](mailto:khalili.ghazal.97@gmail.com).

If you use this class in your code, please acknowledge the author and provide a link to the [GitHub repository](https://github.com/Ghzlikli/CSE701_Ghazal).

**Thank you!**
