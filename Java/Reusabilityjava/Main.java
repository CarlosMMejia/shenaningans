import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Name: ");
    String n = sc.next();
    System.out.println("Age: ");
    int a = sc.nextInt();
    System.out.println("Gender: ");
    char g = sc.next().charAt(0);
    System.out.println("Hours worked: ");
    double h = sc.nextDouble();
    System.out.println("Hourly wage: ");
    double w = sc.nextDouble();

    Barista b = new Barista(n, a, g, h, w);

    System.out.print("Barista: " + b.getName());
    
    System.out.print("\t\tPay: " + b.getPay());

  }
}