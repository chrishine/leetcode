#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

void one_length_procedure(string current, unordered_set<string> &dict, queue<string> &que, map<string, int> &path){
    auto length = path[current];
    for (auto i = 0; i < current.length(); ++i){
        char t_c = current[i];
        for (auto c = 'a'; c <= 'z'; c++){
            current[i] = c;
            if (dict.count(current)){
                dict.erase(current);
                que.push(current);
                path[current] = length + 1;
            }
        }
        current[i] = t_c;
    }
}


int ladderLength(string start, string end, unordered_set<string> &dict) {
    map<string, int> path;
    path[start] = 1;
    if (dict.count(start)){
        dict.erase(start);
    }
    dict.insert(end);
    queue<string> que;
    que.push(start);
    while (!que.empty()){
        auto temp = que.front();
        que.pop();
        if (temp == end){
            return path[temp];
        }
        one_length_procedure(temp, dict, que, path);
    }
    return 0;
}

int main ()
{
    string start("hit");
    string end("cog");
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    auto c = clock();
    cout << ladderLength(start,end,dict) << endl;
    c = clock() - c;
    cout << c << endl;
    return 0;
}