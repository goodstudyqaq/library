#include <bits/stdc++.h>
using namespace std;

/*
@brief Matrix
@docs docs/matrix.md
*/

typedef long long ll;
template <typename T = ll>
struct Matrix {
    int n, m;
    vector<vector<T>> mat;
    Matrix(int n, int m, const T& val = T()) : n(n), m(m), mat(n, vector<T>(m, val)) {}
    Matrix(int n, const T& val = T()) : n(n), m(n), mat(n, vector<T>(n, val)) {}
    Matrix(const vector<vector<T>>& mat) : n(mat.size()), m(mat[0].size()), mat(mat) {}

    static Matrix I(int n) {
        Matrix res(n);
        for (int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }

    vector<T>& operator[](int i) { return mat[i]; }

    Matrix operator+(const Matrix& r) const {
        assert(n == r.n && m == r.m);
        Matrix res(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) res[i][j] = mat[i][j] + r[i][j];
        return res;
    }

    Matrix operator-(const Matrix& r) const {
        assert(n == r.n && m == r.m);
        Matrix res(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) res[i][j] = mat[i][j] - r[i][j];
        return res;
    }

    Matrix operator*(const Matrix& r) const {
        assert(m == r.n);
        Matrix res(n, r.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < r.m; j++)
                for (int k = 0; k < m; k++) res[i][j] += mat[i][k] * r[k][j];
        return res;
    }

    Matrix operator^(ll k) const {
        assert(n == m);
        Matrix res = I(n), a = *this;
        while (k > 0) {
            if (k & 1) res = res * a;
            a = a * a;
            k >>= 1;
        }
        return res;
    }

    static to_string(const Matrix& mat) {
        string res = "";
        for (int i = 0; i < mat.n; i++) {
            for (int j = 0; j < mat.m; j++) res += to_string(mat[i][j]) + " ";
            res += "\n";
        }
        return res;
    }
};
template <typename T = ll>
struct Det : Matrix<T> {
    //行列式辗转相除法
    /*
    https://atcoder.jp/contests/abc253/tasks/abc253_h
    矩阵树定理：维护一个度数矩阵D 和一个邻接矩阵A，Kirchhoff矩阵= D - A，然后把最后一行和最后一列删掉，算行列式，就是树的个数。
    */
    T get() {
        assert(this->n == this->m);
        T res = 1;
        for (int i = 0; i < this->n; i++) {
            for (int j = i + 1; j < this->n; j++) {
                while (this->mat[j][i] != 0) {
                    T t = this->mat[i][i] / this->mat[j][i];
                    for (int k = i; k < this->n; k++) {
                        this->mat[i][k] -= this->mat[j][k] * t;
                        swap(this->mat[i][k], this->mat[j][k]);
                    }
                    res = -res;
                }
            }
            if (this->mat[i][i] == 0) return 0;
            res *= this->mat[i][i];
        }
        return res;
    }
};
