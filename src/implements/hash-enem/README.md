# **Hash Enem With Separate Chaining**

## Index:

- **[1. Objective](#1.-objective)**
- **[2. Description](#2.-description)**
  - **[2.1 Data Reading](#2.1-data-reading)**
  - **[2.2 Hash With Separate Chaining](#2.2-hash-with-separate-chaining)**
  - **[2.3 What To Analyze?](#2.3-what-to-analyze?)**
  - **[2.4 Execution](#2.4-execution)**
- **[3. Documentation](#3.-documentation)**
  - **[3.1 Questions](#3.1-questions)**
  - **[3.2 What Should be Done in the Documentation?](#3.2-what-should-be-done-in-the-documentation)**
- **[4. Help Links](#4.-help-links)**
- **[5. Reference of This Work](#5.-reference-of-this-work)**


#

## 1. Objective

ENEM is Brazil's National High School Exam. The objective of this work is to analyze the *Hash* data structure with *separate chaining*. Analyzing the data taken from schools containing the average grade of the exam.

## 2. Description

This work is divided into three parts described below:

### 2.1 Data Reading

You should write a program to read a file containing data from **30228** schools in ENEM. Each line of the file represents a school and is composed of **nine pieces of information**, separated by semicolons **;** (you can use the **strtok** function):

The data is:

- **id**
- **state** (estado)
- **county** (município)
- **network** (rede)
- **average_nature_science** (media_ciencias_natureza)
- **average_humanities_science** (media_ciencias_humanas)
- **average_language** (media_linguagem)
- **average_math** (media_matematica)
- **average_writing** (media_redacao)

Data for each school should be stored in a **hash table** described in the next section.

You must also implement the function:

```c
void printData(<type> var);
```
This function takes a structure and prints the information.

### 2.2 Hash With Separate Chaining

Given the implementation of the hash table, make adjustments to the code to implement a **hash table with separate chaining** to **store school data** in ENEM. Use the sequential list implementation as well.

The insertion and search for school in the Hash Table must be done by the school ID.

- **Insertion:** if the position is vacant, a sequential list should be created and stored in the Hash Table. Otherwise, the data should be stored or stored in beginning or end of the list (resolving collisions).
  - Note that you should not be able to enter schools with the same ID.
- **Search:** if the position is vacant, the element does not exist. Otherwise, a linear search should be done in the list.

Note that we have two Abstract Data Types defined in separate libraries. This way, the Hash Table can only use the Sequential List functions, that is, you will never have direct access to the list structure.

### 2.3 What To Analyze?

Knowing that ***n*** is the number of keys (30228), ***M*** is the number of slots (spaces) in the hash table and ***bj*** is the number of items in each slot.

- Evaluate the Hash Table on the following indicators:
  - Number of empty *slots* (spaces) in Hash Table;
  - Average size of lists in slots;
  - Number of collisions;
  - Time Calculation to enter all data.
- Show how the above indicators vary by changing the following parameters.
  - Hash Table Size **M**
    * M ∈ {3022, 15114, 22671, 30228, 60456}
  - Hash Function: f (key) = key mod < NUM >
    - ∗ f (key) = key mod 1
    - ∗ f (key) = key mod 10
    - ∗ f (key) = key mod 100
    - ∗ f (key) = key mod M
      - Note that < NUM > cannot be larger than the size of the hash table.
- Hash Function Test.
  - When testing a hash function, the uniform distribution of hashed values can be assessed using the chi-square test (χ2)456. This test is a measure quality of fit. In other words, it is the actual distribution of items in slots versus expected (or uniform) distribution of items.
  - The formula of the chi-square test is:
 
  ![test-square](https://user-images.githubusercontent.com/38081852/70118222-37541300-1646-11ea-9d59-f101d8bb19dd.png)

  - The sum of the numerator ![test-square2](https://user-images.githubusercontent.com/38081852/70118552-0cb68a00-1647-11ea-9a41-41d78b270173.png) estimates the number of slots that should be visited to find the desired value. 
  
  - The denominator ![test-square3](https://user-images.githubusercontent.com/38081852/70118664-530be900-1647-11ea-9031-22e97bb683f0.png) is the number of slots visited in an ideal hash function puts each item in a random slot. 
  - Thus, if the function is ideal, then the formula will give a value of 1. In fact, a good function will give somewhere between 0.95 and 1.05. If the value is higher then there is a high number of collisions (slow insertion, search or removal). If the value is lower, the function gives fewer collisions which is not bad but there is the question of the space used.


### 2.4 Execution

Your program should print information in the following order:

- Number of **slots** (empty spaces) in Hash Table;
- Average size of lists in slots, that is, sum of list size by number possible lists;
- Number of collisions;
- Time to enter all data;

An important detail is that the program should be executed by passing options in the Command Line. The program parameters should be defined as follows:

```sh
$ hashenem [args]
```

Mandatory arguments (in sequence):

- Then we can pass the ID you want to search or a set of ID's stored in a file.
  - **< ID >** indicates a unique ID you want to search
  - **-b < file >** is a parameter that indicates that a search will be performed for a set of IDs stored in the < file > directory;
- **-d < file >** the address of a file containing school information;
- **-M < size >** size of hash table;
- **-mod < number >** positive number ( >= 1) which will be used in the hash function.

Optional arguments (in sequence):

- **-p** optional parameter; if present your program should print the IDs that were found.

Call examples would be:

```sh
$ hashenem 4810 -d ./data-enem.txt -M 30228 -mod 1 -p
```

This command will search for ID 4810 in a hash table containing the data of the **./data-enem.txt** file. The Hash Table will be size 30228 and will use the function ***f(key) = key*** mod 1 to enter and fetch data. This command prompts you to print the search result.

```sh
$ hashenem -b ./ids.txt -d ./data-enem.txt -M 15114 -mod 15114
```

This command will search for the IDs present in the **./ids.txt** file at a nice hash containing the data from the **./data-enem.txt** file. The Hash Table will have size 15114 and use the function ***f(key) = key*** mod 15114 to insert and search the data. This command does not prompt to print the search result.

## 3. Documentation

### 3.1 Questions

- How important is the size of the hash table, hash function, and how many elements are inserted into the performance (time and memory) of solutions that use hash?
  - What is the implication of M (hash table size) being too large?
  - What is the implication of M (hash table size) being too small?
- Is there a factor (ratio) size of the hash table and the number of elements entered to make the search (time) in the hash table efficient?

### 3.2 What Should be Done in the Documentation?

Seek to intelligently organize data collected into tables, and also build graphs from the data (possible Excel, R, matplotlib, plotly, Google sheets, Gnuplot and others). Then, write about the data in the tables and graphs.

The documentation must contain:

1) **Introduction:** description of the problem to be solved and overview of the
program development.
2) **Implementation:** description of the implementation of the program. It must be detailed the data structure used (preferably with illustrative diagrams), the operation of the main functions and procedures used, the format of data entry and exit, as well as decisions made regarding cases and details specification that may be missing from the statement.
3) **Complexity Study:** study of the complexity of the execution time of the implemented procedures and the program as a whole (Big O notation).
4) **List of Tests Performed:** tests performed should simply be presented.
5) **Conclusion:** general comments about the work.
6) **Bibliography:** Bibliography used for the development of the work, including Internet Websites if applicable.


## 4. Help Links

- **[cplusplus.com](http://www.cplusplus.com/)**
- **[C Programming Language](https://www.geeksforgeeks.org/c-programming-language/)**
- **[Generate Random Number in C](https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/)**
- **[Separate Chaining](https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/)**
- **[Function strtok](https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/)**
- **[Measure Time Taken By a Program in C](https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/)**
- **[Command Line Arguments in C](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)**
- **[Hash Functions: An Empirical Comparison](https://www.strchr.com/hash_functions)**
- **[Time Calculation in C](https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/)**
- **[Chi-Squared Test](https://en.wikipedia.org/wiki/Chi-squared_test)**
- **[Hash Function - Wikipedia](https://en.wikipedia.org/wiki/Hash_function)**


## 5. Reference of This Work

This work was developed in the discipline of Algorithms and Data Structures I, **Federal University of Ouro Preto (UFOP - ICEA)** in the **Computer Engineering** Course.

Teacher: Bruno Pereira dos Santos
