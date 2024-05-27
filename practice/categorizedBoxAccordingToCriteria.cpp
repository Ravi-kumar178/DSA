class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string ans="";
        long long volume = (long long)length*width*height;
        if((length>=10000 || width>=10000 || height>=10000)||(volume >= 1000000000))
        {
            if(mass >= 100) ans+="Both";
            else ans+="Bulky";
        }
        else if(mass >= 100) ans+= "Heavy";
        else ans+="Neither";
        return ans;
    }
};