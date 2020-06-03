#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
int n, i, j, p;
long long OB, soma, media; //n = número de elementos que serão gerados nos vetores para
serem ordenados.
//OB = será usado para somar as operações
básicas realizadas.
clock_t tempo, t1, t2, t3, t4, t5, t6;
void troca(char *x, char *y)
{
char aux = *x;
*x = *y;
*y = aux;
}
void bubbleSort(char dados[][200], int n)
{
int i, j;
 for (i = 0; i < n - 1; i++)
 for(j = n - 1; j > i; j--)
 {
OB++;
if (strcmp(dados[j],dados[j-1])<0)
{
OB=OB+3;
troca(dados[j], dados[j - 1]);
}
}
}
void reverseSort(char dados[][200], int n)
{
int i, j;
 for (i = 0; i < n - 1; i++)
 for(j = n - 1; j > i; j--)
 {
OB++;
if (strcmp(dados[j],dados[j-1])>0)
{
OB=OB+3;
troca(dados[j], dados[j - 1]);
}
}
}
void shakerSort(char dados[][200], int n)
{
int trocou=1, i;
while(trocou)
{
trocou = 0;
for (i = (n - 1); i > 0; i--)
{
OB++;
if(strcmp(dados[i-1],dados[i])>0)
 {
 OB=OB+3;
troca(dados[i-1], dados[i]);
trocou = 1;
 }
}
for (i = 1; i < n; i++)
{
OB++;
if(strcmp(dados[i-1],dados[i])>0)
{
//printf("1 %s\n", dados[i-1]);
//printf("2 %s\n", dados[i]);
OB=OB+3;
 troca(dados[i-1], dados[i]);
 //printf("3 %s\n", dados[i-1]);
//printf("4 %s\n", dados[i]);
 trocou = 1;
 }
 }
 //printf("a");
 }
}
void insertionSort(char dados[][200], int n)
{
int i;
 for (i = 1; i < n; i++)
 {
char aux[200];
*aux = *dados[i];
int j = 0;
 for (j = i; (j > 0) && (strcmp(aux,dados[j-1])<0); j--)
 {
 OB++;
*dados[j] = *dados[j - 1];
 }
 *dados[j] = *aux;
 OB++;
 }
}
void selectionSort(char dados[][200], int n)
{
int i, j;
for (i = 0; i < (n - 1); i++)
{
 // encontra o menor elemento
int min = i;
for (j = i + 1; j < n; j ++)
{
OB++;
if (strcmp(dados[j],dados[min])<0)
min = j;
}
 // Troca a posição atual com o menor elemento do vetor
 troca(dados[min], dados[i]);
 OB=OB+3;
 }
}
char left[1000001][200], right[100001][200];
void merge(char V[][200], int low, int mid, int high)
{
int n1 = mid - low + 1;
int n2 = high - mid;
int i = 0, j = 0;
int x, y, k;
for (x = 0; x < n1; x++)
{
OB++;
*left[x] = *V[low + x];
}
for (y = 0; y < n2; y++)
{
OB++;
*right[y] = *V[mid + 1 + y];
}
OB=OB+2;
left[n1][0] = 127;
right[n2][0] = 127;
for (k = low; k <= high; k++)
{
OB++;
if(strcmp(left[i],right[j])<0)
{
OB++;
*V[k] = *left[i++];
}
else
{
OB++;
*V[k] = *right[j++];
}
}
}
void mergeSort(char V[][200], int low, int high)
{
if (low < high)
{
int mid = (low + high) / 2;
mergeSort(V, low, mid);
mergeSort(V, mid + 1, high);
merge(V, low, mid, high);
}
}
int partition(char V[][200], int low, int high)
{
 char pivot[200];
 *pivot = *V[low];
 int i = low - 1, j = high + 1;
 
 while (1)
 {
 do
{
 i++;
} while (strcmp(V[i],pivot)<0);

 do
 {
 j--;
 } while (strcmp(V[j], pivot)>0);
 if (i >= j)
 return j;
troca(V[i], V[j]);
 }
}
void quickSort(char V[][200], int low, int high)
{
 if (low < high)
 {
 int pi = partition(V, low, high);
 quickSort(V, low, pi);
 quickSort(V, pi + 1, high);
 }
}
char v1[100002][200], v2[100002][200], v3[100002][200], v4[100002][200], v5[100002][200],
v6[100002][200], v7[100002][200];
int main ()
{
n=10000;
scanf("%d", &n);
while(n<=100000)
{
printf("Tamanho - %d:\n", n);
soma=0;
srand(time(NULL));//inicio do algoritmo de geração de numeros aleatórios.
for(i=1;i<=n;i++)
{
p=rand()%100;
p=p+1;
for(j=0;j<=p;j++)
{
if(j!=p)
v1[i][j]=97+rand()%26;
else
v1[i][j]='\0';
}
}
for(i=1;i<=n;i++)
{
p=rand()%100;
p=p+1;
for(j=0;j<=p;j++)
{
if(j!=p)
v2[i][j]=97+rand()%26;
else
v2[i][j]='\0';
}
}
for(i=1;i<=n;i++)
{
p=rand()%100;
p=p+1;
for(j=0;j<=p;j++)
{
if(j!=p)
v3[i][j]=97+rand()%26;
else
v3[i][j]='\0';
}
}
for(i=1;i<=n;i++)
{
p=rand()%100;
p=p+1;
for(j=0;j<=p;j++)
{
if(j!=p)
v4[i][j]=97+rand()%26;
else
v4[i][j]='\0';
}
}
for(i=1;i<=n;i++)
{
p=rand()%100;
p=p+1;
for(j=0;j<=p;j++)
{
if(j!=p)
v5[i][j]=97+rand()%26;
else
v5[i][j]='\0';
}
}
for(i=1;i<=n;i++)
{
p=rand()%100;
p=p+1;
for(j=0;j<=p;j++)
{
if(j!=p)
v6[i][j]=97+rand()%26;
else
v6[i][j]='\0';
}
}
for(i=1;i<=n;i++)
{
p=rand()%100;
p=p+1;
for(j=0;j<=p;j++)
{
if(j!=p)
v7[i][j]=97+rand()%26;
else
v7[i][j]='\0';
}
}
bubbleSort(v1,n+1);
reverseSort(v2,n+1);
tempo = clock();
OB=0;
quickSort(v1,0,n);
printf("OB1 %lld\n", OB);
tempo = clock()-tempo;
t1 = clock();
OB=0;
quickSort(v2,0,n);
printf("OB2 %lld\n", OB);
t1 = clock()-t1;
t2 = clock();
OB=0;
quickSort(v3,0,n);
printf("OB3 %lld\n", OB);
soma=soma+OB;
t2 = clock()-t2;
t3 = clock();
OB=0;
quickSort(v4,0,n);
printf("OB4 %lld\n", OB);
soma=soma+OB;
t3 = clock()-t3;
t4 = clock();
OB=0;
quickSort(v5,0,n);
printf("OB5 %lld\n", OB);
soma=soma+OB;
t4 = clock()-t4;
t5 = clock();
OB=0;
quickSort(v6,0,n);
printf("OB6 %lld\n", OB);
soma=soma+OB;
t5 = clock()-t5;
t6 = clock();
OB=0;
quickSort(v7,0,n);
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
//n=n+5000;
for(i=0;i<n;i++)
printf("%s\n", v2[i]);
scanf("%d", &n);
}
return 0;
}
