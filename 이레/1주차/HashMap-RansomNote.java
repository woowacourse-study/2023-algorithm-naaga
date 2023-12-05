import java.util.*;

class LinkedList_LinkedListCycle {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<String,Integer> mapOfMagazine = new HashMap();
        for(String word : magazine.split("")) {
            int oldValue = mapOfMagazine.getOrDefault(word, 0);
            mapOfMagazine.put(word, oldValue+1);
        }
        
        for(String word : ransomNote.split("")) {
            if(!mapOfMagazine.containsKey(word)) {
                return false;
            }
            int oldValue = mapOfMagazine.get(word);
            int newValue = oldValue-1;
            if(newValue <0) {
                return false;
            }
            mapOfMagazine.replace(word, newValue);
        }
        return true;
    }
}
