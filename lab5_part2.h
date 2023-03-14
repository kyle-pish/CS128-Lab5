//Authors: Kyle Pish, Josh Reed
//Date: 2/3/2022

#ifndef LAB5_PART2_H_
#define LAB5_PART2_H_

void Lab5Part2_main();
void Print(int list[], int& size);
void Append(int list[], int value, int& size, int& capacity);
bool Contains(int list[], int value, int& size);
int Index(int list[], int value, int& size);
int Pop(int list[], int& size);
int PopAt(int list[], int i, int& size);
void Insert(int list[], int value, int i, int& size, int& capacity);
void Remove(int list[], int value, int& size, int& capacity);
int Count(int list[], int value, int& size);


#endif