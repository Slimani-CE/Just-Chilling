#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ASCII code <---> Text !!!
    //from ASCII code to Text !!!
    void ASCII_to_Text(char * f_ascii)
    {
        int t_f_ascii , i , f_ascii_lenght ;
        f_ascii_lenght=strlen(f_ascii);
        for (i=0;i<f_ascii_lenght;)
        {
            t_f_ascii=f_ascii[i]-48;
            if (t_f_ascii>2)
            {
                t_f_ascii=t_f_ascii*10+f_ascii[i+1]-48;
                printf("%c",t_f_ascii);
                i=i+2;
            }
            if (t_f_ascii<=2)
            {
                t_f_ascii=t_f_ascii*10+f_ascii[i+1]-48;
                t_f_ascii=t_f_ascii*10+f_ascii[i+2]-48;
                printf("%c",t_f_ascii);
                i=i+3;
            }
        }
    }

    //from Text to ASCII code !!!
    void Text_to_ASCII(char *f_text)
    {
        int text_lenght=strlen(f_text) , i ;
        for(i=0;i<text_lenght;i++)
            printf("%d",f_text[i]);
    }

    //Number to ASCII code
    char* Int_To_Bin(int Numberf)
{
    int i , Temp_Number , *Bin_Code   , lenght , j;
    char *BinNumber=(char*)malloc(9*sizeof(char));
    //Calculate the lenght of the binary code !!!
    i=0;
    Temp_Number=Numberf;
    do
    {
        Temp_Number/=2;
        i++;
    }while (Temp_Number!=0);
    lenght=i;
    //Memory allocation of Bin_Code table using his lenght i !!!
    Bin_Code=(int*)malloc(i*sizeof(int));
    i=0;
    //puting binarys in Bin_Code
    do
    {

        Bin_Code[i]=Numberf%2;
        Numberf/=2;
        i++;
    }while (Numberf!=0);
    for(j=0,i=7;i>7-lenght;i--,j++)
        BinNumber[i]=Bin_Code[j]+48;
    //puting Zeros in the first empty cases that has the lenght=8-lenght !!!
    for(i=0;i<8-lenght;i++)
        BinNumber[i]=48;
    return BinNumber;
}

//ASCII code <---> binary !!!
    //from ASCII code to binary !!!
    void ASCII_to_bin(char *ASCII_code)      //  !!! it works also like a text to bin transformer !!!
    {
        int i=0 , t_ascii , ASCII_lenght=strlen(ASCII_code) ;
            while(ASCII_code[i]!='\0'){
            while((ASCII_code[i]-48<=9)&& ASCII_code[i]-48>=0 )
            {
                t_ascii=ASCII_code[i]-48;      //that means if ascci_code[i] was a part of the ASCII code and that means the table is a string of ASCII codes
                if (t_ascii>2)
                {
                    t_ascii=10*t_ascii+ASCII_code[i+1]-48;
                    i+=2;
                }
                if (t_ascii<=2)
                {
                    t_ascii=10*t_ascii+ASCII_code[i+1]-48;
                    t_ascii=10*t_ascii+ASCII_code[i+2]-48;
                    i+=3;
                }
                printf("%s",Int_To_Bin(t_ascii));
            }
            if (((ASCII_code[i]-48>9)||(ASCII_code[i]-48<0))&&ASCII_code[i]!='\0')     //that means if ascci_code[i] was a character or just one number
            {
                printf("%s",Int_To_Bin(ASCII_code[i]));
                i++;
            }
            }
    }


    //from bin to ASCII code
    void bin_to_ASCII(char* bin_text)
    {
        int i , k , t_bin , bin_lenght ;
        bin_lenght=strlen(bin_text);
        for (i=0;i<bin_lenght;i+=8)
        {
            t_bin=0;
            for(k=i;k<i+8;k++)
            {
                t_bin*=2;
                t_bin+=bin_text[k]-48;
            }
            printf("%d",t_bin);
        }
    }
    //from bin to text code
    void bin_to_text(char* bin_text)
    {
        int i , k , t_bin , bin_lenght ;
        bin_lenght=strlen(bin_text);
        for (i=0;i<bin_lenght;i+=8)
        {
            t_bin=0;
            for(k=i;k<i+8;k++)
            {
                t_bin*=2;
                t_bin+=bin_text[k]-48;
            }
            printf("%c",t_bin);
        }
    }


    void Text_converting(int nswr, char *text)
    {
        if(nswr==1)
        {
            printf("<***              convert your text to an ASCII  code               ***>\n");
            Text_to_ASCII(text);
            printf("\n\n\n");
        }
        if(nswr==2)
        {
            printf("<***              convert your text to a binary  code               ***>\n");
            ASCII_to_bin(text);
            printf("\n\n\n");
        }
    }

    void ASCII_converting (int nswr , char *text)
    {
        if(nswr==1)
        {
            printf("<***               convert your ASCII code to a text               ***>\n");
            ASCII_to_Text(text);
            printf("\n\n\n");
        }
        if(nswr==2)
        {
            printf("<***            convert your ASCII code to a binary   code          ***>\n");
            ASCII_to_bin(text);
            printf("\n\n\n");
        }
    }


    void binary_converting(int nswr , char *text)
    {
        if(nswr==1)
        {
            printf("<***            convert your Binary code to an ASCII  code          ***>\n");
            bin_to_ASCII(text);
            printf("\n\n\n");
        }
        if(nswr==2)
        {
            printf("<***                convert your Binary code to a Text              ***>\n");
            bin_to_text(text);
            printf("\n\n\n");
        }

    }

