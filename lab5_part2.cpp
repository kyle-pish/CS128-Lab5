//Authors: Kyle Pish, Josh Reed
//Date: 2/3/2022
//A collection of C++ partially-filled array functions that work like Python list methods
#include <iostream>
#include "lab5_part2.h"

//A series of tests for the functions
void Lab5Part2_main() {
  int test_array[10];
  int test_size = 0;
  int test_capacity = 10;

  Append(test_array, 2, test_size, test_capacity);
  Append(test_array, 4, test_size, test_capacity);
  Append(test_array, 6, test_size, test_capacity);
  Append(test_array, 8, test_size, test_capacity);
  Append(test_array, 6, test_size, test_capacity);
  Append(test_array, 4, test_size, test_capacity);
  Append(test_array, 2, test_size, test_capacity);

  Print(test_array, test_size);
  std::cout << Contains(test_array, 4, test_size) << std::endl;
  std::cout << Contains(test_array, 5, test_size) << std::endl;

  std::cout << Count(test_array, 6, test_size) << std::endl;
  std::cout << Count(test_array, 7, test_size) << std::endl;

  std::cout << Index(test_array, 8, test_size) << std::endl;

  std::cout << Pop(test_array, test_size) << std::endl;
  Print(test_array, test_size);

  std::cout << PopAt(test_array, 2, test_size) << std::endl;
  Print(test_array, test_size);

  Append(test_array, 12, test_size, test_capacity);
  Print(test_array, test_size);

  Insert(test_array, -9, 3, test_size, test_capacity);
  Print(test_array, test_size);

  Remove(test_array, 2, test_size, test_capacity);
  Print(test_array, test_size);

  for (int i = 0; i < 10; i++) {
    Append(test_array, 99, test_size, test_capacity);
  }

  Print(test_array, test_size);

}

//Outputs to console every value in the array, surrounded by brackets and separated by spaces. Takes as input an int partially-filled array and its size, which it takes as a reference.
void Print(int list[], int& size) {
  std::cout << "[";
  for (int i = 0; i < size; i++){
    std::cout << list[i] << " "; 
  }
  std::cout << "]" << std::endl;
}

//Adds a value to the end an array, if there's sufficient capacity for it. Takes as input an int partially-filled array, its size and capacity, both taken as references, and the value being appended.
void Append(int list[], int value, int& size, int& capacity) {
  if (size < capacity) {
    list[size] = value;
    size++;
  }
}

//Returns true if a specified value is in a given array, and false if it is not. Takes as input an int partially-filled array and its size, which it takes as a reference.
bool Contains(int list[], int value, int& size) {
  for (int i = 0; i < size; i++) {
    if (list[i] == value) {
      return true;
    }
  }

  return false;
}

//Returns the number of times a given value is in a given array as an int. Takes as input an int partially-filled array, its size, which it takes as a reference, and the value being counted.
int Count(int list[], int value, int& size) {
  int output = 0;
  for (int i = 0; i < size; i++) {
    if (list[i] == value) {
      output++;
    }
  }

  return output;
}

//Returns the index of the first instance of a specified value in a given array as an int; if the value is not present, returns -1. Takes as input an int partially-filled array, its size, which is taken as a reference, and the value in question.
int Index(int list[], int value, int& size) { 
  for (int i = 0; i < size; i++) {
    if (list[i] == value) {
      return i;
    }
  }

  return -1;
}

//Removes and returns the last element in a given array. Takes as input an int partially-filled array, and its size, which is taken as a reference.
int Pop(int list[], int& size) {
  int output = list[size - 1];
  list[size - 1] = 0;
  size--;
  return output;
}

//Removes and returns the element and index i in a given array. Takes as input an int partially-filled array, its size, which is taken as a reference, and the index of the value being popped.
int PopAt(int list[], int i, int& size) {
  int output = list[i];
  for (int j = i + 1; j < size; j++) {
    list[j - 1] = list[j];
    list[j] = 0;
  }
  size--;
  return output;
}

//Adds a given value into the array at a given index, provided there's sufficient capacity for it. Takes as input an int partially-filled array, its size and capacity, which are taken as references, the desired index, and the desired value.
void Insert(int list[], int value, int i, int& size, int& capacity) {
  if (size < capacity) {
    if (size > i + 1) {
      for (int j = size - 1; j >= i; j--) {
        list[j + 1] = list[j];
        list[j] = 0;
      }

      list[i] = value;
      size++;
    }

    else {
      list[i] = value;
      size++;
    }
  }
}

//Finds and removes the first instance of a given value in a given array. Takes as input an int partially-filled array, its size and capacity, which are taken as references, and the value being removed.
void Remove(int list[], int value, int& size, int& capacity) {
  int index = Index(list, value, size);
  PopAt(list, index, size);
}
