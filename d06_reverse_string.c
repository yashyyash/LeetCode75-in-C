char* reverseWords(char* s) {
    int l=strlen(s);
    char* r=(char*)malloc((l+1)*sizeof(char));
    int k=0;
    int i=l-1;
    int j,m,end=0;
    
   /* while(s[i]!=' ')
    {
        i--;
    }*/
    
    while(i>=0)
    {
        m=i;
        while(i>=0 && s[i]!=' ')
        {
            i--;
        }

       

        for(j=i+1;j<=m;j++)
        {
           
            *(r+k)=s[j];
            k++;
        }
        
        if(i>=0)
        {
            if(k!=0 && *(r+k-1)!=' ')
            {
            *(r+k)=' ';
            k++;
            }
        }

        i--;
        
        

    }
   /* while(j>=0)
    {
        *(r+k)=s[j];
        k++;
        j--;
    }*/
    if(k>0 && *(r+k-1)==' ')
    {
        k--;
    }
    *(r+k)='\0';
    return r;

}