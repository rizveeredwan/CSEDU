#include <bits/stdc++.h>
using namespace std;
struct info{
char name[50];
int score;

}a[20];


bool cmp(struct info one,struct info two) {
if(one.score >= two.score) return true;
else return false;

}


int main()
{
    FILE *fp1,*fp2;
    fp1 = fopen("input.txt","r");
    int n,i,data,newscore;
    char line[50],newname[20];
    fscanf(fp1,"%d",&n);
    for(i = 0; i < n; i++) {
        fscanf(fp1,"%s",line);
        fscanf(fp1,"%d",&data);
        strcpy(a[i].name,line);
        a[i].score = data;
        }
        scanf("%s %d",newname,&newscore);
        strcpy(a[i].name,newname);
        a[i].score = newscore;
        sort(a, a + n + 1,cmp);
        for(i = 0; i < n + 1; i++) {
            printf("%s %d\n",a[i].name,a[i].score);
        }
        fclose(fp1);
        fopen("input.txt","w");
        fprintf(fp1,"%d\n",n);
        for(i = 0; i < n; i++) {
            fprintf(fp1,"%s %d\n",a[i].name,a[i].score);
        }
        fclose(fp1);








    return 0;

}
