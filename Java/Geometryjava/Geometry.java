/**@author Carlos Mejia*/

import java.util.Scanner;
import java.lang.Math;

/**
   This program demonstrates static methods
*/

public class Geometry
{
   public static void main(String[] args)
   {
      int choice;       // The user's choice
      double value = 0; // The method's return value
      char letter;      // The user's Y or N decision
      double radius;    // The radius of the circle
      double length;    // The length of the rectangle
      double width;     // The width of the rectangle
      double height;    // The height of the triangle
      double base;      // The base of the triangle
      double side1;     // The first side of the triangle
      double side2;     // The second side of the triangle
      double side3;     // The third side of the triangle

      // Create a scanner object to read from the keyboard
      Scanner keyboard = new Scanner(System.in);

      // The do loop allows the menu to be displayed first
      do
      {
         // TASK #1 Call the printMenu method
		printMenu();

         choice = keyboard.nextInt();

         switch(choice)
         {
            case 1:
               System.out.print("Enter the radius of " +
                                "the circle: ");
               radius = keyboard.nextDouble();

               value = circleArea(radius);

               System.out.println("The area of the " +
                                  "circle is " + value);
               break;
            case 2:
               System.out.print("Enter the length of " +
                                "the rectangle: ");
               length = keyboard.nextDouble();
               System.out.print("Enter the width of " +
                                "the rectangle: ");
               width = keyboard.nextDouble();

               value = rectangleArea(length, width);

               System.out.println("The area of the " +
                                  "rectangle is " + value);
               break;
            case 3:
               System.out.print("Enter the height of " +
                                "the triangle: ");
               height = keyboard.nextDouble();
               System.out.print("Enter the base of " +
                                "the triangle: ");
               base = keyboard.nextDouble();

               value = triangleArea(base, height);

               System.out.println("The area of the " +
                                  "triangle is " + value);
               break;
            case 4:
               System.out.print("Enter the radius of " +
                                "the circle: ");
               radius = keyboard.nextDouble();

               value = circleCircumference(radius);

               System.out.println("The circumference " +
                                  "of the circle is " +
                                  value);
               break;
            case 5:
               System.out.print("Enter the length of " +
                                "the rectangle: ");
               length = keyboard.nextDouble();
               System.out.print("Enter the width of " +
                                "the rectangle: ");
               width = keyboard.nextDouble();

               value = rectanglePerimeter(length, width);

               System.out.println("The perimeter of " +
                                  "the rectangle is " +
                                  value);
               break;
            case 6:
               System.out.print("Enter the length of " +
                                "side 1 of the " +
                                "triangle: ");
               side1 = keyboard.nextDouble();
               System.out.print("Enter the length of " +
                                "side 2 of the " +
                                "triangle: ");
               side2 = keyboard.nextDouble();
               System.out.print("Enter the length of " +
                                "side 3 of the " +
                                "triangle: ");
               side3 = keyboard.nextDouble();

               value = trianglePerimeter(side1, side2, side3);

               System.out.println("The perimeter of " +
                                  "the triangle is " +
                                  value);
               break;
            default:
               System.out.println("You did not enter " +
                                  "a valid choice.");
         }
         keyboard.nextLine(); // Consume the new line

         System.out.println("Do you want to exit " +
                            "the program (Y/N)?: ");
         String answer = keyboard.nextLine();
         letter = answer.charAt(0);

      } while(letter != 'Y' && letter != 'y');
   }

   // TASK #1 Create the printMenu method here
  
  /**
  * Displays the menu.
  * <p>
  * Takes no input from the user, just displays the 
  * different options the user can later choose from.
  * </p>
  */
 
   static void printMenu()
   {
     System.out.print("This is a geometry calculator\nChoose what you would like to calculate\n1.\tFind the area of a circle\n2.\tFind the area of a rectangle\n3.\tFind the area of a triangle\n4.\tFind the circumference of a circle\n5.\tFind the perimeter of a rectangle\n6.\tFind the perimeter of a triangle\nEnter the number of your choice: ");
   }
   
   // TASK #2 Create the value-returning methods here
   
  /**
  * Returns the area of a circle.
  * <p>
  * Takes the radius (of type double) of a circle
  * and returns pi * (radius)^2.
  * </p>
  *
  * @param  r - the radius of the circle.
  * @return double - the area of the circle.
  */
 
   static double circleArea(double r)
   {
     return Math.PI * Math.pow(r,2);
   }
   
  /**
  * Returns the area of a rectangle.
  * <p>
  * Takes the length and with (of type double) of a rectangle 
  * and returns length * width.
  * </p>
  *
  * @param  l - the length of the rectangle.
  * @param  w - the width of the rectangle.
  * @return double - the area of the rectangle.
  */
   
  static double rectangleArea(double l, double w)
  {
    return l * w;
  }
  
  /**
  * Returns the area of a triangle.
  * <p>
  * Takes the base and height (of type double) of a triangle 
  * and returns (base * height) / 2.
  * </p>
  *
  * @param  b - the base of the triangle.
  * @param  h - the height of the triangle.
  * @return double - the area of the triangle.
  */
   
  static double triangleArea(double b, double h)
  {
    return b * h / 2;
  }
  
  /**
  * Returns the circumference of a circle.
  * <p>
  * Takes the radius (of type double) of a circle
  * and returns 2 * pi * radius.
  * </p>
  *
  * @param  r - the radius of the circle.
  * @return double - the circumference of the circle.
  */
   
   static double circleCircumference(double r)
   {
     return 2 * Math.PI * r;
   }
   
  /**
  * Returns the perimeter of a rectangle.
  * <p>
  * Takes the length and with (of type double) of a rectangle 
  * and returns (length * 2) + (width * 2).
  * </p>
  *
  * @param  l - the length of the rectangle.
  * @param  w - the width of the rectangle.
  * @return double - the perimeter of the rectangle.
  */
   
   static double rectanglePerimeter(double l, double w)
   {
     return l * 2 + w * 2;
   }
   
  /**
  * Returns the perimeter of a triangle.
  * <p>
  * Takes the three sides (of type double) of a triangle 
  * and returns the sum of all three sides.
  * </p>
  *
  * @param  s1 - one side of the triangle.
  * @param  s2 - another side of the triangle.
  * @param  s3 - the remaining side of the triangle.
  * @return double - the perimeter of the triangle.
  */
   
   static double trianglePerimeter(double s1, double s2, double s3)
   {
     return s1 + s2 + s3;
   }
}