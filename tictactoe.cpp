#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void displayHeader() {
	cout << "======================================" << endl;
    cout << "            TicTacToe Games           " << endl;
    cout << "======================================" << endl;
    cout << "\nDibuat oleh Kelompok 6.\nAnggota\t:\n1. Muhammad Naufal Yazid A\n2. Nasywan Damar F\n3. Daniel Dwi P\n4. Muhammad Ramadhan Nafis A\n5. Zulfa Ainun J" << endl;
    cout << "\nKETERANGAN :\nPlayer 1 : 'X'\nPlayer 2 : 'O'" << endl;
}

void displayMenu() {
	cout << "\n============== [ MENU ] ==============" << endl;
	cout << "\t1. Main\n\t2. Leaderboard\n\t3. Cari Detail Permainan\n\t4. Exit" << endl;
	cout << "======================================\n" << endl;
}

void displayBoard(string board[9], int round, int maxRound) {
	cout << "\n========= [ RONDE : " << round << " / " << maxRound << " ] =========\n" << endl;

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
    int round = 1;
    int MAX_ROUND = 3;
	
	// score table
	string username[10][2];
    int score[10][3] = {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}};
	int point[10][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	string winner[10] = {"Draw", "Draw", "Draw", "Draw", "Draw", "Draw", "Draw", "Draw", "Draw", "Draw"};
    
    while(true) {
		string tempUsername[2] = {"None", "None"};
		int menuChoice = 0;

		displayHeader();
		displayMenu();
		cout << "Pilih Menu\t: ";
		cin >> menuChoice;


		if (menuChoice == 1) {
			system("cls");

			cout << "Masukkan Username Player 1\t: ";
			cin >> tempUsername[0];
			cout << "\nMasukkan Username Player 2\t: ";
			cin >> tempUsername[1];

			system("cls");

			while(true) {
				int choice;
		
				if((board[0] == "X" && board[0] == board[1] && board[1] == board[2]) || ( board[3] == "X" &&board[3] == board[4] && board[4] == board[5]) || (board[6] == "X" && board[6] == board[7] && board[7] == board[8]) || (board[0] == "X" && board[0] == board[3] && board[3] == board[6]) || (board[1] == "X" && board[1] == board[4] && board[4] == board[7]) || (board[2] == "X" && board[2] == board[5] && board[5] == board[8]) || (board[0] == "X" && board[0] == board[4] && board[4] == board[8]) || (board[2] == "X" && board[2] == board[4] && board[4] == board[6])) {
					displayHeader();
					displayBoard(board, round, MAX_ROUND);
					cout << tempUsername[0] << " Menang\n" << endl;
					score[index][1] += 1;
					round += 1;
					turn = 1;

					for(int i = 0; i < 9; i++) {
						board[i] = " ";
					}
		
					Sleep(1500);
					system("cls");

					if (round > MAX_ROUND) {
						round = 1;
						break;
					}
				
				} else if((board[0] == "O" && board[0] == board[1] && board[1] == board[2]) || ( board[3] == "O" &&board[3] == board[4] && board[4] == board[5]) || (board[6] == "O" && board[6] == board[7] && board[7] == board[8]) || (board[0] == "O" && board[0] == board[3] && board[3] == board[6]) || (board[1] == "O" && board[1] == board[4] && board[4] == board[7]) || (board[2] == "O" && board[2] == board[5] && board[5] == board[8]) || (board[0] == "O" && board[0] == board[4] && board[4] == board[8]) || (board[2] == "O" && board[2] == board[4] && board[4] == board[6])) {
					displayHeader();
					displayBoard(board, round, MAX_ROUND);
					cout << tempUsername[1] << " Menang\n" << endl;
					score[index][2] += 1;
					round += 1;
					turn = 1;

					for(int i = 0; i < 9; i++) {
						board[i] = " ";
					}
		
					Sleep(1500);
					system("cls");

					if (round > MAX_ROUND) {
						round = 1;
						break;
					}
		
				} else if(!isMovesLeft(board)) {
					displayHeader();
					displayBoard(board, round, MAX_ROUND);
					cout << "Seimbang\n" << endl;
					round += 1;
					turn = 1;

					for(int i = 0; i < 9; i++) {
						board[i] = " ";
					}
					
					Sleep(1500);
					system("cls");
					
					if (round > MAX_ROUND) {
						round = 1;
						break;
					}
				}
				
				displayHeader();
				displayBoard(board, round, MAX_ROUND);
		
				if(turn == 1) {
					cout << tempUsername[0] << " masukkan nomor index papan : ";
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
								Sleep(1500);
							}
		
							break;
		
						default:
							cout << "\n[ERROR] Pilih papan dari 1-9\n" << endl;
							Sleep(1500);
							break;
					}
				} else {
					cout << tempUsername[1] << " masukkan nomor index papan : ";
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
								Sleep(1500);
							}
		
							break;
		
						default:
							cout << "\n[ERROR] Pilih papan dari 1-9\n" << endl;
							Sleep(1500);
							break;
					}
				}
		
				system("cls");
			}

			index += 1;

			// menentukan winner
			if (score[index - 1][1] > score[index - 1][2]) {
				winner[index - 1] = tempUsername[0];
			} else if (score[index - 1][1] < score[index - 1][2]) {
				winner[index - 1] = tempUsername[1];
			}
			
			// masukkan ke array untuk leaderboard sistem
			username[index - 1][0] = tempUsername[0];
			point[index - 1][0] = score[index - 1][1];
			username[index - 1][1] = tempUsername[1];
			point[index - 1][1] = score[index - 1][2];

		} else if (menuChoice == 2) {
			system("cls");
			// Sorting system
			for (int i = 0; i < 10; i++) {
				if (i >= index || i < 0) {
					break;
				}

				for (int j = 0; j < 10 - i; j++) {
					if (j >= index || j < 0) {
						break;
					}

					int max1 = score[j][1] > score[j][2] ? score[j][1] : score[j][2];
					int max2 = score[j + 1][1] > score[j + 1][2] ? score[j + 1][1] : score[j + 1][2];

					if (max1 < max2) {
						
						for (int k = 0; k < 2; k++) {
							int temp = score[j][k + 1];
							score[j][k + 1] = score[j + 1][k + 1];
							score[j + 1][k + 1] = temp;
						}

						int tempId = score[j][0];
						score[j][0] = score[j + 1][0];
						score[j + 1][0] = tempId;
					}
				}
			}

			// Display the top 5 players
			cout << "\nTop Score:\n";
			cout << "-----------------------------------------\n";
			cout << "|  Rank  |     Winner     |    Score    |\n";
			cout << "-----------------------------------------\n";

			for (int i = 0; i < 5; i++) {
				if (i < index) {
					cout << "|" << setw(4) << i + 1 << setw(5) << "|" << setw(8) << winner[score[i][0]] << setw(9) << "|" << setw(6) << (score[i][1] > score[i][2] ? score[i][1] : score[i][2]) << setw(9) << "|\n";
				} else {
					cout << "|" << setw(4) << i + 1 << setw(5) << "|" << setw(9) << "No Data" << setw(8) <<"|" << setw(8) << "No Data" << setw(7) << "|\n";
				}
			}

			cout << "-----------------------------------------\n" << endl;

			Sleep(1500);

		} else if (menuChoice == 3) {
			string search, searchResult[10][3];
			int searchResultInt[10][3];
			int searchIndex = 0;
			
			cout << "Search berdasarkan username : ";
			cin >> search;
			
			for(int i = 0; i < 10; i++) {
				if(username[i][0] == search) {
					searchResultInt[searchIndex][0] = i;
					searchResult[searchIndex][0] = username[i][0];
					searchResultInt[searchIndex][1] = point[i][0];
					searchResult[searchIndex][1] = username[i][1];
					searchResultInt[searchIndex][2] = point[i][1];
					searchResult[searchIndex][2] = winner[i];
					
					searchIndex++;
					
				} else if (username[i][1] == search) {
					searchResultInt[searchIndex][0] = i;
					searchResult[searchIndex][0] = username[i][0];
					searchResultInt[searchIndex][1] = point[i][0];
					searchResult[searchIndex][1] = username[i][1];
					searchResultInt[searchIndex][2] = point[i][1];
					searchResult[searchIndex][2] = winner[i];
					
					searchIndex++;
				} else if (username[i][0].empty()) {
					break;
				} 
			}

			system("cls");
			
			cout << "================================= SEARCH  RESULT ================================" << endl;
			cout << "---------------------------------------------------------------------------------" << endl;
			cout << "| ID |   Username 1   |   Point 1   |   Username 2   |   Point 2   |   Winner   |" << endl;
			cout << "---------------------------------------------------------------------------------" << endl;
			
			for(int i = 0; i < index; i++) {
				cout << "|" << setw(2) << searchResultInt[i][0] << setw(3) << "|" << setw(8) << searchResult[i][0] << setw(9) << "|" << setw(7) << searchResultInt[i][1] << setw(7) << "|" << setw(10) << searchResult[i][1] << setw(7) << "|" << setw(7) << searchResultInt[i][2] << setw(7) << "|" << setw(7) << searchResult[i][2] << setw(6) << "|" << endl;
			}
			
			cout << "---------------------------------------------------------------------------------\n\n" << endl;

			Sleep(1500);
		} else if(menuChoice == 4) {
			break;
		}
	}
}


