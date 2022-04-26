/*
	Welcome to my Project

	Program:	Gully Cricket App
	Author: 	Pragati Kumari
*/
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>

using namespace std;

class Team
{
    public :
    string name;
    string players[3];
    int runs;
};
 void welcomeUsers();
 void displayPlayers(Team,Team);
 void selectBatsmanOrBowler(Team,Team);
 void startInning(int);
 int playInning();
 void displayScore(Team);
 void decideWinner(Team,Team);
 string batsman,bowler;


int main()
{
    
    welcomeUsers();

 Team a;
 a.name = "A";
 a.players[0]= "Rohit";
 a.players[1]= "Jadeja";
 a.players[2]="Dhoni";
 Team b;
 b.name="B";
 b.players[0]="Virat";
 b.players[1]="Ashwin";
 b.players[2]="Rahul";
 displayPlayers(a,b);
 

startInning(1);
selectBatsmanOrBowler(a,b);
a.runs=playInning();
displayScore(a);
 cout << "\n*********** TeamB needs " << a.runs + 1 << " runs to win ***********" << endl << endl;

startInning(2);
selectBatsmanOrBowler(b,a);
b.runs=playInning();
displayScore(b);

decideWinner(a,b);
 return 0;
}
/* Greet users with a welcome message */ 
void welcomeUsers() {
    cout<<"----------------------------------------------------------------------------------------------------------------------" << endl;
    cout<<"|================================================== GULLY CRICKET ====================================================|" << endl;
    cout<<"|                                                                                                                     |" << endl;
    cout<<"|                                              Welcome to Gully Cricket                                               |" << endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
/* Display all the players in both team A and team B */
void displayPlayers(Team a,Team b) {
   cout<<"Press Enter to see the list of Players \n";
   cin.get();

    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "|\t";
        cout << "[" << i+1 << "] " << a.players[i] << "\t |";
        cout << "\t\t|\t";
        cout << "[" << i+1 << "] " << b.players[i] << "\t |";
        cout << endl;
    }
    cout << "--------------------------\t\t--------------------------" << endl << endl;
}
/* Select randomly a batsman and bowler from the batting team and bowler team respectively for 
a inning */
void selectBatsmanOrBowler(Team a,Team b) {
srand(time(NULL));
int i =rand()%3; // 0, 1 or 2 will be selected
batsman=a.players[i];
int j =rand()%3; // 0, 1 or 2 will be selected
bowler=b.players[j];

    cout << "----------------------------------------------------" << endl;
    cout << "\t\t " << a.name << ": Batsman - " << batsman <<endl;
    cout << "\t\t " << b.name << ": Bowler - " << bowler <<endl;
    cout << "----------------------------------------------------" << endl << endl;

}
/* Start inning by displaying initial inning details */
void startInning(int inning)
{
    cout<<"\n\tPRESS ENTER TO START THE INNINGS \n";
   cin.get();
    string team1,team2;
    if(inning ==1)
    {
        cout << "|------------ Inning " << inning << " Starts ------------|" << endl;
         
      team1="A";
      team2="B";
    }
    else
    {
        if(inning==2)
        {
            cout << "|------------ Inning " << inning << " Starts ------------|" << endl;
            
            team1="B";
            team2="A";
        }
    }
    cout << "|----- " <<team1<< " is batting and " <<team2<< " is bowling -----|" << endl << endl;
    
cout<<"\n\nSelecting Batsman and Bowler for the innings....Please wait....\n\n"<<endl;
usleep(1000*2000);

}
/* Play one inning (6 balls) */
int playInning() {
 srand(time(NULL));
 int runs=0,run;
for(int i=0;i<6;i++)
{
    cout<<"\n\n"<<bowler<<" bowling ball "<<i+1<<"........"<<endl;
    usleep(1000*1000);
srand(time(NULL));
run = rand()%6;
cout<<"\nRuns scored by "<<batsman<<" at ball "<<i+1<<" is : ";
usleep(1000*1000);
cout<<run<<"\n";
runs=runs+run;

}
return runs; // Return the final run scored by the batting team 
}
/* Display runs scored by batting team in the inning */
void displayScore(Team a) {
    usleep(1000*1000);
 cout << "----------------------------------------------------" << endl;
    cout << "\t\t " << a.name << " scored " <<a.runs << " runs." << endl;
    cout << "----------------------------------------------------" << endl << endl;
}
/* Decide winner by comparing final scores of both the teams */
void decideWinner(Team a,Team b)
{
    
   	cout << "----------------------------------------------------" << endl;

    usleep(1000*2000);
     if(a.runs>b.runs)
     {
     cout<<"\n\n\t\tTeam A is the Winner";
     }
     else
     {
         if(a.runs==b.runs)
         {
             cout<<"\n\n\t\tThe match was tied";
         }
         else
         {
             cout<<"\n\n\t\tTeam B is the winner";
         }
     }
      cout << "\n\n----------------------------------------------------" << endl;

}
