#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "intVector.h"


// int main () {
//     int c, i, nw, no;
//     int arr[10]={0};
//     nw=no=0;
//     while ((c=getchar())!=EOF) {
//         if (c>='0' && c<='9') {
//             ++arr[c-'0'];
//         }
//         else if (c==' ' || c=='\n' || c=='\t') {
//             nw++;
//         }
//         else
//             no++;
//     }
//     printf("digits =");
//     for (int i=0; i<10; i++) {
//         printf(" %d ", arr[i]);
//     }
//     printf(", white spaces = %d, other = %d\n", nw, no);
//     return 0;
// }

// #include <stdio.h>
// #define MAXLINE 1000

// int takeline(char s[], int lim) {
//     int c, i;
//     for (int i=0; i<lim-1 && (c=getchar())!= EOF && c!='\n'; i++) {
//         s[i]=c;
//     }
//     if (c=='\n') {
//         i++;
//     }
//     s[i]='\0';
//     return i;
// }

// void copy(char to[], char from[]) {
//     int i=0;
//     while ((to[i]=from[i])!='0'){
//         i++;
//     }
// }

// int main () {
//     int len, max=0;
//     char line[MAXLINE];
//     char longest[MAXLINE];
//     while ((len=takeline(line, MAXLINE))>0) {
//         if (len>max) {
//             max=len;
//             copy(longest, line);
//             break;
//         }
//     }
//     if (max>0) {
//         printf("%s", longest);
//     }
//     return 0;
// }


// #include <stdio.h>
// #define MAX 1000

// void copy(char str1[], char str2[]) {
//     int i=0;
//     while (str1[i]!='\0'){
//         str2[i]=str1[i];
//         i++;
//     }
// }

// int main () {
//     char arr[MAX];
//     scanf("%s", arr);
//     int c=0;
//     while (arr[c]!='\0') {
//         c++;
//     }
//     char arr2[c];
//     copy(arr, arr2);
//     printf("%s", arr2);
//     return 0;
// }

// void swap(int *p, int *q) {
//     int temp = *p;
//     *p = *q;
//     *q = temp;
// }

// int main () {
    // int a=10;
    // int *ip;
    // ip = &a;
    // const char *b="1";
    // char *cp;
    // // cp =&b;
    // *ip = 11;
    // printf("%p\n", cp);
    // printf("%p\n", ip);
    // printf("%p\n", &ip);
    // printf("%d\n", *ip);
    // printf("%d\n", a);
    // double val;
    // val = atof(b);
    // // double *dp = &val;
    // printf("%lf\n", val);
    // (*ip)++;
    // printf("%d\n", *ip);
    // int r = 5, s = 10;
    // swap(&r, &s); 
    // printf("r = %d, s = %d\n", r, s);
    // int arr [5] = {1, 2, 3,4, 5};
    // printf("%d\n", arr[1]);
// }

// void swapR (int *p, int *q) {
//     int temp = *p;
//     *p = *q;
//     *q = temp;
// }

// void swapV (int **a, int **b) {
//     int temp = **a;
//     **a = **b;
//     **b = temp;
// }

// int main () {
//     int p=10;
//     int *r = &p;
//     int q=20;
//     int *p1, *q1;
//     p1 = &p;
//     q1 = &q;
//     // swapR (&p, &q);
//     swapV (&p1, &q1);
//     printf("p: %d, q: %d\n", p, q);
//     return 0;
// }

// typedef struct Book {
//     int pages;
//     char authorName[20];
//     char releaseDate[8];
//     bool isIssued;
//     char title[47];
//     int bookID;
// }book;

// typedef struct Library {
//     int bookCount;
//     int readerCount;
//     int areaCount;
//     int staffCount;
// }library;

int main () {
    // book book1 = {223, "J.K. Rowling", "26061997", false, "Harry Potter and the Philosopher's Stone", 1001};
    // book book2 = {251, "J.K. Rowling", "02071998", false, "Harry Potter and the Chamber of Secrets", 1002};
    // book book3 = {317, "J.K. Rowling", "08071999", false, "Harry Potter and the Prisoner of Azkaban", 1003};
    // book book4 = {636, "J.K. Rowling", "08072000", true, "Harry Potter and the Goblet of Fire", 1004};
    // book book5 = {766, "J.K. Rowling", "21062003", false, "Harry Potter and the Order of the Phoenix", 1005};
    // book book6 = {607, "J.K. Rowling", "16072005", false, "Harry Potter and the Half-Blood Prince", 1006};
    // book book7 = {759, "J.K. Rowling", "21072007", false, "Harry Potter and the Deathly Hallows", 1007};
    // book book8 = {1178, "J.R.R. Tolkien", "29071954", false, "The Lord of the Rings", 1008};
    // book book9 = {224, "Brian W. Kernighan", "22021978", true, "The C Programming Language", 1009};
    // book book10 = {128, "Geronimo Stilton", "01032000", false, "Geronimo Stilton", 1010};
    // library agc = {10, 8, 144, 2};
    intVector myVector;
    initialise(&myVector);

    printf("Pushing and printing elements in a vector.\n");
    for(int i = 0; i<16; i++) {
        push(&myVector, i);
        printf("MaxCapacity: %d, Size: %d\n", myVector.maxCapacity, myVector.size);
    }
    print(&myVector);

    printf("\n\n\nReversing and printing elements in a vector.\n");
    reverse(&myVector);
    print(&myVector);

    printf("\n\n\nEmptying and printing elements in a vector.\n");
    empty(&myVector);
    print(&myVector);

    for(int i = 0; i<18; i++) {
        push(&myVector, i);
    }
    printf("\n\n\nPopping and printing elements in a vector.\n");
    for(int i = 0; i<20; i++) {
        pop(&myVector);
        printf("MaxCapacity: %d, Size: %d\n", myVector.maxCapacity, myVector.size);
    }    
    print(&myVector);
    printf("\n");

    for(int i = 0; i<20; i++) {
        push(&myVector, i);
    }
    printf("\n\n\nDestroying and printing elements in a vector.\n");
    destroy(&myVector);
    print(&myVector);
    return 0;
}



    // printf("Pushing and printing elements in a vector.\n");
    // for(int i = 0; i<130; i++) {
    //     push(&myVector, i);
    //     printf("MaxCapacity: %d, Size: %d\n", myVector.maxCapacity, myVector.size);
    // }
    // print(&myVector);
    // printf("\n\n\nPopping and printing elements in a vector.\n");
    // for(int i = 0; i<135; i++) {
    //     pop(&myVector);
    //     printf("MaxCapacity: %d, Size: %d\n", myVector.maxCapacity, myVector.size);
    // }    
    // print(&myVector);
    // printf("\n");