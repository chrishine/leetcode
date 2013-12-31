#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
#include <queue>
#include <ctime>
#include <unordered_map>

using namespace std;
//map set<dict> to vector<string>,index is the vector index i..n-1
//this is for random access with O(1)
vector<string> map_dict;
//each vector<int> stores the adjacency
vector<vector<int> > adjacency;

void build_layers(unordered_set<string> &dict){
    map_dict.clear();
    // to use count function of map
    unordered_map<string, int> tmp_count;
    for(auto tmp : dict){
        tmp_count[tmp] = map_dict.size();
        map_dict.push_back(tmp);
    }

    adjacency.clear();
    adjacency.resize(map_dict.size());
    for(auto i = 0; i != map_dict.size(); ++i){
        auto t_s = map_dict[i];
        for(auto j = 0; j != t_s.length(); ++j){
            auto t_c = t_s[j];
            for(auto c = 'a'; c <= 'z'; ++c){
                // compare with WordLadder, we use vector here
                // and don't erase the word, so the 0 length word
                // itself will be its adjacency.
                if(t_c !=c){
                    t_s[j] = c;
                    if(tmp_count.count(t_s)){
                        adjacency[i].push_back(tmp_count[t_s]);
                    }
                }
            }
            t_s[j] = t_c;
        }
    }

}

void gen(int start_index, int end_index, vector<vector<int>>& next, vector<int>& path, vector<vector<string>>& ans){
    path.push_back(start_index);
    if(start_index == end_index && path.size() > 1){
        ans.push_back(vector<string>());
        for(auto tmp : path){
            ans.back().push_back(map_dict[tmp]);
        }
    }else{
        for(auto i = 0; i != next[start_index].size(); ++i){
            gen(next[start_index][i], end_index, next, path, ans);
        }
    }
    path.pop_back();
}


vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    
    dict.insert(start);
    dict.insert(end);
    build_layers(dict);
    
    queue<int> que;
    vector<vector<int> > next(map_dict.size());
    //build adjacency into layers 
    vector<int> distance(map_dict.size());

    int start_index, end_index;
    for(start_index = 0; map_dict[start_index] != start; ++start_index);
    for(end_index = 0; map_dict[end_index] != end; ++end_index);
    for(int i = 0; i < adjacency[end_index].size(); i++){
        auto v = adjacency[end_index][i];
        que.push(v);
        next[v].push_back(end_index);
        distance[v] = 1;
    }
    
    while(!que.empty()){
        int end_index = que.front(); que.pop();
        if(start_index == end_index) break;
        int d = distance[end_index] + 1;
        for(int i = 0; i < adjacency[end_index].size(); i++){
            auto v = adjacency[end_index][i];
            if(next[v].size() == 0){
                next[v].clear();
                next[v].push_back(end_index);
                distance[v] = d;
                que.push(v);
            }else if(distance[v] == d){
                next[v].push_back(end_index);
            }
        }
    }

    vector<vector<string> > ans;
    vector<int> path;
    gen(start_index, end_index, next, path, ans);

    return ans;
}



int main ()
{
    string start("hit");
    string end("cog");
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    auto c = clock();
    for(auto tmp : findLadders(start,end,dict)){
        for(auto t : tmp){
            cout << " " << t;
        }
        cout << endl;
    }
    c = clock() - c;
    cout << c << endl;
    return 0;
}