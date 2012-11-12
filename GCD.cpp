#include <stdio.h>

//INPUT: Two non-negative integers a and b.
//OUTPUT: gcd(a, b).
int gcd(int a, int b)
{
  if (b == 0) return a;

  return gcd(b, a % b);
}

/*
Функция gcdext(int a, int b, int *d, int *x, int *y), приведенная ниже,
по входным числам a и b находит d = НОД(a, b) и такие x, y что d = a · x + b · y.
Для поиска неизвестных x и y необходимо рекурсивно запустить функцию gcdext(b, a mod b, d, x, y)
и пересчитать значения x и y по выше приведенной формуле. Рекурсия заканчивается,
когда b = 0. При b = 0 НОД(a, 0) = a и a = a · 1 + 0 · 0, поэтому полагаем x = 1, y = 0.
*/

//INPUT: Two non-negative integers a and b.
//OUTPUT: d = gcd(a, b) and integers x and y satifying ax + by = d.
void gcdext (int a, int b, int *d, int *x, int *y)
{
  int s;

  if (b == 0)
  {
    *d = a; *x = 1; *y = 0;
    return;
  }

  gcdExt(b,a % b,d,x,y);

  s = *y;

  *y = *x - (a / b) * (*y);

  *x = s;
}

int main()
{

}
