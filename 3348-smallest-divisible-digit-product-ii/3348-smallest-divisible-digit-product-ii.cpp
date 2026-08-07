class Solution {
    private: 
    // helper to calculate how many difits are needed to satisfy remaining
    int getMinDigits(int c2 ,int c3,int c5 ,int c7){
        int digits = c5 + c7; //5 and 7 cannot be combined with anyrhing else
        // combine 3s into 9s
        digits  += c3/2;
        c3 %=2;

        // combine 2s into 9s
        digits += c2/3;
        c2 %=3;

        // handle remaining combinatons of 2 and 3
        if(c2 ==2 && c3 ==1) digits +=2;
        else if (c2 == 1 && c3 == 1)digits+=1;
        else if(c2>0 || c3 >0)digits+=1; 
       return digits;
    }

    // generate the smallest suffix string using the remaining prime factors
    string generateSmallestSuffix(int c2 ,int c3 ,int c5,int c7,int remlen){
        string suffix = "";
        // greedily grab 9s ,8s, 7s,6s,5s.4s,3s.2s
        while(c3>=2) {suffix +='9';c3-=2;}
        while(c2>=3) {suffix +='8';c2-=3;}
        while(c7>=1) {suffix +='7';c7-=1;}
        while(c5>=1) {suffix +='5';c5-=1;}

        if(c2 ==2 && c3 == 1){suffix += '6';suffix += '2';c2 =0;c3 =0;}
        else if(c2 ==1 && c3 == 1){suffix += '6';c2 =0;c3 =0;}

        // while(c5 >=1){suffix += '5';c5-=1;}
        while(c2 >=2){suffix += '4';c2-=2;}
        while(c3 >=1){suffix += '3';c3-=1;}
        while(c2 >=1){suffix += '2';c2-=1;}

        // pad with '1's to fill up the remaining length constraints
        while(suffix.length() < remlen){suffix += '1';}

        // sort ascending to get the smallest value
        sort(suffix.begin(),suffix.end());
        return suffix;
    }
public:
    string smallestNumber(string num, long long t) {
        int req2 = 0 ,req3 = 0 ,req5=0,req7=0;
        // step1 :prime factorization of t
        long long temp =t;
        while(temp %2 ==0){req2++;temp/=2;}
        while(temp %3 ==0){req3++;temp/=3;}
        while(temp %5 ==0){req5++;temp/=5;}
        while(temp %7 ==0){req7++;temp/=7;}
        if(temp>1)return "-1";
        int n = num.length();

        // track the total factor count maching the prefix of num
        vector<int>pref2(n+1,0),pref3(n+1,0),pref5(n+1,0),pref7(n+1,0);
        int firstZero = -1;
        for(int i=0;i<n;i++){
            pref2[i+1] = pref2[i];
            pref3[i+1] = pref3[i];
            pref5[i+1] = pref5[i];
            pref7[i+1] = pref7[i];

            if(num[i] == '0'){
                if(firstZero == -1) firstZero = i;
            }else{
                int d = num[i]-'0';
                while(d%2==0){pref2[i+1]++;d/=2;}
                while(d%3 == 0){pref3[i+1]++;d/=3;}
                while(d%5==0){pref5[i+1]++;d/=5;}
                while(d%7==0){pref7[i+1]++;d/=7;}
            }
        }
        // step2 check if num itself matches perfecltly
        if(firstZero == -1 && pref2[n]>= req2 && pref3[n]>= req3 && pref5[n]>= req5 && pref7[n]>= req7){
            return num;
        }

        // step3 : backtrack from right to left to locate a mutable pivot point 
        // if a zero exists we cannot preserve anyhing past it
        int startPos = (firstZero == -1)?n-1:firstZero;
        for(int i = startPos;i>=0;i--){
            int curr = num[i]-'0';

            // tru incrementing the digit at position i
            for(int d = curr+1;d<=9;d++){
                int c2 = max(0,req2 - pref2[i]);
                int c3 = max(0,req3 - pref3[i]);
                int c5 = max(0,req5 - pref5[i]);
                int c7 = max(0,req7 - pref7[i]);

                // subtract factors of the chosen digit d
                int val =d;
                while(val %2 ==0){c2 = max(0,c2-1);val/=2;}
                while(val %3 ==0){c3 = max(0,c3-1);val/=3;}
                while(val %5 ==0){c5 = max(0,c5-1);val/=5;}
                while(val %7 ==0){c7 = max(0,c7-1);val/=7;}

                int remlen = n-1-i;
                if(getMinDigits(c2,c3,c5,c7)<= remlen){
                    string ans = num.substr(0,i);
                    ans += to_string(d);
                    ans += generateSmallestSuffix(c2,c3,c5,c7,remlen);
                    return ans;
                }
            }
        }
        // step4 : if no same length configuration works. the output must be longer
        int remlen = max(n+1,getMinDigits(req2 ,req3,req5,req7));
        return generateSmallestSuffix(req2,req3,req5,req7,remlen);
    }
};