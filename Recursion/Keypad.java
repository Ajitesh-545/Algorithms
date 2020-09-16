
class Keypad{
    static String key[]={".","abc","def","ghi","jkl","mno","pqr","st","uvwx","yz","#","*"};
  static void combo(String str,String asf){
    if(str.length()==0){
   System.out.println(asf);
   return;
    }
    char ch=str.charAt(0);
    String rn=str.substring(1);
    String strkey=key[ch-'0'];
    for(int i=0;i<strkey.length();i++){
      char chstrkey=strkey.charAt(i);
      combo(rn,asf+chstrkey);
      }
  }

  //////////////////////////////////////////////////
  static int combo(String str,int idx, String asf ){
    char ch=str.charAt(idx);
    String chcode=key[ch-'0'];
    int count=0;
    for(int i=0;i<chcode.length();i++){
      char c=chcode.charAt[i];
      count+=combo(str,idx,asf+c);
      if(idx+1<str.length()){
        int num=(ch-'0')*10+ (str.charAt(idx+1)-'0');
        if(num==10 || num==11){
          
        }
      }

    }
  }

    public static void main(String args[]){
      combo("179"," ");}
}