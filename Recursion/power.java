class power{
    static int pow(int a, int b){ 
        if(b==0){
            return 1;

        }
        return pow(a,b-1)*a;
    
    }
    static int pow1(int a , int b){
           if(b==0){
            return 1;

        }
        int halfans=pow1(a,b/2);
        halfans=halfans*halfans;
        if(b%2==0){
            return halfans;
        }
        else{
            return halfans*a;
        }
    }
    public static void main(String args[]){
        System.out.println(pow1(2,10));
    }

}