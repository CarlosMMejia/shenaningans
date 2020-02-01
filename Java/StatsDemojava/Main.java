//Carlos Mejia

import java.util.Scanner;
import java.lang.Math;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileReader;
import java.io.BufferedReader;

/**
   This class reads numbers from a file, calculates the
   mean and standard deviation, and writes the results
   to a file.
*/

public class Main
{
   public static void main(String[] args) throws IOException
   {
      double sum = 0;      // The sum of the numbers
      int count = 0;       // The number of numbers added
      double mean = 0;     // The average of the numbers
      double stdDev = 0;   // The standard deviation
      String line;         // To hold a line from the file
      double difference = 0;   // The value and mean difference

      // Create an object of type Scanner
      Scanner keyboard = new Scanner (System.in);
      String filename;     // The user input file name

      // Prompt the user and read in the file name
      System.out.println("This program calculates " +
                         "statistics on a file " +
                         "containing a series of numbers");
      System.out.print("Enter the file name:  ");
      filename = keyboard.nextLine();

      // ADD LINES FOR TASK #4 HERE
      FileReader fr = new FileReader(filename);// Create a FileReader object passing it the filename
      BufferedReader br = new BufferedReader(fr);// Create a BufferedReader object passing FileReader object
      
      line = br.readLine();// Perform a priming read to read the first line of the file
      while(line != null)// Loop until you are at the end of the file
      {
        sum += Double.parseDouble(line);// Convert the line to a double value and add the value to sum
        count++;// Increment the counter
        line = br.readLine();// Read a new line from the file
      }
      
      br.close();// Close the input file
      mean = (double) sum/count;// Store the calculated mean

      // ADD LINES FOR TASK #5 HERE
      fr = new FileReader(filename);// Reconnect FileReader object passing it the filename
      br = new BufferedReader(fr);// Reconnect BufferedReader object passing FileReader object
      sum = 0;// Reinitialize the sum of the numbers
      count = 0;// Reinitialize the number of numbers added
      
      line = br.readLine();// Perform a priming read to read the first line of the file
      while(line != null)// Loop until you are at the end of the file
      {
        difference = Double.parseDouble(line) - mean;// Convert the line into a double value and subtract the mean
        sum += Math.pow(difference,2);// Add the square of the difference to the sum
        count++;// Increment the counter
        line = br.readLine();// Read a new line from the file
      }
      br.close();// Close the input file
      stdDev = Math.sqrt((double) sum/count);// Store the calculated standard deviation

      // ADD LINES FOR TASK #3 HERE
      FileWriter fw = new FileWriter("Results.txt");// Create a FileWriter object using "Results.txt"
      PrintWriter pw = new PrintWriter(fw);// Create a PrintWriter object passing the FileWriter object
      pw.print("Mean = ");
      pw.format("%.3f%n",mean);
      pw.print("\nStandard Deviation = ");
      pw.format("%.3f%n",stdDev);
      pw.close();// Close the output file
   }
}