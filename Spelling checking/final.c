#include<stdio.h>
#include<string.h>

int main()
{
    int i, j, dic_cnt=0, len, mini, cnt;
    int flag;
    char dictionary[100][15];
    char word[15];
    printf("Enter the dictionary words:\n ");
    while(scanf("%s", dictionary[dic_cnt])==1)
    {
        if(strcmp(dictionary[dic_cnt], "#")==0)
        {
            break;
        }
        dic_cnt++;
    }
    printf("Enter words:\n ");
    while(scanf("%s", word)==1)
    {
        strlwr(word);

        if(strcmp(word, "#")==0)
        {
            break;
        }
        flag=0;
        for(i=0; i<dic_cnt; i++)
        {
            if(strcmp(dictionary[i], word)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("Corrected: %s\n", word);
        }
        else
        {
            len=strlen(word);
            mini=1000000;
            for(i=0; i<dic_cnt; i++)
            {
                if(strlen(dictionary[i])==len)
                {
                    cnt=0;
                    for(j=0; j<len; j++)
                    {
                        if(dictionary[i][j]!=word[j])
                        {
                            cnt++;
                        }
                    }
                    if(mini>cnt)
                    {
                        mini=cnt;
                    }
                }
            }
            printf("Suggested words: ");
            for(i=0; i<dic_cnt; i++)
            {
                if(strlen(dictionary[i])==len)
                {
                    cnt=0;
                    for(j=0; j<len; j++)
                    {
                        if(dictionary[i][j]!=word[j])
                        {
                            cnt++;
                        }
                    }
                    if(mini==cnt)
                    {
                        printf("%s, ", dictionary[i]);
                    }
                }
            }
            printf("\n");

        }
    }

    return 0;
}

