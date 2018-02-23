string Solution::intToRoman(int A) {
    string ans="";
    if(A>=1000){
        int k = A/1000;
        A%=1000;
        for(int i=0;i<k;i++){
            ans = ans+"M";
        }
    }
    if(A>=500){
        if(A<900){
            int k = A/500;
            A%=500;
            for(int i=0;i<k;i++){
                ans = ans+"D";
            }
        }else{
            ans = ans+"C"+"M";
            A = A%100;
        }
    }
    if(A>=100){
        if(A<400){
            int k = A/100;
            A%=100;
            for(int i=0;i<k;i++){
                ans = ans+"C";
            }
        }else{
            ans = ans+"C"+"D";
            A = A%100;
        }
    }
    if(A>=50){
        if(A<90){
            int k = A/50;
            A%=50;
            for(int i=0;i<k;i++){
                ans = ans+"L";
            }
            
        }else{
            ans = ans+"X"+"C";
            A=A%10;
        }
    }
    if(A>=10){
        if(A<40){
            int k = A/10;
            A%=10;
            for(int i=0;i<k;i++){
                ans = ans+"X";
            }
        }else{
            ans = ans+"X"+"L";
            A=A%10;
        }
    }
    if(A>=5){
        if(A<9){
            int k = A/5;
            A%=5;
            for(int i=0;i<k;i++){
                ans = ans+"V";
            }
        }else{
            ans = ans+"I"+"X";
            A=0;
        }
    }
    if(A>=1){
        if(A<4){
            int k = A/1;
            A%=1;
            for(int i=0;i<k;i++){
                ans = ans+"I";
            }
        }else{
            ans = ans+"I"+"V";
            A=A%1;
        }
    }
    return ans;
}
