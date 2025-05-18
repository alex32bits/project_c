#include <stdio.h>
/*
int v[10];  // tablou de solutii
int n;
int kk;

void afiseaza_solutia(int k)
{
    int i;
    for (i = 0; i <= k; i++)
    {
      printf("%d",v[i]);
 
    }
    printf("\n");
}

int valid(int k)
{
    int ones = 0;
    for (int i = 0; i <= k; i++)
    {
        if (v[i] == 1)
        {
            ones++;
        }
    }

    if (v[k] > 9 || v[k] < 0)
        return 0;

    if (v[0] == 0)
        return 0;

    if (k >= n)
        return 0;

    if (ones > kk)
        return 0;

    if (k == n - 1 && ones != kk)
        return 0;

    return 1;
}

int solutie(int k)
{
    if (k == n - 1)
        return 1;  //solutia cuprinde n-1 elemente
    return 0;
}

void back(int k)  //k pasul
{

    for (int i = 0; i <= 9; i++)  // parcurgem pe rand posibilitatile
    {
        v[k] = i;
        if (valid(k)) //daca posibilitatea  e acceptabila
            if (solutie(k))
                afiseaza_solutia(k);
            else

                back(k + 1);   // back(posibilitate_k+1)


    }
}   

int main(void)
{
    n = 3;
    kk = 2;
    back(0);
    return 0;
}
*/
/*
int v[10];
int n = 5;

void afisare(int k)
{
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int valid(int k)
{
    for (int i = 1; i < k; i++)

    {
        if (v[i] == v[k])
            return 0;
    }

    for (int i = 1; i <= k / 2; i++)
    {
        if (v[i] < v[i + 1])
            return 0;
    }
    for (int i = k / 2 + 1; i < k - 1; i++)
    {
        if (v[i] > v[i + 1])
            return 0;
    }
    if (v[k] > n || v[k] < 1)
        return 0;
    if (k > n)
        return 0;

    return 1;
}

int solutie(int k)
{

    if (k == n)
        return 1;
    else
        return 0;
}

void back(int k)
{
    for (int i = 1; i <= n; i++)
    {
        v[k] = i;
        if (valid(k))
            if (solutie(k))
                afisare(k);
            else
                back(k + 1);
    }
}

int main()
{
    back(1);
    return 0;
}
*/
int a[6];  // tablou de solutii
int pos[10] = { 1,2,3,4,5,6 };  //tabloul de culori
int n = 3;

void afiseaza_solutia()
{
    int i;
    for (i = 0; i < n; i++)
    {
        switch (a[i]) {
        case 1:
            printf(" alb ");
            break;
        case 2:
            printf(" galben ");
            break;
        case 3:
            printf(" rosu ");
            break;
        case 4:
            printf(" verde ");
            break;
        case 5:
            printf(" albastru ");
            break;
        case 6:
            printf(" negru ");
            break;

        }
    }
    printf("\n");
}

int acceptabil(int pos)
{
    //elementele din solutie trebuie sa fie unice
    if (pos > n - 1)
        return 0;
    if (pos == 1)
        if (a[pos] != 4 && a[pos] != 2)
            return 0;
    for (int i = 0; i < pos; i++)
    {
        if (a[i] == a[pos])
            return 0;
    }
    return 1;
}

int solutie(int k)
{
    if (k == n - 1)
        return 1;  //solutia cuprinde n-1 elemente
    return 0;
}

void permuta(int k)  //k pasul
{

    for (int i = 0; i < 6; i++)  // parcurgem pe rand posibilitatile
    {
        a[k] = pos[i];
        if (acceptabil(k)) //daca posibilitatea  e acceptabila
            if (solutie(k))
                afiseaza_solutia();
            else

                permuta(k + 1);   // back1(posibilitate_k+1)


    }
}   /*permuta*/

int main(void)
{

    permuta(0);
    return 0;
}

