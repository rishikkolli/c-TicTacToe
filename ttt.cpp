#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> board;
int counter = 1;

void draw(){
  std::cout << "     |     |      \n";
 
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";
 
    std::cout << "\n";
}

void compete(){
	std::string choice;
	int number;
	
	if(counter % 2 == 0){
		std::cout << "User Two Choose Where You Would Like to Place Your 'O' and Between The Numbers 0-8" << std::endl;
		std::cin >> choice;
		number = stoi(choice);
		board[number] = 'O';
	}
	else{
		std::cout << "User One Choose Where You Would Like to Place your 'X' and Between The Numbers 0-8" << std::endl;
		std::cin >> choice;
		number = stoi(choice);
		board[number] = 'X';
	}
	counter++;
}

int checkIfWon(){
	if((board[0] == "O" && board[1] == "O" && board[2] == "O") || (board[3] == "O" && board[4] == "O" && board[5] == "O") || (board[6] == "O" && board[7] == "O" && board[8] == "O") || (board[0] == "O" && board[3] == "O" && board[6] == "O") || (board[1] == "O" && board[4] == "O" && board[7] == "O") || (board[2] == "O" && board[5] == "O" && board[8] == "O") || (board[0] == "O" && board[4] == "O" && board[8] == "O") || (board[2] == "O" && board[4] == "O" && board[6] == "O")) {
		return 2;
	}
	if((board[0] == "X" && board[1] == "X" && board[2] == "X") || (board[3] == "X" && board[4] == "X" && board[5] == "X") || (board[6] == "X" && board[7] == "X" && board[8] == "X") || (board[0] == "X" && board[3] == "X" && board[6] == "X") || (board[1] == "X" && board[4] == "X" && board[7] == "X") || (board[2] == "X" && board[5] == "X" && board[8] == "X") || (board[0] == "X" && board[4] == "X" && board[8] == "X") || (board[2] == "X" && board[4] == "X" && board[6] == "X")) {
		return 1;
	}
	if(board[0] != " " && board[1] != " " && board[2] != " " && board[3] != " " && board[4] != " " && board[5] != " " && board[6] != " " && board[7] != " " && board[8] != " "){
		return 3;
	}
	return 0;
}

int main(){
	int ifDone = 0;
	for(int i=0; i < 9; i++){
	  board.push_back(" ");
	}
  
	draw();
	while(ifDone == 0){
	compete();
	int check = checkIfWon();
	
	if(check == 1){
		std::cout << "Player One has Won" << std::endl;
		break;
	}
	
	if(check == 2){
		std::cout << "Player Two has Won" << std::endl;
		break;
	}
	
	if(check == 3){
		std::cout << "The Game has Resulted in a Tie" << std::endl;
		break;
	}
	
	draw();
  }
}