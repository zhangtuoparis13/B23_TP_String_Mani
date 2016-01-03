#include <stdio.h>
#include <string.h>
/*
 * Manipulation de chaine de charactere
 * 1. Ecrire une procedure void inverse( char s[], char inv[] ) qui copie la chaine de caracteres s dans inv dans l’ordre inverse. Exemple :
— contenu de s : "voici une petite phrase !" ;
— contenu de inv apres l’appel : "! esarhp etitep enu iciov".
 * */
// 1.1 solution1 : la version en utilisant
// un tableau avec le principe d'echange
void inverse1(char p[]) {
    int n = strlen(p);
    for (int i = 0; i < (n / 2); ++i) {
        char t = p[i];
        p[i] = p[n - i - 1];
        p[n - i - 1] = t;
    }
}

// 1.1 solution2 : la version deux pointeurs avec la principe d'echange
void inverse2(char *string) {
    /* on s'arret quand les deux pointeur rencontre */
    char *p;
    /* faire p pointer vers la fin de la chaine */
    for (p = string; *p != '\0'; p++);
    p--;
    /* echanger les caractere que le p et le string pointe vers */
    while (string < p) {
        char temp;
        temp = *string;
        *string++ = *p;
        *p-- = temp;
    }
}
// une traduction de code de solution deux
/*void reverse_2string(char *pointeur_deb_string)
{
    char *pointeur_fin_string=pointeur_deb_string;
    while(*pointeur_fin_string!='\0'){
        pointeur_fin_string++;
    }
    pointeur_fin_string--;
    while(pointeur_deb_string<pointeur_fin_string)
    {
        char carac_temp=*pointeur_deb_string;
        *pointeur_deb_string=*pointeur_fin_string;
        *pointeur_fin_string=carac_temp;
        pointeur_deb_string++;
        pointeur_fin_string--;
    }
}*/

// 1.1 solution3 : la version deux tableaux
void reverse3(char s[], char inv[]) {
    int i, j;
    size_t n = strlen(s);
    for (i = n - 1, j = 0; i >= 0; i--,j++) {
        inv[j] = s[i];
    }
}
// 1.1 solution4 : la version recusive
void reverse4(char *h, int p) {
    size_t end = strlen(h) - 1;
    // quand on touche la fin , il fait output
    if (p == end)
        printf("%c", h[p]);
    else {
        reverse4(h, p + 1); //si c'est pas la fin, faire output la prochaine position
        printf("%c", h[p]); //puis output la postion courante
    }
}

//1.1 solution5 : la version de pointeur pour parcourir un tableau
void reverse5(char s[])
{
    char * pBegin =s;
    char * pEnd = s + strlen(s);
    char * p = NULL;

    for ( p = pEnd-1 ; p >=pBegin ; p--) {
        printf("%c", *p);
    }
    printf("\n");
}


/*
 * 2. Ecrire une procedure void separe et inverse( char entree[], char sortie[] ) qui identifie les mots separes par des espaces
 * dans la chaine de caracteres entree et les copie dans sortie dans l’ordre inverse. Exemple :
— contenu de entree : voici une petite phrase ! ;
— contenu de sortie apres l’appel : "! phrase petite une voici".
 * */
// Exo 2 solution 1 : deux pointeurs
void invertion_separe(char *ch1, char *ch2)
/*char1 接收实参传过来的原字符串指针 char2 接收倒序后的新字符串返回主函数*/
{
    int count = 1, num = 0;
    char *ch = ch1;
    for (; *ch1 != '\0'; ++ch1) {
        if (*ch1 == ' ')
            count++; //单词数等于空格数目加1, 前面把count初始化为1就是这个原因
        if (*ch1 == ' ' && *(ch1 + 1) == ' ') //防止单词之间有两个空格符而多计数了一个单词数
            count--;
    }
    printf("count = %d \n", count);

    ch1 = ch1 - 1;//前面的ch1经过循环之后已经指向字符串的结束标志'\0'，这里减1是为了让它指向字符串的最后一个字符
    while (ch1 >= ch) //让ch1从指向stringA的最后一个字符开始往前递减，当减到字符串的首个字符时结束
    {
        int j = num; //保存num,后面要用到这个数
        if (*ch1 != ' ')
        {
            num++;
        }//记录每个单词的长度 ，以空格符作为标志
        else { //知道了每个单词的长度之后，就可以用循环将字符以单词为单位写入数组stringB中，这样的话单词内就不会倒序了
            for (int i = 1; i <= j; i++, num--)
                *(ch2 - num) = *(ch1 + i);
            *ch2 = *ch1;
        }
        ch1--;
        ch2++;
    }
    for (int i = 1; i <= num; i++, ch2++) //因为stringA的第一个单词前没有空格符，肯定输不出来，所以单独用一个循环将其输出
        *(ch2 - num) = *(ch1 + i);
    *ch2 = '\0';  //string2的结束标志
}

