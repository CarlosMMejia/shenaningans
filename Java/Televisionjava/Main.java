/*
  The purpose of this class is to model a telivision
  Carlos Mejia 04/01/2019
*/

import java.util.Scanner;  // Needed for the Scanner class

public class Main
{
  private final String manufacturer; // brand name
  private final int screenSize; // size of the television screen
  private boolean powerOn; // true if the power is on, false it it is off
  private int channel; // value of the station that the television is showing
  private int volume; // number value representing loudness (0 being no sound)
  
  
  public Main (String m, int s) //Creates a new television object given brand name and screen size
  {
    manufacturer = m; screenSize = s; // assigns brand name and screen size
    powerOn = false; volume = 20; channel = 2; // default power, volume and channel
  }
  
  /**
  * Returns the volume of the television
  *
  * @return int - the volume of the television
  */
  public int getVolume(){return volume;}
  
  /**
  * Returns the channel of the television
  *
  * @return int - the channel of the television
  */
  public int getChannel() {return channel;}
  
  /**
  * Returns the brand name of the television
  *
  * @return String - the brand name of the television
  */
  public String getManufacturer() {return manufacturer;}
  
  /**
  * Returns the screen size of the television
  *
  * @return int - the screen size of the television
  */
  public int getScreenSize() {return screenSize;}
  
  /**
  * Assigns the channel of the television
  *
  * @param int - assigns integer to channel
  */
  public void setChannel (int c) {channel = c;}
  
  /** Switches the power of the television */
  public void power() {powerOn = !powerOn;}
  
  /** Increases the volume of the television by 1 */
  public void increaseVolume() {volume++;}
  
  /** Decreases the volume of the television by 1 */
  public void decreaseVolume() {volume--;}

  public static void main(String[] args)
  {
    // Create a Scanner object to read from the keyboard
    Scanner keyboard = new Scanner (System.in);

    // Declare variables
    int station;         // The user's channel choice

    // Declare and instantiate a television object
    Main bigScreen = new Main("Toshiba", 55);

    // Turn the power on
    bigScreen.power();

    // Display the state of the television
    System.out.println("A " + bigScreen.getScreenSize() + " inch " + bigScreen.getManufacturer() + " has been turned on.");

    // Prompt the user for input and store into station
    System.out.print("What channel do you want? ");
    station = keyboard.nextInt();

    // Change the channel on the television
    bigScreen.setChannel(station);

    // Increase the volume of the television
    bigScreen.increaseVolume();

    // Display the the current channel and
    // volume of the television
    System.out.println("Channel: " + bigScreen.getChannel() + " Volume: " + bigScreen.getVolume());
    System.out.println("Too loud! Lowering the volume.");

    // Decrease the volume of the television
    bigScreen.decreaseVolume();
    bigScreen.decreaseVolume();
    bigScreen.decreaseVolume();
    bigScreen.decreaseVolume();
    bigScreen.decreaseVolume();
    bigScreen.decreaseVolume();

    // Display the the current channel and
    // volume of the television
    System.out.println("Channel: " + bigScreen.getChannel() + " Volume: " + bigScreen.getVolume());

    System.out.println();   // For a blank line


    // Declare and instantiate a television object
    Main portable = new Main("Sharp", 19);

    // Turn the power on
    portable.power();

    // Display the state of the television
    System.out.println("A " + portable.getScreenSize() + " inch " + portable.getManufacturer() + " has been turned on.");

    // Prompt the user for input and store into station
    System.out.print("What channel do you want? ");
    station = keyboard.nextInt();

    // Change the channel on the television
    portable.setChannel(station);

    // Decrease the volume of the television
    portable.decreaseVolume();
    portable.decreaseVolume();

    // Display the the current channel and
    // volume of the television
    System.out.println("Channel: " + portable.getChannel() + " Volume: " + portable.getVolume());
  }
}