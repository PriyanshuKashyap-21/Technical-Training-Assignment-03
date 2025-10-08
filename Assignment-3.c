
//1. Struct for Employee Details

#include <stdio.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee e[3];
    for (int i = 0; i < 3; i++) {
        printf("Enter ID, Name, Salary: ");
        scanf("%d %s %f", &e[i].id, e[i].name, &e[i].salary);
    }
    printf("\nEmployee Details:\n");
    for (int i = 0; i < 3; i++)
        printf("%d %s %.2f\n", e[i].id, e[i].name, e[i].salary);
}


//2. Union Demo

#include <stdio.h>
union Data {
    int i;
    float f;
};

int main() {
    union Data d;
    d.i = 10;
    printf("Integer: %d\n", d.i);
    d.f = 5.5;
    printf("Float: %.2f\n", d.f);
    printf("After assigning float, integer becomes: %d\n", d.i);
}


//3. Swap Two Integers Using Pointers

#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
int main() {
    int x=5, y=10;
    swap(&x,&y);
    printf("x=%d y=%d", x, y);
}


//4. Double Pointer for 2D Array

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows=2, cols=3;
    int **a = malloc(rows * sizeof(int*));
    for(int i=0;i<rows;i++) a[i]=malloc(cols*sizeof(int));

    printf("Enter elements:\n");
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            scanf("%d",&a[i][j]);

    printf("Matrix:\n");
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}


//5. Call by Value (Swap Fails)

#include <stdio.h>
void swap(int a, int b) {
    int t=a; a=b; b=t;
    printf("Inside swap: a=%d b=%d\n", a, b);
}
int main() {
    int x=5, y=10;
    swap(x,y);
    printf("After swap: x=%d y=%d (unchanged)\n", x, y);
}


//6. Call by Reference (Swap Works)

#include <stdio.h>
void swap(int *a, int *b) {
    int t=*a; *a=*b; *b=t;
}
int main() {
    int x=5, y=10;
    swap(&x,&y);
    printf("After swap: x=%d y=%d\n", x, y);
}


//7. Nested Function Simulation (Helper + Pointer)

#include <stdio.h>
void inner(int x) { printf("Inner Function: %d\n", x*x); }
void outer(void (*f)(int), int val) {
    printf("Outer Function calling inner:\n");
    f(val);
}
int main() { outer(inner, 5); }


//8. Function Returning Maximum

#include <stdio.h>
int findMax(int a[], int n) {
    int max = a[0];
    for(int i=1;i<n;i++)
        if(a[i]>max) max=a[i];
    return max;
}
int main() {
    int a[]={5,9,3,7};
    printf("Max = %d", findMax(a,4));
}


//9. Pointer Passed to Function

#include <stdio.h>
void change(int *x) { *x += 10; }
int main() {
    int val = 5;
    change(&val);
    printf("Value changed to %d", val);
}


//10. Struct with Pointer in Function

#include <stdio.h>
struct Box { int *ptr; };

void modify(struct Box *b) {
    *(b->ptr) = 100;
}

int main() {
    int x=10;
    struct Box b; b.ptr=&x;
    modify(&b);
    printf("Modified value: %d", x);
}


//11. Pointer Arithmetic in Array

#include <stdio.h>
int main() {
    int a[]={10,20,30,40,50}, *p=a;
    for(int i=0;i<5;i++)
        printf("%d ", *(p+i));
}


//12. Dynamic Struct Allocation

#include <stdio.h>
#include <stdlib.h>

struct Book { char title[50], author[50]; float price; };

int main() {
    struct Book *b = malloc(5*sizeof(struct Book));
    for(int i=0;i<5;i++)
        scanf("%s %s %f", b[i].title, b[i].author, &b[i].price);
    printf("\nBooks:\n");
    for(int i=0;i<5;i++)
        printf("%s %s %.2f\n", b[i].title, b[i].author, b[i].price);
}


//13. Function Returning Pointer to Largest Element

#include <stdio.h>
int* largest(int a[], int n) {
    int *max = &a[0];
    for(int i=1;i<n;i++)
        if(a[i]>*max) max=&a[i];
    return max;
}
int main() {
    int a[]={4,8,2,9,5};
    printf("Largest = %d", *largest(a,5));
}


//14. Array of Pointers to Strings

#include <stdio.h>
int main() {
    char *names[5];
    char temp[50];
    for(int i=0;i<5;i++){
        names[i]=malloc(50);
        printf("Enter name %d: ", i+1);
        scanf("%s", names[i]);
    }
    printf("\nNames:\n");
    for(int i=0;i<5;i++) printf("%s\n", names[i]);
}


//15. Pointer to Struct (Car Example)

#include <stdio.h>
struct Car { char model[30]; int year; float price; };

int main() {
    struct Car c = {"Tesla", 2022, 65000};
    struct Car *p = &c;
    p->price = 70000;
    printf("Model:%s Year:%d Price:%.2f", p->model, p->year, p->price);
}


//16. Struct Containing Union

#include <stdio.h>
union Value { int i; float f; };
struct Item { char type; union Value v; };

int main() {
    struct Item x;
    x.type='i'; x.v.i=10;
    printf("Integer: %d\n", x.v.i);
    x.type='f'; x.v.f=5.5;
    printf("Float: %.2f\n", x.v.f);
}


//17. Function Pointer for Arithmetic

#include <stdio.h>
int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}

int main() {
    int (*op)(int,int);
    int a,b,choice;
    printf("Enter a b: "); scanf("%d %d",&a,&b);
    printf("1.Add 2.Sub 3.Mul: "); scanf("%d",&choice);
    if(choice==1) op=add;
    else if(choice==2) op=sub;
    else op=mul;
    printf("Result=%d", op(a,b));
}


//18. Sum of All Elements in 2D Array

#include <stdio.h>
int sum2D(int a[2][3]) {
    int sum=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            sum+=a[i][j];
    return sum;
}
int main() {
    int a[2][3]={{1,2,3},{4,5,6}};
    printf("Sum=%d", sum2D(a));
}


//19. Recursive Factorial Using Pointer

#include <stdio.h>
void fact(int n, int *res) {
    if(n==0) *res=1;
    else { fact(n-1,res); *res = *res * n; }
}
int main() {
    int n=5, result;
    fact(n, &result);
    printf("Factorial=%d", result);
}


//20. Sort Students by Marks (Descending)

#include <stdio.h>
struct Student { char name[50]; int marks; };

int main() {
    struct Student s[3] = {{"A",80},{"B",95},{"C",70}};
    for(int i=0;i<2;i++)
        for(int j=i+1;j<3;j++)
            if(s[i].marks < s[j].marks) {
                struct Student t=s[i]; s[i]=s[j]; s[j]=t;
            }
    printf("Sorted by Marks:\n");
    for(int i=0;i<3;i++)
        printf("%s %d\n", s[i].name, s[i].marks);
}
