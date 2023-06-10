# Problem
There is a file called “patients.dat” that contains important information about
patients. Unfortunately, the file’s structure has been damaged, but the information is still
there and we need to retrieve it. We know it contains three pieces of information for each
patient: First Name, Last Name and Age.

## Task

Write a C program that will read the file “patients.dat” line by line and store the valid
information. A valid information is one that contains characters (A-Z or 0-9).


### Output
Your output should look like this
=========================================================
Enter file name: patient.dat
=========================================================
First Name: Sam
Last Name: Smithe
Age: 30
First Name: Tobi
Last Name: Brown
Age: 40
First Name: John
Last Name: Smith
Age: 50
=========================================================

# Hints

● When the program finds a character, it will mean a field is starting, and it will
concatenate each character until a non-character byte is found –meaning that a
field has ended.
● You can store the data any way you like as long as your program can print the data
that is needed i.e. First Name, Last Name and Age.
● You can use an array of structs

# Requirements

There are 3 stages to qualify for this contest. You can improve your chances by completing more than one stage but you can submit your code when you complete any one of these stages.

Stage 1: Your code can print the patients.dat file. DONE
Stage 2: Your code can print the valid data in the patients.dat file. DONE
Stage 3: Stage 2 & your code result is properly formatted and easy to read. DONE saved file to .CSV format
