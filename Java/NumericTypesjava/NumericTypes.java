import java.util.Scanner;
import java.lang.Math.*;
/**
   This program demonstrates how numeric types and
   operators behave in Java.
*/

public class NumericTypes
{
   public static void main (String [] args)
   {
      Scanner keyboard = new Scanner(System.in);
      
     // Identifier declarations
    final int NUMBER = 2;
    final int SCORE1 = 100;
    final int SCORE2 = 95;
    final int BOILING_IN_F = 212; // Boiling temperature
    double fToC;
    double average;
    String output;
    // Temperature Celsius
    // Arithmetic average
    // Line of output
    // Number of scores
    // First test score
    // Second test score
     
  
    // TASK #2 declare variables used here
    String firstName, lastName, fullName;
    
    // TASK #3 declare variables used here
    char firstInitial;
    
    // TASK #4 declare variables used here
    double diameter, radius, volume;
    
    
    // Find an arithmetic average.
    average = (double) (SCORE1 + SCORE2) / NUMBER;
    output = SCORE1 + " and " + SCORE2 + " have an average of " + average;
    System.out.println(output);
    System.out.println();
    
    // Convert Fahrenheit temperature to Celsius.
    fToC = (double) 5/9 * (BOILING_IN_F - 32);
    output = BOILING_IN_F + " in Fahrenheit is " + fToC + " in Celsius.";
    System.out.println(output);
    System.out.println();
    
    // Concatenate First and Last names.
    System.out.print("Type First Name: ");
    firstName = keyboard.nextLine();
    System.out.println();
    System.out.print("Type Last Name: ");
    lastName = keyboard.nextLine();
    System.out.println();
    fullName = firstName + " " + lastName;
    System.out.println("Full Name: " + fullName);
    System.out.println();
    
    // ADD LINES FOR TASK #3 HERE
    firstInitial = firstName.charAt(0);// Get the first character from the user's first name
    System.out.println("First Name Initial: " + firstInitial);// Print out the user's first initial
    fullName = fullName.toUpperCase();// Convert the user's full name to uppercase
    System.out.println("Full Name Uppercaes: " + fullName);// Print out the user's full name in uppercase
    System.out.println("Full Name Length: " + fullName.length());
    System.out.println();
    
    // ADD LINES FOR TASK #4 HERE
    System.out.print("Enter diameter: ");
    diameter = keyboard.nextDouble();
    radius = diameter / 2;
    volume = (double) 4/3 * Math.PI * Math.pow(radius, 3);// Calculate the volume
    System.out.println("Volume: " + volume);
    }
}