#include<iostream>
#include <cmath>
#include <vector>
int AllCardsUsed;
std::vector <int> AvailableCards = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
std::vector <int> UsedCards;
int YourHand(std::vector <int> deck, std::vector <int> Used){
    srand(time(NULL));
    for (int i = 0; i <= 2; i++)
    {
        int randomizer = rand() % AvailableCards.size();
        deck.at(i) =  AvailableCards.at(randomizer);
        std::cout<< deck.at(i) << '\n';
        AvailableCards.erase(AvailableCards.begin() + randomizer);
        
    }
    return 0;
}
int CPUHand(std::vector <int> deck, std::vector <int> Used){
    for (int i = 0; i <= 2; i++)
    {
        int randomizer = rand() % AvailableCards.size();
        deck.at(i) =  AvailableCards.at(randomizer);
        AvailableCards.erase(AvailableCards.begin() + randomizer);
    }
    return 0;
}
int round(int playernum,int playerscore, std::string player){
    if (playernum % 15 == 0 )
    {
        playerscore = 3;
    } else if(playernum % 5 == 0){
        playerscore = 2;

    } else if(playernum % 3 == 0){
        playerscore = 1;
    } else{
        playerscore = 0;
    }
    std::cout<< player << "scored " << playerscore << "points!";

}
int main(){
    std::string player;
    int YourThrow;
    int YourScore;
    int CPUthrow;
    std::vector <int> playerCards = {0,0,0};
    std::vector <int> CPUCards = {0,0,0};
    std::cout<< "welcome to fizzbuzz roulette! "<< '\n';
    std::cout<< "whats your name?";
    std::cin>> player;
    std::cout<< "your cards are: "<< '\n';
    YourHand(playerCards,UsedCards);
    CPUHand(CPUCards,UsedCards);
    std::cout<< "which card are you choosing: "<< '\n';
    std::cin>>YourThrow;
    round(YourThrow,YourScore,player);


}