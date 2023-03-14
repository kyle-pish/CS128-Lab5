//Authors: Kyle Pish, Josh Reed
//Date: 2/3/2022

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

//A collection of tests and experiments with C-Strings
void Lab5Part1_main() {

  char pledge1[] = "I will adhere to the University's COVID-19 PCR testing protocols.";
  int pledge1_len = 0; //Declaring before the loop so it can modified in the loop; set to 0 for safety.

  for (int i = 0; pledge1[i] != '\0'; i++) {
    pledge1_len++;
  } 

  char pledge1_name[85]; //Pledge 1's length was 65; this gives 20 extra characters for the name
  std::cout << "Please enter your name: ";
  std::cin.getline(pledge1_name, 85);

  char* pledge1_ptr = pledge1;
  pledge1_ptr++; //Moving the pointer over to the second char in the array, the space, so 'I' is excluded.
  std::cout << strncat(pledge1_name, pledge1_ptr, 85 - strlen(pledge1_name)) << std::endl; //Due to using pledge1_name as the final destination for the full pledge, strncpy is unnecessary.

  int pledge1_name_len = 0;
  for (int i = 0; pledge1_name[i] != '\0'; i++) {
    pledge1_name_len++;
  } 

  std::cout << pledge1_name_len;
  
  int pledge1_letters = 0;
  int pledge1_non_letter_non_space = 0;
  int pledge1_caps = 0;
  int pledge1_punctuation = 0;
  
  for (int i = 0; pledge1[i] != '\0'; i++) {

    if (isalpha(pledge1[i])) {
      pledge1_letters++;
    }

    if (!(isalpha(pledge1[i])) && !(isspace(pledge1[i]))) {
      pledge1_non_letter_non_space++;
    }
    
    if (isupper(pledge1[i])){
      pledge1_caps++;
    }

    if (ispunct(pledge1[i])){
      pledge1_punctuation++;
    }
  }

  std::cout << "Pledge 1 has " << pledge1_letters << " letters." << std::endl;

  std::cout << "Pledge 1 has " << pledge1_non_letter_non_space << " non-letter, non-space characters." << std::endl;

  std::cout << "Pledge 1 has " << pledge1_caps << " capital letters." << std::endl;

  std::cout << "Pledge 1 has " << pledge1_punctuation << " punctuation marks." << std::endl;

  char pledge2[] = "I will conduct daily selfmonitoring for symptoms of COVID-19 and report to Arnold Health Services (students) or a healthcare professional (faculty and staff) if I experience a fever of 100.4 For higher, dry cough, difficulty breathing, muscle aches, abdominal discomfort, or new loss of taste or smell.";

  for (int i = 0; pledge2[i] != '\0'; i++) {
    
    if (islower(pledge2[i])) {
      pledge2[i] = toupper(pledge2[i]);
    }

    else {
      pledge2[i] = tolower(pledge2[i]);
    }
    
  }

  std::cout << pledge2 << std::endl;

  char pledge3[] = "I will keep my clothing, belongings, personal spaces, and shared common spaces clean.";

  int letters_switched = 0; //We cannot simply use even and odd indices to create the alternating pattern, since spaces take up indices and would cause consecutive caps or uncaps. Instead, we increment this every time we find and witch a letter.
  for (int i = 0; pledge3[i] != '\0'; i++) {
    if (isalpha(pledge3[i])) {
      if (letters_switched == 0) {
        pledge3[i] = tolower(pledge3[i]); //A special case is put in for 0, since, using the modulus test, it would not return as "even".
      }

      else if (letters_switched % 2 == 1) {
        pledge3[i] = toupper(pledge3[i]);
      }
      

      else {
        pledge3[i] = tolower(pledge3[i]);
      }

      letters_switched++;

    }
  }

  std::cout << pledge3 << std::endl;  

  char pledge4[] = "I will be flexible with our current circumstances understanding that none of us has experienced a pandemic and we are all doing our best.";

  int pledge4_len = strlen(pledge4);

  char pledge4_4[(pledge4_len * 4) + 5]; //Length must be 4 times the length of pledge4, plus extra space for the endline and null chars

  strncpy (pledge4_4, pledge4, pledge4_len);
  for (int i = 0; i < 3; i++) {
    strncat (pledge4_4, "\n", 1);
    strncat (pledge4_4, pledge4, pledge4_len);
  }

  std::cout << pledge4_4 << std::endl;
  std::cout << strlen(pledge4_4);
}