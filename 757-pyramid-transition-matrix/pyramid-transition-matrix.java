class Solution {
    private Map<String,Boolean> dp = new HashMap<>();
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String,List<Character>> mp = new HashMap<>();
        for(String s:allowed){
            String pair = s.substring(0,2);
            char ch = s.charAt(2);
            mp.computeIfAbsent(pair,k -> new ArrayList<>()).add(ch);
        }        
        return fun(bottom,mp,0,new StringBuilder());
    }
    public boolean fun(String cur,Map<String,List<Character>> mp,int idx,StringBuilder next){
        if(cur.length() == 1)
            return true;
        String key = cur+"_"+idx+"_"+next;
        if(dp.containsKey(key))
            return dp.get(key);

        if(idx == cur.length()-1){
            boolean res = fun(next.toString(),mp,0,new StringBuilder());
            dp.put(key,res);
            return res;
        }

        String pair = cur.substring(idx,idx+2);
        if(!mp.containsKey(pair)){
            dp.put(key,false);
            return false;
        }

        for(char ch:mp.get(pair)){
            next.append(ch);
            if(fun(cur,mp,idx+1,next)){
                dp.put(key,true);
                return true;
            }
            next.deleteCharAt(next.length()-1);
        }
        dp.put(key,false);
        return false;
    }
}