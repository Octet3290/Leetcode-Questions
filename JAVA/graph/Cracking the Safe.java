// https://leetcode.com/problems/cracking-the-safe/

class Solution {
    
  public String crackSafe(int n, int k) {
        // Initialize pwd to n repeated 0's as the start node of DFS.
        String strPwd = String.join("", Collections.nCopies(n, "0"));
        StringBuilder sbPwd = new StringBuilder(strPwd);
        
        Set<String> visitedComb = new HashSet<>();
        visitedComb.add(strPwd);
    
        int targetNumVisited = (int) Math.pow(k, n);
        
        crackSafeAfter(sbPwd, visitedComb, targetNumVisited, n, k);
        
        return sbPwd.toString();
    }
    
    private boolean crackSafeAfter(StringBuilder pwd, Set<String> visitedComb, int targetNumVisited, int n, int k) {
        // Base case: all n-length combinations among digits 0..k-1 are visited. 
        if (visitedComb.size() == targetNumVisited) {
            return true;
        }
        
        String lastDigits = pwd.substring(pwd.length() - n + 1); // Last n-1 digits of pwd.
        for (char ch = '0'; ch < '0' + k; ch++) {
            String newComb = lastDigits + ch;
            if (!visitedComb.contains(newComb))  {
                visitedComb.add(newComb);
                pwd.append(ch);
                if (crackSafeAfter(pwd, visitedComb, targetNumVisited, n, k)) {
                    return true;
                }
                visitedComb.remove(newComb);
                pwd.deleteCharAt(pwd.length() - 1);
            }
        }
        
        return false;
    }
}
