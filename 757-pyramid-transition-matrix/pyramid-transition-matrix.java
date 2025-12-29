class Solution {
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String,List<Character>> mp = new HashMap<>();
        for(String s:allowed){
            String pair = s.substring(0,2);
            char ch = s.charAt(2);
            mp.computeIfAbsent(pair,k -> new ArrayList<>()).add(ch);
        }        
        /*
        for(Map.Entry<String,List<Character>> e : mp.entrySet()){
            String pair = e.getKey();
            List<Character> val = e.getValue();
            System.out.println(pair+" "+val);
        }

        another way of traversing the map
        mp.forEach((key,value) -> {
            System.out.println(key+" "+value);
        });
        */
        return fun(bottom,mp,0,new StringBuilder());
    }
    public boolean fun(String cur,Map<String,List<Character>> mp,int idx,StringBuilder next){
        if(cur.length() == 1)
            return true;
        if(idx == cur.length()-1){
            return fun(next.toString(),mp,0,new StringBuilder());
        }

        String pair = cur.substring(idx,idx+2);
        if(!mp.containsKey(pair)){
            return false;
        }

        for(char ch:mp.get(pair)){
            next.append(ch);
            if(fun(cur,mp,idx+1,next))
                return true;
            next.deleteCharAt(next.length()-1);
        }
        return false;
    }
}