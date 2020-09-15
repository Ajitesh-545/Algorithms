
class coinper{
    static int arr[]={2,3,5,7};
static void per(int tar,String asf){
    if(tar==0 ){
        System.out.println(asf);
    }
    if(tar<0){
        return;
    }

    for(int i=0;i<arr.length;i++){
        int inter=tar-arr[i];
     
        per(inter,asf+arr[i]);
    }
    }

    public static void main(String args[]){
        per(10,"");
    }
}