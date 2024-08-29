class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>mp;
        mp[0] = 1;
        return dfs(root,0,targetSum,mp);
    }

    int dfs(TreeNode* node, long long currSum, int target, unordered_map<long long, int>& mp){
        if(!node) return 0;

        currSum += node->val;
        int numToCurr = mp[currSum - target];

        mp[currSum]++;

        int result = numToCurr + 
                     dfs(node->left, currSum, target, mp) + 
                     dfs(node->right, currSum, target, mp);

        mp[currSum]--;
        
        return result;
    }
};
