public class AlbumSheet{
  public static int MAX = 22;
  private String country;
  private Sticker[] players;
  private int occupied;
  private int[] roleCouter

  public AlbumSheet(String n){
    country = n;
    players = new Sticker[MAX + 1];
    occupied = 0;
    roleCouter = new int[Sticker.NUM_OF_ROLES + 1];
  }

  public Sticker addOrUpdate(Sticker s){
    int n = s.getNumber();
    if (players[n] == null) {
      players[n] = s;
      occupied++;
      roleCouter[s.getRole()]++;
      return null;
    }
    else {
      Sticker old = players[n];
      roleCouter[players[n].getRole()]--;
      players[n] = s;
      roleCouter[s.getRole()]++;
      return old:
    }
  }

  public Sticker getSticker(String name){
    for(int i = 1; i < MAX + 1; i++){
      if(players[i] != null && name.equals(players[i].getName())) return players[i];
    }
    return null;
  }

  public boolean remove(int number){
    if(players[number] == null) return false;
    else {
      occupied--;
      roleCouter[players[number].getRole]--;
      players[number] = null;
      return true;
    }
  }

  // public int getNumberRoles(int n){
  //   int cnt = 0;
  //   for (int i = 1; i < MAX+1; i++) {
  //     if(players[i] != null && players[i].getRole() == n) cnt++;
  //   }
  //   return cnt;
  // }

  public Sticker[] getPlayersOfRole(int role) {
    int num = roleCouter[role];
    Sticker[] pl = new Sticker[num];
    int cnt = 0;
    if (num == 0) return pl;
    else {
      for (int i = 1; i < MAX + 1; i++) {
        if (players[i] != null && players[i].getRole() == role) {
          pl[cnt] = players[i];
          cnt++;
        }
      }
    }
    return pl;
  }

  public String toString() {
    String res = "***" + country + "*** \n\n";
    for (int i = 1; i < MAX + 1; i++) {
      Sticker aux = players[i];
      if(aux != null) {
        res += aux.toString();
        String role;
        switch(aux.getRole()) {
          case GOALKEEPER: role = "Goalkeeper"; break;
          case MIDFIELDER: role = "Midfielder"; break;
          case FORWARD: role = "Forward"; break;
          case DEFENDER: role = "Defender"; break;
        }
        res += " " + role + "\n";
        // System.out.println(res);
      }
    }
  }

  public static harshad(int n) {
    int sum = 0;
    int a = n;
    while(a > 0) {
      sum += a%10;
      a /= 10;
    }
    return n%sum == 0;
  }

  public static void cancel(int[] a, int[] b) {
    for(int i = 0; i < b.length; i++) {
      for (int j = 0; j < a.length; j++) {
        if (b[i] == -a[j]) a[j] = 0;
     }
    }
  }
}

