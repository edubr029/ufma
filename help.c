void encontrar_palindromo(char str[MAX], int ref[MAX]){ 
         int i, j; 
         int penultimo=strlen(str)-2; 
         for(i=0;i<penultimo;i++){ 
                 if(isalpha(str[i])) { 
                         for(j=strlen(str)-1;j>=(i+2);j--){ 
                                 if(i==0){ 
                                         if(str[i]==str[j]){ 
                                                 if(confirmar(str,i,j)){ 
                                                         int k; 
                                                         for(k=i;k<=j;k++) 
                                                                 str[k]='*'; 
                                                         } 
                                         }                 
                                 } 
                                 else if(str[i-1]==' '){ 
                                         if(str[i]==str[j]){ 
                                                 if(confirmar(str,i,j)){ 
                                                         int k; 
                                                         for(k=i;k<=j;k++) 
                                                                 str[k]='*'; 
                                                         } 
                                         } 
                                 }         
                         } 
                 } 
         } 
 }
