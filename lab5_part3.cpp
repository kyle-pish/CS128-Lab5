//Authors: Kyle Pish, Josh Reed
//Date: 2/3/2022

#include <iostream>
#include <string>

void Lab5Part3_main(){
  std::string pledge1 = "I will adhere to the Universoty's COVID-19 PCR testing protocols.";

  std::cout << pledge1.size() << std::endl;;

  std::string pledge1_name;

  //prompting the user to input their name and storing it as a string variable
  std::cout << "Please enter your name: " << std::endl;
  std::getline(std::cin, pledge1_name);

  //getting a substring of the pledge variable to combine with the users input
  std::string pledge_part = pledge1.substr(1, 64);

  //conbining the users input with part of the pledge
  pledge1_name.append(pledge_part);
  std::cout << pledge1_name << std::endl;

  int pledge1_letters = 0;
  int pledge1_spaces = 0;

  //loop to count the amount of letters and spaces in the pledge
  for (int i = 0; pledge1[i] != '\0'; i++) {

    if (isalpha(pledge1[i])) {
        pledge1_letters++;
      }
    
    if (isspace(pledge1[i])) {
        pledge1_spaces++;
      }
  }

  std::cout << "Pledge 1 has " << pledge1_letters << " letters." << std::endl;
  std::cout << "Pledge 1 has " << pledge1_spaces << " spaces." << std::endl;

  std::string pledge2 = "I will conduct daily selfmonitoring for symptoms of COVID-19 and report to Arnold Health Services (students) or a healthcare professional (faculty and staff) if I experience a fever of 100.4 For higher, dry cough, difficulty breathing, muscle aches, abdominal discomfort, or new loss of taste or smell.";

  //looping over every letter in the string to change uppercase to lowercase and vice versa
  for (int i = 0; pledge2[i] != '\0'; i++) {
    
    if (islower(pledge2[i])) {
      pledge2[i] = toupper(pledge2[i]);
    }

    else {
      pledge2[i] = tolower(pledge2[i]);
    }
    
  }
  std::cout << pledge2 << std::endl;

  std::string pledge3 = "I will keep my clothing, belongings, personal spaces, and shared common spaces clean";

  //repeating the pledge 3 times with a new line character between each of them (but not a new line after the last instance of the pledge)
  std::string pledge3_3 = pledge3;
  for (int i = 0; i < 2; i++){
    pledge3_3 = pledge3_3.append("\n");
    pledge3_3 = pledge3_3.append(pledge3);
  }
  std::cout << pledge3_3 << std::endl;
  std::cout << pledge3_3.size() << std::endl;

  //finding the first and second position of the word "clothing" in the pledge
  int clothing_pos = pledge3_3.find("clothing");
  std::cout << clothing_pos << std::endl;
  int clothing_pos2 = pledge3_3.find("clothing", 16);
  std::cout << clothing_pos2 << std::endl;

  //calculating the distance between the 2 instances of "clothing" in the pledge and sting it in a variable
  int string_length = clothing_pos2 - clothing_pos;

  //outputting the substring contained between the 2 instances of "clothing" but using the position of the first instance, and then using the length found through the previous calculation
  std::string pledge3_1 = pledge3_3.substr(clothing_pos, string_length);
  std::cout << pledge3_1 << std::endl;
}