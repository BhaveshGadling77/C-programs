#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {                //defining structs
        char subs[8];           //
        int credit;             //
        int sem;                //
} subjects;//f1                 //
                                //
typedef struct {                //
        int g[8];               //
} grades;//f2                   //
                                //
typedef struct {                //
        long mis;                //
        float f[100];           //
} marks;//f3                    //till here
typedef struct pointers {
	marks *pt;
	subjects *pt1;
	grades *pt2;
} pointer;

void filtemp(char t[], int fd) {                //fill temp arrays
        int j = 0;
        char c;
        while(read(fd, &c, 1) == 1 && c != '\n' && j < 255) {
                t[j++] = c;
        }
        t[j] = '\0';
}

pointer *fillstruct() {                                     //filling the structs
                                                        //
        int f1, f2, f3;                                 //
        pointer *p = NULL;
	f1 = open("subjects.csv", O_RDONLY);            //
        f2 = open("grades.csv", O_RDONLY);              //
        f3 = open("marks.csv", O_RDONLY);               //file discriptors
        if (f1 < 0 || f2 < 0 || f3 < 0) {               //
                printf("access to files denied");       //
        }                                               //

        char c, temp[256], *tok;        //
        int n = 0, i;                   //n = no of subjects
        while (read(f1, &c, 1)) {       //
                if(c == '\n') {n++;}    //
        }                               //
        lseek(f1, 0, SEEK_SET);         //

        subjects sub[n];        //
        grades grd[n];          //declaring structs
        marks mrk[1024];        //

////////////////////////////////////////////////
        i = 0;                                                          //
        while (i < n) {                                                 //filled subjects
                filtemp(temp, f1);                                      //
                                                                        //
                strcpy(sub[i].subs, strtok(temp, ","));                 //
                sub[i].credit = atoi(strtok(NULL, ","));                //
                sub[i].sem = atoi(strtok(NULL, ","));                   //
                i++;                                                    //
        }                                                               //
                                                                        //
        for(i = 0;i<n;i++){                                             //
        printf(" %s %d %d \n", sub[i].subs, sub[i].credit, sub[i].sem); //
        }                                                               //

///////////////////////////////////////////////

        i = 0;                                                          //
        while(i < n) {                                                  //filled grades.csv
                filtemp(temp, f2);                                      //
                int j = 0;                                              //
                tok = strtok(temp, ",");                                //
                grd[i].g[j++] = atoi(tok);                              //
                printf("%d ", grd[i].g[j-1]);                           //
                while (j < 7) {                                         //
                        tok = strtok(NULL, ",");                        //
                        grd[i].g[j++] = atoi(tok);                      //
                        printf("%d ", grd[i].g[j-1]);                   //
                }                                                       //
                printf("\n");                                           //
                i++;                                                    //
        }
//////////////////////////////////////////////

        static int e = 0;                       //e = no of entries in marks    //
        while (read(f3, &c, 1)) {       //                              //
                if(c == '\n') {e++;}    //                              //
        }                               //                              //
        lseek(f3, 0, SEEK_SET);         //                              //
                                                                        //
        i = 0;                                                          //
        while (i < e) {                                                 //filled marks.csv
                                                                        //
                filtemp(temp, f3);//fill temp                           //
                int j = 0;                                              //
                mrk[i].mis = atoi(strtok(temp, ","));                   //
                while(j < n){                                           //
                        mrk[i].f[j] = atof(strtok(NULL, ","));          //
                        printf("%.2lf ", mrk[i].f[j]);                  //
                        j++;                                            //
                }                                                       //
                printf("\n");                                           //
                i++;                                                    //
                                                                        //
        }                                                               //
///////////////////////////////////////////////// */
        close(f1);
        close(f2);
        close(f3);
	p->pt = mrk;
	p->pt1 = sub;
	p->pt2 = grd;
	return p;
}
/*int findmis(int mis){         //binary search
        int l = -1, start, mid, last = e;

        while()

        return l
}*/
void command1(int mis) {//grade <mis> <subject>
/*      char sub[40];
        int l;
        scanf(" %s", sub);
        //find mis in marks.csv &print
        l = findmis(mis);
        if (l = -1){printf("incorect mis");}

        //find locn of sub in subjects.csv
        //print grade of that sub

*/





        printf("function call sucessfull\n");
}
void command2() {//grade all
        printf("function call sucessfull\n");
}
void command3() {//cgpa <mis>
        printf("function call sucessfull\n");
}
void command4() {//sgpa  <mis>  <sem>
        printf("function call sucessfull\n");
}
void command5() {//failed  <mis>
        printf("function call sucessfull\n");
}
void command6() {//topsem  <sem>
        printf("function call sucessfull\n");
}
void command7() {//topsub  <subject>
        printf("function call sucessfull\n");
}
void command8() {//topnsub  <sub> <n>
        printf("function call sucessfull\n");
}
void command9() {//stdev  <subject>
        printf("function call sucessfull\n");
}

int main () {
        int m;
	pointer *p;
        char c, cmd[100], t[100];
        char c12[12] = "grade", c3[12] = "cgpa", c4[12] = "sgpa", c5[12] = "failed", c6[12] = "topsem";
        char c7[12] = "topsub", c8[12] = "topnsub", c9[12] = "stdev", c10[12] = "exit", t1[12] = "all";

        p = fillstruct(); //take input
	printf("%ld\n", p->pt[0].mis);
        while(1) {
                printf(">");
                scanf("%s", cmd);

                if(strcmp(cmd, c12) == 0) {
                        scanf("%s", t);
                        m = atoi(t);
                        if(strcmp(t, t1) == 0) {
                                command2();
                        } else if (strlen(t) == 9 && (m != 0)) {
                                command1(m);
                        } else {printf("incorrect command\n");}
                } else if(strcmp(cmd, c3) == 0) {
                        command3();
                } else if(strcmp(cmd, c4) == 0) {
                        command4();
                } else if(strcmp(cmd, c5) == 0) {
                        command5();
                } else if(strcmp(cmd, c6) == 0) {
                        command6();
                } else if(strcmp(cmd, c7) == 0) {
                        command7();
                } else if(strcmp(cmd, c8) == 0) {
                        command8();
                } else if(strcmp(cmd, c9) == 0) {
                        command9();
                } else if(strcmp(cmd, c10) == 0) {
                        return 1;
                } else {
                        printf("incorrect command\n");
                }
        }
        return 0;
}
