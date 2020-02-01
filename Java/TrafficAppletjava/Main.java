import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
   This applet displays a timed traffic signal.
*/

public class Main extends JApplet
{
   // Constants for the traffic signal
   public final int WIDTH = 300;
   public final int HEIGHT = 400;
   public final int X_TRAFFICLIGHT = WIDTH / 3;
   public final int Y_TRAFFICLIGHT = HEIGHT / 7;
   public final int TRAFFICLIGHT_WIDTH = WIDTH / 2;
   public final int TRAFFICLIGHT_HEIGHT = HEIGHT * 3 / 5;
   public final int LIGHT_DIAMETER =
                    TRAFFICLIGHT_HEIGHT / 5;
   public final int HOOD_START_ANGLE = 20;
   public final int HOOD_ANGLE_SWEPT = 140;
   public final int X_LIGHTS =
                    TRAFFICLIGHT_WIDTH /
                    3 + X_TRAFFICLIGHT;
   public final int Y_REDLIGHT =
                    TRAFFICLIGHT_HEIGHT /
                    10 + Y_TRAFFICLIGHT;
   public final int Y_ORANGELIGHT =
                    TRAFFICLIGHT_HEIGHT * 4 /
                    10 + Y_TRAFFICLIGHT;
   public final int Y_GREENLIGHT =
                    TRAFFICLIGHT_HEIGHT * 7 /
                    10 + Y_TRAFFICLIGHT;
   public final int TIME_DELAY = 1000;

   private String status = "green"; // Signal status
   
   public void init(){
     Timer timer = new Timer(TIME_DELAY, new TimerListener());
     timer.start();
   }
   
   private class TimerListener implements ActionListener{
    public void actionPerformed (ActionEvent evt)
    {
      switch(status)
      {
        case "green":
        {
         status = "orange";
         break;
        }
        
        case "orange":
        {
          status = "red";
          break;
        }
        
        case "red":
        {
          status = "green";
          break;
        }
      }
      
      repaint();
    }
   }
   public void paint(Graphics g)
   {
     g.setColor(Color.yellow);
     g.fillRect(WIDTH,HEIGHT,WIDTH,HEIGHT);
     g.drawRect(WIDTH,HEIGHT,WIDTH,HEIGHT);
   }
   
   
  public static void main(String[] args) {
   new Main.init();
  }
}