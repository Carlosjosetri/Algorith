#include <iostream>
using namespace std;

int main() {
    while(true){
    int n, m;
    cin >> n;
    cin >> m;
    if(m==0 && n==0){
        break;
    }
    int matrix[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int kanad[n];
    for (int k = 0; k < n; ++k) {
        kanad[k] = 0;
    }
    int res = 0;
    for (int r = 0; r < m; r++) {//posicion de R en la matriz

        for (int l = r; l < m; l++) {//posicion de L en la matriz
            //Los siguientes 2 for son para formar el arreglo que sera la suma de las columnas
            //aunque en este caso sera la cantidad de ceros
            int aux = 0;
            for (int i = 0; i < n; ++i) {

                for (int j = r; j <= l; ++j) {
                    if (matrix[i][j] != 0) {
                        kanad[i] = 0;
                        break;
                    } else {

                        kanad[i]++;
                    }

                }

                if (kanad[i] == 0) {
                    aux = 0;
                } else {
                    aux += kanad[i];
                }
                if (aux > res) {
                    res = aux;
                }
                kanad[i] = 0;
            }


        }
    }

    cout << res << endl;
}
    return 0;
}