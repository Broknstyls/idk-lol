
#include<iostream>
#include <cmath>
#include <vector>
#include <windows.h>
#include <typeinfo>
#include <bits/stdc++.h>
std::vector <std::string> playerPowerUps;
std::vector <std::string> CPUPowerUps;
int powermachine;
std::string uncleben;
std::string activepowerup;
int puttytimer = 4;
bool puttyconfirm;
int liquid;
std::string YourThrow;
bool puttyq;
bool CPUputtyq;
int CPUmold;
int CPUmoldtimer;
bool plungerq;
bool CPUplungerq;
bool plungerconfirm;
bool pieq;
bool CPUpieq;
bool shaverq;
bool shaverconfirm;
bool CPUshaverq;
bool CPUshaverconfirm;
int puttythrow;
int yourpoints;
int CPUpoints;
int AllCardsUsed;
int powerusage;
std::vector <int> AvailableCards = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
std::vector <int> UsedCards;

int powerUp(std::string key, std::vector <int> Cards, std::vector <int> Deck, std::vector <int> thrown){
  if(key == "putty" && puttyq == true){
    std:: cout<< "what card are you making a copy of:" << '\n';
    for (int i = 0; i < Cards.size(); i++)
    {
        std::cout<< Cards.at(i) << '\n';
    }
    std::cin>> puttythrow;
    std::cout<< puttythrow << "has been duplicated" << '\n';
    Cards.push_back(puttythrow);
    puttyq = false;
    puttyconfirm = true;
  } 
  if (shaverq == true && key == "shaver")
  {
    shaverconfirm = true;
    std::cout<< "the buzzer is on, but it isnt powered up yet"<< '\n';
  }
   if (key == "pie" || key == "schrodingers pie" && pieq == true)
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
   pieq = false;
  }
  if(key == "plunger" || key == "flush" && plungerq == true){
    Cards.clear();
    playerPowerUps.clear();
    std::cout<< "the board has been purged, scores will remain, but your cards and power ups will be reset" << "\n";
    plungerconfirm = true;
    plungerq = false;
    
  } 
  return 0;
}

