INVERTED_SEARCH
This project implements an Inverted Index in C language.
It allows storing words from multiple text files and efficiently searching which files contain a given word and how many times it appears.

 Features
📂 Read multiple .txt files
🧱 Build inverted index using hash table + linked lists
🔍 Search a word across all files
📊 Display database (index table)
💾 Save database to file
🔄 Update database from saved file

🔹 Project Structure
├── main.c
├── inverter.h
├── create_database.c
├── display_database.c
├── search_database.c
├── save_database.c
├── update_database.c
├── *.txt   (input files)

🔹 Data Structures Used
1.Hash Table
2.Linked List
3.Structures
4.File Handling

🔹 How It Works
1.User gives multiple text files as input
2.Each word is stored in a hash table
3.For each word, file name and word count are stored
User can:
Search any word
Display entire database
Save and update database

🔹 Compilation & Execution
gcc *.c 
./a.out file1.txt file2.txt file3.txt
🔹 Sample Menu
1. Create Database  
2. Display Database  
3. Search Database  
4. Save Database  
5. Update Database  
6. Exit
7.   
🔹 Sample Output
Enter the word to search: data  
Word found in:  
file1.txt -> 3 times  
file2.txt -> 1 time
 
🔹 Technologies Used
1.C Programming
2.File Handling
3.Data Structures (Hash Table, Linked List)

🔹 Learning Outcomes
1.Understanding Inverted Index
2.Working with Hash Tables
3.Handling Files in C
4.Implementing Search Engine Logic
5.Improving DSA Skills

🔹 Future Enhancements
1.Handle duplicate files
2.Case-insensitive search
3.Ignore stop words
4.Sorting results
5.Improve hashing technique

Support for large files
