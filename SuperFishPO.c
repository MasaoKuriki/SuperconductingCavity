#include <stdio.h>
#include <math.h>

// 楕円の方程式のパラメータ
typedef struct {
    double a;
    double b;
} Ellipse;

// 判別式を計算する関数
double discriminant(double A, double B, double C) {
    return B * B - 4 * A * C;
}

// 楕円の接線の判別式に基づいて共通接線を見つける関数
void findCommonTangents(Ellipse e1, Ellipse e2) {
    double A, B, C, D;
    double d;
    
    // 2つの楕円のパラメータから A, B, C, D を計算
    A = e1.b * e1.b * e2.a * e2.a - e1.a * e1.a * e2.b * e2.b;
    B = 2 * (e1.b * e1.b * e2.a - e1.a * e1.a * e2.b);
    C = e1.b * e1.b - e1.a * e1.a;
    D = e2.a * e2.a - e2.b * e2.b;
    
    // 判別式を計算
    d = discriminant(A, B, C);
    
    // 判別式に基づいて共通接線を判定
    if (d < 0) {
        printf("共通接線は存在しません。\n");
    } else {
        double m1, m2, c1, c2;
        m1 = (-B + sqrt(d)) / (2 * A);
        m2 = (-B - sqrt(d)) / (2 * A);
        
        // 各傾きに対してy切片を計算
        c1 = sqrt(e1.b * e1.b * (1 + m1 * m1) - e1.a * e1.a);
        c2 = sqrt(e2.b * e2.b * (1 + m2 * m2) - e2.a * e2.a);
        
        printf("共通接線の傾き: %lf, %lf\n", m1, m2);
        printf("対応するy切片: %lf, %lf\n", c1, c2);
    }
}

int main() {
    Ellipse e1 = {3, 2}; // 楕円1のパラメータ
    Ellipse e2 = {4, 3}; // 楕円2のパラメータ
    
    findCommonTangents(e1, e2);
    
    return 0;
}
