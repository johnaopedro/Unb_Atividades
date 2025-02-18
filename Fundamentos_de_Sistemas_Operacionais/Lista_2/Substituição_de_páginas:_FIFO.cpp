#include <bits/stdc++.h>
using namespace std;
int fifo(size_t num_quadros, int num_referencias, const vector<int>& referencias){
    int faltas_de_pagina = 0; queue<int> fila; unordered_set<int> paginas_na_memoria;
    for (int i = 0; i < num_referencias; i++){
        int pagina = referencias[i];
        if (not paginas_na_memoria.count(pagina)){
            faltas_de_pagina++;
            if (fila.size() < num_quadros){
                fila.push(pagina);
                paginas_na_memoria.insert(pagina);
            } else{
                int pagina_antiga = fila.front();
                fila.pop();
                paginas_na_memoria.erase(pagina_antiga);
                fila.push(pagina);
                paginas_na_memoria.insert(pagina);}}}
    return faltas_de_pagina;}
void ler_entrada(size_t& num_quadros, int& num_referencias, vector<int>& referencias){
    cin >> num_quadros >> num_referencias; referencias.resize(num_referencias);
    for (int i = 0; i < num_referencias; i++) cin >> referencias[i];}
int main(){
    size_t num_quadros; int num_referencias; vector<int> referencias;
    ler_entrada(num_quadros, num_referencias, referencias);
    int resultado = fifo(num_quadros, num_referencias, referencias);
    cout << resultado << "\n";
    return 0;}