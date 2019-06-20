# Palindrome

<div style="text-align: justify">

> Palindrome: Reading the same backward as forward. Ex: LEVEL, RADAR, EYE ...
<br>

The purpose of this project is to check if a word is palindrome or not. We have a word list in palindrome.txt file. At the end of the program, how many words palindromic or not and all palindromic words will be printed. I used Stack and Queue structures together for fun :). The initial Stack/Queue size is defined as 50. You can change it by changing `#define DEF_SIZE 50` in `source.cpp` line 5. Also, you can change the word list file by changing `#define FILENAME "palindrome.txt"` in `source.cpp` line 6. 

## Usage

For macOS and Linux users, there is a makefile. After downloading the repository folder, you can execute command below. It will compile the source code and create an output file.
```
make
```
To delete the existing output file, you can execute command below.
```
make clean
```
Otherwise, you can compile it without using makefile.
```
g++ source.cpp -o source
```
To execute,
```
./source
```


</div>