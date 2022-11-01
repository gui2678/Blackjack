#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"

//Class with all variables, constructor and member functions, and array for the card deck
class Black
{
    public:
    int sum;
    int sumc;
    int money;
    int win;
    int loss;
    int tie;
    Black();
    void SS();
    void ComTable();
    void StartMenu();
    void Menu();
    void Table();
    void Stats();
    void Credits();
    void Instructions();
    void DealCard(int, int);
    int Sum(int);
    int SumCom(int);
    void Winner();
    private:
    int R[52];
   
};
//Constructor that initializes variables and creates and shuffles the deck
Black::Black()
{
    sum = 0;
    sumc = 0;
    win = 0;
    loss = 0;
    tie = 0;
    money = 1000;

    int count, count2 = 1, count3, ran;
    //for loop that fills an array with values from 1-52
    for (count = 1; count<54; count++)
    {
        R[count] = count2;
        count2++;
    }
    //for loop that generates random numbers between 1-52, these numbers are swapped with the values in the array counting up from 1
    for (count3 = 0; count3<53; count3++)
    {
        ran = rand() % 52 + 1;
        R[ran] = R[count3];
        R[count3] = ran;
    }
}
//Function that draws the start menu when the game is run
void Black::StartMenu()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("Blackjack", 100, 40);
    LCD.WriteAt("Click anywhere to start", 20, 173);

    //Draw spade
    LCD.FillRectangle(50, 100, 26, 20);
    LCD.SetFontColor(LCD.White);
    LCD.FillCircle(48, 104, 14);
    LCD.FillCircle(76, 104, 14);
    LCD.SetFontColor(LCD.Black);
    LCD.FillCircle(52, 100, 12);
    LCD.FillCircle(72, 100, 12);
    LCD.FillRectangle(45, 60, 35, 40);
    LCD.SetFontColor(LCD.White);
    LCD.FillCircle(42, 72, 17);
    LCD.FillCircle(81, 72, 17);
    LCD.FillRectangle(50, 45, 30, 30);

    //Draw heart
    LCD.SetFontColor(LCD.Red);
    LCD.FillCircle(115, 87, 12);
    LCD.FillCircle(135, 87, 12);
    LCD.FillRectangle(111, 92, 29, 40);
    LCD.SetFontColor(LCD.White);
    LCD.FillCircle(108, 119, 18);
    LCD.FillCircle(145, 119, 18);
    LCD.FillRectangle(120, 115, 29, 40);

    //Draw clubs
    LCD.SetFontColor(LCD.Black);
    LCD.FillRectangle(172, 100, 26, 20);
    LCD.SetFontColor(LCD.White);
    LCD.FillCircle(170, 104, 14);
    LCD.FillCircle(198, 104, 14);
    LCD.SetFontColor(LCD.Black);
    LCD.FillCircle(174, 102, 11);
    LCD.FillCircle(194, 102, 11);
    LCD.FillCircle(184, 84, 11);
    LCD.FillRectangle(175, 92, 15, 15);
   
    //Draw diamond
    int count, count1, count2, count3;
    LCD.SetFontColor(LCD.Red);
    LCD.FillRectangle(224, 70, 42, 52);
    LCD.SetFontColor(LCD.White);

    //for loops used to draw diagonal lines that cut out the diamond from a square
    for (count = 0; count<12;count++)
    {
        LCD.DrawLine((245+count), (122+count), (266+count), (96+count));
    }
   
    for (count1 = 0; count1<12;count1++)
    {
        LCD.DrawLine((245-count1), (122+count1), (224-count1), (96+count1));
    }
    for (count2 = 0; count2<12;count2++)
    {
        LCD.DrawLine((224-count2), (96-count2), (245-count2), (70-count2));
    }
    for (count3 = 0; count3<12;count3++)
    {
        LCD.DrawLine((245+count3), (70-count3), (266+count3), (96-count3));
    }
    LCD.Update();
}
//Function that draws the menu screen and the corresponding buttons
void Black::Menu()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("Menu", 130, 30);
    //draw the stats button
    LCD.SetFontColor(LCD.Blue);
    LCD.WriteAt("Stats", 75, 167);
    LCD.DrawRectangle(70, 155, 70, 40);
    //draw the intructions button
    LCD.SetFontColor(LCD.Gray);
    LCD.WriteAt("Instructions", 32, 97);
    LCD.DrawRectangle(30, 85, 150, 40);
    //draw the credits button
    LCD.SetFontColor(LCD.Scarlet);
    LCD.WriteAt("Credits", 192, 97);
    LCD.DrawRectangle(190, 85, 90, 40);
    //draw the play button
    LCD.SetFontColor(LCD.Green);
    LCD.WriteAt("Play", 180, 167);
    LCD.DrawRectangle(170, 155, 70, 40);
    LCD.SetFontColor(LCD.Black);
    LCD.Update();
   
}
//Funcition that draws the table screen and the hit and stand buttons
void Black::Table()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("User's Turn", 85, 10);
    //draw hit button
    LCD.SetFontColor(LCD.Green);
    LCD.WriteAt("Hit", 102, 187);
    LCD.SetFontColor(LCD.Green);
    LCD.DrawRectangle(95, 175, 50, 40);
    //draw stand button
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("Stand", 169, 187);
    LCD.SetFontColor(LCD.Black);
    LCD.DrawRectangle(165, 175, 70, 40);
    //Display the amount of money the user has and the bet amount
    LCD.WriteAt("Money: $", 15, 140);
    LCD.WriteAt(money, 110, 140);
    LCD.WriteAt("Bet: $100", 175, 140);
    LCD.Update();
}
//Function that draws the stats screen
void Black::Stats()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("Stats", 115, 10);
    //display the user's wins
    LCD.WriteAt("Wins:", 90, 80);
    LCD.WriteAt(win, 155, 80);
    //display the user's losses
    LCD.WriteAt("Losses:", 90, 110);
    LCD.WriteAt(loss, 180, 110);
    //display the user's ties
    LCD.WriteAt("Ties:", 90, 140);
    LCD.WriteAt(tie, 155, 140);
    //display the current amount of money
    LCD.WriteAt("Money: $", 80, 170);
    LCD.WriteAt(money, 180, 170);
    LCD.SetFontColor(LCD.Red);
    LCD.WriteAt("Back", 9, 12);
    LCD.SetFontColor(LCD.Red);
    LCD.DrawRectangle(8, 8, 52, 25);
    LCD.Update();
}
//Function that draws the credits screen
void Black::Credits()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("Credits", 110, 10);
    LCD.SetFontColor(LCD.Red);
    LCD.WriteAt("Back", 9, 12);
    LCD.SetFontColor(LCD.Red);
    LCD.DrawRectangle(8, 8, 52, 25);
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("This game was developed by:", 0, 70);
    LCD.WriteAt("Guilherme Oliveira and", 0, 100);
    LCD.WriteAt("Luke Hren", 0, 130);
    LCD.Update();
}
//Function that draws the instructions screen
void Black::Instructions()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("Instructions", 90, 10);
    LCD.SetFontColor(LCD.Red);
    LCD.WriteAt("Back", 9, 12);
    LCD.SetFontColor(LCD.Red);
    LCD.DrawRectangle(8, 8, 52, 25);
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("Blackjack is a game in", 0, 50);
    LCD.WriteAt("which the player tries", 0, 70);
    LCD.WriteAt("to get a score",0,90);
    LCD.WriteAt("that is higher than", 0, 110);
    LCD.WriteAt("that of the", 0, 130);
    LCD.WriteAt("dealer but less than", 0, 150);
    LCD.WriteAt("or equal to 21", 0, 170);
    LCD.Update();
}
//Function that draws the cards on the table screen and decides what kind of card it is
void Black::DealCard(int k, int cor)
{
    LCD.SetFontColor(LCD.Black);
    //if the card is 2,3,4,5,6,7,8,9, or 10 in the first grouping of the deck
    if (R[k]>1 && R[k]<11)
    {
        //determine if the card is a 10 because double digit cards must be formatted differently on the screen
        if (R[k] == 10)
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt((R[k]), (cor+1), 77);
        }
        else
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt((R[k]), (cor+8), 77);
        }
    }
    //if the card is 2,3,4,5,6,7,8,9, or 10 in the second grouping of the deck
    else if (R[k]>14 && R[k]<24)
    {
        //determine if the card is a 10 because double digit cards must be formatted differently on the screen
        if (R[k] == 23)
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt((R[k]-13), (cor+1), 77);
        }
        else
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt((R[k]-13), (cor+8), 77);
        }
    }    
    //if the card is 2,3,4,5,6,7,8,9, or 10 in the third grouping of the deck
    else if (R[k]>27 && R[k]<37)
    {
        //determine if the card is a 10 because double digit cards must be formatted differently on the screen
        if (R[k] == 36)
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt((R[k]-26), (cor+1), 77);
        }
        else
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt((R[k]-26), (cor+8), 77);
        }
    }
    //if the card is 2,3,4,5,6,7,8,9, or 10 in the fourth grouping of the deck
    else if (R[k]>40 && R[k]<50)
    {
        //determine if the card is a 10 because double digit cards must be formatted differently on the screen
        if (R[k] == 49)
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt((R[k]-39), (cor+1), 77);
        }
        else 
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt((R[k]-39), (cor+8), 77);
        }
    }  
    //if the card is an ace, print an "A"
    else if (R[k] == 1 || R[k] == 14 || R[k] == 27 || R[k] == 40)
    {
        LCD.DrawRectangle((cor), 60, 30, 50);
        LCD.WriteAt("A", (cor+8), 77);
    }
    //if the card is a face card, print a letter instead of number value
    else if (R[k]>10 && R[k]<14 || R[k]>23 && R[k]<27 || R[k]>36 && R[k]<40 || R[k]>49 && R[k]<53)
    {
        //if the card is a jack, print a "J"
        if (R[k] == 11 || R[k] == 24 || R[k] == 37 || R[k] == 50)
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt("J", (cor+8), 77);
        }
        //if the card is a queen, print a "Q"
        else if (R[k] == 12 || R[k] == 25 || R[k] == 38 || R[k] == 51)
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt("Q", (cor+8), 77);
        }
        //if the card is a kind, print a "K"
        else if (R[k] == 13 || R[k] == 26 || R[k] == 39 || R[k] == 52)
        {
            LCD.DrawRectangle((cor), 60, 30, 50);
            LCD.WriteAt("K", (cor+8), 77);
        }
    }
}
int Black::Sum(int k)
{
    //if the user's card is 2,3,4,5,6,7,8,9, or 10 in the first grouping of the deck, add that number
    if (R[k]>1 && R[k]<11)
    {
        sum = sum + R[k];
    }
    //if the user's card is 2,3,4,5,6,7,8,9, or 10 in the second grouping of the deck, add that number - 13
    else if (R[k]>14 && R[k]<24)
    {
        sum = sum + R[k] - 13;
    }
    //if the user's card is 2,3,4,5,6,7,8,9, or 10 in the third grouping of the deck, add that number - 26
    else if (R[k]>27 && R[k]<37)
    {
        sum = sum + R[k] - 26;
    }
    //if the user's card is 2,3,4,5,6,7,8,9, or 10 in the fourth grouping of the deck, add that number - 39
    else if (R[k]>40 && R[k]<50)
    {
        sum = sum + R[k] - 39;
    }
    //if the user's card is an ace, add 10 to the sum
    else if (R[k] == 1 || R[k] == 14 || R[k] == 27 || R[k] == 40)
    {
        sum = sum + 11;
    }
    //if the user's card is a face card, add 10 to the sum
    else if (R[k]>10 && R[k]<14 || R[k]>23 && R[k]<27 || R[k]>36 && R[k]<40 || R[k]>49 && R[k]<53)
    {
        sum = sum + 10;
    }
    return sum;
}
//Function that draws the screen when the user stands and displays their total
void Black::SS()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor(LCD.Green);
    LCD.WriteAt("Stand at ", 85, 120);
    LCD.WriteAt(sum, 190, 120);
    LCD.Update();
}
//Function that draws the table for the dealer's turn
void Black::ComTable()
{
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor(LCD.Black);
    LCD.WriteAt("CPU's Turn", 90, 10);
    LCD.Update();
}
//Function that sums the dealer's card values
int Black::SumCom(int k)
{
    //if the dealer's card is 2,3,4,5,6,7,8,9, or 10 in the first grouping of the deck, add that number
    if (R[k]>1 && R[k]<11)
    {
        sumc = sumc + R[k];
    }
    //if the dealer's card is 2,3,4,5,6,7,8,9, or 10 in the second grouping of the deck, add that number - 13
    else if (R[k]>14 && R[k]<24)
    {
        sumc = sumc + R[k] - 13;
    }
    //if the dealer's card is 2,3,4,5,6,7,8,9, or 10 in the third grouping of the deck, add that number - 26
    else if (R[k]>27 && R[k]<37)
    {
        sumc = sumc + R[k] - 26;
    }
    //if the dealer's card is 2,3,4,5,6,7,8,9, or 10 in the fourth grouping of the deck, add that number - 39
    else if (R[k]>40 && R[k]<50)
    {
        sumc = sumc + R[k] - 39;
    }
    //if the dealer's card is an ace, add 10 to the sum
    else if (R[k] == 1 || R[k] == 14 || R[k] == 27 || R[k] == 40)
    {
        sumc = sumc + 11;
    }
    //if the dealer's card is a face card, add 10 to the sum
    else if (R[k]>10 && R[k]<14 || R[k]>23 && R[k]<27 || R[k]>36 && R[k]<40 || R[k]>49 && R[k]<53)
    {
        sumc = sumc + 10;
    }
    return sumc;
}
//Function that uses the sum of the cards of the user and computer to decide who wins
void Black::Winner()
{
    //if the user exceeds 21, they automatically lose
    if (sum>21)
    {
        LCD.SetBackgroundColor(RED);
        LCD.Clear();
        LCD.SetFontColor(LCD.White);
        LCD.WriteAt("You Lose!", 95, 105);
        LCD.WriteAt("You went over 21", 60, 130);
        LCD.Update();
        loss++;
        money = money - 100; //Deduct 100 for losing
    }
    //if the dealer exceeds 21 but the user does not, user wins
    else if (sum<21 && sumc>21)
    {
        LCD.SetBackgroundColor(GREEN);
        LCD.Clear();
        LCD.SetFontColor(LCD.White);
        LCD.WriteAt("You Win!", 95, 105);
        LCD.Update();
        win++;
        money = money + 100; //Add 100 for winning
    }
    //if both sums are below 21 and the user has a greater sum than the dealer, they win
    else if (sum<21 && sumc<21 && sum>sumc)
    {
        LCD.SetBackgroundColor(GREEN);
        LCD.Clear();
        LCD.SetFontColor(LCD.White);
        LCD.WriteAt("You Win!", 95, 105);
        LCD.Update();
        win++;
        money = money + 100; //Add 100 for winning
    }
    //if both sums are below 21 and the dealer has a greater sum than the user, dealer wins
    else if (sum<21 && sumc<21 && sum<sumc)
    {
        LCD.SetBackgroundColor(RED);
        LCD.Clear();
        LCD.SetFontColor(LCD.White);
        LCD.WriteAt("You Lose!", 95, 105);
        LCD.Update();
        loss++;
        money = money - 100; //Deduct 100 for losing
    }
    //if the user's sum is equal to 21 and the dealer is greater or less than 21, user wins
    else if (sum==21 && (sumc>21 || sumc<21))
    {
        LCD.SetBackgroundColor(GREEN);
        LCD.Clear();
        LCD.SetFontColor(LCD.White);
        LCD.WriteAt("You Win!", 95, 105);
        LCD.WriteAt("21", 105, 130);
        LCD.Update();
        win++;
        money = money + 100; //Add 100 for winning
    }
    //if both the user and the dealer's sum are equal to 21, it is a tie
    else if (sum==21 && sumc==21)
    {
        LCD.SetBackgroundColor(GRAY);
        LCD.Clear();
        LCD.SetFontColor(LCD.White);
        LCD.WriteAt("Tie!", 105, 105);
        LCD.Update();
        tie++;
    }
    //if the user is less than 21 and the dealer's sum is 21, dealer wins
    else if (sum<21 && sumc==21)
    {
        LCD.SetBackgroundColor(RED);
        LCD.Clear();
        LCD.SetFontColor(LCD.White);
        LCD.WriteAt("You Lose!", 95, 105);
        LCD.Update();
        loss++;
        money = money - 100; //Deduct 100 for losing
    }
    //if the user and dealer sums are less than 21 and equal, it is a tie
    else if (sum<21 && sumc<21 && sum==sumc)
    {
        LCD.SetBackgroundColor(GRAY);
        LCD.Clear();
        LCD.SetFontColor(LCD.White);
        LCD.WriteAt("Tie!", 105, 105);
        LCD.Update();
        tie++;
    }
}
int main()
{
    //declare variables for allowing misclicks on buttons and jumping out of while loops
    int r1, r2, r3;
    //declare variables for jumping out of loops of the user and dealer's turns
    int i, i2;
    //declare and initialize variable for incrementing by 1 when each card of the deck is dealt
    int k = 0;
    //declare variable for spacing the cards on the screen each time they are dealt
    int cor;
    //declare variable for clicking the screen
    float x, y;
    //create object "B"
    Black B;
    B.StartMenu(); //display menu
    while (1)
    {
        LCD.Update();
        while (!LCD.Touch(&x,&y)){}
        while (LCD.Touch(&x,&y)){}

        if (x>0 && x<320 && y>0 && y<240)
        {
            B.Menu(); //main menu
            while (1)
            {
                while (!LCD.Touch(&x,&y)){}
                while (LCD.Touch(&x,&y)){}
                if (x>170 && x<240 && y>155 && y<195) //execute if "play" button is pressed
                {
                    //Display table screen, deal card on screen, sum cards, increment "k"
                    cor = 10;
                    B.Table();
                    k++;
                    B.DealCard(k, cor);
                    B.Sum(k);
                    cor = cor + 35;

                    //Deal card, increment "k", sum cards
                    k++;
                    B.DealCard(k, cor);
                    B.Sum(k);

                    //intializie variables that are used to jump out of loops when user or dealer's turn is over
                    i = 1;
                    i2 = 1;
                    while (i == 1)
                    {
                        while (!LCD.Touch(&x,&y)){}
                        while (LCD.Touch(&x,&y)){}
                        if (x>95 && x<145 && y>175 && y<215) //Execute if user presses "hit" button
                        {
                            //Increment "k" and "cor", deal card, sum cards
                            k++;
                            cor = cor + 35;
                            B.DealCard(k, cor);
                            B.Sum(k);

                            if (B.sum>21) //End user's turn if they exceed sum of 21
                            {
                                Sleep(2.0);
                                i = 0;
                            }
                        }
                        else if (x>165 && x<235 && y>175 && y<215) //Execute if user presses "stand" button
                        {
                            //initalize "cor" again because cards will now be printed onto the computer's table screen
                            cor = 10;
                            i = 0;
                            B.SS(); //Display that the user "stood" and the value they "stood" at
                            Sleep(2.0);
                            B.ComTable(); //Display computer's table screen

                            //Increment "k", deal card, sum cards
                            k++;
                            B.DealCard(k, cor);
                            Sleep(1.5);
                            B.SumCom(k);
                           
                            //Increment "k" and "cor", deal card, sum cards
                            k++;
                            Sleep(1.5);
                            cor = cor + 35;
                            B.DealCard(k, cor);
                            B.SumCom(k);
                           
                            Sleep(2.0);

                            //while loop for computer to decide to hit or stand
                            while ((B.sum>=B.sumc) && i2==1)
                            {
                                if (B.sum>B.sumc) //deal card, sum cards, and increment "k" and "cor" if user sum is greater
                                {                 //than computer sum
                                    cor = cor + 35;
                                    k++;
                                    B.DealCard(k, cor);
                                    B.SumCom(k);
                                    Sleep(1.5);
                                }
                                else if (B.sum==B.sumc) //if sums are equal, computer needs to decide to try and win or stick with a tie
                                {
                                    if (B.sum>=17) //if user sum is greater or equal to 17, leave loop and settle for a tie
                                    {
                                        i2 = 0;
                                    }
                                    else if (B.sum<17) //if user sum is less than 17, computer tries to win
                                    {
                                        //increment "k" and "cor", deal card, sum cards
                                        k++;
                                        cor = cor + 35;
                                        B.DealCard(k, cor);
                                        B.SumCom(k);
                                        Sleep(1.5);
                                    }
                                }
                            }
                        }  
                    }
                    //Call winner function to decide the winner of the hand
                    B.Winner();
                    Sleep(3.0);
                    //Display main menu
                    B.Menu();
                    //Reset the sum values for the user and CPU
                    B.sum = 0;
                    B.sumc = 0;
                }
                else if (x>70 && x<140 && y>155 && y<195) //execute if "stats" button is pressed
                {
                    //call stats function
                    B.Stats();
                    //initialize "r1"
                    r1 = 1;
                    while (r1 == 1)
                    {
                        while (!LCD.Touch(&x,&y)){}
                        while (LCD.Touch(&x,&y)){}
                        if (x>8 && x<60 && y>8 && y<33) //execute if "back" button is pressed
                        {
                            r1 = 0; //jump out of loop
                            B.Menu(); //return back to main menu
                           
                        }
                    }
                }
                else if (x>190 && x<280 && y>85 && y<125) //execute if "credits" button is pressed
                {
                    //Call credits function
                    B.Credits();
                    //initialize "r2"
                    r2 = 1;
                    while (r2 == 1)
                    {
                        while (!LCD.Touch(&x,&y)){}
                        while (LCD.Touch(&x,&y)){}
                        if (x>8 && x<60 && y>8 && y<33) //execute if "back" button is pressed
                        {
                            B.Menu(); //return back to main menu
                            r2 = 0; //jump out of loop
                        }
                    }
                }
                else if (x>30 && x<180 && y>85 && y<125) //execute if "instructions" button is pressed
                {
                    //call instructions function
                    B.Instructions();
                    //initialize "r3"
                    r3 = 1;
                    while (r3 == 1)
                    {
                        while (!LCD.Touch(&x,&y)){}
                        while (LCD.Touch(&x,&y)){}
                        if (x>8 && x<60 && y>8 && y<33) //execute if "back" button is pressed
                        {
                            B.Menu(); //return back to main menu
                            r3 = 0; //jump out of loop
                     
                        }
                    }
                }
            }
        }
    }

    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}
