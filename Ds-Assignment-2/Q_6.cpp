#include <iostream>
using namespace std;

void printMatrix(int row[], int col[], int val[], int n, string name)
{
    cout << "Matrix " << name << ":" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << row[i] << " " << col[i] << " "<< val[i]  << endl;
    }
    cout << endl;
}

void transpose(int row[], int col[], int val[], int n)
{
    cout << "Transpose of the matrix:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << col[i] << " " << row[i] << " " << val[i] << endl;
    }
    cout << endl;
}

void add(int row1[], int col1[], int val1[], int n1, int row2[], int col2[], int val2[], int n2)
{
    cout << "Addition of the two matrices:" << endl;
    int row[50];
    int col[50];
    int val[50];
    int count = 0;

    for(int i = 0; i < n1; i++)
    {
        row[count] = row1[i];
        col[count] = col1[i];
        val[count] = val1[i];
        count++;
    }

    for(int i = 0; i < n2; i++)
    {
        bool f = false;
        for(int j = 0; j < count; j++)
        {
            if(row[j] == row2[i] && col[j] == col2[i])
            {
                val[j] += val2[i];
                f = true;
                break;
            }
        }
        if(!f)
        {
            row[count] = row2[i];
            col[count] = col2[i];
            val[count] = val2[i];
            count++;
        }
    }

    for(int i = 0; i < count; i++)
    {
        cout <<  row[i] << " " << col[i] << " " << val[i]  << endl;
    }
    cout << endl;
}

void multiply(int row1[], int col1[], int val1[], int n1, int row2[], int col2[], int val2[], int n2)
{
    cout << "Multiplication of the two matrices:" << endl;
    int row[50];
    int col[50];
    int val[50];
    int count = 0;

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(col1[i] == row2[j])
            {
                int r = row1[i];
                int c = col2[j];
                int v = val1[i] * val2[j];

                bool f = false;

                for(int k = 0; k < count; k++)
                {
                    if(row[k] == r && col[k] == c)
                    {
                        val[k] += v;
                        f = true;
                        break;
                    }
                }

                if(!f)
                {
                    row[count] = r;
                    col[count] = c;
                    val[count] = v;
                    count++;
                }
            }
        }
    }

    for(int i = 0; i < count; i++)
    {
        cout  << row[i] << " " << col[i] << " "  << val[i]<< endl;
    }
    cout << endl;
}

int main()
{
    int row1[] = {0,1,2};
    int col1[] = {1,2,0};
    int val1[] = {5,8,3};
    int n1 = 3;

    int row2[] = {0,1,2};
    int col2[] = {1,2,0};
    int val2[] = {2,1,4};
    int n2 = 3;

    printMatrix(row1, col1, val1, n1, "A");
    printMatrix(row2, col2, val2, n2, "B");

    transpose(row1, col1, val1, n1);

    add(row1, col1, val1, n1, row2, col2, val2, n2);

    multiply(row1, col1, val1, n1, row2, col2, val2, n2);

    return 0;
}
