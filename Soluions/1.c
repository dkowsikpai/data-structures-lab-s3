    #include <stdio.h>
     
    void main(){
     char st1[20], st2[20], st[40];
     int option, i, j, un_ind = -1, l1, l2, count, flag = 0, ch, ex = 0, sh_index = -1;
     while(1){
      printf("\n1. Concatenation\n2. Comparison\n3. Substring Search\n4. To Lower\n5. To Upper\n6. Exit\n Enter the option: ");
      if (ex == 1) break;
      scanf("%d", &option);
      switch(option){
       case 1:
    	printf("Enter the string1: ");
    	scanf("%s", st1);
    	printf("Enter the string2: ");
    	scanf("%s", st2);
    	i = 0;
    	while(st1[i] != '\0'){
    		st[i] = st1[i];
    		i++;
    	}
    	j = 0;
    	while(st2[j] != '\0'){
    		st[i+j] = st2[j];
    		j++;
    	}	
    	st[i+j] = '\0';
    	printf("Concatenated String: %s\n", st);
        break;
       case 2:
    	printf("Enter the string1: ");
    	 scanf("%s", st1);
    	 printf("Enter the string2: ");
    	 scanf("%s", st2);
    	 i = 0;
    	 while(st1[i] != '\0' && st2[i] != '\0'){
    	  if(st1[i] != st2[i]){
    	    un_ind = i;
    	    break;
    	  }
    	  i++;
    	 }
    	 if(un_ind == -1) printf("Strings are same.");
    	 else printf("Strings are unequal and diferent at index %d", un_ind);
       break;
       case 3:
    	 printf("Enter the string1: ");
    	 scanf("%s", st1);
    	 printf("Enter the string2: ");
    	 scanf("%s", st2);
    	 l1 = strlen(st1);
    	 l2 = strlen(st2);
    	 for (i=0; i<l1-l2+1; i++){
    	  count = 0;
    	  for (j=0; j<l2; j++){
    	   if (st1[i+j] == st2[j]) count++;
    	  }
    	  if (count == l2) {
               flag = 1;
               sh_index = i;
               break;
              }
    	 }
    	if (flag == 1) printf("Substring Found at %d\n", sh_index);
    	else printf("Substring NOT Found\n");
       break;
       case 4:
    	i = 0;
    	printf("Enter the string: ");
    	 scanf("%s", st1);
    	 while(st1[i] != '\0'){
    	  ch = (int) st1[i];
    	  if (ch <=  90 && ch >= 65){
    	   ch += 32; 
    	  }
    	  st1[i] = (char) ch;
    	  i++;
    	 }
    	 printf("Required String is: %s\n", st1);
       break;
       case 5:
    	i = 0;
    	printf("Enter the string: ");
    	 scanf("%s", st1);
    	 while(st1[i] != '\0'){
    	  ch = (int) st1[i];
    	  if (ch <=  122 && ch >= 97){
    	   ch -= 32; 
    	  }
    	  st1[i] = (char) ch;
    	  i++;
    	 }
    	 printf("Required String is: %s\n", st1);
       break;
     
      case 6:
      	ex = 1;
      break;
      default: break;
      }
     }
    }
