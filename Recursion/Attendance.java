class Attendance{
    static void present(String str){
        int count=0;
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
          char a='A';

            int diff=ch-a;
           
            if(diff==0){
                count++;
                if(count==2 ){
                 System.out.println("Absent");
                  return;
                    }
                
            }
        }
          for(int j=0;j<str.length()-1;j++){
            char ch1=str.charAt(j);
            char ch2=str.charAt(j+1);
            char ch3='L';
            int l=ch1-ch3;
            int l1=ch2-ch3;
	    if(l==l1){
		System.out.println("Absent");
       return;
		}
          
         
          
          
	}
    System.out.println("Present");
    }


    
    public static void main(String ags[]){
        present("PAPL");
    }
}

