/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

//queue =1 root list(1)
//queue = 2, 3 , size = 2
//for( 2)
class BinaryTreeBFS-BinaryTreeRightSideView {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> answer =  new ArrayList();
        LinkedList<TreeNode> queue = new LinkedList();
        if(root == null) {
            return answer;
        }
        queue.add(root); //1
        while(!queue.isEmpty()) {
            int queueSize = queue.size();
            int lastIndex = queueSize -1; //2,3  2=> 1
            TreeNode rightSide = queue.get(lastIndex); //3
            answer.add(rightSide.val); //1
            for(int i = 0 ; i<queueSize ; i++) { //2,3
                TreeNode current = queue.poll();
                if(current.left != null) {
                    queue.add(current.left);
                }
                if(current.right != null) {  //5
                    queue.add(current.right);
                }
            }
        }
        return answer;
        
        // List<Integer> answer = new ArrayList();
        // return count(root, answer);
    }
    
    // static List<Integer> count(TreeNode root, List<Integer> answer) {
    //     if(root == null) {
    //         return answer;
    //     }
    //     answer.add(root.val);
    //     if(root.right ==null) {
    //         return count(root.left, answer);
    //     }
    //     return count(root.right, answer);
    // }
}
