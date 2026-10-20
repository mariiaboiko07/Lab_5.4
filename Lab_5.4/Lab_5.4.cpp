// Лабораторна робота № 5.4
// Варіант 1

#include <iostream>
#include <cmath>

using namespace std;

// 0. Ітераційний спосіб (для контролю)
double S0(const int K, const int N)
{
    double s = 0;
    for (int i = K; i <= N; i++)
        s += (1.0 * i * i) / (1.0 * K * K + 1.0 * N * N);
    return s;
}

// 1. Рекурсія на підйомі, параметр зростає (i++)
double S1(const int K, const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return (1.0 * i * i) / (1.0 * K * K + 1.0 * N * N) + S1(K, N, i + 1);
}

// 2. Рекурсія на підйомі, параметр спадає (i--)
double S2(const int K, const int N, const int i)
{
    if (i < K)
        return 0;
    else
        return (1.0 * i * i) / (1.0 * K * K + 1.0 * N * N) + S2(K, N, i - 1);
}

// 3. Рекурсія на спуску, параметр зростає (i++), накопичувач t
double S3(const int K, const int N, const int i, double t)
{
    t = t + (1.0 * i * i) / (1.0 * K * K + 1.0 * N * N);
    if (i >= N)
        return t;
    else
        return S3(K, N, i + 1, t);
}

// 4. Рекурсія на спуску, параметр спадає (i--), накопичувач t
double S4(const int K, const int N, const int i, double t)
{
    t = t + (1.0 * i * i) / (1.0 * K * K + 1.0 * N * N);
    if (i <= K)
        return t;
    else
        return S4(K, N, i - 1, t);
}

int main()
{
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "(iter)       S0 = " << S0(K, N) << endl;
    cout << "(rec up ++)   S1 = " << S1(K, N, K) << endl;
    cout << "(rec up --)   S2 = " << S2(K, N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << endl;
    cout << "(rec down --) S4 = " << S4(K, N, N, 0) << endl;

    return 0;
}