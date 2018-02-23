public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int lengthOfLastWord(final String a) {
        boolean char_flag = false;
        int len = 0;
        for (int i=a.length()-1; i>=0; i--)
        {
            if (Character.isLetter(a.charAt(i)))
            {
                char_flag = true;
                len++;
            }
            else
            {
                if (char_flag == true)
                    return len;
            }
        }
        return len;
    }
}
