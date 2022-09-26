#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int pocetLektvaru, pocetZavislosti, P, Q;
vector<int> casy, out;
vector<vector<int>> in;

vector<int> topologie() {
    queue<int> fronta;
    int aktualni;
    vector<int> casyVareni(pocetLektvaru+1, 0);
    // Pocatecni naplneni fronty
    for (int i = 1; i < pocetLektvaru; i++) if (out[i] == 0) fronta.push(i);
    while (not fronta.empty()) {
        aktualni = fronta.front();
        fronta.pop();
        for (int soused : in[aktualni]) {
            out[soused]--;
            casyVareni[soused] = max(casyVareni[soused], casyVareni[aktualni] + casy[aktualni]);
            if (out[soused] == 0) {
                fronta.push(soused);
            }
        }

    }
    return casyVareni;
}
int main() {
    cin >> pocetLektvaru >> pocetZavislosti;
    casy.resize(pocetLektvaru+1);
    out.resize(pocetLektvaru+1, 0);
    in.resize(pocetLektvaru+1, vector<int>());
    for (int i = 0; i < pocetLektvaru; i++)
        cin >> casy[i+1];
    for (int i = 0; i < pocetZavislosti; i++) {
        cin >> P >> Q;
        out[Q]++;
        in[P].push_back(Q);
    }
    auto poradi = topologie();
    for (int i = 1; i <= pocetLektvaru; i++)
        cout << poradi[i] << " ";
    return 0;
}
