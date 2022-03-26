#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int howManyDice();
bool anyOtherMods();

int numOfDice = 0;


int main() {
  //variables:
  char choice = 'p';
  char modifyOrNah = 'p';
  int roll = 0;
  int customDice = 0;
  int diceNum = 0;
  int diceTotalResult = 0;
  int modifier = 0;
  int minimum = 6;
  int stat = 0;

  //Srand for constantly random numbers
  srand(time(0));

  //menu
  cout << "Welcome to the Dice Roller App." << endl;
  while(choice != 'x'){
    //print a menu of options
    //take in an option.
    //ask for the number of dice of that type to roll
    //ask for any modifiers
    //print the total
    //loop back to the start
    cout << "Please select the type of die you would like to roll." << endl;
    cout << "a) D4" << endl;
    cout << "b) D6" << endl;
    cout << "c) D8" << endl;
    cout << "d) D10" << endl;
    cout << "e) D12" << endl;
    cout << "f) D20" << endl;
    cout << "g) D100" << endl;
    cout << "h) Custom" << endl;
    cout << "i) Stat generator" << endl;
    cout << "x) Quit" << endl;
    cout << "> ";
    cin >> choice;
    cout << endl;
    if(choice == 'a' || choice == 'A'){
      diceNum = howManyDice();
        diceTotalResult = 0;
        cout << "Rolled:";
        for(int i = 0; i < diceNum; i++){
          roll = rand()%4+1;
          cout << " " << roll << " ";
          if(i != (diceNum-1)){
            cout << " + ";
          }
          diceTotalResult = diceTotalResult + roll;
        }
      cout << endl;

    
    }
    else if(choice == 'b' || choice == 'B'){
      diceNum = howManyDice();
      diceTotalResult = 0;
        cout << "Rolled:";
        for(int i = 0; i < diceNum; i++){
          roll = rand()%6+1;
          cout << " " << roll << " ";
          if(i != (diceNum-1)){
            cout << " + ";
          }
          diceTotalResult = diceTotalResult + roll;
        }
      cout << endl;
    }
    else if(choice == 'c' || choice == 'C'){
      diceNum = howManyDice();
      diceTotalResult = 0;
        cout << "Rolled:";
        for(int i = 0; i < diceNum; i++){
          roll = rand()%8+1;
          cout << " " << roll << " ";
          if(i != (diceNum-1)){
            cout << " + ";
          }
          diceTotalResult = diceTotalResult + roll;
        }
      cout << endl;
    }
    else if(choice == 'd' || choice == 'D'){
      diceNum = howManyDice();
      diceTotalResult = 0;
        cout << "Rolled:";
        for(int i = 0; i < diceNum; i++){
          roll = rand()%10+1;
          cout << " " << roll << " ";
          if(i != (diceNum-1)){
            cout << " + ";
          }
          diceTotalResult = diceTotalResult + roll;
        }
      cout << endl;
    }
    else if(choice == 'e' || choice == 'E'){
      diceNum = howManyDice();
      diceTotalResult = 0;
        cout << "Rolled:";
        for(int i = 0; i < diceNum; i++){
          roll = rand()%12+1;
          cout << " " << roll << " ";
          if(i != (diceNum-1)){
            cout << " + ";
          }
          diceTotalResult = diceTotalResult + roll;
        }
      cout << endl;
    }
    else if(choice == 'f' || choice == 'F'){
      diceNum = howManyDice();
      diceTotalResult = 0;
        cout << "Rolled:";
        for(int i = 0; i < diceNum; i++){
          roll = rand()%20+1;
          cout << " " << roll << " ";
          if(i != (diceNum-1)){
            cout << " + ";
          }
          diceTotalResult = diceTotalResult + roll;
        }
      cout << endl;
    }
    else if(choice == 'g' || choice == 'G'){
      diceNum = howManyDice();
      diceTotalResult = 0;
        cout << "Rolled:";
        for(int i = 0; i < diceNum; i++){
          roll = rand()%100+1;
          cout << " " << roll << " ";
          if(i != (diceNum-1)){
            cout << " + ";
          }
          diceTotalResult = diceTotalResult + roll;
        }
      cout << endl;
    }
    else if(choice == 'h' || choice == 'H'){
      while(customDice <= 0 || customDice > 10000){
        cout << "Input a positive number up to 10,000: ";
        cin >> customDice;
        if(customDice <= 0 || customDice > 10000){
          cout << "Invalid input. Please input a proper input." << endl;
        }
      }
      diceNum = howManyDice();
      diceTotalResult = 0;
        cout << "Rolled:";
        for(int i = 0; i < diceNum; i++){
          roll = rand()%customDice+1;
          cout << " " << roll << " ";
          if(i != (diceNum-1)){
            cout << " + ";
          }
          diceTotalResult = diceTotalResult + roll;
        }
      cout << endl;
      customDice = -1;
    }
    else if(choice == 'i' || choice == 'I'){
      cout << "Rolling Stats..." << endl;
      for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
          roll = rand()%6+1;
          //cout << "DEBUGGING! Roll made = " << roll << endl; 
          if(roll < minimum){
            minimum = roll;
          }
          stat = stat + roll;
        }
        stat = stat - minimum;
        cout << "Stat #" << (i+1) <<": " << stat << endl;
        stat = 0;
        minimum = 6;
      }
      cout << endl;
    
    }
    else if(choice == 'x' || choice == 'X'){
      cout << "Quitting Dice Roller. Have a nice day." << endl;
      return 0;
    }
    else{
      cout << "Invalid input. Please input a proper input." << endl;
    }


    // Modifier request
    if(choice != 'i' && choice != 'I'){
    while(modifyOrNah != 'x' || modifyOrNah != 'X'){
      cout << "Would you like to modify this result?" << endl;
      cout << "a) Add to the roll." << endl;
      cout << "b) Subtract from the roll." << endl;
      cout << "c) Multiply the roll." << endl;
      cout << "d) Divide the roll." << endl;
      cout << "x) No modifications." << endl;
      cout << "> ";
      cin >> modifyOrNah;
      
      if(modifyOrNah == 'a' || modifyOrNah == 'A'){
        cout << "Enter a modifier to add to the roll: ";
        cin >> modifier;
        diceTotalResult = diceTotalResult + modifier;
        if(anyOtherMods() == false){
          break;
        }
      }
      else if(modifyOrNah == 'b' || modifyOrNah == 'B'){
        cout << "Enter a modifier to subtract from the roll: ";
        cin >> modifier;
        diceTotalResult = diceTotalResult - modifier;
        if(anyOtherMods() == false){
          break;
        }
      }
      else if(modifyOrNah == 'c' || modifyOrNah == 'C'){
        cout << "Enter a modifier to multiply the roll by: ";
        cin >> modifier;
        diceTotalResult = diceTotalResult * modifier;
        if(anyOtherMods() == false){
          break;
        }
      }
      else if(modifyOrNah == 'd' || modifyOrNah == 'D'){
        cout << "Enter a modifier to divide the roll by: ";
        cin >> modifier;
        diceTotalResult = diceTotalResult / modifier;
        if(anyOtherMods() == false){
          break;
        }
      }
      else if(modifyOrNah == 'x' || modifyOrNah == 'X'){
        cout << "No modifications are made." << endl;
        break;
      }
      else{
        cout << "Invalid input. Please enter a valid input." << endl;
      }
      
    }
    cout << "The total result is " << diceTotalResult << "." << endl << endl << endl; 
      }
    //Potential Additions
      /*
        Advantage and Disadvantage
      */
    
  }

  return 0;
}

int howManyDice(){
  numOfDice = -1;
  while(numOfDice <= 0){
        cout << "How many dice would you like to roll(Up to 20)?" << endl << "> ";
        cin >> numOfDice;
        if(numOfDice <= 0 || numOfDice > 20){
          cout << "Invalid input. Please input a proper input." << endl;
        }
      }
  return numOfDice;
};

bool anyOtherMods(){
  char moreMods = 'p';
  while(moreMods != 'a' || moreMods != 'A' || moreMods != 'b' || moreMods != 'B'){
    cout << "Would you like to do any more modifications?" << endl;
    cout << "a) Yes" << endl;
    cout << "b) No" << endl << "> ";
    cin >> moreMods;
    if(moreMods == 'a' || moreMods == 'A'){
      return true;
    }
    else if(moreMods == 'b' || moreMods == 'B'){
      return false;
    }
    else{
      cout << "Invalid input. Please input a proper input." << endl;
    } 
  }
};