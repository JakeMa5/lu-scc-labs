package scc111.dice_java;

import java.util.random.RandomGenerator;

public class Dice 
{
    private int numSides;

    public Dice(int numSides) 
    {
        this.numSides = numSides;
    }

    public int Roll() 
    {
        RandomGenerator random = RandomGenerator.getDefault();
        return random.nextInt(1, numSides);
    }
}