import java.util.Scanner;
/**This program will calculate gas mileage, 
given miles and gallons*/

public class Mileage {
  public static void main(String[] args) {
    double miles, gallons; //Declaring Doubles to store miles and respectively
    Scanner sc = new Scanner(System.in); //Declaring Scanner to be able to read input from user
    
    System.out.println("This program will calculate gas mileage, given miles and gallons");
    System.out.println();
    
    System.out.print("Enter number of miles driven: ");
    miles = sc.nextDouble(); //Read input from user (only integers and decimals)
    System.out.println(); //Blank line
    
    System.out.print("Enter number of gallons used: ");
    gallons = sc.nextDouble(); //Read input from user (only integers and decimals)
    System.out.println(); //Blank line
    
    System.out.print("Mileage = " + (miles/gallons) + "mpg"); //Calculate and print mileage
    
  }
}