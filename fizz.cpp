#include<iostream>
#include <cmath>
#include <vector>
int yourpoints;
int CPUpoints;
int AllCardsUsed;
std::vector <int> AvailableCards = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
std::vector <int> UsedCards;
int CPUHand(std::vector <int> deck1, std::vector <int> Used){
    for (int i = 0; i <= 2; i++)
    {
        int randomizer1 = rand() % AvailableCards.size();
        deck1.at(i) =  AvailableCards.at(randomizer1);
        AvailableCards.erase(AvailableCards.begin() + randomizer1);
    }
    return 0;
}
int main(){
    int innerRandomizer;
    std::string player;
    int YourThrow;
    int YourScore;
    int CPUscore;
    std::vector <int> playerCards = {0,0,0};
    std::vector <int> CPUCards = {0,0,0};
    std::cout<< "welcome to fizzbuzz roulette! "<< '\n';
    std::cout<< "whats your name?"<< '\n' ;
    std::cin>> player;
    std::cout<< "your cards are: "<< '\n';
    //YourHand(playerCards,UsedCards);
    srand(time(NULL));
            for(int i = 0;i<=2;i++){
                    int randomizer = rand() % AvailableCards.size();
                    playerCards.at(i) =  AvailableCards.at(randomizer);
                    std::cout<< playerCards.at(i) << '\n';
                    AvailableCards.erase(AvailableCards.begin() + randomizer);
                                     }
    std::cout<< "which card are you choosing: "<< '\n';
    std::cin>>YourThrow;
    for (int i = 0; i <= 2; i++)
    {
        int found;
        if(YourThrow != playerCards.at(i) && i !=2){
            std::cout<< "testing..." << '\n';
        } else if (YourThrow == playerCards.at(i)){
                std::cout<< "card number " << i << " chosen." << '\n';
                found = 1;
        } else if (YourThrow != playerCards.at(i) && i ==2 && found !=1){
            std::cout<< "invalid card, start again";
            return 0;
        }
        
        
    }
    
    for (int i = 0; i <= 2; i++)
    {
         int randomizer1 = rand() % AvailableCards.size();
        CPUCards.at(i) =  AvailableCards.at(randomizer1);
        AvailableCards.erase(AvailableCards.begin() + randomizer1);
    }
    int CPUthrow = CPUCards.at(1);
   // round(CPUthrow,CPUscore, "The CPU");
            if (YourThrow % 15 == 0)
            {
                YourScore = 3;
                /* code */
            } else if (YourThrow % 5 == 0)
            {
                YourScore = 2;
                /* code */
            } else if (YourThrow % 3 == 0)
            {
                YourScore = 1;
                /* code */
            } else{
                YourScore =0;
            }
          std::cout<< "you threw a" << YourThrow << '\n';
          std::cout<< "you scored a" << YourScore << '\n';
            if (CPUthrow % 15 == 0)
            {
                CPUscore = 3;
                /* code */
            } else if (CPUthrow % 5 == 0)
            {
                CPUscore = 2;
                /* code */
            } else if (CPUthrow % 3 == 0)
            {
                CPUscore = 1;
                /* code */
            } else {
                CPUscore =0;
            }
        std::cout<< "The CPU threw a" << CPUthrow << '\n';
        std::cout<< "it scored " << CPUscore; 
            
            
            
            
            
   if(YourScore > CPUscore){
    std::cout<< "YOU WIN" << "\n";
    yourpoints++;
   } else if (YourScore < CPUscore)
   {
    std::cout<< "you lose" << "\n";
    CPUpoints++;
   }
   std::cout<< "do you want to play again?" << "\n";
   std::string playagain;
   std::cin>>playagain;
   if(playagain != "no" && AvailableCards.size() != 0){
    for (int i = 0; i <=2; i++)
    {
        std::cout << playerCards.at(i) << " was thrown away" << '\n';
    }
    for (int j = 0;j <=2;j++){
            std::cout<< CPUCards.at(j) << " was thrown away" << '\n';
    }
    main();
   }
   else if (playagain == "no" || AvailableCards.size() == 0)
   {
    std::cout<< "game over"<< '\n';
    if (yourpoints > CPUpoints)
    {
        std::cout << "you won by " << yourpoints - CPUpoints << " points!";
    } else if (CPUpoints > yourpoints)
    {
        std::cout<< "you lost by" << CPUpoints - yourpoints << " points...";
    }
    
    
   }
   



}