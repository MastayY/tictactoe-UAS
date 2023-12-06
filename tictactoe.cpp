#include <iostream>
#include <cstring>
#include <windows.h>
#include <limits>
#include <cstdlib>
#include <time.h>

using namespace std;

void displayHeader(string board[9]) {
	cout << "======================================" << endl;
    cout << "            TicTacToe Games           " << endl;
    cout << "======================================" << endl;
    cout << "\nDibuat oleh Kelompok 6.\nAnggota\t:\n1. Muhammad Naufal Yazid A\n2. Nasywan Damar F\n3. Daniel Dwi P\n4. Muhammad Ramadhan Nafis A\n5. Zulfa Ainun J" << endl;
    cout << "\nKETERANGAN :\nPlayer 1 : 'X'\nPlayer 2 : 'O'" << endl;
}

void displayMenu(string board[9]) {
	cout << "\n============== [ MENU ] ==============" << endl;
	cout << "\t1. Main\n\t2. Leaderboard\n\t3. Cari Detail Permainan" << endl;
	cout << "======================================\n" << endl;
}

void displayBoard(string board[9]) {
	cout << "\n======================================\n" << endl;

    cout << "\t       |     |     " << endl;
    cout << "\t    " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "\t  _____|_____|_____" << endl;
    cout << "\t       |     |     " << endl;
    cout << "\t    " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "\t  _____|_____|_____" << endl;
    cout << "\t       |     |     " << endl;
    cout << "\t    " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "\t       |     |     " << endl << endl;

    cout << "======================================\n" << endl;
}

bool isMovesLeft(string board[9]) 
{ 
    for (int i = 0; i < 9; i++) 
        if (board[i] == " ") {
            return true; 
        } 
    return false; 
} 



int main() {
    string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ",  " "};
    int turn = 1;
    int index = 0;
    int score = 0;
    int round = 1;
    int MAX_ROUND = 2;
    string username[2] = {" ", " "};
    int point[2] = {0, 0};
    string leaderboard[10][5];
    int menuChoice = 0;
    
    displayHeader(board);
    displayMenu(board);
    cout << "Pilih Menu\t: ";
    cin >> menuChoice;
    
	
	if (menuChoice == 1) {
	    system("cls");
	    
	    cout << "Masukkan Username Player 1\t: ";
	    cin >> username[0];
	    cout << "\nMasukkan Username Player 2\t: ";
	    cin >> username[1];
	    
	    system("cls");
	
	    while(true) {
	        int choice;
	
	        if((board[0] == "X" && board[0] == board[1] && board[1] == board[2]) || ( board[3] == "X" &&board[3] == board[4] && board[4] == board[5]) || (board[6] == "X" && board[6] == board[7] && board[7] == board[8]) || (board[0] == "X" && board[0] == board[3] && board[3] == board[6]) || (board[1] == "X" && board[1] == board[4] && board[4] == board[7]) || (board[2] == "X" && board[2] == board[5] && board[5] == board[8]) || (board[0] == "X" && board[0] == board[4] && board[4] == board[8]) || (board[2] == "X" && board[2] == board[4] && board[4] == board[6])) {
	            displayHeader(board);
				displayBoard(board);
	            cout << username[0] << " Menang\n" << endl;
	            point[0] += 1;
	            index += 1;
	
	            Sleep(1500);
	            system("cls");
	            break;
	            
	        } else if((board[0] == "O" && board[0] == board[1] && board[1] == board[2]) || ( board[3] == "O" &&board[3] == board[4] && board[4] == board[5]) || (board[6] == "O" && board[6] == board[7] && board[7] == board[8]) || (board[0] == "O" && board[0] == board[3] && board[3] == board[6]) || (board[1] == "O" && board[1] == board[4] && board[4] == board[7]) || (board[2] == "O" && board[2] == board[5] && board[5] == board[8]) || (board[0] == "O" && board[0] == board[4] && board[4] == board[8]) || (board[2] == "O" && board[2] == board[4] && board[4] == board[6])) {
	            displayHeader(board);
				displayBoard(board);
	            cout << username[1] << " Menang\n" << endl;
	            point[1] += 1;
	            index += 1;
	
	            Sleep(1500);
	            system("cls");
	            break;
	
	        } else if(!isMovesLeft(board)) {
	            displayHeader(board);
				displayBoard(board);
	            cout << "Seimbang\n" << endl;
	            index += 1;
	            
	            Sleep(1500);
	            system("cls");
	            break;
	        }
	        
	        displayHeader(board);
	        displayBoard(board);
	
	        if(turn == 1) {
	            cout << username[0] << " masukkan nomor index papan : ";
	            cin >> choice;
	            switch(choice) {
	                case 1:
	                case 2:
	                case 3:
	                case 4:
	                case 5:
	                case 6:
	                case 7:
	                case 8:
	                case 9:
	                    if(board[choice - 1] != "X" && board[choice - 1] != "O") {
	                        board[choice - 1] = "X";
	                        turn = 2;
	                    } else {
	                        cout << "\n[ERROR] Pilihan sudah diisi\n" << endl;
	                    }
	
	                    break;
	
	                default:
	                    cout << "\n[ERROR] Pilih papan dari 1-9\n" << endl;
	                    break;
	            }
	        } else {
	            cout << username[1] << " masukkan nomor index papan : ";
	            cin >> choice;
	            switch(choice) {
	                case 1:
	                case 2:
	                case 3:
	                case 4:
	                case 5:
	                case 6:
	                case 7:
	                case 8:
	                case 9:
	                    if(board[choice - 1] != "X" && board[choice - 1] != "O") {
	                        board[choice - 1] = "O";
	                        turn = 1;
	                    } else {
	                        cout << "\n[ERROR] Pilihan sudah diisi\n" << endl;
	                    }
	
	                    break;
	
	                default:
	                    cout << "\n[ERROR] Pilih papan dari 1-9\n" << endl;
	                    break;
	        	}
	        }
	
	        system("cls");
		}
		string gameID = to_string(index);
		string p1Point = to_string(point[0]);
		string p2Point = to_string(point[1]);
		
		leaderboard[index - 1][0] = gameID;
		leaderboard[index - 1][1] = username[0];
		leaderboard[index - 1][2] = p1Point;
		leaderboard[index - 1][3] = username[1];
		leaderboard[index - 1][4] = p2Point;
    }
	
    cout << "ID : " << leaderboard[index - 1][0] << endl;
    cout << leaderboard[index - 1][1] << endl;
    cout << leaderboard[index - 1][2] << endl;
    cout << leaderboard[index - 1][3] << endl;
    cout << leaderboard[index - 1][4] << endl;
}
