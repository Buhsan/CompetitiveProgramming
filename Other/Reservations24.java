public class Reservation24 {
  public static int MAX_DAYS_IN_YEAR = 366;
  private Reservation[] schedule;
  private int[] numPerType;

  public Reservation24() {
    schedule = new Reservation[ MAX_DAYS_IN_YEAR + 1];
    numPerType = new int[3];
  }

  public addReservation(Reservation r) {
    if (r.getDt().getYear() == 2024 && schedule[r.getDt().getDayOfYear()] == null) {
      schedule[r.getDt().getDayOfYear()] = r;
      numPerType[r.getType()]++;
      return true;
    }
    return false;
  }

  public boolean removeReservation (int day) {
    if (day != 0 && day <= MAX_DAYS_IN_YEAR && schedule[day] != null) {
      numPerType[schedule[day].getType()]--;
      schedule[day] = null;
      return true;
    }
    return false;
  }

  public Reservation firstReservationLongerThan (int duration) {
    Reservation res = null;
    for (int i = 1; i < MAX_DAYS_IN_YEAR + 1; i++) {
      if (schedule[i] != null && schedule[i].getDuration() > duration) {res = schedule[i]; break;}
    }
    return res;
  }

  public Reservation[] reservationOfType (int type) {
    int n = numPerType[type];
    Reservation[] res = new Reservation[n];
    int cnt = 0;
    if (n != 0) {
      for (int i = 1; i < MAX_DAYS_IN_YEAR + 1; i++) {
        if (schedule[i] != null && schedule[i].getType() == type) {res[cnt++] = schedule[i];}
      }
    }
    return res;
  }

  public String reservationOf (String name) {
    String res = name + "\n";
    for (int i = 1; i< MAX_DAYS_IN_YEAR + 1; i++) {
      Reservation aux = schedule[i];
      if (aux!= null && aux.getName().equals(name)) {
        res += aux.getDt().toString();
        int t = aux.getType();
        switch(t){
          case Reservation.BASKETBALL: res += " - Basketball"; break;
          case Reservation.VOLLEYBALL: res += " - Volleyball"; break;
          default: res += " - Handball";
        }
        res += "\n";
      }
    }
    return res;
  }

  public static int pell (int n) {
    int res = 0;
    switch(n) {
      case 0: return 0;
      case 1: return 1;
      default: {
        int a = 0;
        int b = 1;
        for (int i = 2; i <= n; i++) {
          res = 2*b + a;
          a = b;
          b = res;
        }
        return res;
      }
    }
  }

  public static int [] freq (int[] a, int[] b) {
    int[] res = new int[b.length];
    for (int i = 0; i < b.length; i++) {
      for (int j = 0; j < a.length; j++) {
        if (b[i] == a[j]) res[i]++;
      }
    }
    return res;
  }

  
}
