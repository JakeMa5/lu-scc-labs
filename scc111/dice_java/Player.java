package scc111.dice_java;

public class Player 
{
    private String name;

    public int MakeGuess() 
    {
        int guess;
        System.out.println("Enter your guess: ");
        guess = Integer.parseInt(System.console().readLine());
        return guess;
    }

    public Player(String name) 
    {
        this.name = name;
    }

    public String GetName() 
    {
        return name;
    }
}