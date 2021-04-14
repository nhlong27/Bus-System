#include<iostream>
#include<vector>
using namespace std;

class BusParking {
public:
    class Interval;
public:
    class Interval{
    public:
        int start, end;
        Interval(int x, int y){
            start = x;
            end = y;
        }
    };
private:
    vector<Interval> park_list;
public:
    void add(int s, int t){
        park_list.push_back(Interval(s,t));
    }
    void remove(int s, int t){
        int location;
        for (size_t i=0; i<park_list.size();i++){
            if (park_list[i].start==s && park_list[i].end==t)
                location=i;
        }
        if (location==0)
            park_list.erase(park_list.begin());
        else
            park_list.erase(park_list.begin()+location);
    }
    int minPark(){
        if(park_list.size() == 0) {
        return -1;
        }

        vector<Interval> result;
        result.push_back(Interval(park_list[0].start, park_list[0].end));
        vector<int> count_list;
        static int count=1;

        for(size_t i=1; i<park_list.size(); i++){
        int x1 = park_list[i].start;
        int y1 = park_list[i].end;
        int x2 = result[result.size()-1].start;
        int y2 = result[result.size()-1].end;

        if(y2 >= x1){
          result[result.size()-1].start = max(x1,x2);
          result[result.size()-1].end = min(y1,y2);
          count++;
        }
        else{
          result.push_back(Interval(x1, y1));
          count_list.push_back(count);
          count=1;
        }
        }
        count_list.push_back(count);
        int max_count=0;
        for (size_t i=0;i<count_list.size();i++){
        if (count_list[i]>max_count)
            max_count=count_list[i];
        }
        return max_count;
    }
};

int main(){
    BusParking* b = new BusParking();
    b->add(1,5);
    b->add(2,5);
    b->add(3,5);
    cout<<b->minPark();
    return 0;
}
