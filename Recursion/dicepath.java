class dicepath{
    static int counter=0;
    public static void path(int tar, int src, String psf){
        if(src==tar){
            counter++;
            System.out.println(counter+ " "+psf);

        }
        if(src>tar){
            return;
        }
        for(int dice=1;dice<=6;dice++){
            int inter=src+dice;
            path(tar,inter,psf+dice);
        }

    }




////////////////////////////////////////
//open with 1 or 6
 
    public static void pathopenwith1or6(int tar, int src, String psf){
        if(src==tar){
            counter++;
            System.out.println(counter+ " "+psf);

        }
         if(src>tar){
            return;
        }
    if(src==0){
        pathopenwith1or6(tar,1,psf+1);
         pathopenwith1or6(tar,1,psf+6);

    }
    else{
       
        for(int dice=1;dice<=6;dice++){
            int inter=src+dice;
            path(tar,inter,psf+dice);
        }
    }

    }
///////////////////////////////////////////////////////
//with ladders 


    public static void pathopenwith1or6ladder(int ladder[], int tar, int src, String psf){
        if(src==tar){
            counter++;
            System.out.println(counter+ " "+psf);

        }
          if(src>tar){
            return;
        }
    if(src==0){
        pathopenwith1or6ladder(ladder,tar,1,psf+1);
         pathopenwith1or6ladder(ladder,tar,1,psf+6);

    }
      
        else{
        for(int dice=1;dice<=6;dice++){
            int inter=src+dice;
            pathopenwith1or6ladder(ladder,tar,inter,psf+dice);
        }
        }

    }













public static void main(String args[])

{
     int ladders[]=new int[16];
    ladders[2]=13;
    ladders[3]=11;
    ladders[5]=7;
    pathopenwith1or6ladder( ladders,15,0,"");

  //  path(10,0,"");
    //pathopenwith1or6(10, 0,"");
}
}