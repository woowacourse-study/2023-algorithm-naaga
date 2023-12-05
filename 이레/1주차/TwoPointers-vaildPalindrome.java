class TwoPointers-vaildPalindrome {
    public boolean isPalindrome(String s) {
        if(s.isBlank()) {
            return true;
        }
        s = s.replace(" ", "");
        StringBuilder sb = new StringBuilder();
        for(char c : s.toCharArray()) {
            if(Character.isLetterOrDigit(c)) {
                sb.append(c);
            }
        }
        String sentence = sb.toString().toLowerCase();
        
        sb = new StringBuilder();
        for(int i = sentence.length()-1 ; i>=0; i--) {
            sb.append(sentence.charAt(i));
        }
        String reversedSentence = sb.toString();
        
        return sentence.equals(reversedSentence);
    }
}
