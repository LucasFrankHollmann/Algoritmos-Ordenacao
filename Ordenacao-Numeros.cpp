#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int n, i, j=0;
long long OB, soma, media; //n = número de elementos que serão gerados nos vetores para
serem ordenados.
//OB = será usado para somar as operações
básicas realizadas.
clock_t tempo, t1, t2, t3, t4, t5, t6;
void troca(int *x, int *y)
{
int aux = *x;
*x = *y;
*y = aux;
}
void bubbleSort(int dados[], int n)
{
int i, j;
 for (i = 0; i < n - 1; i++)
for(j = n - 1; j > i; j--)
 {
OB++;
if (dados[j] < dados[j - 1])
{
OB=OB+3;
troca(&dados[j], &dados[j - 1]);
}
}
}
void shakerSort(int dados[], int n)
{
int trocou, i;
do
{
trocou = 0;
for (i = (n - 1); i > 0; i--)
{
OB++;
if(dados[i - 1] > dados[i])
 {
 OB=OB+3;
troca(&dados[i - 1], &dados[i]);
 trocou = 1;
 }
}
for (i = 1; i < n; i++)
{
OB++;
if (dados[i - 1] > dados[i])
{
OB=OB+3;
 troca(&dados[i - 1], &dados[i]);
 trocou = 1;
 }
 }
 } while (trocou);
}
void insertionSort(int dados[], int n)
{
int i;
 for (i = 1; i < n; i++)
 {
int aux = dados[i];
int j = 0;
 for (j = i; (j > 0) && (aux < dados[j-1]); j--)
 {
 OB++;
dados[j] = dados[j - 1];
 }
 dados[j] = aux;
 OB++;
 }
}
void selectionSort(int dados[], int n)
{
int i, j;
for (i = 0; i < (n - 1); i++)
{
 // encontra o menor elemento
int min = i;
for (j = i + 1; j < n; j ++)
{
OB++;
if (dados[j] < dados[min])
min = j;
}
 // Troca a posição atual com o menor elemento do vetor
 troca(&dados[min], &dados[i]);
 OB=OB+3;
 }
}
void merge(int V[], int low, int mid, int high)
{
int n1 = mid - low + 1;
int n2 = high - mid;
int left[n1 + 1], right[n2 + 1];
int i = 0, j = 0;
int x, y, k;
for (x = 0; x < n1; x++)
{
OB++;
left[x] = V[low + x];
}
for (y = 0; y < n2; y++)
{
OB++;
right[y] = V[mid + 1 + y];
}
OB=OB+2;
left[n1] = INT_MAX;
right[n2] = INT_MAX;
for (k = low; k <= high; k++)
{
OB++;
if (left[i] <= right[j])
{
OB++;
V[k] = left[i++];
}
else
{
OB++;
V[k] = right[j++];
}
}
}
void mergeSort(int V[], int low, int high)
{
if (low < high)
{
int mid = (low + high) / 2;
mergeSort(V, low, mid);
mergeSort(V, mid + 1, high);
merge(V, low, mid, high);
}
}
int partition(int V[], int low, int high)
{
 int pivot = V[low];
 int i = low - 1, j = high + 1;

 while (1)
 {
 do
{
 i++;
} while (V[i] < pivot);

 do
 {
 j--;
 } while (V[j] > pivot);
 if (i >= j)
 return j;
troca(&V[i], &V[j]);
 }
}
void quickSort(int V[], int low, int high)
{
 if (low < high)
 {
 int pi = partition(V, low, high);
 quickSort(V, low, pi);
 quickSort(V, pi + 1, high);
 }
}
int v1[100001], v2[100001], v3[100001], v4[100001], v5[100001], v6[100001], v7[100001];
int main ()
{
//n=10000;
scanf("%d", &n);
while(n<=100000)
{
printf("Tamanho - %d:\n", n);
soma=0;
//Geração do conjunto já ordenado.
for(i=1;i<=n;i++)
{
v1[i]=i;
}
//Geração do conjunto com os valores ordenados ao contrário.
for(i=n;i>0;i--)
{
j++;
v2[i]=j;
}
//Geração do conjunto aleatório.
srand(time(NULL));//inicio do algoritmo de geração de numeros aleatórios.
for(i=1;i<=n;i++)
{
v3[i]=rand();
}
for(i=1;i<=n;i++)
{
v4[i]=rand();
}
for(i=1;i<=n;i++)
{
v5[i]=rand();
}
for(i=1;i<=n;i++)
{
v6[i]=rand();
}
for(i=1;i<=n;i++)
{
v7[i]=rand();
}
tempo = clock();
OB=0;
quickSort(v1,0,n-1);
printf("OB1 %lld\n", OB);
tempo = clock()-tempo;
t1 = clock();
OB=0;
quickSort(v2,0,n-1);
printf("OB2 %lld\n", OB);
t1 = clock()-t1;
t2 = clock();
OB=0;
quickSort(v3,0,n-1);
printf("OB3 %lld\n", OB);
soma=soma+OB;
t2 = clock()-t2;
t3 = clock();
OB=0;
quickSort(v4,0,n-1);
printf("OB4 %lld\n", OB);
soma=soma+OB;
t3 = clock()-t3;
t4 = clock();
OB=0;
quickSort(v5,0,n-1);
printf("OB5 %lld\n", OB);
soma=soma+OB;
t4 = clock()-t4;
t5 = clock();
OB=0;
quickSort(v6,0,n-1);
printf("OB6 %lld\n", OB);
soma=soma+OB;
t5 = clock()-t5;
t6 = clock();
OB=0;
quickSort(v7,0,n-1);
printf("OB7 %lld\n", OB);
soma=soma+OB;
media = soma/5;
printf("Media %lld\n", media);
t6 = clock()-t6;
printf("Tempo gasto 1 = %f segundos\n", ((float)tempo) / CLOCKS_PER_SEC);
printf("Tempo gasto 2 = %f segundos\n", ((float)t1) / CLOCKS_PER_SEC);
printf("Tempo gasto 3 = %f segundos\n", ((float)t2) / CLOCKS_PER_SEC);
printf("Tempo gasto 4 = %f segundos\n", ((float)t3) / CLOCKS_PER_SEC);
printf("Tempo gasto 5 = %f segundos\n", ((float)t4) / CLOCKS_PER_SEC);
printf("Tempo gasto 6 = %f segundos\n", ((float)t5) / CLOCKS_PER_SEC);
printf("Tempo gasto 7 = %f segundos\n", ((float)t6) / CLOCKS_PER_SEC);
n=n+5000;
}
scanf("%d", &n);
return 0;
}
