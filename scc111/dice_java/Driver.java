package scc111.dice_java;

public class Driver
{
    public static void main(String[]args)
    {
        testGame("Player1", 6);
        testGame("Player2",4);
    }

    private static void testGame(String playerName,int numSides)
    {
        Dice sixSidedDice = new Dice(numSides);
        Player player=new Player(playerName);
        int guess=player.MakeGuess();
        int rollResult=sixSidedDice.Roll();
        displayResult(player.GetName(), guess,rollResult);
    }

    private static void displayResult(String playerName,int guess,int rollResult){
        if (guess==rollResult)
        {
            System.out.printf("Congratulations, %s!%d iscorrect. Youwin!\n",
            playerName,guess);
        }
        else
        {
            System.out.printf("Sorry, %s.%d is incorrect. The correct answer is %d. Tryagain!\n",
            playerName,guess,rollResult);
        }
    }
}