/*
int main ()
{
    char *text=(char*)malloc(sizeof(char))  ;
    int N ;
    gets(text);
    ASCII_to_bin(text);
    printf("\n%s\n",text);
    free(text);
    text=(char*)malloc(sizeof(char));

    return 0;
}
*/
int main()
{
    char *text=(char*)malloc(sizeof(char));
    int Answer=0, Answer1=0;
    while(Answer1==0 && Answer1!=1 && Answer1!=2 && Answer1!=3)
    {
        printf("<***               Encrypting and Decrypting programme              ***>\n");
        printf("<***           Please Choose the format you want to convert         ***>\n\n");
        printf("<***           type 1 if you want to convert a text                 ***>\n");
        printf("<***           type 2 if you want to convert an ASCII code          ***>\n");
        printf("<***           type 3 if you want to convert a binary code          ***>\n");
        printf("***>Respond:");
        scanf("%d",&Answer);
            if(Answer==1){
                Answer1=3;
                printf("<***                   Please give me the text                      ***>\n");
                //free(text);
                //text=(char*)malloc(sizeof(char));
                getchar();gets(text);
                while (Answer1!=0 )
                {
                 printf("<*** Please Choose the format you want your text to be converted to ***>\n");
                 printf("<***             type 1 to convert it to an ASCII  code             ***>\n");
                 printf("<***             type 2 to convert it  to a binary code             ***>\n");
                 printf("<***                 type 0 to go  back to the menu                 ***>\n");
                 printf("***>Respond:");
                 scanf("%d",&Answer1);
                 Text_converting(Answer1,text);
                 }
            }
            if(Answer==2){
                Answer1=3;
                printf("<***          Please give me the ASCII code                 ***>\n");
                //free(text);
                //text=(char*)malloc(sizeof(char));
                getchar();gets(text);
                while ( Answer1!=0 )
                {
                 printf("<***               Please Choose the  format you want              ***>\n");
                 printf("<***               your ASCII code to be converted to              ***>\n");
                 printf("<***                type 1 to convert  it to a text                ***>\n");
                 printf("<***             type 2 to convert it to a binary code             ***>\n");
                 printf("<***                 type 0 to go back to the menu                 ***>\n");
                 printf("***>Respond:");
                 scanf("%d",&Answer1);
                 ASCII_converting(Answer1,text);
                }
            }
            if(Answer==3)
            {
                Answer1=3;
                printf("<***               Please give me  the binary code                  ***>\n");
                //free(text);
                //text=(char*)malloc(sizeof(char));
                getchar();gets(text);
                while (Answer1!=0){
                    printf("<***               Please Choose  the format you want               ***>\n");
                    printf("<***              your binary code to  be converted to              ***>\n");
                    printf("<***             type 1 to convert it to an ASCII  code             ***>\n");
                    printf("<***              type 2 to convert it to an text code              ***>\n");
                    printf("<***                 type 0 to go  back to the menu                 ***>\n");
                    printf("***>Respond:");
                    scanf("%d",&Answer1);
                    binary_converting(Answer1,text);
                }
            }
    }
}

