#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<string, int> > key;

struct song_info{
    string genre;
    int playtimes;
    int index;
};

bool cmp(pair<string, int> & a, pair<string,int> & b) 
{
    if(a.second > b.second){
        return true;
    } else {
        return false;
    }
}

struct compPair
{
    compPair(std::string const& s) : _s(s) { }

    bool operator () (std::pair<std::string, int> const& p)
    {
        return (p.first == _s);
    }

    std::string _s;
};


bool compSong(const song_info & a , song_info & b ){
    auto it1 = find_if(key.begin(), key.end(), compPair(a.genre) );
    auto it2 = find_if(key.begin(), key.end(), compPair(b.genre) );
    
    int index1 = distance(key.begin(),it1);
    int index2 = distance(key.begin(),it2);
        
    if( index1 < index2 ){
        return true;
    } else if(index1 == index2){
        if( a.playtimes > b.playtimes ){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<song_info> songInfos;
    for(int i = 0; i<genres.size(); i++){
        song_info song;
        song.genre = genres[i];
        song.playtimes = plays[i];
        song.index = i;
        songInfos.push_back(song);
        
        auto it = find_if(key.begin(), key.end(), compPair(song.genre) );
        if( it != key.end()){
            int indexKey = distance(key.begin(),it);
            key[indexKey].second += song.playtimes;
        } else {
            key.push_back(make_pair(song.genre,song.playtimes));
        }
        
    }
    sort(key.begin(),key.end(),cmp);
    
    sort(songInfos.begin(),songInfos.end(),compSong);
    map<string,int> keyCount;
    for(int si = 0; si < songInfos.size(); si++){  
        auto it = keyCount.find(songInfos[si].genre);
        if(it != keyCount.end()){
            keyCount[songInfos[si].genre]++;
        } else {
            keyCount.insert(make_pair(songInfos[si].genre,1));
        }
        if(keyCount[songInfos[si].genre] <= 2){
            answer.push_back(songInfos[si].index);
        }
    }
    return answer;
}