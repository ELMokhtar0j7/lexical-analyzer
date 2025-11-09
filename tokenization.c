#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main (){
    char c,next ;
    int i = 0,k=0,l=0,flag=0,keyword_num=0,id_num=0,dig=0;
    char word[100];
    char *keywords[12] = {"int","while","for","return", "if", "else","char","float","const","do","sizeof","include"};
    FILE *fp = fopen("clean.c","r");
    FILE *out = fopen("token.txt","w");
    if (fp ==NULL)
    {
        printf("clean.c is not opened");
    } else {
        printf("clean.c is opened\n");
        while ( (c = fgetc(fp)) != EOF)
        {
            // detect two characters operators
        if (c=='!' || c=='=' || c=='<' || c=='>' || c=='|' || c=='&') {
            next = fgetc(fp);
            if ((c=='!' && next=='=') || (c=='=' && next=='=') ||
                (c=='<' && next=='=') || (c=='>' && next=='=') ||
                (c=='|' && next=='|') || (c=='&' && next=='&')) 
            {
                 i++;
                 fprintf(out,"we detected %c%c operator\n",c,next);
            } else {
        i++;
        fprintf(out,"we detected %c operator\n",c);
        ungetc(next, fp); // push back next char, it’s not part of operator
            }
        }
        // detect basic operators
        else if (c=='+' || c=='-' || c=='/' || c=='*') {
            i++;
            fprintf(out,"we detected %c operator\n",c);
        }

            // detect separator
            else if (c =='(' || c == ')' || c == '{' || c == '}'
                    || c == ',' || c == ';' || c == '[' || c == ']' )
            {
                fprintf(out,"we detected %c Separator\n",c);
                k++;
            }
            else if (isalpha(c) || c == '_') // if char is alpha then it's the start of a word , if it blank it ends
            {
                word[l]=c ;
                l++; //buffer incrementation
            }
            else if (l>0) { //if a char is added to a buffer at least once = word
                        // i used elseif of the isalpha() condition so it's automaticly NOT ALPHA (blank or digit or special char ...)

                word[l]='\0'; // added to the end of a char buffer 
                for(int j=0;j<12;j++){
                    flag = 0; // this flag is to know if the "is it a keyword" condition happened or no
                    if ((strcmp(keywords[j],word)) == 0) // is it a keyword ?
                    {                    
                        flag ++;
                        keyword_num ++;
                        fprintf(out,"%s ==> is keyword\n", word);
                        break; // we break from the loop when we find a match
                    }  
                }
                if(flag == 0){ // here is our flag : the word is an id if it not a keyword
                    id_num++;
                    fprintf(out,"%s ==> is id\n", word);
                }
                l = 0 ;
            }
              // detect a string literal
             if ( c== '"')
            {
                fprintf(out,"/");
                while ((c=fgetc(fp)) != '"') // loop till another '"'
                {
                   fputc(c,out);
                }
                fprintf(out,"/ ==> is literal string\n");
            }
            //detect a char literal
            if ( c == '\'')
            {
                fprintf(out,"/");
                while ((c=fgetc(fp)) != '\'')
                {
                    fputc(c,out);
                }
                fprintf(out,"/ ==> is literal char\n");
            }
            // detect a number literal
            if (isdigit(c))
            {
                fprintf(out,"/");
                while ( isdigit(c) || c == '.') // if it float or integer
                {
                    fputc(c,out);
                    c=fgetc(fp);
                }
                dig++;
                fprintf(out,"/ ==> is literal number\n");
            }
        }
         fprintf(out,"\nthere is %d operators\n",i);
         fprintf(out,"\nthere is %d separator\n",k);
         fprintf(out,"\nthere is %d keywords\n",keyword_num);
         fprintf(out,"%d is the number of identifiers\n", id_num);
         fprintf(out,"%d is the number of literal numbers\n", dig);
         fprintf(out,"--------------------------\n");
         printf("check token.txt file");
        fclose(fp);
        fclose(out);
    }
}