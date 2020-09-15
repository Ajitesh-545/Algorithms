import java.util.ArrayList;

class subsequence{
   static ArrayList<String> gss(String str){
           if(str.length()==0){
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }
        char ch =str.charAt(0);
        String rs=str.substring(1);
        ArrayList<String> rrs = gss(rs);
        ArrayList<String> myans=new ArrayList<>();
        for(String s:rrs){
            myans.add(s);
            myans.add(ch+s);
        }
        return myans;
    }


///////////////////////////////////////////////////

    static void subseq(String str, String asf){
        if(str.length()==0){
            System.out.println(asf);
            return;
            
        }
        char ch =str.charAt(0);
        String rstr=str.substring(1);
        int count=0;

        subseq(rstr,asf+ch);
        subseq(rstr,asf);
      
    }

///////////////////////////////////////////////////////////

 public static ArrayList<String> permutation(String str){
        if(str.length()==1){
            ArrayList<String> base=new ArrayList<>();
            base.add(str);
            return base;
        }

        char ch=str.charAt(0);
        String nstr=str.substring(1); 
        
        ArrayList<String> smallAns=permutation(nstr);
        ArrayList<String> myAns=new ArrayList<>();

        for(String s:smallAns){
            for(int i=0;i<=s.length();i++){
                String ans=s.substring(0,i) + ch + s.substring(i);
                myAns.add(ans);
            }
        }
        return myAns;
    }

////////////////////////////////////////////////////////////////
       public static int permutation(String str,String ans){
        if(str.length()==0){
            System.out.println(ans);
            return 1;
        }

        int count=0;
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            String nstr=str.substring(0,i) + str.substring(i+1);
            count+=permutation(nstr,ch + ans);
        }
        return count;
    }





    
    public static void main(String args[]){
       // System.out.println(gss("abc"));
       System.out.println(permutation("abcde",""));
       //subseq("abc","");
    }
}