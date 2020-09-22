#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <math.h>

using namespace std;

int main(int argc, char* argv[]){
  string inputfile;
  int linecount = 0;
  int sum = 0;

  char dnaletter;
  int countA = 0;
  int countC = 0;
  int countG = 0;
  int countT = 0;

  float a; //for gaussian distribution
  float b;
  int c;
  float d;

  bool repeat = true;

  while(repeat) {
    cout << "Enter DNA file: ";
    cin >> inputfile;

    cout << "Writing results to nayelicastro.out" << endl;

    ifstream in(inputfile);

    string line;
    while(getline(in, line)){
      for (int i = 0; i < line.size(); i++){
        sum++; //counting the characters in each string
        dnaletter = char(line[i]);
        switch (dnaletter) {
          case 'A':
            countA++;
            break;
          case 'C':
            countC++;
            break;
          case 'G':
            countG++;
            break;
          case 'T':
            countT++;
            break;
        }
      }
      linecount++; //counting amount of strings
    }
    float avg = (float)sum/(linecount); //mean
    float variance = (pow(((float)sum - avg), 2))/linecount; //variance

    ofstream studentfile("nayelicastro.out");
    studentfile << "Nayeli Castro" << endl;
    studentfile << "2340374" << endl;
    studentfile << "ncastro@chapman.edu" << endl;
    studentfile << endl;
    studentfile << "Amount of DNA strings: " << linecount << endl;
    studentfile << "Sum of lengths of the DNA strings: " << sum << endl;
    studentfile << "Average (mean) length of a DNA string: " << avg << endl;
    studentfile << "Variance of DNA strings: " << variance << endl;
    studentfile << "Standard deviation of DNA Strings: " << sqrt(variance) << endl;
    studentfile << endl;
    studentfile << "Amount of A: " << countA << endl;
    studentfile << "Amount of C: " << countC << endl;
    studentfile << "Amount of G: " << countG << endl;
    studentfile << "Amount of T: " << countT << endl;
    studentfile << endl;
    studentfile << "Probability of A: " << ((float)countA/sum) << endl;
    studentfile << "Probability of C: " << ((float)countC/sum) << endl;
    studentfile << "Probability of G: " << ((float)countG/sum) << endl;
    studentfile << "Probability of T: " << ((float)countT/sum) << endl;
    studentfile << endl;
    studentfile << "Probability of AA: " << ((float)(countA*2)/sum)*100 << "%" << endl;
    studentfile << "Probability of CC: " << ((float)(countC*2)/sum)*100 << "%" << endl;
    studentfile << "Probability of GG: " << ((float)(countG*2)/sum)*100 << "%" << endl;
    studentfile << "Probability of TT: " << ((float)(countT*2)/sum)*100 << "%" << endl;
    studentfile << "Probability of AC: " << ((float)(countA+countC)/sum)*100 << "%" << endl;
    studentfile << "Probability of AG: " << ((float)(countA+countG)/sum)*100 << "%" << endl;
    studentfile << "Probability of AT: " << ((float)(countA+countT)/sum)*100 << "%" << endl;
    studentfile << "Probability of CA: " << ((float)(countC+countA)/sum)*100 << "%" << endl;
    studentfile << "Probability of CG: " << ((float)(countC+countG)/sum)*100 << "%" << endl;
    studentfile << "Probability of CT: " << ((float)(countC+countT)/sum)*100 << "%" << endl;
    studentfile << "Probability of GA: " << ((float)(countG+countA)/sum)*100 << "%" << endl;
    studentfile << "Probability of GC: " << ((float)(countG+countC)/sum)*100 << "%" << endl;
    studentfile << "Probability of GT: " << ((float)(countG+countT)/sum)*100 << "%" << endl;
    studentfile << "Probability of TA: " << ((float)(countT+countA)/sum)*100 << "%" << endl;
    studentfile << "Probability of TC: " << ((float)(countT+countC)/sum)*100 << "%" << endl;
    studentfile << "Probability of TG: " << ((float)(countT+countA)/sum)*100 << "%" << endl;
    studentfile << endl;
    studentfile << "1000 generated DNA string lengths using Gaussian distribution: " << endl;
    studentfile << endl;
    for (int j = 0; j <= 1000; ++j){
      a = (float)rand();
      b = (float)rand();
      c = sqrt((-2*log(a))*cos(2*3.14*b));
      d = (sqrt(variance)*c) + avg;
      studentfile << d << endl;
    }
    char choice;
    cout << "Do you want to calculate another file? (y/n)" << endl;
    cin >> choice;
    if (tolower(choice) == 'y') {
      repeat = true;
    }
    else if (tolower(choice) == 'n') {
      cout << "Program will terminate." << endl;
      repeat = false;
      studentfile.close();
      in.close();
    }
    else {
      cout << "Program will terminate." << endl;
      repeat = false;
      studentfile.close();
      in.close();
    }
  }

  return 0;

}
