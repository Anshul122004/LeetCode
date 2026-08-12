class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> mp = new HashMap <>();
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            char a= s.charAt(i);
            char b= t.charAt(i);
            if(mp.containsKey(a)){
                if(mp.get(a)!=b){
                    return false;
                }
            }
            else{
                if(mp.containsValue(b)){
                    return false;
                }
            }
            mp.put(a,b);
        }
        return true;
    }
}