int main(){
    if (puttyconfirm == true && puttytimer != 0)
    {
        puttytimer--;
    }
    
    int innerRandomizer;
    std::string player;
    int YourThrow;
    std::string key1;
    int YourScore;
    int CPUscore;
    std::vector <int> playerCards = {0,0,0};
    std::vector <int> CPUCards = {0,0,0};
    if (AvailableCards.size() < 6)
    {
         std::cout<< "game over"<< '\n';
    if (yourpoints > CPUpoints)
    {
        std::cout << "you won by " << yourpoints - CPUpoints << " points!";
        return 0;
    } 
    if (CPUpoints > yourpoints)
    {
        std::cout<< "you lost by" << CPUpoints - yourpoints << " points...";
        return 0;
    }
    }
    
    std::cout<< "welcome to fizzbuzz roulette! "<< '\n';
    Sleep(2000);
    std::cout<< "your cards are: "<< '\n';

    srand(time(NULL));
            for(int i = 0;i<=2;i++){
                    int randomizer = rand() % AvailableCards.size();
                    playerCards.at(i) =  AvailableCards.at(randomizer);
                    std::cout<< playerCards.at(i) << '\n';
                    Sleep(500);
                    AvailableCards.erase(AvailableCards.begin() + randomizer);
                                     }
                                     
if (puttyconfirm == true)
{

switch (puttytimer)
{
   
case 1:
    std::cout<< "last chance to use the putty" << '\n';
    Sleep(1000);
    break;
case 2:
    std::cout<< "putty is ready" << '\n';
    Sleep(1000);
    puttythrow = liquid;
    break;
case 3: 
    std::cout<< "putty is drying, cant be used yet" << '\n';
    Sleep(1000);
     liquid = puttythrow;
    puttythrow = 1;
    break;
default:
    std::cout<< "putty is broken, it cant be used" << '\n';
    puttyconfirm = false;
    puttythrow = 1;
    break;
}
}
std::cout<< "your power up is a: " << '\n';
Sleep(500);
//powermachine = 1;
powermachine = rand() % 4;
switch (powermachine)
{
case 1:
    std::cout<< "Paper mache"<< '\n';
    puttyq = true;
    playerPowerUps.push_back("putty");
    break;
case 2:
    std::cout<< "schrodingers pie" << '\n';
    pieq = true;
    playerPowerUps.push_back("pie");
    break;
case 3: 
    std::cout<< "a plunger" << '\n';
    plungerq = true;
    playerPowerUps.push_back("plunger");
    break;

default: std::cout<< "a shaving machine, it isnt powered up tho, waiting for voltage"<<'\n';
        playerPowerUps.push_back("shaver");
    shaverq = true;
    break;
}
std::cout<< "your power ups are: " << '\n';
 for (int i = 0; i < playerPowerUps.size(); i++)
            {
             Sleep(500);
                std::cout<< playerPowerUps.at(i) << '\n';
            }
        std::cout<< " are you using any power up?: " << '\n';
        std::cin>> uncleben; 

        if(uncleben == "yes"){
            std:: cout<< " which power up are you choosing? " << '\n';
           
            std::cin >> activepowerup;     
            if (activepowerup == "shaving" || activepowerup == "Shaver" || activepowerup == "Shaving")
            {
                activepowerup = "shaver";
            } else if (activepowerup == "flush" || activepowerup == "Flush" || activepowerup == "Plunger" )
            {
                activepowerup = "plunger";
            } else if (activepowerup == "paper" || activepowerup == "Paper" || activepowerup == "Mache" || activepowerup == "mache" || activepowerup == "Putty")
            {
                activepowerup = "putty";
            }
            else if (activepowerup == "schrodinger" || activepowerup == "Schrodinger" || activepowerup == "Pie")
            {
                activepowerup = "pie";
            }
            
            
                   
    for (int i = 0; i < playerPowerUps.size(); i++)
    {
        if(activepowerup == playerPowerUps.at(i)){
            playerPowerUps.erase(playerPowerUps.begin() + i);
        }
    }
    
            powerUp(activepowerup,playerCards,AvailableCards,UsedCards);
            if(plungerconfirm== true ){
                main();
            }
        }
    Sleep(1000);
    std::cout<< "which card are you choosing: "<< '\n';
    std::cin>>YourThrow;
    int found;
    for (int i = 0; i < playerCards.size(); i++)
    {
        if (YourThrow == playerCards.at(i)){
                std::cout<< "card number " << i+1 << " chosen." << '\n';
                Sleep(1000);
                found = 5;
        } 
        else if(YourThrow != playerCards.at(i)){
    
        if (i == playerCards.size() && found != 5)
                {
                std::cout<< "invalid card, try again" << '\n';
                YourThrow = 1;
                }
            
            Sleep(500);
            std::cout<< "testing..." << '\n';
        }
        
        
    }


    for (int i = 0; i <= 2; i++)
    {
         int randomizer1 = rand() % AvailableCards.size();
        CPUCards.at(i) =  AvailableCards.at(randomizer1);
        AvailableCards.erase(AvailableCards.begin() + randomizer1);
    }

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
          Sleep(2000);
          std::cout<< "you scored a" << YourScore << '\n';
          Sleep(500);
                     int CPUthrow;

     int CPUpowermachine = rand() % 4;
     switch (CPUpowermachine)
     {
     case 1:
        CPUpieq = true;
        break;
    case 2:
        CPUputtyq = true;
        break;
    case 3:
    CPUshaverq = true;
    break;
     default:
     CPUplungerq = true;
        break;
     }        
          for (int i = 0; i < CPUCards.size(); i++)
          {
            if (CPUCards.at(i) % 15 == 0)
            {
                CPUthrow = CPUCards.at(i);
                if (CPUputtyq == true)
                {
                    CPUmold = CPUCards.at(i);
                    CPUmoldtimer = 4;
                    CPUputtyq = false;
                }
                
            } else if (CPUCards.at(i) % 5 == 0)
            {
                 CPUthrow = CPUCards.at(i);
                if (CPUputtyq == true)
                {
                    CPUmold = CPUCards.at(i);
                    CPUmoldtimer = 4;
                    CPUputtyq = false;
                }
            } else if (CPUCards.at(i) % 3 == 0)
            {
                 CPUthrow = CPUCards.at(i);
                if (CPUputtyq == true)
                {
                    CPUmold = CPUCards.at(i);
                    CPUmoldtimer = 4;
                    CPUputtyq = false;
                } else if (CPUshaverq == true)
                {
                    CPUshaverconfirm = true;
                }
                
            } else if (CPUCards.at(i) % 3 != 0){
                if (CPUplungerq == true)
         {
            std::cout<< "CPU used the plunger" << "\n";
                CPUCards.clear();
                playerCards.clear();
                CPUPowerUps.clear();
                Sleep(2000);
            std::cout << "all cards have been cleared" << '\n';
            CPUplungerq = false;
            main();
                
         }
         else{
                    CPUthrow = CPUCards.at(i);
                }
                }
            
            }
            if(CPUthrow > 30){
            CPUthrow = CPUthrow % 30;
          }
          if(CPUthrow == 0 ){
            CPUthrow = 1;
          } 
            if (CPUthrow % 15 == 0)
            {
                CPUscore = 3;
                /* code */
            } else if (CPUthrow % 5 == 0)
            {
                CPUscore = 2;
                
            } else if (CPUthrow % 3 == 0)
            {
                CPUscore = 1;
                /* code */
            } else {
                CPUscore =0;
            }
        std::cout<< "The CPU threw a" << CPUthrow << '\n';
        Sleep(2000);
        std::cout<< "it scored " << CPUscore << '\n'; 

            
            
            
            
          if (activepowerup == "shave" || activepowerup == "buzz" || activepowerup == "shaving machine" && shaverconfirm == true)
          {
            if (CPUscore >= 2)
            {
                std::cout<< "voltage detected, the card has been drained";
                CPUscore = 0;
                shaverconfirm = false;
            }
            
          }
          else if (CPUshaverconfirm == true && YourScore >= 2)
          {
            std::cout<< "the CPU used the shaving machine, your card has been drained"<< '\n';
            Sleep(3000);
            YourScore = 0;
            CPUshaverconfirm = false;

          }
          
            Sleep(500);
   if(YourScore > CPUscore){
    std::cout<< "YOU WIN" << "\n";
    yourpoints++;
   } else if (YourScore < CPUscore)
   {
    std::cout<< "you lose" << "\n";
    CPUpoints++;
   } else{
        if (YourThrow > CPUthrow)
        {
            std::cout<< "you win by magnitude," << '\n';
            yourpoints++;
        } else if (CPUthrow > YourThrow)
        {
            std::cout<< "THE CPU won by magnitude" << "\n";
            CPUpoints++;
        } else
        {
            std::cout<< "nigga how did you draw?  you know how hard that is?" << "\n";
        }
        
        
        
   }
   std::cout<< "do you want to play again?" << "\n";
   std::string playagain;
   std::cin>>playagain;
   if(playagain != "no" && AvailableCards.size() != 0){
    for (int i = 0; i <=2; i++)
    {
        std::cout << playerCards.at(i) << " was thrown away" << '\n';
        Sleep(500);
    }
    for (int j = 0;j <=2;j++){
            std::cout<< CPUCards.at(j) << " was thrown away" << '\n';
            Sleep(500);
    }
    main();
   }
   else if (playagain == "no" || AvailableCards.size() == 0)
   {
    std::cout<< "game over"<< '\n';
    Sleep(500);
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
