class Twitter {

    class Tweet{
        public int tweetId;
        public int count;
        public int userId;

        public Tweet(int tweetId,int count,int userId){
            this.tweetId = tweetId;
            this.count = count;
            this.userId = userId;
        }
    }


    Map<Integer,List<Integer>> followMap;
    Map<Integer,List<Tweet>> tweetMap;
    int globalCount; 

    public Twitter() {
          followMap = new HashMap<>();
          tweetMap = new HashMap<>();  
          globalCount =0;
    }
    
    public void initFollowerMap(int followerId){
        List<Integer> list1;
         if(!followMap.containsKey(followerId)){
            list1 = new ArrayList<>();
            list1.add(followerId);
            followMap.put(followerId ,list1);
        }
    }
    public void postTweet(int userId, int tweetId) {
        initFollowerMap(userId);
        List<Tweet> list;
        if(tweetMap.containsKey(userId)){
            list = tweetMap.get(userId);
        }else list = new ArrayList<>();
        
        Tweet tweet = new Tweet(tweetId,globalCount,userId);
        
        list.add(tweet);
        tweetMap.put(userId,list);

        globalCount++;
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> res = new ArrayList<>();


        List<Integer> myFriends = followMap.get(userId);

        PriorityQueue<Tweet> pq = new PriorityQueue<>((a, b) -> b.count - a.count);
        
        List<Tweet> tweets;
        Map<Integer,Integer> userOffsetMap = new HashMap<>();

        for(int friend:myFriends){
            // get latest post by every friend 
            if(tweetMap.containsKey(friend)){
                
                tweets = tweetMap.get(friend);
                userOffsetMap.put(friend,tweets.size()-1);
                pq.offer(tweets.get(tweets.size()-1));
            
            }
           
        }

        int index;
        while(res.size()<10 && pq.size() >0){
            Tweet t= pq.poll();

            res.add(t.tweetId);
            
            tweets = tweetMap.get(t.userId);

            userOffsetMap.get(t.userId);

            index = userOffsetMap.get(t.userId) -1;
            if(index >=0)
                pq.offer(tweets.get(index));

            userOffsetMap.put(t.userId,index);    
            

        }

        return res;


    }

    public void follow(int followerId, int followeeId) {
            initFollowerMap(followerId);
            initFollowerMap(followeeId);

            if(followerId == followeeId)
                return;
            int myId = followerId;
            int destId = followeeId;

            List<Integer> list = followMap.get(myId);

            if(list.indexOf(destId)!=-1)
                return;

            list.add(destId);

            followMap.put(myId,list);
    }
    
    public void unfollow(int followerId, int followeeId) {

            if(followerId == followeeId)
                return;

            int myId = followerId;
            int destId = followeeId;

            List<Integer> list = followMap.get(myId);

            int i = list.indexOf(destId);

            if(i!=-1){
                list.remove(i);
            }

    }
}
