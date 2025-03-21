class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> res;
        unordered_set<string> st(begin(supplies), end(supplies));
        vector<bool> cook(n, false);
        int count = n;
        while(count--) {
            for(int j = 0; j < n; j++) {
                if(cook[j]) {
                    continue;
                }
                bool banpaega = true;
                for(int k = 0; k < ingredients[j].size(); k++) {
                    if(!st.count(ingredients[j][k])) {
                        banpaega = false;
                        break;
                    }
                }

                if(banpaega) {
                    st.insert(recipes[j]);
                    res.push_back(recipes[j]);
                    cook[j] = true;
                }
            }
        }
        return res;
    }
};