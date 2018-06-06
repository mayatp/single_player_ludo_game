#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Token{
private:
  char name;
  int startPos;
  int endPos;
  int pos;
public:
	Token(char name, int startPos, int endPos){
    this->startPos = startPos;
    this->endPos = endPos;
    this->name = name;
    this->pos = startPos;
  };


	void move(int pos) {
    int newPos = pos + this->pos;
    if (newPos == 20) { // // TRAP which returns the token to its start position
      this->pos = startPos;
    }
    else if (newPos == 30 ){ // TRAP
      this->pos = startPos;
    }
    else if (newPos == 40 ){ // TRAP
      this->pos = startPos;
    }
    else if (newPos == 50 ){ // TRAP
      this->pos = startPos;
    }
    else if (newPos == 60 ){ // TRAP
      this->pos = startPos;
    }
    else if (newPos >= 65){ // 64 is the last playable (aquare) that a token can step
      this->pos = endPos;
    } else {
      this->pos = newPos;
    }
  }

  char getName() {
    return this->name;
  };

  char getPos() {
    return this->pos;
  };

  void goToStart() {
    this->pos = 4;
  };

  bool isFinished() {
    return this->pos == endPos; // simple check if the current token is finished going around the board or not. The function returns TRUE or FALSE
  }
};

class Board{
private:
  const int ROWS = 33; // x
  const int COLS = 48; //y
  Token t1;
  Token t2;
  Token t3;
  Token t4;
  Token* activeToken; // activeToken pointer as the active token on the board tends to change from t1 to t2 to t3 to t4
public:
  Board():t1('T',0,68),t2('T',1,67),t3('T',2,66),t4('T',3,65){
    activeToken = &t1;
  }; //initialising all the tokens in the Board's default constructor (they always need to be there)

  bool isActiveFinished(){
    return activeToken->isFinished();
  }

  void drawBoard(const int ROWS, const int COLS);

  void moveToken(int pos) {
    activeToken->move(pos);
  };

  // set setNewToken function checks if the first token has made it until the end and if so, the second ome starts, then third and then fourth
  void setNewToken(){
    if (activeToken->isFinished())
    {
      if (activeToken == &t1){
        activeToken = &t2;
      }
      else if (activeToken == &t2){
        activeToken = &t3;
      }
      else if (activeToken == &t3){
        activeToken = &t4;
      }
    }
  };

  void startMoving() {
    t1.goToStart();
  };
};

