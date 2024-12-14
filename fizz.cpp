#include<iostream>
#include <cmath>
#include <vector>
#include <windows.h>
std::vector <std::string> playerPowerUps;
std::vector <std::string> CPUPowerUps;
int powermachine;
std::string uncleben;
std::string activepowerup;
int puttytimer = 2;
bool puttyq;
bool blenderq;
bool plungerq;
bool plungerconfirm;
bool pieq;
bool shaverq;
int puttythrow;
int yourpoints;
int CPUpoints;
int AllCardsUsed;
std::vector <int> AvailableCards = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
std::vector <int> UsedCards;

int powerUp(  std::string key, std::vector <int> Cards, std::vector <int> Deck, std::vector <int> thrown){
  if(key == "putty" && puttyq == true){
    std:: cout<< "what card are you making a copy of:";
    for (int i = 0; i < Cards.size(); i++)
    {
        std::cout<< Cards.at(i) << '\n';
    }
    std::cin>> puttythrow;
    std::cout<< puttythrow << "has been duplicated" << '\n';
    Cards.push_back(puttythrow);
    return 0;
  } else if (key == "pie" || key == "schrodingers pie" && pieq == true)
  {
    int deadoralive = rand() % 2;
    int cat;
    int observation;
    std::cout<< "what number are you flipping?:" << '\n';
    std::cin>>cat;
   for (int i = 0; i < Cards.size(); i++)
   {
    if(cat == Cards.at(i)){
        std::cout<< "card picked, about to be flipped" << '\n';
        std::cout<< cat << "has been flipped to: ";
        observation = i;
        switch (deadoralive)
        {
        case 1:
        cat = Cards.at(observation) + 2;
        if(cat >=30){
            cat = 30;
        } else{
        Cards.at(observation) = cat;
            break;
        }
        
        default: 
        float catq;
        float cata = Cards.at(observation);
        catq =  cata/3.14;
        cat = round(catq);
        if(cat <=0){
            cat++;
        }
        Cards.at(observation) = cat;
            break;
        }
        std::cout<< cat;
    }



   }
   
  }
  else if(key == "plunger" || key == "flush" && plungerq == true){
    for(int i = 0;i<Cards.size();i++){
        int j;
        Deck.push_back(Cards.at(i));
        Cards.erase(Cards.begin() + i);

    }
    for (int i = 0; i < thrown.size(); i++)
    {
        Deck.push_back(thrown.at(i));
        thrown.erase(thrown.begin() + i);
    }
    std::cout<< "the board has been purged, scores will remain, but your cards and power ups will be reset" << "\n";
    plungerconfirm = true;
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

    srand(time(NULL));
            for(int i = 0;i<=2;i++){
                    int randomizer = rand() % AvailableCards.size();
                    playerCards.at(i) =  AvailableCards.at(randomizer);
                    std::cout<< playerCards.at(i) << '\n';
                    AvailableCards.erase(AvailableCards.begin() + randomizer);
                                     }
if (puttyq == true)
{
switch (puttytimer)
{
case 0:
    std::cout<< "the putty is drying, you cant use it yet" << '\n';
    break;
case 1:
    std::cout<< "the putty is ready for use" << '\n';
    break;
case 2:
    std::cout<< "last chance to use the putty, it will break on the next turn";
    break;
case 3:
    std::cout<< "the putty has broken";
    puttyq = false;
}
}
std::cout<< "your power up is a: " << '\n';
powermachine = rand() % 4;
switch (powermachine)
{
case 1:
    std::cout<< "Paper mache"<< '\n';
    puttyq = true;
    playerPowerUps.push_back("Putty");
    break;
case 2:
    std::cout<< " Schrodingers pie" << '\n';
    pieq = true;
    playerPowerUps.push_back("Schrodinger's pie");
    break;
case 3: 
    std::cout<< " A plunger, it can attach to the bottom of the table..." << '\n';
    plungerq = true;
    playerPowerUps.push_back("Plunger");
    break;
case 4:
    std::cout<< "a blender?, really?" <<'\n';
    std:: cout<< "my intern tells me its a food processor, personally i dont get it" << '\n';
    playerPowerUps.push_back("food processor that looks eerily close to a blender");
    blenderq =true;
    break;
default: std::cout<< "a shaving machine but its unplugged, needs some voltage to work,"<<'\n';
        playerPowerUps.push_back("buzzer without a buzz");
    shaverq = true;
    break;
}
        std::cout<< " are you using any power up?: " << '\n';
        std::cin>> uncleben; 

        if(uncleben == "yes"){
            std:: cout<< " which power up are you choosing? " << '\n';
            for (int i = 0; i < playerPowerUps.size(); i++)
            {
                std::cout<< playerPowerUps.at(i) << '\n';
            }
            std::cin >> activepowerup;
            powerUp(activepowerup,playerCards,AvailableCards,UsedCards);
            if(plungerconfirm== true ){
                main();
            }
        }
    std::cout<< "which card are you choosing: "<< '\n';
    std::cin>>YourThrow;
    for (int i = 0; i < playerCards.size(); i++)
    {
        int found;
        if(YourThrow != playerCards.at(i) && i != playerCards.size()){
            std::cout<< "testing..." << '\n';
        } else if (YourThrow == playerCards.at(i)){
                std::cout<< "card number " << i << " chosen." << '\n';
                found = 1;
        } else if (YourThrow != playerCards.at(i) && i ==playerCards.size() && found !=1){
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
    
    return 0;
   }
   



}