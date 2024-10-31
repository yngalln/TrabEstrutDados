#include <iostream>
#include <vector>
using namespace std;

void inserir(vector<int>& v, int e) {
    if (v.size() >= 40) {
        cout << "ERRO: Lista cheia." << endl;
    } else {
        v.push_back(e);
    }
}

void percorrer(const vector<int>& v) {
    for (int num : v)
        cout << num << " ";
    cout << endl;
}

bool troca(vector<int>& v, int a, int b) {
    swap(v[a], v[b]);
    return true;
}

int ordenaBolha(vector<int>& v) {
    bool trocou = true;
    int aux = 6;
    while (trocou) {
        trocou = false;
        aux += 2;
        for (int i = 0; i < v.size() - 1; i++) {
            aux += 3;
            if (v[i] > v[i + 1]) {
                trocou = troca(v, i, i + 1);
                aux += 5;
            }
        }
    }
    return aux;
}

int ordenaSelecao(vector<int>& v) {
    int aux = 4;
    for (int j = 0; j < v.size() - 1; j++) {
        aux += 2;
        int menor = j;
        aux += 1;
        for (int i = j + 1; i < v.size(); i++) {
            aux += 3;
            if (v[i] < v[menor]) {
                menor = i;
                aux += 1;
            }
        }
        troca(v, j, menor);
        aux += 5;
    }
    return aux;
}

int ordenaInsercao(vector<int>& v) {
    int aux = 3;
    for (int j = 1; j < v.size(); j++) {
        aux += 2;
        for (int i = j; i > 0 && v[i - 1] > v[i]; i--) {
            aux += 4;
            troca(v, i, i - 1);
            aux += 5;
        }
    }
    return aux;
}

void quicksort(vector<int>& values, int began, int end, int& passos) {
    if (began >= end) return;
    
    int i = began, j = end - 1, pivo = values[(began + end) / 2];

    while (i <= j) {
        while (values[i] < pivo) {
            i++;
            passos++;
        }
        while (values[j] > pivo) {
            j--;
            passos++;
        }
        if (i <= j) {
            troca(values, i, j);
            i++;
            j--;
            passos++;
        }
    }

    quicksort(values, began, j + 1, passos);
    quicksort(values, i, end, passos);
}

int main() {
    vector<int> v, v2, v3, v4;
    int passos = 0, temp;

    cout << "\nRotina de leitura da colecao:\n";
    for (int i = 0; i < 10; i++) {
        int num;
        cout << "Digite um numero: ";
        cin >> num;
        inserir(v, num);
        inserir(v2, num);
        inserir(v3, num);
        inserir(v4, num);
    }

    cout << "\n Insert Sort";
    cout << "\n Imprimindo antes de ordenar C1: ";
    percorrer(v);
    temp = ordenaInsercao(v);
    cout << "Imprimindo depois de ordenar C1: ";
    percorrer(v);
    cout << "Precisei de " << temp << " operacoes para ordenar...\n";

    cout << "\n Select Sort";
    cout << "\n Imprimindo antes de ordenar C2: ";
    percorrer(v2);
    temp = ordenaSelecao(v2);
    cout << "Imprimindo depois de ordenar C2: ";
    percorrer(v2);
    cout << "Precisei de " << temp << " operacoes para ordenar...\n";

    cout << "\n Bubble Sort";
    cout << "\n Imprimindo antes de ordenar C3: ";
    percorrer(v3);
    temp = ordenaBolha(v3);
    cout << "Imprimindo depois de ordenar C3: ";
    percorrer(v3);
    cout << "Precisei de " << temp << " operacoes para ordenar...\n";

    cout << "\n Quick Sort";
    cout << "\n Imprimindo antes de ordenar C4: ";
    percorrer(v4);
    quicksort(v4, 0, v4.size(), passos);
    cout << "Imprimindo depois de ordenar C4: ";
    percorrer(v4);
    cout << "Precisei de " << passos << " operacoes para ordenar...\n";

    cout << "Pressione Enter para continuar...";
    cin.ignore();
    cin.get();

    return 0;
}
