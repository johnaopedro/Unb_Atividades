#include <bits/stdc++.h>
using namespace std;
void ler_dados(int &num_processos, vector<int> &quantidade_tarefas, queue<pair<int, queue<int>>> &processos){
    cin >> num_processos; quantidade_tarefas.resize(num_processos);
    for (auto &tarefa : quantidade_tarefas) cin >> tarefa;
    for (int i = 0; i < num_processos; i++){
        queue<int> tarefas;
        while (quantidade_tarefas[i]--){
            int tempo;cin >> tempo;tarefas.emplace(tempo);}
        processos.emplace(i + 1, tarefas);}}
int execucao(queue<pair<int, queue<int>>> &processos){
    int tempo_total = 0;
    while (!processos.empty()){
        auto &[id_processo, fila_tarefas] = processos.front();
        while (!fila_tarefas.empty()){
            auto &tempo_tarefa = fila_tarefas.front();
            if (tempo_tarefa){
                tempo_tarefa = 0;
                break;}
            fila_tarefas.pop();
            tempo_total += 10;}
        if (fila_tarefas.empty()) cout << id_processo << " (" << tempo_total << ")\n";
        else processos.emplace(id_processo, fila_tarefas);
        processos.pop();}
    return tempo_total;}
int main(){
    int num_processos; vector<int> quantidade_tarefas; queue<pair<int, queue<int>>> processos;
    ler_dados(num_processos, quantidade_tarefas, processos);
    execucao(processos);
    return 0;}