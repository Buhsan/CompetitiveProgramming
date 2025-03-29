
java.util.Scanner;

public class Laboratory {
  public static int PHYSICS = 1, CHEMISTRY = 2, BIOLOGY = 3, CAPASITY = 40;

  private Place[] places;
  private int occupied;

  public Laboratory(){
    occupied = 0;
    places = new Place[CAPASITY];
  }

  public int search(String s){
    for(int i = 0; i < CAPASITY; i++){
      if(places[i].getStudent().equals(s)){return i;}
    }
    return -1;
  }

  public boolean add(String s, int type){
    Place aux = new Place(s, type, new DateTime());
    int id = search(s);
    if(id != -1 || occupied == CAPASITY) return false;
    else{
      this.places[id] = aux;
      occupied++;
    }
  }

  public boolean remove(String s){
    int id = search(s);
    if(id == -1) return false;
    else{
      places[id] = null;
      for(int i = id; i<CAPASITY-1; i++){
        this.places[i] = this.places[i+1];
        this.places[i+1] = null;
      }
    }
    return true;
    // 0 1 3 4 null 
  }

  public int numPlacesWithActivity(int type){
    int cnt = 0;
    for(int i = 0; i < CAPASITY; i++){
      if(places[i] != null && places[i].getType() == type) cnt++;
    }
    return cnt;
  }

  public Place[] placeWithActivity(int type) {
    Place[] pl = new Place[numPlacesWithActivity(type)];
    int id = 0;
    for(int i = 0; i<CAPASITY; i++){
      if(places[i] != null && places[i].getType() == type){ pl[id] = places[i]; id++; }
    }
  }

  public string toString(){
    if(occupied == 0){
      return "No places occupied";
    }
    for(int i = 0; i<CAPASITY; i++) {
      if (places[i] != null){
        string res = "Student: " + places[i].getStudent() + " - Activity: ";
        switch (places[i].getType()) {
          case PHYSICS:{
            res += "Physics";
            break;
          } 
          case BIOLOGY:{
            res += "Biology";
            break;
          }
          case CHEMISTRY:{
            res += "Chemistry";
            break;
          }
          default:
            break;
        }
        res += "\n";
      }
    }
    return s;
  }

  public static double media(Scanner kb, int n){
    double v = kb.getDouble();
    double res = 0.0;
    for (int i = 2; i <= n; i++) {
      double val = kb.getDouble();
      res = ((i-1) * v + val) / i;
      v = val;
    }
    return res;
  }

  public static int[] freq(String[] a, String[] b) {
    int[] result = new int[a.length()];
    for(int i = 0; i < a.length()) {
      int cnt = 0;
      for (int j = 0; j < b.length(), j++) {
        if(a[i].equals(b[i])) cnt++;
      }
      result[i] = cnt;
    }
  }
}

