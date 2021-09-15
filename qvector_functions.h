#ifndef QVECTOR_FUNCTIONS_H
#define QVECTOR_FUNCTIONS_H

#include <QVector>
#include <iostream>
#include <cstdlib>

using namespace std;

QVector<int> VECTOR_SUM(QVector<int> X, QVector<int> Y);
QVector<QVector<int>> VECTOR_SUM(QVector<QVector<int>> X, QVector<QVector<int>> Y);
QVector<int> VECTOR_SUB(QVector<int> X, QVector<int> Y);
int VECTOR_PRODUCT(QVector<int> X, QVector<int> Y);
QVector<int> VECTOR_PRODUCT(int k, QVector<int> X);
QVector<QVector<int>> VECTOR_PRODUCT(int k, QVector<QVector<int>> X);
void DISPLAY_VECTOR(QVector<int> X);
void DISPLAY_VECTOR(QVector<QVector<int>> X);

#endif // QVECTOR_FUNCTIONS_H
