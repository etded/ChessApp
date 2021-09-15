#include "qvector_functions.h"

QVector<int> VECTOR_SUM(QVector<int> X, QVector<int> Y)
{
    int i;
    QVector<int> Z(X.size());
    for (i = 0; i < X.size(); i++)
    {
        Z[i] = X[i] + Y[i];
    }
    return(Z);
}

QVector<QVector<int>> VECTOR_SUM(QVector<QVector<int>> X, QVector<QVector<int>> Y)
{
    QVector<QVector<int>> Z(X.size(), QVector<int>(X[0].size()));
    int i;
    int j;
    for (i = 0; i < X.size(); i++)
    {
        for (j = 0; j < X[0].size(); j++)
        {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
    return(Z);
}

QVector<int> VECTOR_SUB(QVector<int> X, QVector<int> Y)
{
    int i;
    QVector<int> Z(X.size());
    for (i = 0; i < X.size(); i++)
    {
        Z[i] = X[i] - Y[i];
    }
    return(Z);
}

int VECTOR_PRODUCT(QVector<int> X, QVector<int> Y)
{
    double product = 0;
    int i;
    for (i = 0; i < X.size(); i++)
    {
        product += X[i] * Y[i];
    }
    return(product);
}

QVector<int> VECTOR_PRODUCT(int k, QVector<int> X)
{
    QVector<int> Y(X.size());
    int i;
    for (i = 0; i < X.size(); i++)
    {
        Y[i] = k * X[i];
    }
    return(Y);
}

QVector<QVector<int>> VECTOR_PRODUCT(int k, QVector<QVector<int>> X)
{
    QVector<QVector<int>> Y(X.size(), QVector<int>(X[0].size()));
    int i;
    int j;
    for (i = 0; i < X.size(); i++)
    {
        for (j = 0; j < X[0].size(); j++)
        {
            Y[i][j] = k * X[i][j];
        }
    }
    return(Y);
}

void DISPLAY_VECTOR(QVector<int> X)
{
    int i;
    cout << "[";
    for (i = 0; i < X.size(); i++)
    {
        cout << X[i] << " ";
    }
    cout << "]" << endl;
}

void DISPLAY_VECTOR(QVector<QVector<int>> X)
{
    int i; int j;
    cout << "[" << endl;
    for (i = 0; i < X.size(); i++)
    {
        cout << "[";

        for (j = 0; j < X[0].size(); j++)
        {
            cout << X[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}
