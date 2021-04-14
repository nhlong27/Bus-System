#include <iostream>
#include <vector>
using namespace std;

class Interval{
  public:
    int start, end;
    Interval(int x, int y){
      start = x;
      end = y;
    }
};

int minPark(vector<Interval> lInterval) {

    if(lInterval.size() == 0) {
    return -1;
    }

    vector<Interval> result;
    result.push_back(Interval(lInterval[0].start, lInterval[0].end));
    vector<int> count_list;
    static int count=1;

    for(size_t i=1; i<lInterval.size(); i++){
    int x1 = lInterval[i].start;
    int y1 = lInterval[i].end;
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

int main() {
  vector<Interval> v;
  v.push_back(Interval(1, 5));
  v.push_back(Interval(3, 9));
  v.push_back(Interval(4, 7));
  v.push_back(Interval(2, 5));
  cout<<minPark(v);
  return 0;
}
