 int s = 0;
        long long int e = x;
        long long int mid = s + (e-s)/2;
        int ans = 0;
        while(s <= e){
            long long int prod = mid*mid;
            if(prod == e){
                return mid;
            }
            else if(prod > e){
                e = mid-1;
            }
            else if(prod < e){
                ans = mid;
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;