void Board::drawBoard(int y, int x) {

	char drawBoard[33][48] = {

	{' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
	{'|', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', '|'},
	{'|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
	{'|', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', '|'},
	{'|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
	{'|', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', '|'},
	{'|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', '.', '.', '.', '.', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', '.', ' ', '.', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', '.', '.', '.', '.', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', '.', ' ', '.', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', ' ', '.', '.', '.', '.', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
	{'|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|'},
	};

  // all the possible squares a token are defined below, where the first (0,1,2,4 are the starting and 66,67,68,69 are the ending points of the tokens A, B, C and D respectively.)
  int road [][68] = { {28,3},{28,5},{30,3},{30,5}, {30,20}, {28,20}, {26,20}, {24,20}, {22,20}, {20,20}, {20,17}, {18,17}, {18,14}, {18,11}, {18,8}, {18,5}, {18,2}, {16,2}, {14,2}, {14,5}, {14,8}, {14,11}, {14,14}, {14,17}, {12,17}, {12,20}, {10,20}, {8,20}, {6,20}, {4,20}, {2,20}, {2,23}, {2,26}, {4,26}, {6,26}, {8,26}, {10,26}, {12,26}, {12,29}, {14,29}, {14,32}, {14,35}, {14,38}, {14,41}, {14,44}, {16,44}, {18,44}, {18,41}, {18,38}, {18,35}, {18,32}, {18,29}, {20,29}, {20,26}, {22,26}, {24,26}, {26,26}, {28,26}, {30,26}, {30,23}, {28,23}, {26,23}, {24,23}, {22,23}, {20,23}, {17,22}, {15,22}, {17,25}, {15,25}};

  // from the 0th element from the array above thate the 0th element [0][0], and the 1st one [0][1]
  drawBoard[road[t1.getPos()][0]][road[t1.getPos()][1]] = t1.getName();
  drawBoard[road[t2.getPos()][0]][road[t2.getPos()][1]] = t2.getName();
	drawBoard[road[t3.getPos()][0]][road[t3.getPos()][1]] = t3.getName();
	drawBoard[road[t4.getPos()][0]][road[t4.getPos()][1]] = t4.getName();

	cout << drawBoard[1][1] << endl;

	for(int ROWS = 0; ROWS < 33; ROWS++){
		cout << endl;

		for(int COLS = 0; COLS < 48; COLS++){
			cout << drawBoard[ROWS][COLS];
		}
	}
	cout << endl;
	}

class Dice{
private:
  int choice; // takes the next input
  int dice;
  bool rollMore;
	int firstSixThrown = 0;
	int sixThrown = 1; // checking if 6 is thrown so it can start summing up the position of the token
	int sixThrownCounter = 0; // a random counter used to skip the first if statement, which initially sets the position to 4 so that the game can start (tokens initial position after 6 is thrown)
public:
  Dice(){};
  void rolling(int &rollDice);
	void reset();
};

void Dice::rolling(int &rollDice) //passing it by REF so that it can be changed on every roll
{
  Board ludo; // creating the ludo board
    bool rollMore = true;
    while (rollMore == true)
    {
        for (int ROWS = 0; ROWS != rollDice; ROWS++)
        {
            dice = (rand() % 6) + 1;

            if (ludo.isActiveFinished()){
              reset();
              ludo.setNewToken();
            }

            if (dice == 6)
						{
							firstSixThrown = 1;
							sixThrownCounter += sixThrown;
              cout << "\t\t\t\t\t\t Wowowowo you rolled " << dice << "!" << endl;
						}
            else{
              cout << "\t\t\t\t\t\t You rolled " << dice << "!" << endl;
						}

						if (firstSixThrown == 1){ // outer loop checks if 6 was thrown for a first time
							if (sixThrownCounter == 1){ // checks if it was the first time of 6 thrown and sets position to 3, as we need to skip the starting posints of the four tokens
								ludo.startMoving();
								sixThrownCounter = 2; // setting it to any number so that the game can continue after 6 being thrown and after position was set to 4, we don't need the position to be set to 4 anymore unless the token needs to start again
							}
							else{
								ludo.moveToken(dice);
							}
						}
            ludo.drawBoard(33,48);
        }


        cout<<"\t\t\t\t\t\t1.Roll again\n\t\t\t\t\t\t"
        <<"0.Exit\n\t\t\t\t\t\t"
        <<"-> ";
        cin >> choice;

        if (choice == 1){
          rollMore = true;
        }
        else if (choice == 0){
          rollMore = false;
        }
        else if (choice != 1 || choice != 0){
          cout << "Wrong choice. Game terminated!" << endl;
          break;
        }
    }
}

// Reset function resets the dice values so that if another token needs to be taken out on the board, the player must roll 6 (as per the original rules of the game)
void Dice::reset(){
 	dice = 1;
	firstSixThrown = 0;
	sixThrown = 1;
  cout << "\n Congratulations" << endl;
}

int main()
{
    string playerName;
    string playerSurname;
    string playedBefore;
    string inFile = ("players.txt"); // external text file where players can enter their details
    string inputFile = ("rules.txt"); // external text file with the rules of the game
		string line;
    int gameOn = true;
    int rollDice;

    srand(static_cast<unsigned int>(time(0)));

    while (gameOn == true)
    {
        cout<<"\t\t\t\t\t\t1.Play\n\t\t\t\t\t\t"
        <<"2.Read the rules\n\t\t\t\t\t\t"
        <<"3.I want to compete! Sign me up!\n\t\t\t\t\t\t"
        <<"4.List of players\n\t\t\t\t\t\t"
        <<"0.Exit\n\t\t\t\t\t\t"
        <<"-> ";
        cin >> rollDice;

        if (rollDice == 1)
        { //instantiation of the dice class below
          Dice myDice; // creating an instance of the Dice class
          myDice.rolling(rollDice);
        }
        else if (rollDice == 2)
        {
						ifstream myStream(inputFile);
						if (myStream.is_open()){
							while(getline(myStream,line))
								cout << line << endl;
						}
						myStream.close();
        }
        else if (rollDice == 3)
        {
          //string inFile = 'players.txt';
          ofstream myStream(inFile, ios::app);

          cout << "\t\t\t\t\t\tWhat's your first name? \n\t\t\t\t\t\t";
          cin >> playerName;
          cout << "\t\t\t\t\t\tWhat's your surname? \n\t\t\t\t\t\t";
          cin >> playerSurname;
          cout << "\t\t\t\t\t\tHave you played Ludo before? (Yes/No) \n\t\t\t\t\t\t";
          cin >> playedBefore;

          if (myStream.is_open())
            myStream << "\n" << "Name: " << playerName;
            myStream << "\n" << "Surname: " << playerSurname;
            myStream << "\n" << "Played before: " << playedBefore;
            myStream << "\n" << " " << endl;
          myStream.close();

          cout << "\t\t\t\t\t\tThanks! Please press 1 to start the game! :)  \n\t\t\t\t\t\t" << endl;
        }
        else if (rollDice == 4){
						ifstream myStream(inFile);
						if (myStream.is_open()){
							while(getline(myStream,line))
								cout << line << endl;
						}
						myStream.close();
        }
        else if (rollDice == 0)
        {
            cout << "Bye bye :)" << endl;
            return 0;
        }
        else {
            cout << "\n That was invalid input!" << endl;
            cout << "\n ";
        }
    }
}
