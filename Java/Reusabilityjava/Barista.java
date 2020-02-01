class Barista extends Person{
  double hours;
  double wage;
  double pay;

  Barista(String n, int a, char g, double h, double w)
  {
    super(n, a, g);
    hours = h;
    wage = w;
    pay = hours * wage;
  }

  void setHours(int h) {hours = h; pay = hours * wage;}

  void setWage(double w) {wage = w; pay = hours * wage;}

  double getPay() {return pay;}

  String getName() {return name;}
}