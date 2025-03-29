#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

// Función para calcular el mayor número de monedas que se pueden usar
ll maxCoins(ll a, ll b, ll c, ll n) {
    ll maxCoins = 0;

    // Iterar sobre todas las combinaciones posibles de monedas de tipo a
    for (ll x = 0; x <= n / a; ++x) {
        for (ll y = 0; y <= (n - x * a) / b; ++y) {
            ll remaining = n - x * a - y * b;

            // Si lo que queda es divisible por c
            if (remaining % c == 0) {
                ll z = remaining / c;
                maxCoins = max(maxCoins, x + y + z);
            }
        }
    }

    return maxCoins;
}

int main() {
    ll a, b, c, n;
    ll t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> n;
        if (a <= 0 || b <= 0 || c <= 0 || n <= 0 || a >= 1e12 || b >= 1e12 || c >= 1e12 || n >= 1e12) {
            cout << "Los valores deben estar en el rango 0 < a,b,c,n < 1e12" << endl;
            return 1;
        }

        ll result = maxCoins(a, b, c, n);
        cout << "El mayor número de monedas que se pueden usar es: " << result << endl;
    }

    return 0;
}