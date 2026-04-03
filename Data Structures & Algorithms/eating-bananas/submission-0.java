class Solution {

    public boolean binarySearchOnAnswer(int []piles,int k,int h){
        System.out.println("next");
        for(int i=0;i<piles.length;i++){
            h -= ((piles[i]/k) + ((piles[i]%k == 0) ? 0 : 1));

            System.out.println(h + " "+ k + " "+ i);
            if(h<0)
                return false;
        }

       
        return true;

    }
    public int minEatingSpeed(int[] piles, int h) {
        int left =1;
        int right = piles[0];


        for(int i=0;i<piles.length;i++)
            right = Math.max(right,piles[i]);

        int mid;
        int ans=right;
        while(left<=right){
            mid = right - (right-left)/2;

            if(binarySearchOnAnswer(piles,mid,h)){
                ans = mid ;
                right = mid -1;
            }else left = mid+1;    

        }

        return ans;    
    }
}
