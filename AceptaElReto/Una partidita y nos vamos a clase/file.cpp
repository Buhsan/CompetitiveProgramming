#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define TESTCASES 1

void solve(int tt){
  int l, n;
  cin >> l >> n;

  vector<pair<int, int>> clases(n);

  int inicio = 8 * 60;
  int final = 14 * 60;

  for (int i = 0; i < n; i++) {
    string tiempo;
    cin >> tiempo;
    int duracion;
    cin >> duracion;

    int minutosTotales = stoi(tiempo.substr(0, 2)) * 60 + stoi(tiempo.substr(3, 2));
    clases[i] = make_pair(minutosTotales, duracion);
  }

  if (n == 0) {
    cout << (final - inicio >= l ? final - inicio : 0) << endl;
    return;
  }
  int tiempoAntesDeClase = clases[0].first - inicio;

  if (tiempoAntesDeClase < l) tiempoAntesDeClase = 0;

  int tiempoEntreClases = 0;
  for (int i = 0; i < n - 1; i++) {
    int tiempoEntreClase = clases[i + 1].first - (clases[i].first + clases[i].second);
    if (tiempoEntreClase >= l) {
      tiempoEntreClases += tiempoEntreClase;
    }
  }

  int tiempoDespuesDeClase = final - (clases[n - 1].first + clases[n - 1].second);
  if (tiempoDespuesDeClase < l) tiempoDespuesDeClase = 0;

  cout << (tiempoAntesDeClase + tiempoEntreClases + tiempoDespuesDeClase) << endl;



}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  if (TESTCASES) {
    int tt; cin >> tt;
    for (int i = 1; i < tt+1; i++) {
      solve(i);
    }
  } else solve(1);

  return 0;
}