// Exo2 solution 2 : deux tableux et 'pure pointeur' sans utiliser bibliotheque string.h
void separe_et_inverse(char entree[], char sortie[])
{
    int compteur =1, num = 0;
    char *tmp = entree;
    for (; *entree!='\0' ; ++entree) {
        if (*entree ==' ')
            compteur++; // nbr de mot égal nbr de l'espace plus 1, c'est pourquoi on initiale le compteur à 1
        if (*entree == ' ' && *(entree +1)== ' ') // éviter de compter 1 plus en raison de deux espaces entre les mots
            compteur--;
    }
    printf("compteur = %d \n",compteur);
    entree =entree-1; // le entree pointe vers '\0' après la boucle avant. Il faut donc -1 puisque il pointe vers le dernier caractère de la chaine
    while (entree >= tmp) // faire entree diminuer depuis le dernier cara, il se termine quand il renconte le premier cara
    {
        int j=num; // stocker num, on va l'utilise au fur et a mesure
        if (*entree != ' ') // recorder longeur de chaque mot, les mots sont separer par espace
            num++;
        else{ //lorque on connait longeur de chaque mot, puis on peut le write dans tableau de sortie en utilisant la boucle, dans le meme temps garder bon l'ordre pour chaque mot
            for (int i=1; i<=j;i++,num--)
                *(sortie-num) =*(entree +i);
            *sortie =*entree;
        }
        entree--;
        sortie++;
    }
    for (int i=1; i<= num; i++,sortie++)// genre il n'ya pas l'espace avant le premier mot de entree , on devrait le printer avec une boucle tout seul
        *(sortie-num) = *(entree +i);
    *sortie = '\0'; // signification la fin de sortie
}

/*
 * 3. Un tautogramme est une phrase composee de mots commencant tous par la meme lettre. Par exemple,
 * la chaıne le lion lape le lait lentement est un tautogramme.
 Ecrire une fonction int estTautogramme( char s[] ) qui prend en entree une chaıne de caracteres s et retourne vrai si s est un tautogramme, faux sinon.
 On supposera que s est composee uniquement de lettres minuscules et que deux mots consecutifs sont separes par un seul espace.
 * */
// exo 1.3 tautogramme
int estTautogramme (char s[])
{
    const char t[10] = " ";
    char *token;
    char tmp;
    int flag=1;

    /* get the first token */
    token = strtok(s, t);
    tmp =token[0];

    /* walk through other tokens */
    while (token != NULL) {
//        printf(" %s\n", token);
//        printf(" %c\n",token[0]);
        if (tmp!=token[0])
            flag=0;
        token = strtok(NULL, t);
    }
    return flag;
}


int main() {
//  exo1.1 solution 1
/*    char str1[] = "voici une petite phrase!";
    inverse1(str1);
    printf("%s\n",str1);*/
//  exo1.1 solution 2
/*    char str2[]="Hello world !";
    inverse2(str2);
    printf("after reversed:%s\n",str2);*/
//test solution3
/*    char str3[] = "voici une petite phrase!";
    char str4[50]={0};
    reverse3(str3,str4);
    printf("before reversed:%s\n",str3);
    printf("after reversed:%s\n",str4);*/
//test de solution4
/*    char str5[] = "Please help me!";
    reverse4(str5, 0);*/

// test solution5
/*    char str6[100];
    gets(str6);
    reverse5(str6);*/

    //test de Exo2 solution 1 invertion_separe
/*    char string5[200]; //用于存放输入的字符串
    char string6[200]; //用于存放倒序后的字符串
    printf("Please input a sentences:\n");
    scanf("%[^\n]", string5); //正则表达式的方法用来解决gets不安全的问题
    // gets(string5); //这里不要用scanf,因为scanf遇到空白符就会结束
    printf("Your inputed sentences is:%s\n", string5);
    invertion_separe(string5, string6);
    printf("The invertion sentences is:%s\n", string6);*/


    // separe_et_inverse(string5,string6);
   /*    char str11[80] = "le lion lape le lait lentement";
       char str12[70] = "toto tata blabla";
       printf("Tautogramme? : %d\n",estTautogramme(str11));
       printf("Tautogramme? : %d\n",estTautogramme(str12));*/

    return 0;
}
